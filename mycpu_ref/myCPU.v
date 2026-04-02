`timescale 1ns / 1ps  
module mycpu(  
    input  wire         cpu_rstn,
    input  wire         cpu_clk,    

    input  wire         dev2ic_rrdy,
    input  wire         dev2ic_rvalid,
    input  wire [63:0] dev2ic_rdata,
    output wire[3:0]    ic2dev_ren,
    output wire[31:0]   ic2dev_addr,
    
    output wire [ 3:0]  daccess_ren,    // 读使能，发出读请求时置为4'hF
    output wire [31:0]  daccess_addr,   // 写地址
    input  wire         daccess_valid,  // 读数据有效信
    input  wire [31:0]  daccess_rdata,  // 读数据
    output wire [ 3:0]  daccess_wen,    // 写使能
    output wire [31:0]  daccess_wdata,  // 写数据
    output wire [31:0]  daccess_waddr,
    input  wire         daccess_wresp  // 写响应       
    );
//PC
wire [31:0]PC_pc;
wire PC_inst_rreq;
//BPU
wire                BPU_bj_offset;
wire                BPU_pred_taken;
wire [31:0]         BPU_pred_target;
//Icache
wire                Icache_full;
wire [1:0]          Icache_inst_valid;
wire [63:0]        Icache_inst_out;
wire [31:0]         Icache_inst_pc1;
wire [31:0]         Icache_inst_pc2;
wire                Icache_pred_taken1;
wire                Icache_pred_taken2;
wire [31:0]         Icache_pred_target1;
wire [31:0]         Icache_pred_target2;
//inst_buffer
wire                      Inst_buffer_front1_valid;
wire [`DECODED_PACKET_WIDTH:0]               Inst_buffer_front1_inst;  // WIDTH = 123
wire                      Inst_buffer_front2_valid;
wire [`DECODED_PACKET_WIDTH:0]               Inst_buffer_front2_inst;  // WIDTH = 123
wire                      Inst_buffer_full;
//接入译码的两条指令从inst buffer来
wire id_pred_taken1 = Inst_buffer_front1_inst[96];
wire id_pred_taken2 = Inst_buffer_front2_inst[96];
wire [31:0]id_pred_target1 = Inst_buffer_front1_inst[95:64];
wire [31:0]id_pred_target2 = Inst_buffer_front2_inst[95:64];
wire [31:0]id_pc1  = Inst_buffer_front1_inst[63:32];
wire [31:0]id_pc2  = Inst_buffer_front2_inst[63:32];
wire [31:0]inst1      = Inst_buffer_front1_inst[31:0];
wire [31:0]inst2      = Inst_buffer_front2_inst[31:0];
// CU_0 控制信号
wire                CU_0_branch_inst_flag = Inst_buffer_front1_inst[`DEC_BRANCH_FLAG_RANGE];
wire [2:0]          CU_0_ext_op           = Inst_buffer_front1_inst[`DEC_EXT_OP_RANGE];
wire [2:0]          CU_0_ram_ext_op       = Inst_buffer_front1_inst[`DEC_RAM_EXT_OP_RANGE];
wire [4:0]          CU_0_alu_op           = Inst_buffer_front1_inst[`DEC_ALU_OP_RANGE];
wire                CU_0_rf_we            = Inst_buffer_front1_inst[`DEC_RF_WE_RANGE];
wire [3:0]          CU_0_ram_we           = Inst_buffer_front1_inst[`DEC_RAM_WE_RANGE];
wire                CU_0_r2_sel           = Inst_buffer_front1_inst[`DEC_R2_SEL_RANGE];
wire                CU_0_wr_sel           = Inst_buffer_front1_inst[`DEC_WR_SEL_RANGE];
wire [1:0]          CU_0_wd_sel           = Inst_buffer_front1_inst[`DEC_WD_SEL_RANGE];
wire                CU_0_rR1_re           = Inst_buffer_front1_inst[`DEC_RR1_RE_RANGE];
wire                CU_0_rR2_re           = Inst_buffer_front1_inst[`DEC_RR2_RE_RANGE];
wire                CU_0_alua_sel         = Inst_buffer_front1_inst[`DEC_ALUA_SEL_RANGE];
wire                CU_0_alub_sel         = Inst_buffer_front1_inst[`DEC_ALUB_SEL_RANGE];
wire                CU_0_is_store          = Inst_buffer_front1_inst[122];

