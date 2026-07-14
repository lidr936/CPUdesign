# Run inside Vivado Tcl Console:
#   cd F:/cpu-design
#   source tools/vivado_lab1_check.tcl

set project_file [file normalize "lab1/miniRV_basic_ego1/miniRV_basic/miniRV.xpr"]

if {![file exists $project_file]} {
    error "Project file not found: $project_file"
}

set current_project_file ""
if {[current_project -quiet] ne ""} {
    set current_project_file [file normalize [get_property FILE [current_project]]]
}

if {$current_project_file eq $project_file} {
    puts "Project already open: $project_file"
} elseif {[current_project -quiet] ne ""} {
    puts "Closing currently open project: $current_project_file"
    close_project
    puts "Opening project: $project_file"
    open_project $project_file
} else {
    puts "Opening project: $project_file"
    open_project $project_file
}

puts "Updating compile order..."
update_compile_order -fileset sources_1
if {[get_filesets -quiet sim_1] ne ""} {
    update_compile_order -fileset sim_1
}

puts "Launching behavioral simulation..."
if {[catch {launch_simulation -mode behavioral} launch_err]} {
    puts "ERROR: launch_simulation failed before an active XSim session was created."
    puts "Vivado message:"
    puts $launch_err
    puts "Check compile/elaborate logs under:"
    puts "  [file normalize "lab1/miniRV_basic_ego1/miniRV_basic/miniRV.sim/sim_1/behav/xsim"]"
    error $launch_err
}

puts "Running simulation..."
if {[catch {run all} run_err]} {
    puts "ERROR: run all failed. This usually means XSim is not active or elaboration did not finish."
    puts "Vivado message:"
    puts $run_err
    puts "If the message says 'No active Vivado Simulator simulation', run:"
    puts "  launch_simulation -mode behavioral"
    puts "then wait until the simulation is active before running:"
    puts "  run all"
    error $run_err
}

puts "Vivado behavioral simulation finished. Check transcript for errors and testbench pass/fail messages."
