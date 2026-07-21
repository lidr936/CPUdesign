`timescale 1ns / 1ps

`include "defines.vh"

module miniRV_SoC(
    input  wire         fpga_clk,
    input  wire         fpga_rst,
    input  wire [15:0]  sw,
    output wire [15:0]  led,
    output wire [7:0]   dig_en,
    output wire [7:0]   dig_seg,
    output wire [7:0]   dig_seg1,
    input  wire         rx,
    output wire         tx
);

`ifdef RUN_TRACE
    wire sys_clk = fpga_clk;
    wire sys_rst = fpga_rst;
`else
    // The board clock IP is created in Vivado; see the Lab2 manual notes.
    wire pll_clk1;
    wire pll_lock;
    wire sys_clk = pll_lock & pll_clk1;
    reg  sys_rst;
    always @(posedge fpga_clk) sys_rst <= !fpga_rst | !pll_lock;

    clk_wiz_0 U_clkgen (
        .clk_in1(fpga_clk), .locked(pll_lock), .clk_out1(pll_clk1)
    );
`endif

    wire [31:0] axi_awaddr;
    wire [7:0]  axi_awlen;
    wire [2:0]  axi_awsize;
    wire [1:0]  axi_awburst;
    wire        axi_awvalid;
    wire        axi_awready;
    wire [31:0] axi_wdata;
    wire [3:0]  axi_wstrb;
    wire        axi_wlast;
    wire        axi_wvalid;
    wire        axi_wready;
    wire        axi_bready;
    wire [1:0]  axi_bresp;
    wire        axi_bvalid;
    wire [31:0] axi_araddr;
    wire [7:0]  axi_arlen;
    wire [2:0]  axi_arsize;
    wire [1:0]  axi_arburst;
    wire        axi_arvalid;
    wire        axi_arready;
    wire        axi_rready;
    wire [31:0] axi_rdata;
    wire [1:0]  axi_rresp;
    wire        axi_rlast;
    wire        axi_rvalid;

    cpu_top U_cpu (
        .cpu_clk(sys_clk), .cpu_rst(sys_rst),
        .m_axi_awaddr(axi_awaddr), .m_axi_awlen(axi_awlen), .m_axi_awsize(axi_awsize),
        .m_axi_awburst(axi_awburst), .m_axi_awvalid(axi_awvalid), .m_axi_awready(axi_awready),
        .m_axi_wdata(axi_wdata), .m_axi_wstrb(axi_wstrb), .m_axi_wlast(axi_wlast),
        .m_axi_wvalid(axi_wvalid), .m_axi_wready(axi_wready), .m_axi_bready(axi_bready),
        .m_axi_bresp(axi_bresp), .m_axi_bvalid(axi_bvalid), .m_axi_araddr(axi_araddr),
        .m_axi_arlen(axi_arlen), .m_axi_arsize(axi_arsize), .m_axi_arburst(axi_arburst),
        .m_axi_arvalid(axi_arvalid), .m_axi_arready(axi_arready), .m_axi_rready(axi_rready),
        .m_axi_rdata(axi_rdata), .m_axi_rresp(axi_rresp), .m_axi_rlast(axi_rlast),
        .m_axi_rvalid(axi_rvalid)
    );

`ifdef RUN_TRACE
    // Trace supplies bram_axi.v and loads its memory from the selected binary.
    bram_axi U_trace_bram (
        .s_aclk(sys_clk), .s_aresetn(!sys_rst),
        .s_axi_awid(4'h0), .s_axi_awaddr(axi_awaddr), .s_axi_awlen(axi_awlen),
        .s_axi_awsize(axi_awsize), .s_axi_awburst(axi_awburst), .s_axi_awlock(1'b0),
        .s_axi_awcache(4'h0), .s_axi_awprot(3'h0), .s_axi_awvalid(axi_awvalid),
        .s_axi_awready(axi_awready), .s_axi_wdata(axi_wdata), .s_axi_wstrb(axi_wstrb),
        .s_axi_wlast(axi_wlast), .s_axi_wvalid(axi_wvalid), .s_axi_wready(axi_wready),
        .s_axi_bid(), .s_axi_bresp(axi_bresp), .s_axi_bvalid(axi_bvalid),
        .s_axi_bready(axi_bready), .s_axi_arid(4'h0), .s_axi_araddr(axi_araddr),
        .s_axi_arlen(axi_arlen), .s_axi_arsize(axi_arsize), .s_axi_arburst(axi_arburst),
        .s_axi_arlock(1'b0), .s_axi_arcache(4'h0), .s_axi_arprot(3'h0),
        .s_axi_arvalid(axi_arvalid), .s_axi_arready(axi_arready), .s_axi_rid(),
        .s_axi_rdata(axi_rdata), .s_axi_rresp(axi_rresp), .s_axi_rlast(axi_rlast),
        .s_axi_rvalid(axi_rvalid), .s_axi_rready(axi_rready)
    );
`else
    // Replace this trace-only slave with Vivado AXI Interconnect/MIG/peripheral
    // IP when building the FPGA design.  The source-level AXI master boundary
    // is intentionally kept identical between simulation and hardware.
    assign axi_awready = 1'b0;
    assign axi_wready  = 1'b0;
    assign axi_bresp   = 2'b00;
    assign axi_bvalid  = 1'b0;
    assign axi_arready = 1'b0;
    assign axi_rdata   = 32'h0;
    assign axi_rresp   = 2'b00;
    assign axi_rlast   = 1'b0;
    assign axi_rvalid  = 1'b0;
`endif

    // Board peripherals are connected by the Vivado AXI subsystem in hardware.
    assign led      = 16'h0000;
    assign dig_en   = 8'hff;
    assign dig_seg  = 8'hff;
    assign dig_seg1 = 8'hff;
    assign tx       = 1'b1;

endmodule
