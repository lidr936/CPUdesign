`timescale 1ns / 1ps

`include "defines.vh"

// 主存地址位宽：32bit
// Cache容量：1KB
// Cache块大小：128bit / 4 * 32bit
// Cache块个数：64

module ICache(
    input  wire         cpu_clk,
    input  wire         cpu_rst,        // high active
    // Interface to CPU
    input  wire         inst_rreq,      // 来自CPU的取指请求
    input  wire [31:0]  inst_addr,      // 来自CPU的取指地址
    output reg          inst_valid,     // 输出给CPU的指令有效信号（读指令命中）
    output reg  [31:0]  inst_out,       // 输出给CPU的指令
    // Interface to Read Bus
    input  wire         dev_rrdy,       // 主存就绪信号（高电平表示主存可接收ICache的读请求）
    output reg  [ 3:0]  cpu_ren,        // 输出给主存的读使能信号
    output reg  [31:0]  cpu_raddr,      // 输出给主存的读地址
    input  wire         dev_rvalid,     // 来自主存的数据有效信号
    input  wire [127:0] dev_rdata       // 来自主存的读数据
);

`ifdef ENABLE_ICACHE    /******** 不要修改此行代码 ********/

    // ============================================================
    // 基本参数
    // ============================================================

    localparam TAG_WIDTH   = 22;
    localparam INDEX_WIDTH = 6;
    localparam LINE_WIDTH  = 151;

    // ============================================================
    // 请求地址锁存
    // ============================================================

    reg [31:0]  req_addr;
    reg [127:0] refill_data;

    wire [TAG_WIDTH-1:0]   tag_from_cpu = req_addr[31:10];   // 主存地址的TAG字段
    wire [1:0]             offset       = req_addr[3:2];     // 32位字偏移量
    wire [INDEX_WIDTH-1:0] index        = req_addr[9:4];

    // ============================================================
    // valid / tag 表
    // ============================================================

    reg                 valid_table [0:63];
    reg [TAG_WIDTH-1:0] tag_table   [0:63];

    wire                 valid_bit      = valid_table[index];    // Cache块的有效位
    wire [TAG_WIDTH-1:0] tag_from_cache = tag_table[index];      // Cache块的TAG字段

    // ============================================================
    // ICache状态机
    // ============================================================

    localparam IDLE        = 3'b000;
    localparam TAG_CHECK   = 3'b001;
    localparam REFILL_REQ  = 3'b010;
    localparam REFILL_WAIT = 3'b011;
    localparam REFILL_RESP = 3'b100;

    reg [2:0] state;
    reg [2:0] nstat;

    wire hit = (state == TAG_CHECK) &&
               valid_bit &&
               (tag_from_cache == tag_from_cpu);

    // ============================================================
    // Cache存储体信号
    // ============================================================

    wire                  cache_we;
    wire [INDEX_WIDTH-1:0] cache_index;
    wire [LINE_WIDTH-1:0]  cache_line_w;
    wire [LINE_WIDTH-1:0]  cache_line_r;

    wire refill_done = (state == REFILL_WAIT) && dev_rvalid;

    assign cache_we = refill_done;

    assign cache_index = (state == IDLE) ? inst_addr[9:4] : index;

    assign cache_line_w = {1'b1, tag_from_cpu, dev_rdata};

    // ICache存储体：Block MEM IP核
    blk_mem_gen_1 U_isram (
        .clka   (cpu_clk),
        .wea    (cache_we),
        .addra  (cache_index),
        .dina   (cache_line_w),
        .douta  (cache_line_r)
    );

    // ============================================================
    // 输出给CPU的指令
    // ============================================================

    function [31:0] line_word;
        input [127:0] line;
        input [  1:0] word_sel;
        begin
            case (word_sel)
                2'b00: line_word = line[ 31:  0];
                2'b01: line_word = line[ 63: 32];
                2'b10: line_word = line[ 95: 64];
                2'b11: line_word = line[127: 96];
                default: line_word = 32'h0000_0000;
            endcase
        end
    endfunction

    wire [31:0] hit_inst    = line_word(cache_line_r[127:0], offset);
    wire [31:0] refill_inst = line_word(refill_data, offset);

    always @(*) begin
        inst_valid = 1'b0;
        inst_out   = 32'h0000_0000;

        case (state)
            TAG_CHECK: begin
                inst_valid = hit;
                inst_out   = hit ? hit_inst : 32'h0000_0000;
            end

            REFILL_RESP: begin
                inst_valid = 1'b1;
                inst_out   = refill_inst;
            end

            default: begin
                inst_valid = 1'b0;
                inst_out   = 32'h0000_0000;
            end
        endcase
    end

    // ============================================================
    // 状态机现态更新逻辑
    // ============================================================

    integer i;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            state       <= IDLE;
            req_addr    <= 32'h0000_0000;
            refill_data <= 128'h0;

            for (i = 0; i < 64; i = i + 1) begin
                valid_table[i] <= 1'b0;
                tag_table[i]   <= {TAG_WIDTH{1'b0}};
            end
        end else begin
            state <= nstat;

            if ((state == IDLE) && inst_rreq) begin
                req_addr <= inst_addr;
            end

            if (refill_done) begin
                refill_data        <= dev_rdata;
                valid_table[index] <= 1'b1;
                tag_table[index]   <= tag_from_cpu;
            end
        end
    end

    // ============================================================
    // 状态转移逻辑
    // ============================================================

    always @(*) begin
        case (state)
            IDLE: begin
                nstat = inst_rreq ? TAG_CHECK : IDLE;
            end

            TAG_CHECK: begin
                nstat = hit ? IDLE : REFILL_REQ;
            end

            REFILL_REQ: begin
                nstat = dev_rrdy ? REFILL_WAIT : REFILL_REQ;
            end

            REFILL_WAIT: begin
                nstat = dev_rvalid ? REFILL_RESP : REFILL_WAIT;
            end

            REFILL_RESP: begin
                nstat = IDLE;
            end

            default: begin
                nstat = IDLE;
            end
        endcase
    end

    // ============================================================
    // 状态机输出信号
    // ============================================================

    always @(*) begin
        cpu_ren   = 4'h0;
        cpu_raddr = 32'h0000_0000;

        case (state)
            REFILL_REQ: begin
                cpu_ren   = dev_rrdy ? 4'hF : 4'h0;
                cpu_raddr = dev_rrdy ? {req_addr[31:4], 4'b0000} : 32'h0000_0000;
            end

            default: begin
                cpu_ren   = 4'h0;
                cpu_raddr = 32'h0000_0000;
            end
        endcase
    end

    /******** 不要修改以下代码 ********/
`else

    localparam IDLE  = 2'b00;
    localparam STAT0 = 2'b01;
    localparam STAT1 = 2'b11;
    reg [1:0] state, nstat;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        state <= cpu_rst ? IDLE : nstat;
    end

    always @(*) begin
        case (state)
            IDLE:    nstat = inst_rreq ? (dev_rrdy ? STAT1 : STAT0) : IDLE;
            STAT0:   nstat = dev_rrdy ? STAT1 : STAT0;
            STAT1:   nstat = dev_rvalid ? IDLE : STAT1;
            default: nstat = IDLE;
        endcase
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            inst_valid <= 1'b0;
            cpu_ren    <= 4'h0;
        end else begin
            case (state)
                IDLE: begin
                    inst_valid <= 1'b0;
                    cpu_ren    <= (inst_rreq & dev_rrdy) ? 4'hF : 4'h0;
                    cpu_raddr  <= inst_rreq ? inst_addr : 32'h0;
                end
                STAT0: begin
                    cpu_ren    <= dev_rrdy ? 4'hF : 4'h0;
                end
                STAT1: begin
                    cpu_ren    <= 4'h0;
                    inst_valid <= dev_rvalid ? 1'b1 : 1'b0;
                    inst_out   <= dev_rvalid ? dev_rdata[31:0] : 32'h0;
                end
                default: begin
                    inst_valid <= 1'b0;
                    cpu_ren    <= 4'h0;
                end
            endcase
        end
    end

`endif

endmodule
