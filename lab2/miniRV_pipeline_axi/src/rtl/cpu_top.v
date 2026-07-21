`timescale 1ns / 1ps

`include "defines.vh"

module cpu_top(
    input  wire         cpu_clk,
    input  wire         cpu_rst,

    output wire [31:0]  m_axi_awaddr,
    output wire [7:0]   m_axi_awlen,
    output wire [2:0]   m_axi_awsize,
    output wire [1:0]   m_axi_awburst,
    output wire         m_axi_awvalid,
    input  wire         m_axi_awready,
    output wire [31:0]  m_axi_wdata,
    output wire [3:0]   m_axi_wstrb,
    output wire         m_axi_wlast,
    output wire         m_axi_wvalid,
    input  wire         m_axi_wready,
    output wire         m_axi_bready,
    input  wire [1:0]   m_axi_bresp,
    input  wire         m_axi_bvalid,
    output wire [31:0]  m_axi_araddr,
    output wire [7:0]   m_axi_arlen,
    output wire [2:0]   m_axi_arsize,
    output wire [1:0]   m_axi_arburst,
    output wire         m_axi_arvalid,
    input  wire         m_axi_arready,
    output wire         m_axi_rready,
    input  wire [31:0]  m_axi_rdata,
    input  wire [1:0]   m_axi_rresp,
    input  wire         m_axi_rlast,
    input  wire         m_axi_rvalid
);

    wire        cpu2ic_rreq;
    wire [31:0] cpu2ic_addr;
    wire        ic2cpu_valid;
    wire [31:0] ic2cpu_inst;
    wire [3:0]  ic2axi_ren;
    wire [31:0] ic2axi_addr;
    wire        axi2ic_rrdy;
    wire        axi2ic_rvalid;
    wire [`IC_BLK_SIZE-1:0] axi2ic_rdata;

    wire [3:0]  cpu2dc_ren;
    wire [31:0] cpu2dc_addr;
    wire        dc2cpu_valid;
    wire [31:0] dc2cpu_rdata;
    wire [3:0]  cpu2dc_wen;
    wire [31:0] cpu2dc_wdata;
    wire        dc2cpu_wresp;
    wire [3:0]  dc2axi_wen;
    wire [31:0] dc2axi_waddr;
    wire [31:0] dc2axi_wdata;
    wire        axi2dc_wrdy;
    wire [3:0]  dc2axi_ren;
    wire [31:0] dc2axi_raddr;
    wire        axi2dc_rrdy;
    wire        axi2dc_rvalid;
    wire [`DC_BLK_SIZE-1:0] axi2dc_rdata;

    cpu_core U_core (
        .cpu_clk(cpu_clk), .cpu_rst(cpu_rst),
        .ifetch_req(cpu2ic_rreq), .ifetch_addr(cpu2ic_addr),
        .ifetch_valid(ic2cpu_valid), .ifetch_inst(ic2cpu_inst),
        .daccess_ren(cpu2dc_ren), .daccess_addr(cpu2dc_addr),
        .daccess_rvalid(dc2cpu_valid), .daccess_rdata(dc2cpu_rdata),
        .daccess_wen(cpu2dc_wen), .daccess_wdata(cpu2dc_wdata),
        .daccess_wresp(dc2cpu_wresp)
    );

    ICache U_icache (
        .cpu_clk(cpu_clk), .cpu_rst(cpu_rst),
        .inst_rreq(cpu2ic_rreq), .inst_addr(cpu2ic_addr),
        .inst_valid(ic2cpu_valid), .inst_out(ic2cpu_inst),
        .dev_rrdy(axi2ic_rrdy), .cpu_ren(ic2axi_ren), .cpu_raddr(ic2axi_addr),
        .dev_rvalid(axi2ic_rvalid), .dev_rdata(axi2ic_rdata)
    );

    DCache U_dcache (
        .cpu_clk(cpu_clk), .cpu_rst(cpu_rst),
        .data_ren(cpu2dc_ren), .data_addr(cpu2dc_addr),
        .data_valid(dc2cpu_valid), .data_rdata(dc2cpu_rdata),
        .data_wen(cpu2dc_wen), .data_wdata(cpu2dc_wdata), .data_wresp(dc2cpu_wresp),
        .dev_wrdy(axi2dc_wrdy), .cpu_wen(dc2axi_wen), .cpu_waddr(dc2axi_waddr),
        .cpu_wdata(dc2axi_wdata), .dev_rrdy(axi2dc_rrdy), .cpu_ren(dc2axi_ren),
        .cpu_raddr(dc2axi_raddr), .dev_rvalid(axi2dc_rvalid), .dev_rdata(axi2dc_rdata)
    );

    axi_master U_axi_master (
        .aclk(cpu_clk), .areset(cpu_rst),
        .ic_dev_rrdy(axi2ic_rrdy), .ic_cpu_ren(ic2axi_ren), .ic_cpu_raddr(ic2axi_addr),
        .ic_dev_rvalid(axi2ic_rvalid), .ic_dev_rdata(axi2ic_rdata),
        .dc_dev_wrdy(axi2dc_wrdy), .dc_cpu_wen(dc2axi_wen), .dc_cpu_waddr(dc2axi_waddr),
        .dc_cpu_wdata(dc2axi_wdata), .dc_dev_rrdy(axi2dc_rrdy), .dc_cpu_ren(dc2axi_ren),
        .dc_cpu_raddr(dc2axi_raddr), .dc_dev_rvalid(axi2dc_rvalid), .dc_dev_rdata(axi2dc_rdata),
        .m_axi_awaddr(m_axi_awaddr), .m_axi_awlen(m_axi_awlen), .m_axi_awsize(m_axi_awsize),
        .m_axi_awburst(m_axi_awburst), .m_axi_awvalid(m_axi_awvalid), .m_axi_awready(m_axi_awready),
        .m_axi_wdata(m_axi_wdata), .m_axi_wstrb(m_axi_wstrb), .m_axi_wlast(m_axi_wlast),
        .m_axi_wvalid(m_axi_wvalid), .m_axi_wready(m_axi_wready), .m_axi_bready(m_axi_bready),
        .m_axi_bresp(m_axi_bresp), .m_axi_bvalid(m_axi_bvalid), .m_axi_araddr(m_axi_araddr),
        .m_axi_arlen(m_axi_arlen), .m_axi_arsize(m_axi_arsize), .m_axi_arburst(m_axi_arburst),
        .m_axi_arvalid(m_axi_arvalid), .m_axi_arready(m_axi_arready), .m_axi_rready(m_axi_rready),
        .m_axi_rdata(m_axi_rdata), .m_axi_rresp(m_axi_rresp), .m_axi_rlast(m_axi_rlast),
        .m_axi_rvalid(m_axi_rvalid)
    );

endmodule