// CU_1 控制信号
wire                CU_1_branch_inst_flag = Inst_buffer_front2_inst[`DEC_BRANCH_FLAG_RANGE];
wire [2:0]          CU_1_ext_op           = Inst_buffer_front2_inst[`DEC_EXT_OP_RANGE];
wire [2:0]          CU_1_ram_ext_op       = Inst_buffer_front2_inst[`DEC_RAM_EXT_OP_RANGE];
wire [4:0]          CU_1_alu_op           = Inst_buffer_front2_inst[`DEC_ALU_OP_RANGE];
wire                CU_1_rf_we            = Inst_buffer_front2_inst[`DEC_RF_WE_RANGE];
wire [3:0]          CU_1_ram_we           = Inst_buffer_front2_inst[`DEC_RAM_WE_RANGE];
wire                CU_1_r2_sel           = Inst_buffer_front2_inst[`DEC_R2_SEL_RANGE];
wire                CU_1_wr_sel           = Inst_buffer_front2_inst[`DEC_WR_SEL_RANGE];
wire [1:0]          CU_1_wd_sel           = Inst_buffer_front2_inst[`DEC_WD_SEL_RANGE];
wire                CU_1_rR1_re           = Inst_buffer_front2_inst[`DEC_RR1_RE_RANGE];
wire                CU_1_rR2_re           = Inst_buffer_front2_inst[`DEC_RR2_RE_RANGE];
wire                CU_1_alua_sel         = Inst_buffer_front2_inst[`DEC_ALUA_SEL_RANGE];
wire                CU_1_alub_sel         = Inst_buffer_front2_inst[`DEC_ALUB_SEL_RANGE];
wire                CU_1_is_store           = Inst_buffer_front2_inst[122];
//data_forward
wire                      Data_forward_load_use_stall_0;
wire                      Data_forward_load_use_stall_1;
wire [31:0]               Data_forward_fd0_rD1;
wire                      Data_forward_fd0_rD1_sel;
wire [31:0]               Data_forward_fd0_rD2;
wire                      Data_forward_fd0_rD2_sel;
wire [31:0]               Data_forward_fd1_rD1;
wire                      Data_forward_fd1_rD1_sel;
wire [31:0]               Data_forward_fd1_rD2;
wire                      Data_forward_fd1_rD2_sel;
//regfile
wire [31:0] RF_rD1;
wire [31:0] RF_rD2;
wire [31:0] RF_rD3;
wire [31:0] RF_rD4;
//id_0阶段的输出
wire [ 4:0] id0_rR1 = inst1[9:5]; 
wire [ 4:0] id0_rR2 = CU_0_r2_sel ? inst1[14:10] : inst1[4:0]; 
wire [ 4:0] id0_wR  = CU_0_wr_sel ? inst1[ 4: 0] : 5'h1;

wire [31:0] id0_real_rD1 = Data_forward_fd0_rD1_sel ? Data_forward_fd0_rD1 :RF_rD1 ;     
wire [31:0] id0_real_rD2 = Data_forward_fd0_rD2_sel ? Data_forward_fd0_rD2 :RF_rD2 ;

//id_1阶段的输出
wire [ 4:0] id1_rR1 = inst2[9:5]; 
wire [ 4:0] id1_rR2 = CU_1_r2_sel ? inst2[14:10] : inst2[4:0]; 
wire [ 4:0] id1_wR  = CU_1_wr_sel ? inst2[ 4: 0] : 5'h1;

wire [31:0] id1_real_rD1 = Data_forward_fd1_rD1_sel ? Data_forward_fd1_rD1 :RF_rD3 ;     
wire [31:0] id1_real_rD2 = Data_forward_fd1_rD2_sel ? Data_forward_fd1_rD2 :RF_rD4 ;


//ext
wire [31:0]               EXT0_ext;  
wire [31:0]               EXT1_ext;   

wire pop0,pop1;
// EX_MEM 
wire                      ID_EX0_valid_out;
wire [4:0]                ID_EX0_wR_out;
wire [31:0]               ID_EX0_pc_out;
wire [31:0]               ID_EX0_rD1_out;
wire [31:0]               ID_EX0_rD2_out;
wire [31:0]               ID_EX0_ext_out;
wire                      ID_EX0_rf_we_out;
wire [1:0]                ID_EX0_wd_sel_out;
wire [4:0]                ID_EX0_alu_op_out;
wire                      ID_EX0_alua_sel_out;
wire                      ID_EX0_alub_sel_out;
wire [3:0]                ID_EX0_ram_we_out;
wire [2:0]                ID_EX0_ram_ext_op_out;
wire                      ID_EX0_pred_taken_o;
wire [31:0]               ID_EX0_pred_target_o;
wire                      ID_EX0_is_branch_o;

wire                      ID_EX1_valid_out;
wire [4:0]                ID_EX1_wR_out;
wire [31:0]               ID_EX1_pc_out;
wire [31:0]               ID_EX1_rD1_out;
wire [31:0]               ID_EX1_rD2_out;
wire [31:0]               ID_EX1_ext_out;
wire                      ID_EX1_rf_we_out;
wire [1:0]                ID_EX1_wd_sel_out;
wire [4:0]                ID_EX1_alu_op_out;
wire                      ID_EX1_alua_sel_out;
wire                      ID_EX1_alub_sel_out;
wire [3:0]                ID_EX1_ram_we_out;
wire [2:0]                ID_EX1_ram_ext_op_out;
wire                      ID_EX1_pred_taken_o;
wire [31:0]               ID_EX1_pred_target_o;
wire                      ID_EX1_is_branch_o;

wire                      ID_EX0_is_load_o;
wire                      ID_EX0_is_store_o;
wire                      ID_EX0_is_mult_o;

wire                      ID_EX1_is_load_o;
wire                      ID_EX1_is_store_o;
wire                      ID_EX1_is_mult_o;
//alu
wire [31:0]               ALU0_C;
wire                      ALU0_suspend;

wire [31:0]               ALU1_C;
wire                      ALU1_suspend;

wire ex_suspend = ALU0_suspend || ALU1_suspend;
//ex_branch_judge
wire                      BJ0_actual_taken_o;
wire [31:0]               BJ0_actual_target_pc_o;

wire                      BJ1_actual_taken_o;
wire [31:0]               BJ1_actual_target_pc_o;
//ex_mem
wire                      EX_MEM0_valid_out;
wire [4:0]                EX_MEM0_wR_out;
wire [31:0]               EX_MEM0_pc_out;
wire [31:0]               EX_MEM0_alu_C_out;
wire [31:0]               EX_MEM0_rD2_out;
wire                      EX_MEM0_rf_we_out;
wire [1:0]                EX_MEM0_wd_sel_out;
wire [3:0]                EX_MEM0_ram_we_out;
wire [2:0]                EX_MEM0_ram_ext_op_out;
wire                      EX_MEM0_is_load_out;
wire                      EX_MEM0_is_store_out;
wire                      EX_MEM0_is_branch_out;
wire                      EX_MEM0_actual_taken_out;
wire [31:0]               EX_MEM0_actual_target_pc_out;
wire                      EX_MEM0_pred_taken_out;
wire [31:0]               EX_MEM0_pred_target_out;


wire                      EX_MEM1_valid_out;
wire [4:0]                EX_MEM1_wR_out;
wire [31:0]               EX_MEM1_pc_out;
wire [31:0]               EX_MEM1_alu_C_out;
wire [31:0]               EX_MEM1_rD2_out;
wire                      EX_MEM1_rf_we_out;
wire [1:0]                EX_MEM1_wd_sel_out;
wire [3:0]                EX_MEM1_ram_we_out;
wire [2:0]                EX_MEM1_ram_ext_op_out;
wire                      EX_MEM1_is_load_out;
wire                      EX_MEM1_is_store_out;
wire                      EX_MEM1_is_branch_out;
wire                      EX_MEM1_actual_taken_out;
wire [31:0]               EX_MEM1_actual_target_pc_out;
wire                      EX_MEM1_pred_taken_out;
wire [31:0]               EX_MEM1_pred_target_out;
//mem
wire         mem_suspend;            
wire [31:0]  mem_final_load_data;   

wire        MEM_BJ0_flush_o;
wire [31:0] MEM_BJ0_flush_pc_o;
wire        MEM_BJ0_real_taken_o;

wire        MEM_BJ1_flush_o;
wire [31:0] MEM_BJ1_flush_pc_o;
wire        MEM_BJ1_real_taken_o;

wire flush =  MEM_BJ0_flush_o || MEM_BJ1_flush_o;
wire [31:0]flush_real_pc =EX_MEM0_is_branch_out ? EX_MEM0_pc_out:EX_MEM1_pc_out;
wire [31:0]flush_pc = MEM_BJ0_flush_o ? MEM_BJ0_flush_pc_o : MEM_BJ1_flush_pc_o;
wire real_taken = MEM_BJ0_real_taken_o ||MEM_BJ1_real_taken_o;

//MEM_WB
wire                      MEM_WB0_valid_out;
wire [4:0]                MEM_WB0_wR_out;
wire [31:0]               MEM_WB0_pc_out;
wire [31:0]               MEM_WB0_alu_C_out;
wire [31:0]               MEM_WB0_ram_ext_out;
wire                      MEM_WB0_rf_we_out;
wire [1:0]                MEM_WB0_wd_sel_out;

wire                      MEM_WB1_valid_out;
wire [4:0]                MEM_WB1_wR_out;
wire [31:0]               MEM_WB1_pc_out;
wire [31:0]               MEM_WB1_alu_C_out;
wire [31:0]               MEM_WB1_ram_ext_out;
wire                      MEM_WB1_rf_we_out;
wire [1:0]                MEM_WB1_wd_sel_out;

PC  u_PC(
    .cpu_rstn(cpu_rstn),
    .cpu_clk(cpu_clk), 
    .flush (flush),
    .flush_pc(flush_pc),
    .suspend(Icache_full ),
    .din(BPU_pred_target),
    
    .pc(PC_pc),
    .inst_rreq(PC_inst_rreq)
);

BPU u_BPU (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    
    .if_pc          (PC_pc),
    .if_valid       (PC_inst_rreq),

    .bj_offset      (BPU_bj_offset),
    .pred_taken     (BPU_pred_taken),
    .pred_target    (BPU_pred_target),
    
    .update_valid   ((EX_MEM0_is_branch_out||EX_MEM1_is_branch_out)&&!mem_suspend),
    .target_error   (flush),
    .real_pc        (flush_real_pc),
    .real_taken     (real_taken),
    .real_target    (flush_pc)

);

inst_cache u_icache (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .flush          (flush),
    
    .pred_taken     (BPU_pred_taken),
    .pred_target    (BPU_pred_target),
    .bj_offset      (BPU_bj_offset),

    .buffer_is_full (Inst_buffer_full),
    .inst_rreq      (PC_inst_rreq),
    .inst_addr      (PC_pc),

    .dev_rrdy       (dev2ic_rrdy),
    .dev_rvalid     (dev2ic_rvalid),
    .dev_rdata      (dev2ic_rdata),
    
    .full           (Icache_full),
    .inst_valid     (Icache_inst_valid),
    .inst_out       (Icache_inst_out),
    .inst_pc1       (Icache_inst_pc1),
    .inst_pc2       (Icache_inst_pc2),
    .cpu_ren        (ic2dev_ren),
    .cpu_raddr      (ic2dev_addr),

    .pred_taken1    (Icache_pred_taken1),
    .pred_taken2    (Icache_pred_taken2),
    .pred_target1   (Icache_pred_target1),
    .pred_target2   (Icache_pred_target2)
);
wire [96:0] buffer_in1={Icache_pred_taken1,Icache_pred_target1,Icache_inst_pc1,Icache_inst_out[31:0]};
wire [96:0] buffer_in2={Icache_pred_taken2,Icache_pred_target2,Icache_inst_pc2,Icache_inst_out[63:32]};
wire   buffer_valid1=Icache_inst_valid[0];
wire   buffer_valid2=Icache_inst_valid[1];

inst_buffer u_inst_buffer (
    // ===== Inputs =====
    .clk            (cpu_clk),
    .rstn           (cpu_rstn),
    .flush          (flush),

    // --- Push  ---
    .push1_valid    (buffer_valid1&&!Inst_buffer_full),
    .push1_inst     (buffer_in1),
    .push2_valid    (buffer_valid2&&!Inst_buffer_full),
    .push2_inst     (buffer_in2),

    // --- Pop ---
    .pop1           (pop0 && !ex_suspend &&!mem_suspend),
    .pop2           (pop1 && !ex_suspend &&!mem_suspend),
    // ===== Outputs=====
    .front1_valid   (Inst_buffer_front1_valid),
    .front1_inst    (Inst_buffer_front1_inst),
    .front2_valid   (Inst_buffer_front2_valid),
    .front2_inst    (Inst_buffer_front2_inst),
    .full           (Inst_buffer_full)
);


EXT u_EXT0 (
    .din        (inst1[25:0]),     
    .ext_op     (CU_0_ext_op),     
    .ext        (EXT0_ext)
);

EXT u_EXT1 (
    .din        (inst2[25:0]),    
    .ext_op     (CU_1_ext_op),     
    .ext        (EXT1_ext)
);

reg[31:0] ex_wd_fd0;
reg[31:0] ex_wd_fd1;

reg[31:0] mem_wd_fd0;
reg[31:0] mem_wd_fd1;

reg[31:0] wb_wd_fd0;
reg[31:0] wb_wd_fd1;

wire        load_use0_rd0;
wire        load_use0_rd1;
wire        load_use1_rd0;
wire        load_use1_rd1;
data_forward u_data_forward (
    .id0_rR1            (id0_rR1),
    .id0_rR2            (id0_rR2),
    .id0_rR1_re         (CU_0_rR1_re),
    .id0_rR2_re         (CU_0_rR2_re),
    
    .id1_rR1            (id1_rR1),
    .id1_rR2            (id1_rR2),
    .id1_rR1_re         (CU_1_rR1_re),
    .id1_rR2_re         (CU_1_rR2_re),

    // --- Pipe 0 ---
    .ex0_wd             (ex_wd_fd0),
    .ex0_wr             (ID_EX0_wR_out),
    .ex0_we             (ID_EX0_rf_we_out),
    .ex0_is_load        (ID_EX0_is_load_o),
    .mem0_wd            (mem_wd_fd0),
    .mem0_wr            (EX_MEM0_wR_out),
    .mem0_we            (EX_MEM0_rf_we_out),
    // --- Pipe 1 ---
    .ex1_wd             (ex_wd_fd1),
    .ex1_wr             (ID_EX1_wR_out),
    .ex1_we             (ID_EX1_rf_we_out),
    .ex1_is_load        (ID_EX1_is_load_o),
    .mem1_wd            (mem_wd_fd1),
    .mem1_wr            (EX_MEM1_wR_out),
    .mem1_we            (EX_MEM1_rf_we_out),

    .load_use_stall_0   (Data_forward_load_use_stall_0),
    .load_use_stall_1   (Data_forward_load_use_stall_1),

    .fd0_rD1            (Data_forward_fd0_rD1),
    .fd0_rD1_sel        (Data_forward_fd0_rD1_sel),
    .fd0_rD2            (Data_forward_fd0_rD2),
    .fd0_rD2_sel        (Data_forward_fd0_rD2_sel), 
    .fd1_rD1            (Data_forward_fd1_rD1),
    .fd1_rD1_sel        (Data_forward_fd1_rD1_sel),
    .fd1_rD2            (Data_forward_fd1_rD2),
    .fd1_rD2_sel        (Data_forward_fd1_rD2_sel),
    
    .load_use0_rd0(load_use0_rd0),
    .load_use0_rd1(load_use0_rd1),
    .load_use1_rd0(load_use1_rd0),
    .load_use1_rd1(load_use1_rd1)
);


RF u_RF (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),

    .rR1            (id0_rR1),
    .rR2            (id0_rR2),
    .rR3            (id1_rR1),
    .rR4            (id1_rR2),

    .we1            (MEM_WB0_rf_we_out),
    .wR1            (MEM_WB0_wR_out),
    .wD1            (wb_wd_fd0),
    .we2            (MEM_WB1_rf_we_out),
    .wR2            (MEM_WB1_wR_out),
    .wD2            (wb_wd_fd1),

    .rD1            (RF_rD1),
    .rD2            (RF_rD2),
    .rD3            (RF_rD3),
    .rD4            (RF_rD4)
);

wire inst0_writes_to_rR1_of_inst1 = CU_0_rf_we &&(id0_wR != 5'b0) && CU_1_rR1_re &&(id0_wR == id1_rR1);
wire inst0_writes_to_rR2_of_inst1 = CU_0_rf_we &&(id0_wR != 5'b0) && CU_1_rR2_re &&(id0_wR == id1_rR2);
wire raw_hazard_0_to_1 = inst0_writes_to_rR1_of_inst1 || inst0_writes_to_rR2_of_inst1;

assign pop0 = !(Data_forward_load_use_stall_0 && !(CU_0_is_store &&!load_use0_rd0)) && Inst_buffer_front1_valid;
assign pop1 = !(CU_0_branch_inst_flag && CU_1_branch_inst_flag) && !((CU_1_wd_sel == `WD_RAM)&&(CU_0_wd_sel == `WD_RAM))&& !(Data_forward_load_use_stall_1) && pop0 && !raw_hazard_0_to_1 && Inst_buffer_front2_valid;


wire id_ex_load_use0_rd0;
wire id_ex_load_use0_rd1;
wire id_ex_load_use1_rd0;
wire id_ex_load_use1_rd1;
ID_EX u_ID_EX0 (
    // --- Inputs ---
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .flush          (flush),
    .suspend        (ex_suspend||mem_suspend),
    .valid_in       (Inst_buffer_front1_valid),
    .load_use_i     (!pop0),
    .wR_in          (id0_wR),
    .pc_in          (id_pc1),
    .rD1_in         (id0_real_rD1),
    .rD2_in         (id0_real_rD2),
    .ext_in         (EXT0_ext),
    .rf_we_in       (CU_0_rf_we),
    .wd_sel_in      (CU_0_wd_sel),
    .alu_op_in      (CU_0_alu_op),
    .alua_sel_in    (CU_0_alua_sel),
    .alub_sel_in    (CU_0_alub_sel),
    .ram_we_in      (CU_0_ram_we),
    .ram_ext_op_in  (CU_0_ram_ext_op),
    .pred_taken     (id_pred_taken1),
    .pred_target    (id_pred_target1),
    .is_branch      (CU_0_branch_inst_flag),

    // --- Outputs ---
    .valid_out      (ID_EX0_valid_out),
    .wR_out         (ID_EX0_wR_out),
    .pc_out         (ID_EX0_pc_out),
    .rD1_out        (ID_EX0_rD1_out),
    .rD2_out        (ID_EX0_rD2_out),
    .ext_out        (ID_EX0_ext_out),
    .rf_we_out      (ID_EX0_rf_we_out),
    .wd_sel_out     (ID_EX0_wd_sel_out),
    .alu_op_out     (ID_EX0_alu_op_out),
    .alua_sel_out   (ID_EX0_alua_sel_out),
    .alub_sel_out   (ID_EX0_alub_sel_out),
    .ram_we_out     (ID_EX0_ram_we_out),
    .ram_ext_op_out (ID_EX0_ram_ext_op_out),
    .pred_taken_o   (ID_EX0_pred_taken_o),
    .pred_target_o  (ID_EX0_pred_target_o),
    .is_branch_o    (ID_EX0_is_branch_o),
    
    .is_load        ( (CU_0_wd_sel == `WD_RAM)&&(CU_0_ram_we==`RAM_WE_N) ), 
    .is_store       ( CU_0_is_store ), 
    .is_mult        ( (CU_0_alu_op==`ALU_MUL||CU_0_alu_op==`ALU_MULH ||CU_0_alu_op==`ALU_MULHU) ),  
    .is_load_o      ( ID_EX0_is_load_o ),  
    .is_store_o     ( ID_EX0_is_store_o ), 
    .is_mult_o      ( ID_EX0_is_mult_o ),
    
    .load_use_rd0_in(load_use0_rd0),
    .load_use_rd1_in(load_use0_rd1),

    .load_use_rd0_out(id_ex_load_use0_rd0),
    .load_use_rd1_out(id_ex_load_use0_rd1)
);

