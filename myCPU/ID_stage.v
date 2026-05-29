`include "mycpu.vh"

module ID_stage(
    input  wire                           clk,
    input  wire                           resetn,
    input  wire                           fs_to_ds_valid,
    input  wire [`FS_TO_DS_BUS_WD-1:0]    fs_to_ds_bus,
    output wire                           ds_allowin,
    output wire                           br_taken,
    output wire [31:0]                    br_target,
    // BPU 接口
    output wire                           bpu_valid,
    output wire                           bpu_is_bj,
    output wire [31:0]                    bpu_pc,
    output wire                           bpu_real_taken,
    output wire [31:0]                    bpu_real_target,
    output wire                           bpu_is_call,
    output wire                           bpu_is_ret,
    output wire [31:0]                    bpu_ret_addr,

    input  wire                           es_allowin,
    input  wire [`ES_FWD_BUS_WD-1  :  0]  es_fwd_bus,
    input  wire [`MS_FWD_BUS_WD-1  :  0]  ms_fwd_bus,
    input  wire [`WS_FWD_BUS_WD-1  :  0]  ws_fwd_bus,
    input  wire [`WS_TO_RF_BUS_WD-1:  0]  ws_to_rf_bus,
    output wire                           ds_to_es_valid,
    output wire [`DS_TO_ES_BUS_WD-1:  0]  ds_to_es_bus
  );
  reg         reset;
  always @(posedge clk)
    reset <= ~resetn;

  // ID 级寄存器
  reg         ds_valid;
  reg  [31:0] ds_pc;
  reg  [31:0] ds_inst;
  reg         ds_pred_taken;
  reg  [31:0] ds_pred_target;

  wire [31:0] fs_pc;
  wire [31:0] fs_inst;
  wire        fs_pred_taken;
  wire [31:0] fs_pred_target;

  assign {fs_pc, fs_inst, fs_pred_taken, fs_pred_target} = fs_to_ds_bus;


  //  EXE MEM WB 前递逻辑
  wire        es_fwd_es_valid;       // EXE阶段指令有效
  wire        es_fwd_gr_we;          // EXE指令是否写通用寄存器
  wire        es_fwd_fwd_valid;      // 是否可前递
  wire        es_fwd_res_from_mem;   // 是否来自 MEM (Load)
  wire [ 4:0] es_fwd_dest;           // 目的寄存器地址
  wire [31:0] es_fwd_data;           // 前递数据
  assign {es_fwd_es_valid, es_fwd_gr_we, es_fwd_fwd_valid,
          es_fwd_res_from_mem, es_fwd_dest, es_fwd_data} = es_fwd_bus;

  wire        ms_fwd_ms_valid;
  wire        ms_fwd_gr_we;
  wire        ms_fwd_res_from_mem;
  wire [ 4:0] ms_fwd_dest;
  wire [31:0] ms_fwd_data;
  assign {ms_fwd_ms_valid, ms_fwd_gr_we, ms_fwd_res_from_mem,
          ms_fwd_dest, ms_fwd_data} = ms_fwd_bus;

  wire        ws_fwd_ws_valid;
  wire        ws_fwd_gr_we;
  wire [ 4:0] ws_fwd_dest;
  wire [31:0] ws_fwd_data;
  assign {ws_fwd_ws_valid, ws_fwd_gr_we, ws_fwd_dest, ws_fwd_data} = ws_fwd_bus;




  wire        ws_rf_we;      // 写使能
  wire [ 4:0] ws_rf_waddr;   // 写地址
  wire [31:0] ws_rf_wdata;   // 写数据
  assign {ws_rf_we, ws_rf_waddr, ws_rf_wdata} = ws_to_rf_bus;

  // 指令解码
  wire   [31:0]  inst;
  assign inst = ds_inst;

  // 指令字段拆解
  wire [ 5:0] op_31_26 = inst[31:26];
  wire [ 3:0] op_25_22 = inst[25:22];
  wire [ 1:0] op_21_20 = inst[21:20];
  wire [ 4:0] op_19_15 = inst[19:15];
  wire [ 4:0] rd       = inst[ 4: 0];
  wire [ 4:0] rj       = inst[ 9: 5];
  wire [ 4:0] rk       = inst[14:10];
  wire [11:0] i12      = inst[21:10];
  wire [19:0] i20      = inst[24: 5];
  wire [15:0] i16      = inst[25:10];
  wire [25:0] i26      = {inst[9:0], inst[25:10]};

  // 译码器输出
  wire [63:0] op_31_26_d;
  wire [15:0] op_25_22_d;
  wire [ 3:0] op_21_20_d;
  wire [31:0] op_19_15_d;


  // ALU 指令
  wire inst_add_w, inst_sub_w, inst_slt, inst_sltu;
  wire inst_nor, inst_and, inst_or, inst_xor;
  wire inst_slli_w, inst_srli_w, inst_srai_w;
  wire inst_addi_w, inst_ld_w, inst_st_w;
  wire inst_jirl, inst_b, inst_bl, inst_beq, inst_bne;
  wire inst_lu12i_w;
  wire inst_slti, inst_sltui, inst_andi, inst_ori, inst_xori;
  wire inst_sll_w, inst_srl_w, inst_sra_w, inst_pcaddu12i;
  wire inst_blt, inst_bge, inst_bltu, inst_bgeu;
  wire inst_ld_b, inst_ld_h, inst_ld_bu, inst_ld_hu;
  wire inst_st_b, inst_st_h;
  wire inst_mul_w, inst_mulh_w, inst_mulh_wu;


  // ALU 指令译码
  assign inst_add_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h00];
  assign inst_sub_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h02];
  assign inst_slt     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h04];
  assign inst_sltu    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h05];
  assign inst_nor     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h08];
  assign inst_and     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h09];
  assign inst_or      = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0a];
  assign inst_xor     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0b];
  assign inst_slli_w  = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h01];
  assign inst_srli_w  = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h09];
  assign inst_srai_w  = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h11];
  assign inst_addi_w  = op_31_26_d[6'h00] & op_25_22_d[4'ha];
  assign inst_ld_w    = op_31_26_d[6'h0a] & op_25_22_d[4'h2];
  assign inst_st_w    = op_31_26_d[6'h0a] & op_25_22_d[4'h6];
  assign inst_jirl    = op_31_26_d[6'h13];
  assign inst_b       = op_31_26_d[6'h14];
  assign inst_bl      = op_31_26_d[6'h15];
  assign inst_beq     = op_31_26_d[6'h16];
  assign inst_bne     = op_31_26_d[6'h17];
  assign inst_lu12i_w = op_31_26_d[6'h05] & ~inst[25];
  assign inst_slti      = op_31_26_d[6'h00] & op_25_22_d[4'h8];
  assign inst_sltui     = op_31_26_d[6'h00] & op_25_22_d[4'h9];
  assign inst_andi      = op_31_26_d[6'h00] & op_25_22_d[4'hd];
  assign inst_ori       = op_31_26_d[6'h00] & op_25_22_d[4'he];
  assign inst_xori      = op_31_26_d[6'h00] & op_25_22_d[4'hf];
  assign inst_sll_w     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0e];
  assign inst_srl_w     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0f];
  assign inst_sra_w     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h10];
  assign inst_pcaddu12i = op_31_26_d[6'h07] & ~inst[25];
  assign inst_mul_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h18];
  assign inst_mulh_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h19];
  assign inst_mulh_wu = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h1a];
  assign inst_blt  = op_31_26_d[6'h18];
  assign inst_bge  = op_31_26_d[6'h19];
  assign inst_bltu = op_31_26_d[6'h1a];
  assign inst_bgeu = op_31_26_d[6'h1b];
  assign inst_ld_b  = op_31_26_d[6'h0a] & op_25_22_d[4'h0];
  assign inst_ld_h  = op_31_26_d[6'h0a] & op_25_22_d[4'h1];
  assign inst_ld_bu = op_31_26_d[6'h0a] & op_25_22_d[4'h8];
  assign inst_ld_hu = op_31_26_d[6'h0a] & op_25_22_d[4'h9];
  assign inst_st_b = op_31_26_d[6'h0a] & op_25_22_d[4'h4];
  assign inst_st_h = op_31_26_d[6'h0a] & op_25_22_d[4'h5];

  // 找出未知指令
  wire inst_known = inst_add_w | inst_sub_w | inst_slt | inst_sltu |
       inst_nor | inst_and | inst_or | inst_xor |
       inst_slli_w | inst_srli_w | inst_srai_w |
       inst_addi_w | inst_ld_w | inst_st_w |
       inst_jirl | inst_b | inst_bl | inst_beq | inst_bne |
       inst_lu12i_w |
       inst_slti | inst_sltui | inst_andi | inst_ori | inst_xori |
       inst_sll_w | inst_srl_w | inst_sra_w | inst_pcaddu12i |
       inst_blt | inst_bge | inst_bltu | inst_bgeu |
       inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu |
       inst_st_b | inst_st_h |
       inst_mul_w | inst_mulh_w | inst_mulh_wu;



  wire is_mul      = inst_mul_w | inst_mulh_w | inst_mulh_wu;
  wire ld_byte     = inst_ld_b | inst_ld_bu;
  wire ld_half     = inst_ld_h | inst_ld_hu;
  wire ld_sign_ext = inst_ld_b | inst_ld_h;
  wire st_byte     = inst_st_b;
  wire st_half     = inst_st_h;

  // 立即数生成
  wire need_ui5  = inst_slli_w | inst_srli_w | inst_srai_w;
  wire need_si12 = inst_addi_w | inst_ld_w | inst_st_w | inst_slti | inst_sltui |
       inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu | inst_st_b | inst_st_h;
  wire need_ui12 = inst_andi | inst_ori | inst_xori;
  wire need_si16 = inst_jirl | inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu;
  wire need_si20 = inst_lu12i_w | inst_pcaddu12i;
  wire need_si26 = inst_b | inst_bl;
  wire src2_is_4 = inst_jirl | inst_bl;

  wire [31:0] imm = src2_is_4 ? 32'h4 :
       need_si20 ? {i20[19:0], 12'b0} :
       need_ui12 ? {20'b0, i12[11:0]} :
       {{20{i12[11]}}, i12[11:0]};

  wire [31:0] br_offs   = need_si26 ? {{4{i26[25]}}, i26[25:0], 2'b0} :
       {{14{i16[15]}}, i16[15:0], 2'b0};
  wire [31:0] jirl_offs = {{14{i16[15]}}, i16[15:0], 2'b0};

  // 控制信号生成
  wire src_reg_is_rd = inst_beq | inst_bne | inst_st_w |
       inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_st_b | inst_st_h;
  wire src1_is_pc    = inst_jirl | inst_bl | inst_pcaddu12i;
  wire src2_is_imm   = inst_slli_w | inst_srli_w | inst_srai_w | inst_addi_w |
       inst_ld_w | inst_st_w | inst_lu12i_w | inst_jirl | inst_bl |
       inst_slti | inst_sltui | inst_andi | inst_ori | inst_xori |
       inst_pcaddu12i |
       inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu | inst_st_b | inst_st_h;
  wire res_from_mem  = inst_ld_w | inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu;
  wire dst_is_r1     = inst_bl;
  wire gr_we         = inst_known & ~inst_st_w & ~inst_st_b & ~inst_st_h &
       ~inst_beq & ~inst_bne & ~inst_b &
       ~inst_blt & ~inst_bge & ~inst_bltu & ~inst_bgeu;
  wire mem_we        = inst_st_w | inst_st_b | inst_st_h;
  wire [ 4:0] dest   = dst_is_r1   ? 5'd1 : rd;

  // ALU 操作码
  wire [11:0] alu_op;
  assign alu_op[ 0] = inst_add_w | inst_addi_w | inst_ld_w | inst_st_w | inst_jirl | inst_bl | inst_pcaddu12i | inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu | inst_st_b | inst_st_h;
  assign alu_op[ 1] = inst_sub_w;
  assign alu_op[ 2] = inst_slt | inst_slti;
  assign alu_op[ 3] = inst_sltu | inst_sltui;
  assign alu_op[ 4] = inst_and | inst_andi;
  assign alu_op[ 5] = inst_nor;
  assign alu_op[ 6] = inst_or | inst_ori;
  assign alu_op[ 7] = inst_xor | inst_xori;
  assign alu_op[ 8] = inst_slli_w | inst_sll_w;
  assign alu_op[ 9] = inst_srli_w | inst_srl_w;
  assign alu_op[10] = inst_srai_w | inst_sra_w;
  assign alu_op[11] = inst_lu12i_w;

  // 寄存器堆接口
  wire [ 4:0] rf_raddr1 = rj;
  wire [ 4:0] rf_raddr2 = src_reg_is_rd ? rd : rk;
  wire [31:0] rf_rdata1;
  wire [31:0] rf_rdata2;

  // 数据前递
  wire rj_fwd_from_es = es_fwd_es_valid && es_fwd_gr_we && es_fwd_fwd_valid &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr1);
  wire rj_fwd_from_ms = ms_fwd_ms_valid && ms_fwd_gr_we && !ms_fwd_res_from_mem &&
       (ms_fwd_dest != 5'b0) && (ms_fwd_dest == rf_raddr1);
  wire rj_fwd_from_ws = ws_fwd_ws_valid && ws_fwd_gr_we &&
       (ws_fwd_dest != 5'b0) && (ws_fwd_dest == rf_raddr1);
  wire [31:0] rj_value = rj_fwd_from_es ? es_fwd_data :
       rj_fwd_from_ms ? ms_fwd_data :
       rj_fwd_from_ws ? ws_fwd_data :
       rf_rdata1;

  wire rkd_fwd_from_es = es_fwd_es_valid && es_fwd_gr_we && es_fwd_fwd_valid &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr2);
  wire rkd_fwd_from_ms = ms_fwd_ms_valid && ms_fwd_gr_we && !ms_fwd_res_from_mem &&
       (ms_fwd_dest != 5'b0) && (ms_fwd_dest == rf_raddr2);
  wire rkd_fwd_from_ws = ws_fwd_ws_valid && ws_fwd_gr_we &&
       (ws_fwd_dest != 5'b0) && (ws_fwd_dest == rf_raddr2);
  wire [31:0] rkd_value = rkd_fwd_from_es ? es_fwd_data :
       rkd_fwd_from_ms ? ms_fwd_data :
       rkd_fwd_from_ws ? ws_fwd_data :
       rf_rdata2;


  wire ds_need_rj  = ~inst_b & ~inst_bl & ~inst_lu12i_w & ~inst_pcaddu12i;
  wire ds_need_rkd = inst_beq | inst_bne | inst_st_w |
       inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_st_b | inst_st_h |
       inst_add_w | inst_sub_w | inst_slt | inst_sltu |
       inst_nor | inst_and | inst_or | inst_xor |
       inst_sll_w | inst_srl_w | inst_sra_w |
       inst_mul_w | inst_mulh_w | inst_mulh_wu;
  wire ds_rf_raddr1_valid = ds_need_rj  && (rf_raddr1 != 5'b0);
  wire ds_rf_raddr2_valid = ds_need_rkd && (rf_raddr2 != 5'b0);

  // Load-Use 冒险检测
  wire load_stall_rj_es  = es_fwd_es_valid && es_fwd_res_from_mem && es_fwd_gr_we &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr1) && ds_rf_raddr1_valid; // rj 依赖 EXE 阶段的 Load 指令
  wire load_stall_rkd_es = es_fwd_es_valid && es_fwd_res_from_mem && es_fwd_gr_we &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr2) && ds_rf_raddr2_valid;

  wire load_stall_rj_ms  = ms_fwd_ms_valid && ms_fwd_res_from_mem && ms_fwd_gr_we &&
       (ms_fwd_dest != 5'b0) && (ms_fwd_dest == rf_raddr1) && ds_rf_raddr1_valid;
  wire load_stall_rkd_ms = ms_fwd_ms_valid && ms_fwd_res_from_mem && ms_fwd_gr_we &&
       (ms_fwd_dest != 5'b0) && (ms_fwd_dest == rf_raddr2) && ds_rf_raddr2_valid;
  wire load_use_stall = load_stall_rj_es || load_stall_rkd_es ||
       load_stall_rj_ms || load_stall_rkd_ms ||
       multicycle_stall_rj || multicycle_stall_rkd;

  // 乘法多周期阻塞
  wire es_multicycle_busy = es_fwd_es_valid && es_fwd_gr_we &&
       !es_fwd_fwd_valid && !es_fwd_res_from_mem;
  wire multicycle_stall_rj  = es_multicycle_busy &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr1) && ds_rf_raddr1_valid;
  wire multicycle_stall_rkd = es_multicycle_busy &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr2) && ds_rf_raddr2_valid;



  // 流水线控制
  wire   ds_ready_go    = !load_use_stall;
  assign ds_allowin     = !ds_valid || (ds_ready_go && es_allowin);
  assign ds_to_es_valid = ds_valid && ds_ready_go;

  // 分支判断 (前移)
  wire rj_eq_rd          = (rj_value == rkd_value);
  wire rj_lt_rd_signed   = ($signed(rj_value) < $signed(rkd_value));
  wire rj_lt_rd_unsigned = (rj_value < rkd_value);

  wire ds_is_bj = inst_beq || inst_bne || inst_blt || inst_bge ||
       inst_bltu || inst_bgeu || inst_jirl || inst_bl || inst_b;

  wire ds_is_call = inst_bl || (inst_jirl && (rd == 5'd1));   // 调用信号
  wire ds_is_ret  = inst_jirl && (rd == 5'd0) && (rj == 5'd1) && (i16 == 16'h0000); // 返回信号

  wire ds_real_taken = (inst_beq  &&  rj_eq_rd ||
                        inst_bne  && !rj_eq_rd ||
                        inst_blt  &&  rj_lt_rd_signed ||
                        inst_bge  && !rj_lt_rd_signed ||
                        inst_bltu &&  rj_lt_rd_unsigned ||
                        inst_bgeu && !rj_lt_rd_unsigned ||
                        inst_jirl ||
                        inst_bl   ||
                        inst_b) && ds_is_bj;

  wire [31:0] ds_real_target = (inst_beq || inst_bne || inst_blt || inst_bge ||
                                inst_bltu || inst_bgeu || inst_bl || inst_b)
       ? (ds_pc + br_offs) : (rj_value + jirl_offs);

  wire ds_br_resolve = ds_valid && ds_ready_go && es_allowin && ds_is_bj;
  wire ds_taken_miss = ds_real_taken ^ ds_pred_taken;
  wire ds_target_miss = ds_real_taken && ds_pred_taken && (ds_real_target != ds_pred_target);

  assign br_taken = ds_br_resolve && (ds_taken_miss || ds_target_miss);
  assign br_target = ds_real_taken ? ds_real_target : (ds_pc + 32'h4);

  // 反馈给 BPU 的真实分支结果
  assign bpu_valid       = ds_to_es_valid && es_allowin;
  assign bpu_is_bj       = bpu_valid && ds_is_bj;
  assign bpu_pc          = ds_pc;
  assign bpu_real_taken  = ds_real_taken;
  assign bpu_real_target = ds_real_target;
  assign bpu_is_call     = bpu_is_bj && ds_real_taken && ds_is_call;
  assign bpu_is_ret      = bpu_is_bj && ds_real_taken && ds_is_ret;
  assign bpu_ret_addr    = ds_pc + 32'h4;

  // ALU 源操作数
  wire [31:0] ds_alu_src1 = src1_is_pc ? ds_pc : rj_value;
  wire [31:0] ds_alu_src2 = src2_is_imm ? imm : rkd_value;

  // 总线打包
  assign ds_to_es_bus = {ds_pc,
                         alu_op,
                         ds_alu_src1,
                         ds_alu_src2,
                         rkd_value,
                         res_from_mem,
                         gr_we,
                         mem_we,
                         dest,
                         is_mul,
                         inst_mul_w | inst_mulh_w,
                         inst_mulh_w | inst_mulh_wu,
                         ld_byte,
                         ld_half,
                         ld_sign_ext,
                         st_byte,
                         st_half
                        };

  always @(posedge clk)
  begin
    if (reset)
      ds_valid <= 1'b0;
    else if (br_taken)
      ds_valid <= 1'b0;
    else if (ds_allowin)
      ds_valid <= fs_to_ds_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ds_pc       <= 32'b0;
      ds_inst     <= 32'b0;
      ds_pred_taken <= 1'b0;
      ds_pred_target <= 32'b0;
    end
    else if (ds_allowin && fs_to_ds_valid)
    begin
      ds_pc       <= fs_pc;
      ds_inst     <= fs_inst;
      ds_pred_taken <= fs_pred_taken;
      ds_pred_target <= fs_pred_target;
    end
  end

  decoder_6_64 u_dec0 (.in(op_31_26), .out(op_31_26_d));
  decoder_4_16 u_dec1 (.in(op_25_22), .out(op_25_22_d));
  decoder_2_4  u_dec2 (.in(op_21_20), .out(op_21_20_d));
  decoder_5_32 u_dec3 (.in(op_19_15), .out(op_19_15_d));

  regfile u_regfile(
            .clk    (clk        ),
            .raddr1 (rf_raddr1  ),
            .rdata1 (rf_rdata1  ),
            .raddr2 (rf_raddr2  ),
            .rdata2 (rf_rdata2  ),
            .we     (ws_rf_we   ),
            .waddr  (ws_rf_waddr),
            .wdata  (ws_rf_wdata)
          );

endmodule
