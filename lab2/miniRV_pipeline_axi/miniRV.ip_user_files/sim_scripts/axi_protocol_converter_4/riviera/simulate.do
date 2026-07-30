transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+axi_protocol_converter_4  -L xpm -L generic_baseblocks_v2_1_1 -L fifo_generator_v13_2_9 -L axi_data_fifo_v2_1_28 -L axi_infrastructure_v1_1_0 -L axi_register_slice_v2_1_29 -L axi_protocol_converter_v2_1_29 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.axi_protocol_converter_4 xil_defaultlib.glbl

do {axi_protocol_converter_4.udo}

run 1000ns

endsim

quit -force
