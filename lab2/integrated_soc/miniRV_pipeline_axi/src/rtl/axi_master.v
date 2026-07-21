`timescale 1ns / 1ps

`include "defines.vh"

// Serializes the two cache ports onto one AXI4 master port.  Cache requests
// are acknowledged once when accepted and once when a write response returns.
module axi_master(
    input  wire                     aclk,
    input  wire                     areset,

    output reg                      ic_dev_rrdy,
    input  wire [3:0]               ic_cpu_ren,
    input  wire [31:0]              ic_cpu_raddr,
    output reg                      ic_dev_rvalid,
    output reg [`IC_BLK_SIZE-1:0]   ic_dev_rdata,

    output reg                      dc_dev_wrdy,
    input  wire [3:0]               dc_cpu_wen,
    input  wire [31:0]              dc_cpu_waddr,
    input  wire [31:0]              dc_cpu_wdata,
    output reg                      dc_dev_rrdy,
    input  wire [3:0]               dc_cpu_ren,
    input  wire [31:0]              dc_cpu_raddr,
    output reg                      dc_dev_rvalid,
    output reg [`DC_BLK_SIZE-1:0]   dc_dev_rdata,

    output reg [31:0]               m_axi_awaddr,
    output reg [7:0]                m_axi_awlen,
    output reg [2:0]                m_axi_awsize,
    output reg [1:0]                m_axi_awburst,
    output reg                      m_axi_awvalid,
    input  wire                     m_axi_awready,

    output reg [31:0]               m_axi_wdata,
    output reg [3:0]                m_axi_wstrb,
    output wire                     m_axi_wlast,
    output reg                      m_axi_wvalid,
    input  wire                     m_axi_wready,

    output reg                      m_axi_bready,
    input  wire [1:0]               m_axi_bresp,
    input  wire                     m_axi_bvalid,

    output reg [31:0]               m_axi_araddr,
    output reg [7:0]                m_axi_arlen,
    output reg [2:0]                m_axi_arsize,
    output reg [1:0]                m_axi_arburst,
    output reg                      m_axi_arvalid,
    input  wire                     m_axi_arready,

    output reg                      m_axi_rready,
    input  wire [31:0]              m_axi_rdata,
    input  wire [1:0]               m_axi_rresp,
    input  wire                     m_axi_rlast,
    input  wire                     m_axi_rvalid
);

    localparam [3:0] GRANT_D = 4'd0;
    localparam [3:0] CHECK_D = 4'd1;
    localparam [3:0] GRANT_I = 4'd2;
    localparam [3:0] CHECK_I = 4'd3;
    localparam [3:0] W_AW    = 4'd4;
    localparam [3:0] W_W     = 4'd5;
    localparam [3:0] W_B     = 4'd6;
    localparam [3:0] R_AR    = 4'd7;
    localparam [3:0] R_DAT   = 4'd8;
    localparam [3:0] R_RSP   = 4'd9;

    reg [3:0]  state;
    reg        read_is_data;
    reg [31:0] write_addr_r;
    reg [31:0] write_data_r;
    reg [3:0]  write_strb_r;
    reg [31:0] read_addr_r;
    reg [7:0]  read_len_r;
    reg [1:0]  read_count;
    // Keep full cache-line storage even when the cache is bypassed.  The
    // public ports are sliced to one word in that configuration.
    reg [127:0] ic_read_buf;
    reg [127:0] dc_read_buf;

    assign m_axi_wlast = 1'b1;

    always @(*) begin
        ic_dev_rrdy  = 1'b0;
        dc_dev_wrdy  = 1'b0;
        dc_dev_rrdy  = 1'b0;
        ic_dev_rvalid = 1'b0;
        dc_dev_rvalid = 1'b0;
        ic_dev_rdata  = ic_read_buf[`IC_BLK_SIZE-1:0];
        dc_dev_rdata  = dc_read_buf[`DC_BLK_SIZE-1:0];

        m_axi_awaddr  = write_addr_r;
        m_axi_awlen   = 8'd0;
        m_axi_awsize  = 3'd2;
        m_axi_awburst = 2'b01;
        m_axi_awvalid = 1'b0;

        m_axi_wdata   = write_data_r;
        m_axi_wstrb   = write_strb_r;
        m_axi_wvalid  = 1'b0;
        m_axi_bready  = 1'b0;

        m_axi_araddr  = read_addr_r;
        m_axi_arlen   = read_len_r;
        m_axi_arsize  = 3'd2;
        m_axi_arburst = 2'b01;
        m_axi_arvalid = 1'b0;
        m_axi_rready  = 1'b0;

        case (state)
            GRANT_D: begin
                // Cache request outputs are registered after ready is seen.
                // Offer one cache at a time, then sample its request in the
                // following state so simultaneous I/D cache activity cannot
                // make both clients believe they own the single AXI port.
                dc_dev_wrdy = 1'b1;
                dc_dev_rrdy = 1'b1;
            end
            GRANT_I: begin
                ic_dev_rrdy = 1'b1;
            end
            W_AW: begin
                m_axi_awvalid = 1'b1;
            end
            W_W: begin
                m_axi_wvalid = 1'b1;
            end
            W_B: begin
                m_axi_bready = 1'b1;
                dc_dev_wrdy  = m_axi_bvalid;
            end
            R_AR: begin
                m_axi_arvalid = 1'b1;
            end
            R_DAT: begin
                m_axi_rready = 1'b1;
            end
            R_RSP: begin
                if (read_is_data)
                    dc_dev_rvalid = 1'b1;
                else
                    ic_dev_rvalid = 1'b1;
            end
            default: begin
            end
        endcase
    end

    always @(posedge aclk or posedge areset) begin
        if (areset) begin
            state        <= GRANT_D;
            read_is_data <= 1'b0;
            write_addr_r <= 32'h0;
            write_data_r <= 32'h0;
            write_strb_r <= 4'h0;
            read_addr_r  <= 32'h0;
            read_len_r   <= 8'h0;
            read_count   <= 2'h0;
            ic_read_buf  <= 128'h0;
            dc_read_buf  <= 128'h0;
        end else begin
            case (state)
                GRANT_D: begin
                    state <= CHECK_D;
                end
                CHECK_D: begin
                    if (|dc_cpu_wen) begin
                        write_addr_r <= dc_cpu_waddr;
                        write_data_r <= dc_cpu_wdata;
                        write_strb_r <= dc_cpu_wen;
                        state        <= W_AW;
                    end else if (|dc_cpu_ren) begin
                        read_is_data <= 1'b1;
                        read_addr_r  <= dc_cpu_raddr;
                        read_len_r   <= `DC_BLK_LEN - 1;
                        read_count   <= 2'h0;
                        dc_read_buf  <= 128'h0;
                        state        <= R_AR;
                    end else begin
                        state <= GRANT_I;
                    end
                end
                GRANT_I: begin
                    state <= CHECK_I;
                end
                CHECK_I: begin
                    if (|ic_cpu_ren) begin
                        read_is_data <= 1'b0;
                        read_addr_r  <= ic_cpu_raddr;
                        read_len_r   <= `IC_BLK_LEN - 1;
                        read_count   <= 2'h0;
                        ic_read_buf  <= 128'h0;
                        state        <= R_AR;
                    end else begin
                        state <= GRANT_D;
                    end
                end
                W_AW: begin
                    if (m_axi_awready) state <= W_W;
                end
                W_W: begin
                    if (m_axi_wready) state <= W_B;
                end
                W_B: begin
                    if (m_axi_bvalid) state <= GRANT_D;
                end
                R_AR: begin
                    if (m_axi_arready) state <= R_DAT;
                end
                R_DAT: begin
                    if (m_axi_rvalid) begin
                        if (read_is_data) begin
                            case (read_count)
                                2'd0: dc_read_buf[31:0]   <= m_axi_rdata;
                                2'd1: dc_read_buf[63:32]  <= m_axi_rdata;
                                2'd2: dc_read_buf[95:64]  <= m_axi_rdata;
                                2'd3: dc_read_buf[127:96] <= m_axi_rdata;
                            endcase
                        end else begin
                            case (read_count)
                                2'd0: ic_read_buf[31:0]   <= m_axi_rdata;
                                2'd1: ic_read_buf[63:32]  <= m_axi_rdata;
                                2'd2: ic_read_buf[95:64]  <= m_axi_rdata;
                                2'd3: ic_read_buf[127:96] <= m_axi_rdata;
                            endcase
                        end
                        if (m_axi_rlast)
                            state <= R_RSP;
                        else
                            read_count <= read_count + 1'b1;
                    end
                end
                R_RSP: begin
                    state <= GRANT_D;
                end
                default: state <= GRANT_D;
            endcase
        end
    end

endmodule
