`timescale 1ns / 1ps

module axi_peripheral_subsystem(
    input wire clk, input wire resetn,
    input wire [31:0] s_axi_awaddr, input wire [7:0] s_axi_awlen, input wire [2:0] s_axi_awsize,
    input wire [1:0] s_axi_awburst, input wire s_axi_awvalid, output wire s_axi_awready,
    input wire [31:0] s_axi_wdata, input wire [3:0] s_axi_wstrb, input wire s_axi_wlast,
    input wire s_axi_wvalid, output wire s_axi_wready, output wire [1:0] s_axi_bresp,
    output wire s_axi_bvalid, input wire s_axi_bready,
    input wire [31:0] s_axi_araddr, input wire [7:0] s_axi_arlen, input wire [2:0] s_axi_arsize,
    input wire [1:0] s_axi_arburst, input wire s_axi_arvalid, output wire s_axi_arready,
    output wire [31:0] s_axi_rdata, output wire [1:0] s_axi_rresp, output wire s_axi_rlast,
    output wire s_axi_rvalid, input wire s_axi_rready,
    input wire [15:0] sw, output wire [15:0] led, output wire [7:0] dig_en,
    output wire [7:0] dig_seg, output wire [7:0] dig_seg1, input wire rx, output wire tx
);
    wire [191:0] m_awaddr, m_wdata, m_araddr, m_rdata;
    wire [47:0] m_awlen, m_arlen;
    wire [17:0] m_awsize, m_arsize, m_awprot, m_arprot;
    wire [11:0] m_awburst, m_arburst, m_bresp, m_rresp;
    wire [5:0] m_awlock, m_awvalid, m_awready, m_wlast, m_wvalid, m_wready;
    wire [5:0] m_bvalid, m_bready, m_arlock, m_arvalid, m_arready, m_rlast, m_rvalid, m_rready;
    wire [23:0] m_awcache, m_awregion, m_awqos, m_wstrb, m_arcache, m_arregion, m_arqos;
    wire [31:0] led_gpio, dig_gpio;
    reg [63:0] timer;

    always @(posedge clk) begin
        if (!resetn) timer <= 64'b0;
        else timer <= timer + 64'd1;
    end

    axi_crossbar_0 U_crossbar (
        .aclk(clk), .aresetn(resetn),
        .s_axi_awaddr(s_axi_awaddr), .s_axi_awlen(s_axi_awlen), .s_axi_awsize(s_axi_awsize),
        .s_axi_awburst(s_axi_awburst), .s_axi_awlock(1'b0), .s_axi_awcache(4'b0),
        .s_axi_awprot(3'b0), .s_axi_awqos(4'b0), .s_axi_awvalid(s_axi_awvalid), .s_axi_awready(s_axi_awready),
        .s_axi_wdata(s_axi_wdata), .s_axi_wstrb(s_axi_wstrb), .s_axi_wlast(s_axi_wlast),
        .s_axi_wvalid(s_axi_wvalid), .s_axi_wready(s_axi_wready), .s_axi_bresp(s_axi_bresp),
        .s_axi_bvalid(s_axi_bvalid), .s_axi_bready(s_axi_bready),
        .s_axi_araddr(s_axi_araddr), .s_axi_arlen(s_axi_arlen), .s_axi_arsize(s_axi_arsize),
        .s_axi_arburst(s_axi_arburst), .s_axi_arlock(1'b0), .s_axi_arcache(4'b0),
        .s_axi_arprot(3'b0), .s_axi_arqos(4'b0), .s_axi_arvalid(s_axi_arvalid), .s_axi_arready(s_axi_arready),
        .s_axi_rdata(s_axi_rdata), .s_axi_rresp(s_axi_rresp), .s_axi_rlast(s_axi_rlast),
        .s_axi_rvalid(s_axi_rvalid), .s_axi_rready(s_axi_rready),
        .m_axi_awaddr(m_awaddr), .m_axi_awlen(m_awlen), .m_axi_awsize(m_awsize), .m_axi_awburst(m_awburst),
        .m_axi_awlock(m_awlock), .m_axi_awcache(m_awcache), .m_axi_awprot(m_awprot),
        .m_axi_awregion(m_awregion), .m_axi_awqos(m_awqos), .m_axi_awvalid(m_awvalid), .m_axi_awready(m_awready),
        .m_axi_wdata(m_wdata), .m_axi_wstrb(m_wstrb), .m_axi_wlast(m_wlast), .m_axi_wvalid(m_wvalid),
        .m_axi_wready(m_wready), .m_axi_bresp(m_bresp), .m_axi_bvalid(m_bvalid), .m_axi_bready(m_bready),
        .m_axi_araddr(m_araddr), .m_axi_arlen(m_arlen), .m_axi_arsize(m_arsize), .m_axi_arburst(m_arburst),
        .m_axi_arlock(m_arlock), .m_axi_arcache(m_arcache), .m_axi_arprot(m_arprot),
        .m_axi_arregion(m_arregion), .m_axi_arqos(m_arqos), .m_axi_arvalid(m_arvalid), .m_axi_arready(m_arready),
        .m_axi_rdata(m_rdata), .m_axi_rresp(m_rresp), .m_axi_rlast(m_rlast), .m_axi_rvalid(m_rvalid), .m_axi_rready(m_rready)
    );

    bram_axi U_bram (
        .s_aclk(clk), .s_aresetn(resetn), .s_axi_awid(4'b0), .s_axi_awaddr(m_awaddr[31:0]),
        .s_axi_awlen(m_awlen[7:0]), .s_axi_awsize(m_awsize[2:0]), .s_axi_awburst(m_awburst[1:0]),
        .s_axi_awvalid(m_awvalid[0]), .s_axi_awready(m_awready[0]), .s_axi_wdata(m_wdata[31:0]),
        .s_axi_wstrb(m_wstrb[3:0]), .s_axi_wlast(m_wlast[0]), .s_axi_wvalid(m_wvalid[0]), .s_axi_wready(m_wready[0]),
        .s_axi_bid(), .s_axi_bresp(m_bresp[1:0]), .s_axi_bvalid(m_bvalid[0]), .s_axi_bready(m_bready[0]),
        .s_axi_arid(4'b0), .s_axi_araddr(m_araddr[31:0]), .s_axi_arlen(m_arlen[7:0]),
        .s_axi_arsize(m_arsize[2:0]), .s_axi_arburst(m_arburst[1:0]), .s_axi_arvalid(m_arvalid[0]),
        .s_axi_arready(m_arready[0]), .s_axi_rid(), .s_axi_rdata(m_rdata[31:0]), .s_axi_rresp(m_rresp[1:0]),
        .s_axi_rlast(m_rlast[0]), .s_axi_rvalid(m_rvalid[0]), .s_axi_rready(m_rready[0])
    );

`define PERIPHERAL(N, KVAL, IN0, IN1, OUT0, RX0, TX0) \
    axi4lite_peripheral_wrap #(.KIND(KVAL)) U_peripheral_``N ( \
        .aclk(clk), .aresetn(resetn), \
        .s_axi_awaddr(m_awaddr[(N)*32 +: 32]), .s_axi_awlen(m_awlen[(N)*8 +: 8]), \
        .s_axi_awsize(m_awsize[(N)*3 +: 3]), .s_axi_awburst(m_awburst[(N)*2 +: 2]), \
        .s_axi_awlock(m_awlock[N]), .s_axi_awcache(m_awcache[(N)*4 +: 4]), \
        .s_axi_awprot(m_awprot[(N)*3 +: 3]), .s_axi_awregion(m_awregion[(N)*4 +: 4]), .s_axi_awqos(m_awqos[(N)*4 +: 4]), \
        .s_axi_awvalid(m_awvalid[N]), .s_axi_awready(m_awready[N]), .s_axi_wdata(m_wdata[(N)*32 +: 32]), \
        .s_axi_wstrb(m_wstrb[(N)*4 +: 4]), .s_axi_wlast(m_wlast[N]), .s_axi_wvalid(m_wvalid[N]), .s_axi_wready(m_wready[N]), \
        .s_axi_bresp(m_bresp[(N)*2 +: 2]), .s_axi_bvalid(m_bvalid[N]), .s_axi_bready(m_bready[N]), \
        .s_axi_araddr(m_araddr[(N)*32 +: 32]), .s_axi_arlen(m_arlen[(N)*8 +: 8]), \
        .s_axi_arsize(m_arsize[(N)*3 +: 3]), .s_axi_arburst(m_arburst[(N)*2 +: 2]), \
        .s_axi_arlock(m_arlock[N]), .s_axi_arcache(m_arcache[(N)*4 +: 4]), .s_axi_arprot(m_arprot[(N)*3 +: 3]), \
        .s_axi_arregion(m_arregion[(N)*4 +: 4]), .s_axi_arqos(m_arqos[(N)*4 +: 4]), .s_axi_arvalid(m_arvalid[N]), .s_axi_arready(m_arready[N]), \
        .s_axi_rdata(m_rdata[(N)*32 +: 32]), .s_axi_rresp(m_rresp[(N)*2 +: 2]), .s_axi_rlast(m_rlast[N]), .s_axi_rvalid(m_rvalid[N]), .s_axi_rready(m_rready[N]), \
        .gpio_in(IN0), .gpio2_in(IN1), .gpio_out(OUT0), .rx(RX0), .tx(TX0) );

    `PERIPHERAL(1, 3'd0, {16'b0, sw}, 32'b0, , 1'b1, )
    `PERIPHERAL(2, 3'd1, 32'b0, 32'b0, led_gpio, 1'b1, )
    `PERIPHERAL(3, 3'd2, 32'b0, 32'b0, dig_gpio, 1'b1, )
    `PERIPHERAL(4, 3'd3, 32'b0, 32'b0, , rx, tx)
    `PERIPHERAL(5, 3'd4, timer[31:0], timer[63:32], , 1'b1, )
`undef PERIPHERAL

    assign led = led_gpio[15:0];
    assign dig_en = dig_gpio[7:0];
    assign dig_seg = dig_gpio[15:8];
    assign dig_seg1 = dig_gpio[23:16];
endmodule
