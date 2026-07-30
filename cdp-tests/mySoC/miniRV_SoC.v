`timescale 1ns / 1ps

`include "defines.vh"

module miniRV_SoC(
    input  wire         fpga_clk,
    input  wire         fpga_rst,   // Low Active
    input  wire [15:0]  sw,
    output wire [15:0]  led,
    output wire [ 7:0]  dig_en,
    output wire [ 7:0]  dig_seg,    // {CA, CB, ..., CG, DP}
    output wire [ 7:0]  dig_seg1,
    input  wire         rx,
    output wire         tx
);

`ifdef RUN_TRACE
    wire sys_clk = fpga_clk;
    wire sys_rst = fpga_rst;
`else
    wire pll_clk1;
    wire pll_lock;
    wire sys_clk = pll_lock & pll_clk1;
    reg  sys_rst;
    always @(posedge fpga_clk) sys_rst <= !fpga_rst | !pll_lock;

    clk_wiz_0 U_clkgen (
        .clk_in1    (fpga_clk),
        .locked     (pll_lock),
        .clk_out1   (pll_clk1)
    );
`endif

    cpu_top U_cpu (
        .cpu_clk        (sys_clk),
        .cpu_rst        (sys_rst)
    );

endmodule
