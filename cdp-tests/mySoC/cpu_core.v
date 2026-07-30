`timescale 1ns / 1ps

`include "defines.vh"

module cpu_core(
    input  wire         cpu_rst,
    input  wire         cpu_clk,

    // Instruction Fetch Interface
    output wire         ifetch_req   /* verilator public */ ,
    output wire [31:0]  ifetch_addr  /* verilator public */ ,
    input  wire         ifetch_valid /* verilator public */ ,
    input  wire [31:0]  ifetch_inst,
    
    // Data Access Interface
    output reg  [ 3:0]  daccess_ren,
    output reg  [31:0]  daccess_addr,
    input  wire         daccess_rvalid,
    input  wire [31:0]  daccess_rdata,
    output reg  [ 3:0]  daccess_wen,
    output reg  [31:0]  daccess_wdata,
    input  wire         daccess_wresp
);

    // PC and NPC
    wire [31:0] pc;
    wire [31:0] npc;
    wire [31:0] pc4;
    wire [31:0] inst;

    // Controller
    wire [ 1:0] npc_op;
    wire [ 1:0] rf_wsel;
    wire [ 2:0] sext_op;
    wire [ 4:0] alu_op;
    wire        alua_sel;
    wire        alub_sel;
    wire [ 2:0] ram_rop;
    reg  [ 2:0] ram_rop_r;
    wire [ 3:0] ram_wop;
    wire        is_mul;
    wire        is_div;
    wire        is_mul_div;
    reg         mul_div_flag;       // 乘除法运算的标志位信号

    // Register File
    wire [31:0] rf_rd1;
    wire [31:0] rf_rd2;
    wire [31:0] rf_rd3;
    wire        rf_we;
    wire        rf_we1;
    reg  [ 4:0] rf_wR_r;
    wire [ 4:0] rf_wR;
    reg  [31:0] rf_wD;
    reg  [31:0] pc_r;

    // Signed Extension
    wire [31:0] ext;

    // ALU
    wire [31:0] alu_a;
    wire [31:0] alu_b;
    wire [31:0] alu_c;
    reg  [31:0] alu_c_r;
    wire        br;
    wire        mul_div_busy;
    
    // Memory Access
    wire [ 3:0] da_ren;
    wire [31:0] da_addr;
    wire [ 3:0] da_wen;
    wire [31:0] da_wdata;
    wire [31:0] ram_ext;
    wire        is_ld_st;
    reg         ld_st_flag;
    reg  [31:0] store_wdata_r;
    wire        ld_st_done;         // 访存完成的标志位信号

    wire        inst_finished;      // 指令执行完成的标志位信号
    reg         inst_finished_r;

    /***************************** IF *****************************/
    reg rst_r;
    wire first_req = rst_r & !cpu_rst;
    always @(posedge cpu_clk) rst_r <= cpu_rst;

    // 复位信号发生边沿变化时首次取指; 当前指令执行完毕后取下一条指令
    assign ifetch_req  = first_req | inst_finished_r;
    assign ifetch_addr = pc;

    NPC U_NPC (
        .op         (npc_op),
        .pc         (pc),
        .base       (rf_rd1),
        .offset     (ext),
        .br         (br),
        .npc        (npc),
        .pc4        (pc4)
    );

    PC U_PC (
        .clk        (cpu_clk),
        .rst        (cpu_rst),
        .npc        (npc),
        .fetch      (inst_finished),
        .pc         (pc)
    );
    
    /***************************** ID *****************************/
    // 按照约定的时序，ifetch_inst只在ifetch_valid有效时有效，且它们仅有效1个时钟.
    // 此处是为了避免ifetch_valid撤销后，ifetch_inst发生变化从而导致指令执行出错.
    assign inst = ifetch_valid ? ifetch_inst : 32'h13 /* NOP */ ;

    Controller U_CU (
        // input
        .opcode         (inst[6:0]),
        .funct3         (inst[14:12]),
        .funct7         (inst[31:25]),
        // output
        .npc_op         (npc_op),
        .sext_op        (sext_op),
        .alu_op         (alu_op),
        .alua_sel       (alua_sel),
        .alub_sel       (alub_sel),
        .is_mul         (is_mul),
        .is_div         (is_div),
        .ram_r_op       (ram_rop),
        .ram_w_op       (ram_wop),
        .rf_we          (rf_we),
        .rf_wsel        (rf_wsel)
    );

    RF U_RF (
        .clk        (cpu_clk),
        .rR1        (inst[19:15]),
        .rR2        (inst[24:20]),
        .rD1        (rf_rd1),
        .rD2        (rf_rd2),
        .we         (rf_we1),
        .wR         (rf_wR),
        .wD         (rf_wD)
    );

    SEXT U_SEXT (
        .op         (sext_op),
        .imm        (inst[31:7]),
        .ext        (ext)
    );
    
    // 遇到访存指令时, 拉高ld_st_flag标志位，表示正在执行访存指令
    assign is_ld_st = (ram_rop != `RAM_EXT_N) | (ram_wop != `RAM_WE_N);
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if      (cpu_rst)    ld_st_flag <= 1'b0;
        else if (is_ld_st)   ld_st_flag <= 1'b1;
        else if (ld_st_done) ld_st_flag <= 1'b0;
    end

    // 遇到乘除法指令时，拉高mul_div_flag标志位，表示正在执行乘除法指令
    assign is_mul_div = is_mul | is_div;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if      (cpu_rst)       mul_div_flag <= 1'b0;
        else if (is_mul_div)    mul_div_flag <= 1'b1;
        else if (!mul_div_busy) mul_div_flag <= 1'b0;
    end

    // 访存、乘除法指令无法在1个时钟内执行完，故先把指令的目标寄存器缓存起来
    always @(posedge cpu_clk) begin
        if (is_ld_st | is_mul_div) rf_wR_r <= inst[11:7];
    end

    // 缓存多周期指令的PC，保证load/乘除完成拍Trace仍对应原指令.
    always @(posedge cpu_clk) begin
        if (is_ld_st | is_mul_div) pc_r <= pc;
    end

    /***************************** EX *****************************/
    assign alu_a = alua_sel ? pc  : rf_rd1;
    assign alu_b = alub_sel ? ext : rf_rd2;

    ALU U_ALU (
        .rst        (cpu_rst),
        .clk        (cpu_clk),
        .op         (alu_op),
        .a          (alu_a),
        .b          (alu_b),
        .br         (br),
        .c          (alu_c),
        .busy       (mul_div_busy)
    );

    /***************************** MEM *****************************/
    MREQ U_MEM_REQ (
        .ram_addr   (alu_c),

        .ram_rop    (ram_rop),
        .da_ren     (da_ren),
        .da_addr    (da_addr),

        .ram_wop    (ram_wop),
        .ram_wdata  (rf_rd2),
        .da_wen     (da_wen),
        .da_wdata   (da_wdata)
    );

    MEXT U_MEM_EXT (
        .op             (ram_rop_r),
        .din            (daccess_rdata),
        .byte_offs      (alu_c_r[1:0]),
        .ext            (ram_ext)
    );

    always @(posedge cpu_clk) if (is_ld_st) alu_c_r   <= alu_c;
    always @(posedge cpu_clk) if (is_ld_st) ram_rop_r <= ram_rop;
    always @(posedge cpu_clk) if (ram_wop != `RAM_WE_N) store_wdata_r <= rf_rd2;

    // Interface to Bus
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            daccess_ren   <= 4'h0;
            daccess_wen   <= 4'h0;
        end else begin
            daccess_ren   <= da_ren;
            daccess_addr  <= da_addr;
            daccess_wen   <= da_wen;
            daccess_wdata <= da_wdata;
        end
    end

    assign ld_st_done = daccess_rvalid | daccess_wresp;

    /***************************** WB *****************************/
    assign rf_we1 = ld_st_flag   & daccess_rvalid |                 // Load指令在读取到数据时写回
                    mul_div_flag & !mul_div_busy  |                 // 乘除法指令在运算完成时写回
                    ifetch_valid & rf_we & !is_ld_st & !is_mul_div; // 其他指令在取到指令时写回

    assign rf_wR  = ld_st_flag | mul_div_flag ? rf_wR_r : inst[11:7];

    always @(*) begin
        casex ({ld_st_flag, rf_wsel})
            {1'b0, `WB_ALU}: rf_wD = alu_c;
            {1'b0, `WB_PC4}: rf_wD = pc4;
            {1'b0, `WB_EXT}: rf_wD = ext;
            {1'b1, 2'b??  }: rf_wD = ram_ext;
            default        : rf_wD = 32'h0;
        endcase
    end

    assign inst_finished = ld_st_flag   & ld_st_done    |           // 访存指令在读写完毕时执行完成
                           mul_div_flag & !mul_div_busy |           // 乘除法指令在运算完毕时完成
                           ifetch_valid & !is_ld_st & !is_mul_div;  // 其他指令单周期完成（即取到指令的同时执行完成）

    always @(posedge cpu_clk or posedge cpu_rst) begin
        inst_finished_r <= cpu_rst ? 1'b0 : inst_finished;
    end



    /********************* Your CPU ends here *********************/

`ifdef RUN_TRACE
    wire [31:0] debug_wb_pc    /* verilator public */ ;     // WB阶段的PC
    wire        debug_wb_rf_we /* verilator public */ ;     // WB阶段的寄存器写使能
    wire [ 4:0] debug_wb_rf_wR /* verilator public */ ;     // WB阶段的目标寄存器   (若wb_rf_we为0，此项可为任意值)
    wire [31:0] debug_wb_rf_wD /* verilator public */ ;     // WB阶段写入寄存器的值 (若wb_rf_we为0，此项可为任意值)

    wire [31:0] debug_mem_pc    /* verilator public */ ;    // MEM阶段的PC
    wire [ 3:0] debug_mem_we    /* verilator public */ ;    // MEM阶段写访存时的写使能
    wire [31:0] debug_mem_waddr /* verilator public */ ;    // MEM阶段写访存时的写地址 (若mem_we为0，此项可为任意值)
    wire [31:0] debug_mem_wdata /* verilator public */ ;    // MEM阶段写访存时的写数据 (若mem_we为0，此项可为任意值)

    assign debug_wb_pc    = ld_st_flag | mul_div_flag ? pc_r : pc;
    assign debug_wb_rf_we = rf_we1;
    assign debug_wb_rf_wR = rf_wR;
    assign debug_wb_rf_wD = rf_wD;

    assign debug_mem_pc    = pc;
    assign debug_mem_we    = daccess_wen;
    assign debug_mem_waddr = daccess_addr;
    assign debug_mem_wdata = store_wdata_r;
`endif

endmodule
