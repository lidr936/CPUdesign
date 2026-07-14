cd [get_property DIRECTORY [current_project]]

set current_dir [pwd]

set proj_name [get_property NAME [current_project]]

set_property CONFIG.Coe_File "$current_dir/src/coe/main.coe" [get_ips bram_axi]

generate_target all [get_files $current_dir/src/rtl/ip/bram_axi/bram_axi.xci]

catch { config_ip_cache -export [get_ips -all bram_axi] }

export_ip_user_files -of_objects [get_files $current_dir/src/rtl/ip/bram_axi/bram_axi.xci] -no_script -sync -force -quiet

reset_run bram_axi_synth_1

launch_runs bram_axi_synth_1 -jobs 16

export_simulation -of_objects [get_files $current_dir/src/rtl/ip/bram_axi/bram_axi.xci] -directory $current_dir/$proj_name.ip_user_files/sim_scripts -ip_user_files_dir $current_dir/$proj_name.ip_user_files -ipstatic_source_dir $current_dir/$proj_name.ip_user_files/ipstatic -lib_map_path [list {modelsim=$current_dir/$proj_name.cache/compile_simlib/modelsim} {questa=$current_dir/$proj_name.cache/compile_simlib/questa} {riviera=$current_dir/$proj_name.cache/compile_simlib/riviera} {activehdl=$current_dir/$proj_name.cache/compile_simlib/activehdl}] -use_ip_compiled_libs -force -quiet

reset_run synth_1

launch_runs impl_1 -to_step write_bitstream -jobs 16
