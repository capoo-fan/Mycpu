set script_dir [file dirname [file normalize [info script]]]

set proj_name "loongson"
set proj_dir  [file join $script_dir "project"]
set part_name "xc7a200tfbg676-1"

create_project -force $proj_name $proj_dir -part $part_name

set mycpu_dir   [file join $script_dir "myCPU"]
set soc_rtl_dir [file join $script_dir "soc_verify" "soc_axi" "rtl"]
set tb_dir      [file join $script_dir "soc_verify" "soc_axi" "testbench"]

# Add myCPU RTL.
set mycpu_rtl_files [glob -nocomplain [file join $mycpu_dir *.v]]
if {[llength $mycpu_rtl_files] > 0} {
    add_files -scan_for_includes $mycpu_rtl_files
}

# Add myCPU headers.
set mycpu_header_files [glob -nocomplain [file join $mycpu_dir *.vh]]
if {[llength $mycpu_header_files] > 0} {
    add_files $mycpu_header_files
}

# Add soc_verify/soc_axi/rtl RTL.
set soc_rtl_files [glob -nocomplain \
    [file join $soc_rtl_dir *.v] \
    [file join $soc_rtl_dir * *.v] \
    [file join $soc_rtl_dir * * *.v]]
if {[llength $soc_rtl_files] > 0} {
    add_files -scan_for_includes $soc_rtl_files
}

# Add myCPU IP.
set mycpu_ip_files [glob -nocomplain [file join $mycpu_dir xilinx_ip *.xci]]
if {[llength $mycpu_ip_files] > 0} {
    add_files -quiet $mycpu_ip_files
}

# Add soc_verify rtl IP (.xci).
set soc_ip_files [glob -nocomplain [file join $soc_rtl_dir xilinx_ip * *.xci]]
if {[llength $soc_ip_files] > 0} {
    add_files -quiet $soc_ip_files
}

# Add simulation files.
set sim_files [glob -nocomplain [file join $tb_dir *.v]]
if {[llength $sim_files] > 0} {
    add_files -fileset sim_1 $sim_files
    set_property -name "top" -value "tb_top" -objects [get_filesets sim_1]
    set_property -name "xsim.simulate.log_all_signals" -value "1" -objects [get_filesets sim_1]
}

# Set synthesis top.
set_property -name "top" -value "soc_lite_top" -objects [get_filesets sources_1]

update_compile_order -fileset sources_1
if {[llength $sim_files] > 0} {
    update_compile_order -fileset sim_1
}

puts "Project created at: $proj_dir"
puts "Added myCPU RTL + myCPU IP + soc_verify/soc_axi/rtl RTL + soc_verify/soc_axi/rtl/xilinx_ip/*.xci"