ID_EX u_ID_EX1 (
    // --- Inputs ---
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .flush          (flush),
    .suspend        (ex_suspend ||mem_suspend),
    .valid_in       (Inst_buffer_front2_valid),
    .load_use_i     (!pop1),
    .wR_in          (id1_wR),
    .pc_in          (id_pc2),
    .rD1_in         (id1_real_rD1),
    .rD2_in         (id1_real_rD2),
    .ext_in         (EXT1_ext),
    .rf_we_in       (CU_1_rf_we),
    .wd_sel_in      (CU_1_wd_sel),
    .alu_op_in      (CU_1_alu_op),
    .alua_sel_in    (CU_1_alua_sel),
    .alub_sel_in    (CU_1_alub_sel),
    .ram_we_in      (CU_1_ram_we),
    .ram_ext_op_in  (CU_1_ram_ext_op),
    .pred_taken     (id_pred_taken2),
    .pred_target    (id_pred_target2),
    .is_branch      (CU_1_branch_inst_flag),

    // --- Outputs ---
    .valid_out      (ID_EX1_valid_out),
    .wR_out         (ID_EX1_wR_out),
    .pc_out         (ID_EX1_pc_out),
    .rD1_out        (ID_EX1_rD1_out),
    .rD2_out        (ID_EX1_rD2_out),
    .ext_out        (ID_EX1_ext_out),
    .rf_we_out      (ID_EX1_rf_we_out),
    .wd_sel_out     (ID_EX1_wd_sel_out),
    .alu_op_out     (ID_EX1_alu_op_out),
    .alua_sel_out   (ID_EX1_alua_sel_out),
    .alub_sel_out   (ID_EX1_alub_sel_out),
    .ram_we_out     (ID_EX1_ram_we_out),
    .ram_ext_op_out (ID_EX1_ram_ext_op_out),
    .pred_taken_o   (ID_EX1_pred_taken_o),
    .pred_target_o  (ID_EX1_pred_target_o),
    .is_branch_o    (ID_EX1_is_branch_o),
    
    .is_load        ( (CU_1_wd_sel == `WD_RAM)&&(CU_1_ram_we==`RAM_WE_N) ), 
    .is_store       (  CU_1_is_store ),  
    .is_mult        ( (CU_1_alu_op==`ALU_MUL||CU_1_alu_op==`ALU_MULH ||CU_1_alu_op==`ALU_MULHU) ), 
    .is_load_o      ( ID_EX1_is_load_o ),  
    .is_store_o     ( ID_EX1_is_store_o ),  
    .is_mult_o      ( ID_EX1_is_mult_o ),
    
    .load_use_rd0_in(load_use1_rd0),
    .load_use_rd1_in(load_use1_rd1),

    .load_use_rd0_out(id_ex_load_use1_rd0),
    .load_use_rd1_out(id_ex_load_use1_rd1)   
);
wire [31:0]ex0_real_rd2 = (id_ex_load_use0_rd1?mem_final_load_data:ID_EX0_rD2_out);

wire [31:0] ex0_alu_A = ID_EX0_alua_sel_out ? ID_EX0_rD1_out : ID_EX0_pc_out;    // EX阶段的ALU操作数A
wire [31:0] ex0_alu_B = ID_EX0_alub_sel_out ? ID_EX0_rD2_out : ID_EX0_ext_out;   // EX阶段的ALU操作数B
wire [31:0] ex1_alu_A = ID_EX1_alua_sel_out ? ID_EX1_rD1_out : ID_EX1_pc_out;    // EX阶段的ALU操作数A
wire [31:0] ex1_alu_B = ID_EX1_alub_sel_out ? ID_EX1_rD2_out : ID_EX1_ext_out;   // EX阶段的ALU操作数B

ALU u_ALU0 (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .A              (ex0_alu_A),
    .B              (ex0_alu_B),
    .PC             (ID_EX0_pc_out),
    .alu_op         (ID_EX0_alu_op_out),
    .mem_suspend    (mem_suspend),

    .C              (ALU0_C),
    .suspend        (ALU0_suspend),
    .is_mult        (ID_EX0_is_mult_o)
);

ALU u_ALU1(
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .A              (ex1_alu_A),
    .B              (ex1_alu_B),
    .PC             (ID_EX1_pc_out),
    .alu_op         (ID_EX1_alu_op_out),
    .mem_suspend    (mem_suspend),


    .C              (ALU1_C),
    .suspend        (ALU1_suspend),
    .is_mult        (ID_EX1_is_mult_o)
);

branch_judge u_EX_BJ0 (
    .rD1_in             (ID_EX0_rD1_out),
    .rD2_in             (ID_EX0_rD2_out),
    .ext_i              (ID_EX0_ext_out),
    .branch_flag_i      (ID_EX0_is_branch_o),
    .aluop_i            (ID_EX0_alu_op_out),
    .pc_i               (ID_EX0_pc_out),

    .actual_taken_o     (BJ0_actual_taken_o),
    .actual_target_pc_o (BJ0_actual_target_pc_o)
);

branch_judge u_EX_BJ1 (

    .rD1_in             (ID_EX1_rD1_out),
    .rD2_in             (ID_EX1_rD2_out),
    .ext_i              (ID_EX1_ext_out),
    .branch_flag_i      (ID_EX1_is_branch_o),
    .aluop_i            (ID_EX1_alu_op_out),
    .pc_i               (ID_EX1_pc_out),

    .actual_taken_o     (BJ1_actual_taken_o),
    .actual_target_pc_o (BJ1_actual_target_pc_o)
);

always @(*) begin
    case (ID_EX0_wd_sel_out)
        `WD_RAM: ex_wd_fd0 = 32'h0;
        `WD_ALU: ex_wd_fd0 = ALU0_C;
        default: ex_wd_fd0 = 32'h1;
    endcase
end

always @(*) begin
    case (ID_EX1_wd_sel_out)
        `WD_RAM: ex_wd_fd1 = 32'h0;
        `WD_ALU: ex_wd_fd1 = ALU1_C;
        default: ex_wd_fd1 = 32'h1;
    endcase
end
wire ex_ld_req;
wire [31:0]ex_ld_addr;
wire [3:0]dread_en;
wire [31:0] dread_addr;
wire mem0_req;
wire mem1_req;

assign ex_ld_req = ID_EX0_is_load_o&& !ex_ld_addr[29]&&!ex_suspend && !mem0_req && !mem1_req ;
assign ex_ld_addr = ID_EX0_rD1_out+ID_EX0_ext_out;

EX_MEM ex_mem0_reg (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .flush          (flush),
    .suspend        (mem_suspend),
    .ex_suspend     (ex_suspend), 
    .valid_in       (ID_EX0_valid_out),

    .wR_in          (ID_EX0_wR_out),
    .pc_in          (ID_EX0_pc_out),
    .alu_C_in       (ALU0_C), 
    .rD2_in         (ex0_real_rd2),
    .rf_we_in       (ID_EX0_rf_we_out),
    .wd_sel_in      (ID_EX0_wd_sel_out),
    .ram_we_in      (ID_EX0_ram_we_out),
    .ram_ext_op_in  (ID_EX0_ram_ext_op_out),
    .is_load        (ID_EX0_is_load_o),
    .is_store       (ID_EX0_is_store_o),

    .is_branch_in          (ID_EX0_is_branch_o), 
    .actual_taken_in       (BJ0_actual_taken_o), 
    .actual_target_pc_in   (BJ0_actual_target_pc_o),
    .pred_taken_in         (ID_EX0_pred_taken_o), 
    .pred_target_in        (ID_EX0_pred_target_o), 

    .valid_out             (EX_MEM0_valid_out),
    .wR_out                (EX_MEM0_wR_out),
    .pc_out                (EX_MEM0_pc_out),
    .alu_C_out             (EX_MEM0_alu_C_out),
    .rD2_out               (EX_MEM0_rD2_out),
    .rf_we_out             (EX_MEM0_rf_we_out),
    .wd_sel_out            (EX_MEM0_wd_sel_out),
    .ram_we_out            (EX_MEM0_ram_we_out),
    .ram_ext_op_out        (EX_MEM0_ram_ext_op_out),
    .is_load_out           (EX_MEM0_is_load_out),
    .is_store_out          (EX_MEM0_is_store_out),
    .is_branch_out         (EX_MEM0_is_branch_out),
    .actual_taken_out      (EX_MEM0_actual_taken_out),
    .actual_target_pc_out  (EX_MEM0_actual_target_pc_out),
    .pred_taken_out        (EX_MEM0_pred_taken_out),
    .pred_target_out       (EX_MEM0_pred_target_out)
);


EX_MEM ex_mem1_reg (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .flush          (flush),
    .suspend        (mem_suspend),
    .ex_suspend     (ex_suspend), 
    .valid_in       (ID_EX1_valid_out),

    .wR_in          (ID_EX1_wR_out),
    .pc_in          (ID_EX1_pc_out),
    .alu_C_in       (ALU1_C), 
    .rD2_in         (ID_EX1_rD2_out),
    .rf_we_in       (ID_EX1_rf_we_out),
    .wd_sel_in      (ID_EX1_wd_sel_out),
    .ram_we_in      (ID_EX1_ram_we_out),
    .ram_ext_op_in  (ID_EX1_ram_ext_op_out),
    .is_load        (ID_EX1_is_load_o),
    .is_store       (ID_EX1_is_store_o),

    .is_branch_in          (ID_EX1_is_branch_o), 
    .actual_taken_in       (BJ1_actual_taken_o), 
    .actual_target_pc_in   (BJ1_actual_target_pc_o), 
    .pred_taken_in         (ID_EX1_pred_taken_o), 
    .pred_target_in        (ID_EX1_pred_target_o), 

    .valid_out             (EX_MEM1_valid_out),
    .wR_out                (EX_MEM1_wR_out),
    .pc_out                (EX_MEM1_pc_out),
    .alu_C_out             (EX_MEM1_alu_C_out),
    .rD2_out               (EX_MEM1_rD2_out),
    .rf_we_out             (EX_MEM1_rf_we_out),
    .wd_sel_out            (EX_MEM1_wd_sel_out),
    .ram_we_out            (EX_MEM1_ram_we_out),
    .ram_ext_op_out        (EX_MEM1_ram_ext_op_out),
    .is_load_out           (EX_MEM1_is_load_out),
    .is_store_out          (EX_MEM1_is_store_out),
    .is_branch_out         (EX_MEM1_is_branch_out),
    .actual_taken_out      (EX_MEM1_actual_taken_out),
    .actual_target_pc_out  (EX_MEM1_actual_target_pc_out),
    .pred_taken_out        (EX_MEM1_pred_taken_out),
    .pred_target_out       (EX_MEM1_pred_target_out)
);
assign mem0_req = EX_MEM0_is_load_out || EX_MEM0_is_store_out;
assign mem1_req = EX_MEM1_is_load_out || EX_MEM1_is_store_out;
wire select_pipe1 = mem1_req; 

wire selected_is_load       = select_pipe1 ? EX_MEM1_is_load_out      : EX_MEM0_is_load_out;
wire selected_is_store      = select_pipe1 ? EX_MEM1_is_store_out     : EX_MEM0_is_store_out;
wire selected_ex_valid      = select_pipe1 ? EX_MEM1_valid_out        : EX_MEM0_valid_out; // 等价于 mem0_req || mem1_req
wire [31:0] selected_addr   = select_pipe1 ? EX_MEM1_alu_C_out      : EX_MEM0_alu_C_out;
wire [3:0] selected_ram_we  = select_pipe1 ? EX_MEM1_ram_we_out       : EX_MEM0_ram_we_out;
wire [2:0] selected_ram_ext = select_pipe1 ? EX_MEM1_ram_ext_op_out   : EX_MEM0_ram_ext_op_out;
wire [1:0] selected_wd_sel  = select_pipe1 ? EX_MEM1_wd_sel_out       : EX_MEM0_wd_sel_out;
wire [31:0] selected_rD2    = select_pipe1 ? EX_MEM1_rD2_out          : EX_MEM0_rD2_out;

reg [31:0] formatted_data_reg;
always @(*) begin
    case (selected_ram_we)
        `RAM_WE_B: formatted_data_reg = {4{selected_rD2[7:0]}};
        `RAM_WE_H: formatted_data_reg = {2{selected_rD2[15:0]}};
        `RAM_WE_W: formatted_data_reg = selected_rD2;
        default:   formatted_data_reg = 32'b0;
    endcase
end
assign daccess_wdata = formatted_data_reg;

assign daccess_ren = {4{ex_ld_req}}| dread_en;
assign daccess_addr = ex_ld_req ?ex_ld_addr :dread_addr;
MEM_REQ_easy mem_req_inst (
    .clk                (cpu_clk),
    .rstn               (cpu_rstn),

    .is_load            (selected_is_load),
    .is_store           (selected_is_store),
    .ex_valid           (selected_ex_valid),
    .mem_ram_addr       (selected_addr),
    .mem_ram_we         (selected_ram_we),
    .mem_ram_ext_op     (selected_ram_ext),
    .mem_wd_sel         (selected_wd_sel),

    .dcache_read_valid  (daccess_valid),
    .dcache_read_data   (daccess_rdata),
    .dcache_write_valid (daccess_wresp),

    .suspend            (mem_suspend),
    .dcache_read_en     (dread_en),
    .dcache_write_we    (daccess_wen),
    .dcache_addr        (dread_addr),
    .dcache_waddr       (daccess_waddr),
    .final_load_data    (mem_final_load_data)
);

mem_branch_judge mem_bj0_inst (
    .is_branch_i        (EX_MEM0_is_branch_out), 
    .pc_i               (EX_MEM0_pc_out), 
    .actual_taken_i     (EX_MEM0_actual_taken_out), 
    .actual_target_pc_i (EX_MEM0_actual_target_pc_out), 
    .pred_taken_i       (EX_MEM0_pred_taken_out), 
    .pred_target_i      (EX_MEM0_pred_target_out), 

    .flush_o            (MEM_BJ0_flush_o),
    .flush_pc_o         (MEM_BJ0_flush_pc_o),
    .real_taken_o       (MEM_BJ0_real_taken_o)
);
mem_branch_judge mem_bj1_inst (
    .is_branch_i        (EX_MEM1_is_branch_out), 
    .pc_i               (EX_MEM1_pc_out), 
    .actual_taken_i     (EX_MEM1_actual_taken_out), 
    .actual_target_pc_i (EX_MEM1_actual_target_pc_out), 
    .pred_taken_i       (EX_MEM1_pred_taken_out), 
    .pred_target_i      (EX_MEM1_pred_target_out), 

    .flush_o            (MEM_BJ1_flush_o),
    .flush_pc_o         (MEM_BJ1_flush_pc_o),
    .real_taken_o       (MEM_BJ1_real_taken_o)
);
always @(*) begin
    case (EX_MEM0_wd_sel_out)
        `WD_RAM: mem_wd_fd0 = mem_final_load_data;
        `WD_ALU: mem_wd_fd0 = EX_MEM0_alu_C_out;
        default: mem_wd_fd0 = 32'h87654321;
    endcase
end
always @(*) begin
    case (EX_MEM1_wd_sel_out)
        `WD_RAM: mem_wd_fd1 = mem_final_load_data;
        `WD_ALU: mem_wd_fd1 = EX_MEM1_alu_C_out;
        default: mem_wd_fd1 = 32'h87654321;
    endcase
end

MEM_WB mem_wb0_reg (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .suspend        (mem_suspend), 
    .valid_in       (EX_MEM0_valid_out), 

    .wR_in          (EX_MEM0_wR_out), 
    .pc_in          (EX_MEM0_pc_out), 
    .alu_C_in       (EX_MEM0_alu_C_out), 
    .ram_ext_in     (mem_final_load_data), 
    .rf_we_in       (EX_MEM0_rf_we_out),
    .wd_sel_in      (EX_MEM0_wd_sel_out), 

    .valid_out      (MEM_WB0_valid_out),
    .wR_out         (MEM_WB0_wR_out),
    .pc_out         (MEM_WB0_pc_out),
    .alu_C_out      (MEM_WB0_alu_C_out),
    .ram_ext_out    (MEM_WB0_ram_ext_out),
    .rf_we_out      (MEM_WB0_rf_we_out),
    .wd_sel_out     (MEM_WB0_wd_sel_out)
);


MEM_WB mem_wb1_reg (
    .cpu_clk        (cpu_clk),
    .cpu_rstn       (cpu_rstn),
    .suspend        (mem_suspend || MEM_BJ0_flush_o), 
    .valid_in       (EX_MEM1_valid_out), 

    .wR_in          (EX_MEM1_wR_out),
    .pc_in          (EX_MEM1_pc_out), 
    .alu_C_in       (EX_MEM1_alu_C_out), 
    .ram_ext_in     (mem_final_load_data), 
    .rf_we_in       (EX_MEM1_rf_we_out), 
    .wd_sel_in      (EX_MEM1_wd_sel_out), 

    .valid_out      (MEM_WB1_valid_out),
    .wR_out         (MEM_WB1_wR_out),
    .pc_out         (MEM_WB1_pc_out),
    .alu_C_out      (MEM_WB1_alu_C_out),
    .ram_ext_out    (MEM_WB1_ram_ext_out),
    .rf_we_out      (MEM_WB1_rf_we_out),
    .wd_sel_out     (MEM_WB1_wd_sel_out)
);

always @(*) begin
    case (MEM_WB0_wd_sel_out)
        `WD_RAM: wb_wd_fd0 = MEM_WB0_ram_ext_out;
        `WD_ALU: wb_wd_fd0 = MEM_WB0_alu_C_out;
        default: wb_wd_fd0 = 32'haabbccdd;
    endcase
end

always @(*) begin
    case (MEM_WB1_wd_sel_out)
        `WD_RAM: wb_wd_fd1 = MEM_WB1_ram_ext_out;
        `WD_ALU: wb_wd_fd1 = MEM_WB1_alu_C_out;
        default: wb_wd_fd1 = 32'haabbccdd;
    endcase
end
endmodule
