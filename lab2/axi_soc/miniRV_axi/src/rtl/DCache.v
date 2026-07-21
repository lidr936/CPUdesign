`timescale 1ns / 1ps

`include "defines.vh"

// 主存地址位宽：32bit
// Cache容量：1KB
// Cache块大小：128bit (4*32bit)
// Cache块个数：64

module DCache(
    input  wire         cpu_clk,
    input  wire         cpu_rst,        // high active
    // Interface to CPU
    input  wire [ 3:0]  data_ren,       // 来自CPU的读使能信号
    input  wire [31:0]  data_addr,      // 来自CPU的地址（读、写共用）
    output reg          data_valid,     // 输出给CPU的数据有效信号
    output reg  [31:0]  data_rdata,     // 输出给CPU的读数据
    input  wire [ 3:0]  data_wen,       // 来自CPU的写使能信号
    input  wire [31:0]  data_wdata,     // 来自CPU的写数据
    output reg          data_wresp,     // 输出给CPU的写响应（高电平表示DCache已完成写操作）
    // Interface to Write Bus
    input  wire         dev_wrdy,       // 主存/外设的写就绪信号
    output reg  [ 3:0]  cpu_wen,        // 输出给主存/外设的写使能信号
    output reg  [31:0]  cpu_waddr,      // 输出给主存/外设的写地址
    output reg  [31:0]  cpu_wdata,      // 输出给主存/外设的写数据
    // Interface to Read Bus
    input  wire         dev_rrdy,       // 主存/外设的读就绪信号
    output reg  [ 3:0]  cpu_ren,        // 输出给主存/外设的读使能信号
    output reg  [31:0]  cpu_raddr,      // 输出给主存/外设的读地址
    input  wire         dev_rvalid,     // 来自主存/外设的数据有效信号
    input  wire [127:0] dev_rdata       // 来自主存/外设的读数据
);

    // Peripherals access should be uncached.
    wire uncached = (data_addr[31:16] == 16'hFFFF) & (data_ren != 4'h0 | data_wen != 4'h0) ? 1'b1 : 1'b0;

`ifdef ENABLE_DCACHE    /******** 不要修改此行代码 ********/

    // ============================================================
    // 基本参数
    // ============================================================

    localparam TAG_WIDTH   = 22;
    localparam INDEX_WIDTH = 6;
    localparam LINE_WIDTH  = 151;

    // ============================================================
    // 读请求锁存
    // ============================================================

    reg [31:0]  r_req_addr;
    reg [ 3:0]  r_req_ren;
    reg         r_req_uncached;
    reg [127:0] r_refill_data;

    // ============================================================
    // 写请求锁存
    // ============================================================

    reg [31:0] w_req_addr;
    reg [ 3:0] w_req_wen;
    reg [31:0] w_req_wdata;
    reg        w_req_uncached;

    // ============================================================
    // 地址划分
    // ============================================================

    wire [TAG_WIDTH-1:0] tag_from_cpu = data_addr[31:10];   // 主存地址的TAG字段
    wire [ 1:0]          offset       = data_addr[3:2];     // 32位字偏移量

    wire [TAG_WIDTH-1:0]   r_tag    = r_req_addr[31:10];
    wire [INDEX_WIDTH-1:0] r_index  = r_req_addr[9:4];
    wire [ 1:0]            r_offset = r_req_addr[3:2];

    wire [TAG_WIDTH-1:0]   w_tag    = w_req_addr[31:10];
    wire [INDEX_WIDTH-1:0] w_index  = w_req_addr[9:4];
    wire [ 1:0]            w_offset = w_req_addr[3:2];

    // ============================================================
    // valid/tag 表
    // ============================================================

    reg                 valid_table [0:63];
    reg [TAG_WIDTH-1:0] tag_table   [0:63];

    wire                 valid_bit      = valid_table[data_addr[9:4]];    // Cache块的有效位
    wire [TAG_WIDTH-1:0] tag_from_cache = tag_table[data_addr[9:4]];      // Cache块的TAG字段

    wire                 r_valid_bit = valid_table[r_index];
    wire [TAG_WIDTH-1:0] r_cache_tag = tag_table[r_index];

    wire                 w_valid_bit = valid_table[w_index];
    wire [TAG_WIDTH-1:0] w_cache_tag = tag_table[w_index];

    // ============================================================
    // DCache读状态机
    // ============================================================

    localparam R_IDLE        = 3'b000;
    localparam R_TAG_CHECK   = 3'b001;
    localparam R_REFILL_REQ  = 3'b010;
    localparam R_REFILL_WAIT = 3'b011;
    localparam R_RESP        = 3'b100;
    localparam R_UNC_REQ     = 3'b101;
    localparam R_UNC_WAIT    = 3'b110;

    reg [2:0] r_state;
    reg [2:0] r_nstat;

    wire hit_r = (r_state == R_TAG_CHECK) &&
                 (!r_req_uncached) &&
                 r_valid_bit &&
                 (r_cache_tag == r_tag);

    // ============================================================
    // DCache写状态机
    // ============================================================

    localparam W_IDLE      = 3'b000;
    localparam W_TAG_CHECK = 3'b001;
    localparam W_BUS_REQ   = 3'b010;
    localparam W_BUS_WAIT  = 3'b011;
    localparam W_RESP      = 3'b100;
    localparam W_UNC_REQ   = 3'b101;
    localparam W_UNC_WAIT  = 3'b110;

    reg [2:0] w_state;
    reg [2:0] w_nstat;

    wire hit_w = (w_state == W_TAG_CHECK) &&
                 (!w_req_uncached) &&
                 w_valid_bit &&
                 (w_cache_tag == w_tag);

    // ============================================================
    // 从Cache行中选出32位读数据
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

    function [127:0] merge_write_word;
        input [127:0] old_line;
        input [  1:0] word_sel;
        input [  3:0] byte_en;
        input [ 31:0] write_data;
        reg   [ 31:0] word_data;
        begin
            word_data = line_word(old_line, word_sel);

            if (byte_en[0]) word_data[ 7: 0] = write_data[ 7: 0];
            if (byte_en[1]) word_data[15: 8] = write_data[15: 8];
            if (byte_en[2]) word_data[23:16] = write_data[23:16];
            if (byte_en[3]) word_data[31:24] = write_data[31:24];

            merge_write_word = old_line;
            case (word_sel)
                2'b00: merge_write_word[ 31:  0] = word_data;
                2'b01: merge_write_word[ 63: 32] = word_data;
                2'b10: merge_write_word[ 95: 64] = word_data;
                2'b11: merge_write_word[127: 96] = word_data;
                default: merge_write_word = old_line;
            endcase
        end
    endfunction

    wire [31:0] cache_word_r  = line_word(cache_line_r[127:0], r_offset);
    wire [31:0] refill_word_r = line_word(r_refill_data, r_offset);

    always @(*) begin
        data_valid = 1'b0;
        data_rdata = 32'h0000_0000;

        case (r_state)
            R_TAG_CHECK: begin
                if (hit_r) begin
                    data_valid = 1'b1;
                    data_rdata = cache_word_r;
                end
            end

            R_RESP: begin
                data_valid = 1'b1;
                data_rdata = refill_word_r;
            end

            R_UNC_WAIT: begin
                if (dev_rvalid) begin
                    data_valid = 1'b1;
                    data_rdata = dev_rdata[31:0];
                end
            end

            default: begin
                data_valid = 1'b0;
                data_rdata = 32'h0000_0000;
            end
        endcase
    end

    // ============================================================
    // 写命中时生成新的Cache数据块
    // ============================================================

    reg [127:0] wr_cache_data;

    always @(*) begin
        wr_cache_data = merge_write_word(cache_line_r[127:0],
                                         w_offset,
                                         w_req_wen,
                                         w_req_wdata);
    end

    // ============================================================
    // Cache存储体
    // ============================================================

    wire                   cache_we;
    wire [INDEX_WIDTH-1:0] cache_index;
    wire [LINE_WIDTH-1:0]  cache_line_w;
    wire [LINE_WIDTH-1:0]  cache_line_r;

    wire read_refill_we = (r_state == R_REFILL_WAIT) && dev_rvalid;
    wire write_hit_we   = (w_state == W_TAG_CHECK) && hit_w;

    assign cache_we = read_refill_we | write_hit_we;

    assign cache_index =
        read_refill_we ? r_index :
        write_hit_we   ? w_index :
        ((r_state == R_IDLE) && (|data_ren)) ? data_addr[9:4] :
        ((w_state == W_IDLE) && (|data_wen)) ? data_addr[9:4] :
        (r_state != R_IDLE) ? r_index :
        (w_state != W_IDLE) ? w_index :
        data_addr[9:4];

    assign cache_line_w =
        read_refill_we ? {1'b1, r_tag, dev_rdata} :
        write_hit_we   ? {1'b1, w_tag, wr_cache_data} :
                         {LINE_WIDTH{1'b0}};

    // DCache存储体：Block MEM IP核
    blk_mem_gen_1 U_dsram (
        .clka   (cpu_clk),
        .wea    (cache_we),
        .addra  (cache_index),
        .dina   (cache_line_w),
        .douta  (cache_line_r)
    );

    // ============================================================
    // DCache读状态机现态更新逻辑
    // ============================================================

    integer i;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            r_state       <= R_IDLE;
            r_req_addr    <= 32'h0000_0000;
            r_req_ren     <= 4'h0;
            r_req_uncached<= 1'b0;
            r_refill_data <= 128'h0;

            for (i = 0; i < 64; i = i + 1) begin
                valid_table[i] <= 1'b0;
                tag_table[i]   <= {TAG_WIDTH{1'b0}};
            end
        end else begin
            r_state <= r_nstat;

            if ((r_state == R_IDLE) && (|data_ren)) begin
                r_req_addr     <= data_addr;
                r_req_ren      <= data_ren;
                r_req_uncached <= uncached;
            end

            if ((r_state == R_REFILL_WAIT) && dev_rvalid) begin
                r_refill_data        <= dev_rdata;
                valid_table[r_index] <= 1'b1;
                tag_table[r_index]   <= r_tag;
            end
        end
    end

    // ============================================================
    // DCache读状态机状态转移逻辑
    // ============================================================

    always @(*) begin
        case (r_state)
            R_IDLE: begin
                r_nstat = (|data_ren) ? (uncached ? R_UNC_REQ : R_TAG_CHECK) : R_IDLE;
            end

            R_TAG_CHECK: begin
                r_nstat = hit_r ? R_IDLE : R_REFILL_REQ;
            end

            R_REFILL_REQ: begin
                r_nstat = dev_rrdy ? R_REFILL_WAIT : R_REFILL_REQ;
            end

            R_REFILL_WAIT: begin
                r_nstat = dev_rvalid ? R_RESP : R_REFILL_WAIT;
            end

            R_RESP: begin
                r_nstat = R_IDLE;
            end

            R_UNC_REQ: begin
                r_nstat = dev_rrdy ? R_UNC_WAIT : R_UNC_REQ;
            end

            R_UNC_WAIT: begin
                r_nstat = dev_rvalid ? R_IDLE : R_UNC_WAIT;
            end

            default: begin
                r_nstat = R_IDLE;
            end
        endcase
    end

    // ============================================================
    // DCache读状态机输出信号
    // ============================================================

    always @(*) begin
        cpu_ren   = 4'h0;
        cpu_raddr = 32'h0000_0000;

        case (r_state)
            R_REFILL_REQ: begin
                if (dev_rrdy) begin
                    cpu_ren   = 4'hF;
                    cpu_raddr = {r_req_addr[31:4], 4'b0000};
                end
            end

            R_UNC_REQ: begin
                if (dev_rrdy) begin
                    cpu_ren   = r_req_ren;
                    cpu_raddr = r_req_addr;
                end
            end

            default: begin
                cpu_ren   = 4'h0;
                cpu_raddr = 32'h0000_0000;
            end
        endcase
    end

    // ============================================================
    // DCache写状态机现态更新逻辑
    // ============================================================

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            w_state        <= W_IDLE;
            w_req_addr     <= 32'h0000_0000;
            w_req_wen      <= 4'h0;
            w_req_wdata    <= 32'h0000_0000;
            w_req_uncached <= 1'b0;
        end else begin
            w_state <= w_nstat;

            if ((w_state == W_IDLE) && (|data_wen)) begin
                w_req_addr     <= data_addr;
                w_req_wen      <= data_wen;
                w_req_wdata    <= data_wdata;
                w_req_uncached <= uncached;
            end
        end
    end

    // ============================================================
    // DCache写状态机状态转移逻辑
    // ============================================================

    always @(*) begin
        case (w_state)
            W_IDLE: begin
                w_nstat = (|data_wen) ? (uncached ? W_UNC_REQ : W_TAG_CHECK) : W_IDLE;
            end

            W_TAG_CHECK: begin
                w_nstat = W_BUS_REQ;
            end

            W_BUS_REQ: begin
                w_nstat = dev_wrdy ? W_BUS_WAIT : W_BUS_REQ;
            end

            W_BUS_WAIT: begin
                w_nstat = dev_wrdy ? W_RESP : W_BUS_WAIT;
            end

            W_RESP: begin
                w_nstat = W_IDLE;
            end

            W_UNC_REQ: begin
                w_nstat = dev_wrdy ? W_UNC_WAIT : W_UNC_REQ;
            end

            W_UNC_WAIT: begin
                w_nstat = dev_wrdy ? W_RESP : W_UNC_WAIT;
            end

            default: begin
                w_nstat = W_IDLE;
            end
        endcase
    end

    // ============================================================
    // DCache写状态机输出信号
    // ============================================================

    always @(*) begin
        cpu_wen    = 4'h0;
        cpu_waddr  = 32'h0000_0000;
        cpu_wdata  = 32'h0000_0000;
        data_wresp = 1'b0;

        case (w_state)
            W_BUS_REQ,
            W_UNC_REQ: begin
                if (dev_wrdy) begin
                    cpu_wen   = w_req_wen;
                    cpu_waddr = w_req_addr;
                    cpu_wdata = w_req_wdata;
                end
            end

            W_RESP: begin
                data_wresp = 1'b1;
            end

            default: begin
                cpu_wen    = 4'h0;
                cpu_waddr  = 32'h0000_0000;
                cpu_wdata  = 32'h0000_0000;
                data_wresp = 1'b0;
            end
        endcase
    end

    /******** 不要修改以下代码 ********/
`else

    localparam R_IDLE  = 2'b00;
    localparam R_STAT0 = 2'b01;
    localparam R_STAT1 = 2'b11;
    reg [1:0] r_state, r_nstat;
    reg [3:0] ren_r;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        r_state <= cpu_rst ? R_IDLE : r_nstat;
    end

    always @(*) begin
        case (r_state)
            R_IDLE:  r_nstat = (|data_ren) ? (dev_rrdy ? R_STAT1 : R_STAT0) : R_IDLE;
            R_STAT0: r_nstat = dev_rrdy ? R_STAT1 : R_STAT0;
            R_STAT1: r_nstat = dev_rvalid ? R_IDLE : R_STAT1;
            default: r_nstat = R_IDLE;
        endcase
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            data_valid <= 1'b0;
            cpu_ren    <= 4'h0;
        end else begin
            case (r_state)
                R_IDLE: begin
                    data_valid <= 1'b0;

                    if (|data_ren) begin
                        if (dev_rrdy)
                            cpu_ren <= data_ren;
                        else
                            ren_r   <= data_ren;

                        cpu_raddr <= data_addr;
                    end else
                        cpu_ren   <= 4'h0;
                end
                R_STAT0: begin
                    cpu_ren    <= dev_rrdy ? ren_r : 4'h0;
                end   
                R_STAT1: begin
                    cpu_ren    <= 4'h0;
                    data_valid <= dev_rvalid ? 1'b1 : 1'b0;
                    data_rdata <= dev_rvalid ? dev_rdata : 32'h0;
                end
                default: begin
                    data_valid <= 1'b0;
                    cpu_ren    <= 4'h0;
                end 
            endcase
        end
    end

    localparam W_IDLE  = 2'b00;
    localparam W_STAT0 = 2'b01;
    localparam W_STAT1 = 2'b11;
    reg  [1:0] w_state, w_nstat;
    reg  [3:0] wen_r;
    wire       wr_resp = dev_wrdy & (cpu_wen == 4'h0) ? 1'b1 : 1'b0;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        w_state <= cpu_rst ? W_IDLE : w_nstat;
    end

    always @(*) begin
        case (w_state)
            W_IDLE:  w_nstat = (|data_wen) ? (dev_wrdy ? W_STAT1 : W_STAT0) : W_IDLE;
            W_STAT0: w_nstat = dev_wrdy ? W_STAT1 : W_STAT0;
            W_STAT1: w_nstat = wr_resp ? W_IDLE : W_STAT1;
            default: w_nstat = W_IDLE;
        endcase
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            data_wresp <= 1'b0;
            cpu_wen    <= 4'h0;
        end else begin
            case (w_state)
                W_IDLE: begin
                    data_wresp <= 1'b0;

                    if (|data_wen) begin
                        if (dev_wrdy)
                            cpu_wen <= data_wen;
                        else
                            wen_r   <= data_wen;

                        cpu_waddr  <= data_addr;
                        cpu_wdata  <= data_wdata;
                    end else
                        cpu_wen    <= 4'h0;
                end
                W_STAT0: begin
                    cpu_wen    <= dev_wrdy ? wen_r : 4'h0;
                end
                W_STAT1: begin
                    cpu_wen    <= 4'h0;
                    data_wresp <= wr_resp ? 1'b1 : 1'b0;
                end
                default: begin
                    data_wresp <= 1'b0;
                    cpu_wen    <= 4'h0;
                end
            endcase
        end
    end

`endif

endmodule
