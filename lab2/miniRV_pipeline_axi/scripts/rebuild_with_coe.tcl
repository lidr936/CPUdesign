# Run from the Vivado Tcl Console after opening miniRV.xpr:
#   source {F:/lab2/lab2/miniRV_pipeline_axi/scripts/rebuild_with_coe.tcl}
#
# This script intentionally uses 0_uart_test/main.coe as the fixed program image.

set script_dir [file dirname [file normalize [info script]]]
set project_dir [file normalize [file join $script_dir ..]]
set project_file [file join $project_dir miniRV.xpr]
set target_coe {F:/lab2/lab2/c_test_rv_stu/0_uart_test/main.coe}

if {[llength [get_projects -quiet]] == 0} {
    if {![file exists $project_file]} {
        error "Project file not found: $project_file"
    }
    open_project $project_file
}

if {![file exists $target_coe]} {
    error "Fixed COE image not found: $target_coe"
}

set bram_ip [get_ips -quiet bram_axi]
if {[llength $bram_ip] != 1} {
    error "Expected one IP named bram_axi, found: $bram_ip"
}

puts "Using COE: $target_coe"
set_property CONFIG.Load_Init_File true $bram_ip
set_property CONFIG.Coe_File $target_coe $bram_ip
puts "Configured bram_axi COE: [get_property CONFIG.Coe_File $bram_ip]"
generate_target all $bram_ip
export_ip_user_files -of_objects [get_files -of_objects $bram_ip] -no_script -sync -force -quiet

reset_run bram_axi_synth_1
launch_runs bram_axi_synth_1 -jobs 8
wait_on_run bram_axi_synth_1

set bram_status [get_property STATUS [get_runs bram_axi_synth_1]]
if {![string match "*Complete*" $bram_status]} {
    error "BRAM IP synthesis did not complete: $bram_status"
}

reset_run synth_1
reset_run impl_1
launch_runs impl_1 -to_step write_bitstream -jobs 8
wait_on_run impl_1

set bit_file [file join $project_dir miniRV.runs impl_1 miniRV_SoC.bit]
if {![file exists $bit_file]} {
    error "Bitstream was not created. Check synth_1 and impl_1 run logs."
}

puts "DONE: $bit_file"
