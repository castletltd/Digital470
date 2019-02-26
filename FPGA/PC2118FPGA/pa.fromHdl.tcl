
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name PC2118FPGA -dir "C:/Xilinx/Projects/PC2118FPGA/planAhead_run_1" -part xc3s500eft256-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "Top_PC2118.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {ipcore_dir/DCM.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {Top_PC2118.vf}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top Top_PC2118 $srcset
add_files [list {Top_PC2118.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s500eft256-4
