`timescale 1ns / 1ps

// One AXI4 slave-facing wrapper around the course AXI4-Lite peripheral IPs.
// KIND: 0 Switch, 1 LED, 2 Digit display, 3 UARTLite, 4 Timer GPIO.
module axi4lite_peripheral_wrap #(
    parameter [2:0] KIND = 3'd0
)(
    input  wire        aclk,
    input  wire        aresetn,
    input  wire [31:0] s_axi_awaddr,
    input  wire [ 7:0] s_axi_awlen,
    input  wire [ 2:0] s_axi_awsize,
    input  wire [ 1:0] s_axi_awburst,
    input  wire        s_axi_awlock,
    input  wire [ 3:0] s_axi_awcache,
    input  wire [ 2:0] s_axi_awprot,
    input  wire [ 3:0] s_axi_awregion,
    input  wire [ 3:0] s_axi_awqos,
    input  wire        s_axi_awvalid,
    output wire        s_axi_awready,
    input  wire [31:0] s_axi_wdata,
    input  wire [ 3:0] s_axi_wstrb,
    input  wire        s_axi_wlast,
    input  wire        s_axi_wvalid,
    output wire        s_axi_wready,
    output wire [ 1:0] s_axi_bresp,
    output wire        s_axi_bvalid,
    input  wire        s_axi_bready,
    input  wire [31:0] s_axi_araddr,
    input  wire [ 7:0] s_axi_arlen,
    input  wire [ 2:0] s_axi_arsize,
    input  wire [ 1:0] s_axi_arburst,
    input  wire        s_axi_arlock,
    input  wire [ 3:0] s_axi_arcache,
    input  wire [ 2:0] s_axi_arprot,
    input  wire [ 3:0] s_axi_arregion,
    input  wire [ 3:0] s_axi_arqos,
    input  wire        s_axi_arvalid,
    output wire        s_axi_arready,
    output wire [31:0] s_axi_rdata,
    output wire [ 1:0] s_axi_rresp,
    output wire        s_axi_rlast,
    output wire        s_axi_rvalid,
    input  wire        s_axi_rready,
    input  wire [31:0] gpio_in,
    input  wire [31:0] gpio2_in,
    output wire [31:0] gpio_out,
    input  wire        rx,
    output wire        tx
);
    wire [31:0] m_awaddr, m_wdata, m_araddr, m_rdata;
    wire [ 3:0] m_wstrb;
    wire [ 2:0] m_awprot, m_arprot;
    wire [ 1:0] m_bresp, m_rresp;
    wire m_awvalid, m_awready, m_wvalid, m_wready, m_bvalid, m_bready;
    wire m_arvalid, m_arready, m_rvalid, m_rready;
    wire [31:0] gpio_out_int;
    wire tx_int;

`define CONNECT_CONVERTER(MODULE_NAME) \
    MODULE_NAME U_converter ( \
        .aclk(aclk), .aresetn(aresetn), \
        .s_axi_awaddr(s_axi_awaddr), .s_axi_awlen(s_axi_awlen), \
        .s_axi_awsize(s_axi_awsize), .s_axi_awburst(s_axi_awburst), \
        .s_axi_awlock(s_axi_awlock), .s_axi_awcache(s_axi_awcache), \
        .s_axi_awprot(s_axi_awprot), .s_axi_awregion(s_axi_awregion), \
        .s_axi_awqos(s_axi_awqos), .s_axi_awvalid(s_axi_awvalid), \
        .s_axi_awready(s_axi_awready), .s_axi_wdata(s_axi_wdata), \
        .s_axi_wstrb(s_axi_wstrb), .s_axi_wlast(s_axi_wlast), \
        .s_axi_wvalid(s_axi_wvalid), .s_axi_wready(s_axi_wready), \
        .s_axi_bresp(s_axi_bresp), .s_axi_bvalid(s_axi_bvalid), \
        .s_axi_bready(s_axi_bready), .s_axi_araddr(s_axi_araddr), \
        .s_axi_arlen(s_axi_arlen), .s_axi_arsize(s_axi_arsize), \
        .s_axi_arburst(s_axi_arburst), .s_axi_arlock(s_axi_arlock), \
        .s_axi_arcache(s_axi_arcache), .s_axi_arprot(s_axi_arprot), \
        .s_axi_arregion(s_axi_arregion), .s_axi_arqos(s_axi_arqos), \
        .s_axi_arvalid(s_axi_arvalid), .s_axi_arready(s_axi_arready), \
        .s_axi_rdata(s_axi_rdata), .s_axi_rresp(s_axi_rresp), \
        .s_axi_rlast(s_axi_rlast), .s_axi_rvalid(s_axi_rvalid), \
        .s_axi_rready(s_axi_rready), .m_axi_awaddr(m_awaddr), \
        .m_axi_awprot(m_awprot), .m_axi_awvalid(m_awvalid), \
        .m_axi_awready(m_awready), .m_axi_wdata(m_wdata), \
        .m_axi_wstrb(m_wstrb), .m_axi_wvalid(m_wvalid), \
        .m_axi_wready(m_wready), .m_axi_bresp(m_bresp), \
        .m_axi_bvalid(m_bvalid), .m_axi_bready(m_bready), \
        .m_axi_araddr(m_araddr), .m_axi_arprot(m_arprot), \
        .m_axi_arvalid(m_arvalid), .m_axi_arready(m_arready), \
        .m_axi_rdata(m_rdata), .m_axi_rresp(m_rresp), \
        .m_axi_rvalid(m_rvalid), .m_axi_rready(m_rready) \
    );

    generate
        if (KIND == 3'd0) begin : G_CONVERTER_SWITCH
            `CONNECT_CONVERTER(axi_protocol_converter_0)
        end else if (KIND == 3'd1) begin : G_CONVERTER_LED
            `CONNECT_CONVERTER(axi_protocol_converter_1)
        end else if (KIND == 3'd2) begin : G_CONVERTER_DIG
            `CONNECT_CONVERTER(axi_protocol_converter_2)
        end else if (KIND == 3'd3) begin : G_CONVERTER_UART
            `CONNECT_CONVERTER(axi_protocol_converter_3)
        end else begin : G_CONVERTER_TIMER
            `CONNECT_CONVERTER(axi_protocol_converter_4)
        end
    endgenerate
`undef CONNECT_CONVERTER

    generate
        if (KIND == 3'd0) begin : G_SWITCH
            Switch U_ip (
                .s_axi_aclk(aclk), .s_axi_aresetn(aresetn),
                .s_axi_awaddr(m_awaddr[8:0]), .s_axi_awvalid(m_awvalid), .s_axi_awready(m_awready),
                .s_axi_wdata(m_wdata), .s_axi_wstrb(m_wstrb), .s_axi_wvalid(m_wvalid), .s_axi_wready(m_wready),
                .s_axi_bresp(m_bresp), .s_axi_bvalid(m_bvalid), .s_axi_bready(m_bready),
                .s_axi_araddr(m_araddr[8:0]), .s_axi_arvalid(m_arvalid), .s_axi_arready(m_arready),
                .s_axi_rdata(m_rdata), .s_axi_rresp(m_rresp), .s_axi_rvalid(m_rvalid), .s_axi_rready(m_rready),
                .gpio_io_i(gpio_in)
            );
        end else if (KIND == 3'd1) begin : G_LED
            LED U_ip (
                .s_axi_aclk(aclk), .s_axi_aresetn(aresetn),
                .s_axi_awaddr(m_awaddr[8:0]), .s_axi_awvalid(m_awvalid), .s_axi_awready(m_awready),
                .s_axi_wdata(m_wdata), .s_axi_wstrb(m_wstrb), .s_axi_wvalid(m_wvalid), .s_axi_wready(m_wready),
                .s_axi_bresp(m_bresp), .s_axi_bvalid(m_bvalid), .s_axi_bready(m_bready),
                .s_axi_araddr(m_araddr[8:0]), .s_axi_arvalid(m_arvalid), .s_axi_arready(m_arready),
                .s_axi_rdata(m_rdata), .s_axi_rresp(m_rresp), .s_axi_rvalid(m_rvalid), .s_axi_rready(m_rready),
                .gpio_io_o(gpio_out_int[15:0])
            );
        end else if (KIND == 3'd2) begin : G_DIG
            Dig U_ip (
                .s_axi_aclk(aclk), .s_axi_aresetn(aresetn),
                .s_axi_awaddr(m_awaddr[8:0]), .s_axi_awvalid(m_awvalid), .s_axi_awready(m_awready),
                .s_axi_wdata(m_wdata), .s_axi_wstrb(m_wstrb), .s_axi_wvalid(m_wvalid), .s_axi_wready(m_wready),
                .s_axi_bresp(m_bresp), .s_axi_bvalid(m_bvalid), .s_axi_bready(m_bready),
                .s_axi_araddr(m_araddr[8:0]), .s_axi_arvalid(m_arvalid), .s_axi_arready(m_arready),
                .s_axi_rdata(m_rdata), .s_axi_rresp(m_rresp), .s_axi_rvalid(m_rvalid), .s_axi_rready(m_rready),
                .gpio_io_o(gpio_out_int)
            );
        end else if (KIND == 3'd3) begin : G_UART
            axi_uartlite_0 U_ip (
                .s_axi_aclk(aclk), .s_axi_aresetn(aresetn), .interrupt(),
                .s_axi_awaddr(m_awaddr[3:0]), .s_axi_awvalid(m_awvalid), .s_axi_awready(m_awready),
                .s_axi_wdata(m_wdata), .s_axi_wstrb(m_wstrb), .s_axi_wvalid(m_wvalid), .s_axi_wready(m_wready),
                .s_axi_bresp(m_bresp), .s_axi_bvalid(m_bvalid), .s_axi_bready(m_bready),
                .s_axi_araddr(m_araddr[3:0]), .s_axi_arvalid(m_arvalid), .s_axi_arready(m_arready),
                .s_axi_rdata(m_rdata), .s_axi_rresp(m_rresp), .s_axi_rvalid(m_rvalid), .s_axi_rready(m_rready),
                .rx(rx), .tx(tx_int)
            );
        end else begin : G_TIMER
            Timer U_ip (
                .s_axi_aclk(aclk), .s_axi_aresetn(aresetn),
                .s_axi_awaddr(m_awaddr[8:0]), .s_axi_awvalid(m_awvalid), .s_axi_awready(m_awready),
                .s_axi_wdata(m_wdata), .s_axi_wstrb(m_wstrb), .s_axi_wvalid(m_wvalid), .s_axi_wready(m_wready),
                .s_axi_bresp(m_bresp), .s_axi_bvalid(m_bvalid), .s_axi_bready(m_bready),
                .s_axi_araddr(m_araddr[8:0]), .s_axi_arvalid(m_arvalid), .s_axi_arready(m_arready),
                .s_axi_rdata(m_rdata), .s_axi_rresp(m_rresp), .s_axi_rvalid(m_rvalid), .s_axi_rready(m_rready),
                .gpio_io_i(gpio_in), .gpio2_io_i(gpio2_in)
            );
        end
    endgenerate

    assign gpio_out = (KIND == 3'd1 || KIND == 3'd2) ? gpio_out_int : 32'b0;
    assign tx = (KIND == 3'd3) ? tx_int : 1'b1;
endmodule
