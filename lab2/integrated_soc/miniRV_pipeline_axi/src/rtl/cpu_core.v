`timescale 1ns / 1ps

`include "defines.vh"

// Five-stage miniRV core.  The external fetch/data interfaces remain identical
// to the Lab1 core so it can be used by both the simple RAM and the Lab2 SoC.
module cpu_core(
    input  wire         cpu_rst,
    input  wire         cpu_clk,

    output wire         ifetch_req   /* verilator public */ ,
    output wire [31:0]  ifetch_addr  /* verilator public */ ,
    input  wire         ifetch_valid /* verilator public */ ,
    input  wire [31:0]  ifetch_inst,

    output reg  [ 3:0]  daccess_ren,
    output reg  [31:0]  daccess_addr,
    input  wire         daccess_rvalid,
    input  wire [31:0]  daccess_rdata,
    output reg  [ 3:0]  daccess_wen,
    output reg  [31:0]  daccess_wdata,
    input  wire         daccess_wresp
);

    // IF response buffer.  The instruction interface has no ready signal, so
    // a returned instruction is retained while ID is stalled.
    reg  [31:0] fetch_pc;
    reg  [31:0] fetch_req_pc;
    reg          fetch_wait;
    reg          fetch_discard;
    reg          fetch_buf_valid;
    reg  [31:0] fetch_buf_pc;
    reg  [31:0] fetch_buf_inst;

    // IF/ID
    reg          if_id_valid;
    reg  [31:0] if_id_pc;
    reg  [31:0] if_id_inst;

    // ID/EX
    reg          id_ex_valid;
    reg  [31:0] id_ex_pc;
    reg  [31:0] id_ex_rs1_data;
    reg  [31:0] id_ex_rs2_data;
    reg  [31:0] id_ex_ext;
    reg  [ 4:0] id_ex_rs1;
    reg  [ 4:0] id_ex_rs2;
    reg  [ 4:0] id_ex_rd;
    reg  [ 1:0] id_ex_npc_op;
    reg  [ 4:0] id_ex_alu_op;
    reg          id_ex_alua_sel;
    reg          id_ex_alub_sel;
    reg  [ 2:0] id_ex_ram_rop;
    reg  [ 3:0] id_ex_ram_wop;
    reg          id_ex_rf_we;
    reg  [ 1:0] id_ex_rf_wsel;
    reg          id_ex_is_muldiv;
    reg          id_ex_mul_started;

    // EX/MEM
    reg          ex_mem_valid;
    reg  [31:0] ex_mem_pc;
    reg  [31:0] ex_mem_alu_c;
    reg  [31:0] ex_mem_ext;
    reg  [31:0] ex_mem_store_data;
    reg  [ 4:0] ex_mem_rd;
    reg  [ 2:0] ex_mem_ram_rop;
    reg  [ 3:0] ex_mem_ram_wop;
    reg          ex_mem_rf_we;
    reg  [ 1:0] ex_mem_rf_wsel;
    reg          ex_mem_mem_started;

    // MEM/WB
    reg          mem_wb_valid;
    reg  [31:0] mem_wb_pc;
    reg  [31:0] mem_wb_data;
    reg  [ 4:0] mem_wb_rd;
    reg          mem_wb_rf_we;

    // ID decode and register file.
    wire [ 1:0] id_npc_op;
    wire [ 2:0] id_sext_op;
    wire        id_alua_sel;
    wire        id_alub_sel;
    wire [ 4:0] id_alu_op;
    wire        id_is_mul;
    wire        id_is_div;
    wire [ 2:0] id_ram_rop;
    wire [ 3:0] id_ram_wop;
    wire        id_rf_we;
    wire [ 1:0] id_rf_wsel;
    wire [31:0] rf_rd1;
    wire [31:0] rf_rd2;
    wire [31:0] id_ext;
    wire [ 4:0] id_rs1 = if_id_inst[19:15];
    wire [ 4:0] id_rs2 = if_id_inst[24:20];
    wire [ 4:0] id_rd  = if_id_inst[11:7];

    Controller U_controller (
        .opcode     (if_id_inst[6:0]),
        .funct3     (if_id_inst[14:12]),
        .funct7     (if_id_inst[31:25]),
        .npc_op     (id_npc_op),
        .sext_op    (id_sext_op),
        .alua_sel   (id_alua_sel),
        .alub_sel   (id_alub_sel),
        .alu_op     (id_alu_op),
        .is_mul     (id_is_mul),
        .is_div     (id_is_div),
        .ram_r_op   (id_ram_rop),
        .ram_w_op   (id_ram_wop),
        .rf_we      (id_rf_we),
        .rf_wsel    (id_rf_wsel)
    );

    SEXT U_sext (
        .op         (id_sext_op),
        .imm        (if_id_inst[31:7]),
        .ext        (id_ext)
    );

    RF U_rf (
        .clk        (cpu_clk),
        .rR1        (id_rs1),
        .rR2        (id_rs2),
        .rD1        (rf_rd1),
        .rD2        (rf_rd2),
        .we         (mem_wb_valid & mem_wb_rf_we),
        .wR         (mem_wb_rd),
        .wD         (mem_wb_data)
    );

    // A WB result is bypassed directly into ID to avoid relying on RF write/read
    // ordering in the target FPGA primitive.
    wire [31:0] id_rs1_value = (mem_wb_valid & mem_wb_rf_we &
                                (mem_wb_rd != 5'h0) & (mem_wb_rd == id_rs1)) ?
                                mem_wb_data : rf_rd1;
    wire [31:0] id_rs2_value = (mem_wb_valid & mem_wb_rf_we &
                                (mem_wb_rd != 5'h0) & (mem_wb_rd == id_rs2)) ?
                                mem_wb_data : rf_rd2;

    // Only real source reads participate in RAW detection.
    wire id_uses_rs1 = (if_id_inst[6:0] == 7'b0010011) |
                       (if_id_inst[6:0] == 7'b0110011) |
                       (if_id_inst[6:0] == 7'b0000011) |
                       (if_id_inst[6:0] == 7'b0100011) |
                       (if_id_inst[6:0] == 7'b1100011) |
                       (if_id_inst[6:0] == 7'b1100111);
    wire id_uses_rs2 = (if_id_inst[6:0] == 7'b0110011) |
                       (if_id_inst[6:0] == 7'b0100011) |
                       (if_id_inst[6:0] == 7'b1100011);

    wire id_ex_is_load = id_ex_ram_rop != `RAM_EXT_N;
    wire load_use_stall = if_id_valid & id_ex_valid & id_ex_is_load &
                          (id_ex_rd != 5'h0) &
                          ((id_uses_rs1 & (id_ex_rd == id_rs1)) |
                           (id_uses_rs2 & (id_ex_rd == id_rs2)));

    // EX forwarding.  EX/MEM only forwards non-load results; a load is held in
    // MEM until its response is available and is then forwarded from MEM/WB.
    wire ex_mem_can_forward = ex_mem_valid & ex_mem_rf_we &
                              (ex_mem_rd != 5'h0) &
                              (ex_mem_ram_rop == `RAM_EXT_N);
    wire mem_wb_can_forward = mem_wb_valid & mem_wb_rf_we &
                              (mem_wb_rd != 5'h0);
    reg [31:0] ex_rs1_value;
    reg [31:0] ex_rs2_value;
    always @(*) begin
        ex_rs1_value = id_ex_rs1_data;
        ex_rs2_value = id_ex_rs2_data;
        if (mem_wb_can_forward & (mem_wb_rd == id_ex_rs1))
            ex_rs1_value = mem_wb_data;
        if (mem_wb_can_forward & (mem_wb_rd == id_ex_rs2))
            ex_rs2_value = mem_wb_data;
        if (ex_mem_can_forward & (ex_mem_rd == id_ex_rs1))
            ex_rs1_value = ex_mem_alu_c;
        if (ex_mem_can_forward & (ex_mem_rd == id_ex_rs2))
            ex_rs2_value = ex_mem_alu_c;
    end

    wire mem_in_progress = ex_mem_valid &
                           ((ex_mem_ram_rop != `RAM_EXT_N) |
                            (ex_mem_ram_wop != `RAM_WE_N));
    wire mem_response = ((ex_mem_ram_rop != `RAM_EXT_N) & daccess_rvalid) |
                        ((ex_mem_ram_wop != `RAM_WE_N) & daccess_wresp);
    wire mem_stall = mem_in_progress &
                     !(ex_mem_mem_started & mem_response);

    // Multi-cycle ALU operations start exactly once.  While a previous memory
    // operation blocks EX, a younger multiply/divide must not start early.
    wire [4:0] ex_alu_op = (!id_ex_valid | id_ex_mul_started | mem_stall) ?
                           `ALU_NOP : id_ex_alu_op;
    wire [31:0] ex_alu_a = id_ex_alua_sel ? id_ex_pc : ex_rs1_value;
    wire [31:0] ex_alu_b = id_ex_alub_sel ? id_ex_ext : ex_rs2_value;
    wire [31:0] ex_alu_c;
    wire        ex_br;
    wire        ex_alu_busy;

    ALU U_alu (
        .rst        (cpu_rst),
        .clk        (cpu_clk),
        .op         (ex_alu_op),
        .a          (ex_alu_a),
        .b          (ex_alu_b),
        .c          (ex_alu_c),
        .br         (ex_br),
        .busy       (ex_alu_busy)
    );

    wire mul_stall = !mem_stall & id_ex_valid & id_ex_is_muldiv &
                     !(id_ex_mul_started & !ex_alu_busy);
    wire pipe_stall = mem_stall | mul_stall;

    wire ex_is_branch = id_ex_npc_op == `NPC_BRA;
    wire ex_is_jal    = id_ex_npc_op == `NPC_JMP;
    wire ex_is_jalr   = id_ex_npc_op == `NPC_JALR;
    wire ex_redirect = !pipe_stall & id_ex_valid &
                       ((ex_is_branch & ex_br) | ex_is_jal | ex_is_jalr);
    wire [31:0] ex_redirect_pc = ex_is_jalr ?
                                ((ex_rs1_value + id_ex_ext) & 32'hffff_fffe) :
                                (id_ex_pc + id_ex_ext);

    // MEM request shaping and load extraction.
    wire [ 3:0] mreq_ren;
    wire [31:0] mreq_addr;
    wire [ 3:0] mreq_wen;
    wire [31:0] mreq_wdata;
    wire [31:0] mem_ext_data;

    MREQ U_mreq (
        .ram_addr   (ex_mem_alu_c),
        .ram_rop    (ex_mem_ram_rop),
        .da_ren     (mreq_ren),
        .da_addr    (mreq_addr),
        .ram_wop    (ex_mem_ram_wop),
        .ram_wdata  (ex_mem_store_data),
        .da_wen     (mreq_wen),
        .da_wdata   (mreq_wdata)
    );

    MEXT U_mext (
        .op         (ex_mem_ram_rop),
        .din        (daccess_rdata),
        .byte_offs  (ex_mem_alu_c[1:0]),
        .ext        (mem_ext_data)
    );

    always @(*) begin
        daccess_ren   = 4'h0;
        daccess_addr  = mreq_addr;
        daccess_wen   = 4'h0;
        daccess_wdata = mreq_wdata;
        if (mem_in_progress & !ex_mem_mem_started) begin
            daccess_ren = mreq_ren;
            daccess_wen = mreq_wen;
        end
    end

    reg [31:0] mem_wb_input_data;
    always @(*) begin
        case (ex_mem_rf_wsel)
            `WB_RAM: mem_wb_input_data = mem_ext_data;
            `WB_PC4: mem_wb_input_data = ex_mem_pc + 32'd4;
            `WB_EXT: mem_wb_input_data = ex_mem_ext;
            default: mem_wb_input_data = ex_mem_alu_c;
        endcase
    end

    // Request only when no fetched instruction is buffered.  This avoids losing
    // an instruction on the simple valid-only interface during a pipeline stall.
    assign ifetch_req  = !cpu_rst & !fetch_wait & !fetch_buf_valid &
                         !pipe_stall & !load_use_stall & !ex_redirect;
    assign ifetch_addr = fetch_pc;

    wire take_fetch_buf = fetch_buf_valid & !pipe_stall &
                          !load_use_stall & !ex_redirect;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            fetch_pc        <= `PC_INIT_VAL;
            fetch_req_pc    <= 32'h0;
            fetch_wait      <= 1'b0;
            fetch_discard   <= 1'b0;
            fetch_buf_valid <= 1'b0;
            fetch_buf_pc    <= 32'h0;
            fetch_buf_inst  <= 32'h00000013;
        end else begin
            if (ifetch_req) begin
                fetch_wait   <= 1'b1;
                fetch_req_pc <= fetch_pc;
                fetch_pc     <= fetch_pc + 32'd4;
            end
            if (ifetch_valid) begin
                fetch_wait <= 1'b0;
                if (!fetch_discard & !ex_redirect) begin
                    fetch_buf_valid <= 1'b1;
                    fetch_buf_pc    <= fetch_req_pc;
                    fetch_buf_inst  <= ifetch_inst;
                end else begin
                    fetch_buf_valid <= 1'b0;
                    fetch_discard   <= 1'b0;
                end
            end
            if (take_fetch_buf)
                fetch_buf_valid <= 1'b0;
            if (ex_redirect) begin
                fetch_pc        <= ex_redirect_pc;
                fetch_buf_valid <= 1'b0;
                fetch_discard   <= fetch_wait & !ifetch_valid;
            end
        end
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            if_id_valid        <= 1'b0;
            if_id_pc           <= 32'h0;
            if_id_inst         <= 32'h00000013;
            id_ex_valid        <= 1'b0;
            id_ex_pc           <= 32'h0;
            id_ex_rs1_data     <= 32'h0;
            id_ex_rs2_data     <= 32'h0;
            id_ex_ext          <= 32'h0;
            id_ex_rs1          <= 5'h0;
            id_ex_rs2          <= 5'h0;
            id_ex_rd           <= 5'h0;
            id_ex_npc_op       <= `NPC_PC4;
            id_ex_alu_op       <= `ALU_NOP;
            id_ex_alua_sel     <= `ALU_A_RS1;
            id_ex_alub_sel     <= `ALU_B_RS2;
            id_ex_ram_rop      <= `RAM_EXT_N;
            id_ex_ram_wop      <= `RAM_WE_N;
            id_ex_rf_we        <= 1'b0;
            id_ex_rf_wsel      <= `WB_ALU;
            id_ex_is_muldiv    <= 1'b0;
            id_ex_mul_started  <= 1'b0;
            ex_mem_valid       <= 1'b0;
            ex_mem_pc          <= 32'h0;
            ex_mem_alu_c       <= 32'h0;
            ex_mem_ext         <= 32'h0;
            ex_mem_store_data  <= 32'h0;
            ex_mem_rd          <= 5'h0;
            ex_mem_ram_rop     <= `RAM_EXT_N;
            ex_mem_ram_wop     <= `RAM_WE_N;
            ex_mem_rf_we       <= 1'b0;
            ex_mem_rf_wsel     <= `WB_ALU;
            ex_mem_mem_started <= 1'b0;
            mem_wb_valid       <= 1'b0;
            mem_wb_pc          <= 32'h0;
            mem_wb_data        <= 32'h0;
            mem_wb_rd          <= 5'h0;
            mem_wb_rf_we       <= 1'b0;
        end else if (pipe_stall) begin
            // WB is a one-cycle commit pulse.  Holding an older MEM/WB entry
            // while EX or MEM stalls would make Trace observe the same write
            // on every stalled clock.
            mem_wb_valid <= 1'b0;
            if (mul_stall & !id_ex_mul_started)
                id_ex_mul_started <= 1'b1;
            if (mem_stall & !ex_mem_mem_started)
                ex_mem_mem_started <= 1'b1;
        end else begin
            // MEM -> WB
            mem_wb_valid <= ex_mem_valid;
            mem_wb_pc    <= ex_mem_pc;
            mem_wb_data  <= mem_wb_input_data;
            mem_wb_rd    <= ex_mem_rd;
            mem_wb_rf_we <= ex_mem_rf_we;

            // EX -> MEM
            ex_mem_valid       <= id_ex_valid;
            ex_mem_pc          <= id_ex_pc;
            ex_mem_alu_c       <= ex_alu_c;
            ex_mem_ext         <= id_ex_ext;
            ex_mem_store_data  <= ex_rs2_value;
            ex_mem_rd          <= id_ex_rd;
            ex_mem_ram_rop     <= id_ex_ram_rop;
            ex_mem_ram_wop     <= id_ex_ram_wop;
            ex_mem_rf_we       <= id_ex_rf_we;
            ex_mem_rf_wsel     <= id_ex_rf_wsel;
            ex_mem_mem_started <= 1'b0;

            if (ex_redirect) begin
                // The branch itself advances, but both younger stages become bubbles.
                id_ex_valid <= 1'b0;
                if_id_valid <= 1'b0;
            end else if (load_use_stall) begin
                // Keep ID in place and insert one EX bubble for a load-use pair.
                id_ex_valid <= 1'b0;
            end else begin
                // ID -> EX
                id_ex_valid       <= if_id_valid;
                id_ex_pc          <= if_id_pc;
                id_ex_rs1_data    <= id_rs1_value;
                id_ex_rs2_data    <= id_rs2_value;
                id_ex_ext         <= id_ext;
                id_ex_rs1         <= id_rs1;
                id_ex_rs2         <= id_rs2;
                id_ex_rd          <= id_rd;
                id_ex_npc_op      <= id_npc_op;
                id_ex_alu_op      <= id_alu_op;
                id_ex_alua_sel    <= id_alua_sel;
                id_ex_alub_sel    <= id_alub_sel;
                id_ex_ram_rop     <= id_ram_rop;
                id_ex_ram_wop     <= id_ram_wop;
                id_ex_rf_we       <= id_rf_we;
                id_ex_rf_wsel     <= id_rf_wsel;
                id_ex_is_muldiv   <= id_is_mul | id_is_div;
                id_ex_mul_started <= 1'b0;

                // IF -> ID
                if_id_valid <= fetch_buf_valid;
                if_id_pc    <= fetch_buf_pc;
                if_id_inst  <= fetch_buf_inst;
            end
        end
    end

`ifdef RUN_TRACE
    wire [31:0] debug_wb_pc    /* verilator public */ ;
    wire        debug_wb_rf_we /* verilator public */ ;
    wire [ 4:0] debug_wb_rf_wR /* verilator public */ ;
    wire [31:0] debug_wb_rf_wD /* verilator public */ ;
    wire [31:0] debug_mem_pc    /* verilator public */ ;
    wire [ 3:0] debug_mem_we    /* verilator public */ ;
    wire [31:0] debug_mem_waddr /* verilator public */ ;
    wire [31:0] debug_mem_wdata /* verilator public */ ;

    assign debug_wb_pc    = mem_wb_pc;
    assign debug_wb_rf_we = mem_wb_valid & mem_wb_rf_we;
    assign debug_wb_rf_wR = mem_wb_rd;
    assign debug_wb_rf_wD = mem_wb_data;
    assign debug_mem_pc    = ex_mem_pc;
    assign debug_mem_we    = daccess_wen;
    assign debug_mem_waddr = daccess_addr;
    assign debug_mem_wdata = ex_mem_store_data;
`endif

endmodule
