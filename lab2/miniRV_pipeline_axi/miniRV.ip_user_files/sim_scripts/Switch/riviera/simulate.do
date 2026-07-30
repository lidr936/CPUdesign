transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+Switch  -L xpm -L axi_lite_ipif_v3_0_4 -L lib_cdc_v1_0_2 -L interrupt_control_v3_1_5 -L axi_gpio_v2_0_31 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.Switch xil_defaultlib.glbl

do {Switch.udo}

run 1000ns

endsim

quit -force
