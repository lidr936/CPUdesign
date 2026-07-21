`timescale 1ns / 1ps

`include "defines.vh"

module soc_simple_tb();

    reg         clk  = 1;
    reg         rstn = 0;
    reg  [23:0] switch = 24'h123456;
    wire [23:0] led;
    wire [ 7:0] dig_en;
    wire [ 7:0] dig_seg;
    wire        tx;
    wire        rx = 1;

    initial #590 rstn = 01;
    always #5 clk = !clk;

    always @(*) begin
        if (DUT.U_cpu.U_core.ifetch_valid && DUT.U_cpu.U_core.ifetch_inst == 32'h73) begin
            #20 $display("Test Passed!");
            $finish;
        end
    end

    miniRV_SoC DUT (
        .fpga_clk   (clk),
        .fpga_rst   (rstn),
        .sw         (switch),
        .led        (led),
        .dig_en     (dig_en),
        .dig_seg    (dig_seg),
        .rx         (rx),
        .tx         (tx)

`ifdef USE_DDR
        ,// DDR Interface
        .ddr3_addr      (ddr3_addr),
        .ddr3_ba        (ddr3_ba),
        .ddr3_cas_n     (ddr3_cas_n),
        .ddr3_ck_n      (ddr3_ck_n),
        .ddr3_ck_p      (ddr3_ck_p),
        .ddr3_cke       (ddr3_cke),
        .ddr3_ras_n     (ddr3_ras_n),
        .ddr3_we_n      (ddr3_we_n),
        .ddr3_dq        (ddr3_dq),
        .ddr3_dqs_n     (ddr3_dqs_n),
        .ddr3_dqs_p     (ddr3_dqs_p),
        .ddr3_reset_n   (ddr3_reset_n),
        .ddr3_cs_n      (ddr3_cs_n),
        .ddr3_dm        (ddr3_dm),
        .ddr3_odt       (ddr3_odt)
`endif
    );

`ifdef USE_DDR
    wire [14:0] ddr3_addr;
    wire [ 2:0] ddr3_ba;
    wire        ddr3_cas_n;
    wire [ 0:0] ddr3_ck_p;
    wire [ 0:0] ddr3_ck_n;
    wire [ 0:0] ddr3_cke;
    wire        ddr3_ras_n;
    wire        ddr3_we_n;
    wire [15:0] ddr3_dq;
    wire [ 1:0] ddr3_dqs_n;
    wire [ 1:0] ddr3_dqs_p;
    wire        ddr3_reset_n;
    wire [ 0:0] ddr3_cs_n;
    wire [ 1:0] ddr3_dm;
    wire [ 0:0] ddr3_odt;

    ddr3_model u_ddr3 (
        .rst_n          (ddr3_reset_n),
        .ck             (ddr3_ck_p),
        .ck_n           (ddr3_ck_n),
        .cke            (ddr3_cke),
        .cs_n           (ddr3_cs_n),
        .ras_n          (ddr3_ras_n),
        .cas_n          (ddr3_cas_n),
        .we_n           (ddr3_we_n),
        .dm_tdqs        (ddr3_dm),
        .ba             (ddr3_ba),
        .addr           (ddr3_addr),
        .dq             (ddr3_dq),
        .dqs            (ddr3_dqs_p),
        .dqs_n          (ddr3_dqs_n),
        .tdqs_n         (),
        .odt            (ddr3_odt)
    );
`endif

endmodule
