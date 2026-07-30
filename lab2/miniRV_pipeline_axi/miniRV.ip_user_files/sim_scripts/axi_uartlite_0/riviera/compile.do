transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

vlib work
vlib riviera/xpm
vlib riviera/axi_lite_ipif_v3_0_4
vlib riviera/lib_pkg_v1_0_3
vlib riviera/lib_srl_fifo_v1_0_3
vlib riviera/lib_cdc_v1_0_2
vlib riviera/axi_uartlite_v2_0_33
vlib riviera/xil_defaultlib

vmap xpm riviera/xpm
vmap axi_lite_ipif_v3_0_4 riviera/axi_lite_ipif_v3_0_4
vmap lib_pkg_v1_0_3 riviera/lib_pkg_v1_0_3
vmap lib_srl_fifo_v1_0_3 riviera/lib_srl_fifo_v1_0_3
vmap lib_cdc_v1_0_2 riviera/lib_cdc_v1_0_2
vmap axi_uartlite_v2_0_33 riviera/axi_uartlite_v2_0_33
vmap xil_defaultlib riviera/xil_defaultlib

vlog -work xpm  -incr -l xpm -l axi_lite_ipif_v3_0_4 -l lib_pkg_v1_0_3 -l lib_srl_fifo_v1_0_3 -l lib_cdc_v1_0_2 -l axi_uartlite_v2_0_33 -l xil_defaultlib \
"D:/Xilinx/Vivado/2023.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -93  -incr \
"D:/Xilinx/Vivado/2023.2/data/ip/xpm/xpm_VCOMP.vhd" \

vcom -work axi_lite_ipif_v3_0_4 -93  -incr \
"../../../ipstatic/hdl/axi_lite_ipif_v3_0_vh_rfs.vhd" \

vcom -work lib_pkg_v1_0_3 -93  -incr \
"../../../ipstatic/hdl/lib_pkg_v1_0_rfs.vhd" \

vcom -work lib_srl_fifo_v1_0_3 -93  -incr \
"../../../ipstatic/hdl/lib_srl_fifo_v1_0_rfs.vhd" \

vcom -work lib_cdc_v1_0_2 -93  -incr \
"../../../ipstatic/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work axi_uartlite_v2_0_33 -93  -incr \
"../../../ipstatic/hdl/axi_uartlite_v2_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93  -incr \
"../../../../src/rtl/ip/axi_uartlite_0/sim/axi_uartlite_0.vhd" \


vlog -work xil_defaultlib \
"glbl.v"

