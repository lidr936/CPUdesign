# Run inside Vivado Tcl Console:
#   cd F:/cpu-design
#   source tools/vivado_lab1_check.tcl

set project_file [file normalize "lab1/miniRV_basic_ego1/miniRV_basic/miniRV.xpr"]

if {![file exists $project_file]} {
    error "Project file not found: $project_file"
}

puts "Opening project: $project_file"
open_project $project_file

puts "Updating compile order..."
update_compile_order -fileset sources_1
if {[get_filesets -quiet sim_1] ne ""} {
    update_compile_order -fileset sim_1
}

puts "Launching behavioral simulation..."
launch_simulation -mode behavioral
run all

puts "Vivado behavioral simulation finished. Check transcript for errors and testbench pass/fail messages."
