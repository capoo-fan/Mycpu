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

  // 分支纠错打一拍，避免 ID 组合分支结果直接输出到 IF/PC。
  reg         br_taken_r;
  reg  [31:0] br_target_r;

  // BPU 训练信息与分支纠错同拍延后，避免 flush 当拍训练错误路径。
  reg         bpu_valid_r;
  reg         bpu_is_bj_r;
  reg  [31:0] bpu_pc_r;
  reg         bpu_real_taken_r;
  reg  [31:0] bpu_real_target_r;
  reg         bpu_is_call_r;
  reg         bpu_is_ret_r;
  reg  [31:0] bpu_ret_addr_r;

  wire [31:0] fs_pc;
  wire [31:0] fs_inst;
  wire        fs_pred_taken;
  wire [31:0] fs_pred_target;

  assign {fs_pc, fs_inst, fs_pred_taken, fs_pred_target} = fs_to_ds_bus;

  assign br_taken  = br_taken_r;
  assign br_target = br_target_r;

  assign bpu_valid       = bpu_valid_r;
  assign bpu_is_bj       = bpu_is_bj_r;
  assign bpu_pc          = bpu_pc_r;
  assign bpu_real_taken  = bpu_real_taken_r;
  assign bpu_real_target = bpu_real_target_r;
  assign bpu_is_call     = bpu_is_call_r;
  assign bpu_is_ret      = bpu_is_ret_r;
  assign bpu_ret_addr    = bpu_ret_addr_r;


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
  wire [`DS_DEC_BUS_WD-1:0] ds_dec_bus;
  wire [11:0] alu_op;
  wire [31:0] imm;
  wire [31:0] br_offs;
  wire [31:0] jirl_offs;
  wire [ 4:0] rf_raddr1;
  wire [ 4:0] rf_raddr2;
  wire [ 4:0] dest;
  wire        src1_is_pc;
  wire        src2_is_imm;
  wire        res_from_mem;
  wire        gr_we;
  wire        mem_we;
  wire        is_mul;
  wire        mul_signed;
  wire        mul_hi;
  wire        ld_byte;
  wire        ld_half;
  wire        ld_sign_ext;
  wire        st_byte;
  wire        st_half;
  wire        ds_need_rj;
  wire        ds_need_rkd;
  wire        ds_is_bj;
  wire        inst_beq;
  wire        inst_bne;
  wire        inst_blt;
  wire        inst_bge;
  wire        inst_bltu;
  wire        inst_bgeu;
  wire        inst_jirl;
  wire        inst_bl;
  wire        inst_b;
  wire        ds_is_call;
  wire        ds_is_ret;
  wire [31:0] rf_rdata1;
  wire [31:0] rf_rdata2;

  assign {alu_op, imm, br_offs, jirl_offs,
          rf_raddr1, rf_raddr2, dest,
          src1_is_pc, src2_is_imm, res_from_mem, gr_we, mem_we,
          is_mul, mul_signed, mul_hi,
          ld_byte, ld_half, ld_sign_ext, st_byte, st_half,
          ds_need_rj, ds_need_rkd, ds_is_bj,
          inst_beq, inst_bne, inst_blt, inst_bge, inst_bltu, inst_bgeu,
          inst_jirl, inst_bl, inst_b,
          ds_is_call, ds_is_ret} = ds_dec_bus;

  inst_decoder u_inst_decoder(
                 .inst    (ds_inst   ),
                 .dec_bus (ds_dec_bus)
               );

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

  // 分支解析不直接使用 EXE 组合前递结果；若需要该结果，会先 stall 一拍。
  wire [31:0] rj_br_value = rj_fwd_from_ms ? ms_fwd_data :
       rj_fwd_from_ws ? ws_fwd_data :
       rf_rdata1;
  wire [31:0] rkd_br_value = rkd_fwd_from_ms ? ms_fwd_data :
       rkd_fwd_from_ws ? ws_fwd_data :
       rf_rdata2;

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

  // 乘法多周期阻塞
  wire es_multicycle_busy = es_fwd_es_valid && es_fwd_gr_we &&
       !es_fwd_fwd_valid && !es_fwd_res_from_mem;
  wire multicycle_stall_rj  = es_multicycle_busy &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr1) && ds_rf_raddr1_valid;
  wire multicycle_stall_rkd = es_multicycle_busy &&
       (es_fwd_dest != 5'b0) && (es_fwd_dest == rf_raddr2) && ds_rf_raddr2_valid;
  wire load_use_stall = load_stall_rj_es || load_stall_rkd_es ||
       load_stall_rj_ms || load_stall_rkd_ms ||
       multicycle_stall_rj || multicycle_stall_rkd;

  // 分支指令若依赖 EXE 当前组合结果，等待一拍从 MEM 结果前递
  wire branch_dep_stall_es = ds_valid && ds_is_bj &&
       es_fwd_es_valid && es_fwd_gr_we && (es_fwd_dest != 5'b0) &&
       ((ds_rf_raddr1_valid && (es_fwd_dest == rf_raddr1)) ||
        (ds_rf_raddr2_valid && (es_fwd_dest == rf_raddr2)));

  // 流水线控制
  wire   ds_ready_go    = !load_use_stall && !branch_dep_stall_es;
  wire   ds_fire        = ds_valid && ds_ready_go && es_allowin && !br_taken; // 表示 ID 当前指令可以进入 EXE 阶段，且不发生分支跳转
  assign ds_allowin     = br_taken || !ds_valid || (ds_ready_go && es_allowin);
  assign ds_to_es_valid = ds_valid && ds_ready_go && !br_taken;

  // 分支判断 (前移)
  wire rj_eq_rd          = (rj_br_value == rkd_br_value);
  wire rj_lt_rd_signed   = ($signed(rj_br_value) < $signed(rkd_br_value));
  wire rj_lt_rd_unsigned = (rj_br_value < rkd_br_value);

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
       ? (ds_pc + br_offs) : (rj_br_value + jirl_offs);

  wire ds_br_resolve = ds_fire && ds_is_bj;
  wire ds_taken_miss = ds_real_taken ^ ds_pred_taken;
  wire ds_target_miss = ds_real_taken && ds_pred_taken && (ds_real_target != ds_pred_target);
  wire ds_redirect = ds_br_resolve && (ds_taken_miss || ds_target_miss);
  wire [31:0] ds_redirect_target = ds_real_taken ? ds_real_target : (ds_pc + 32'h4);

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
                         mul_signed,
                         mul_hi,
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

  always @(posedge clk)
  begin
    if (reset)
    begin
      br_taken_r  <= 1'b0;
      br_target_r <= 32'b0;
    end
    else
    begin
      br_taken_r  <= ds_redirect;
      br_target_r <= ds_redirect ? ds_redirect_target : 32'b0;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      bpu_valid_r       <= 1'b0;
      bpu_is_bj_r       <= 1'b0;
      bpu_pc_r          <= 32'b0;
      bpu_real_taken_r  <= 1'b0;
      bpu_real_target_r <= 32'b0;
      bpu_is_call_r     <= 1'b0;
      bpu_is_ret_r      <= 1'b0;
      bpu_ret_addr_r    <= 32'b0;
    end
    else
    begin
      bpu_valid_r <= ds_fire;
      if (ds_fire)
      begin
        bpu_is_bj_r       <= ds_is_bj;
        bpu_pc_r          <= ds_pc;
        bpu_real_taken_r  <= ds_real_taken;
        bpu_real_target_r <= ds_real_target;
        bpu_is_call_r     <= ds_is_bj && ds_real_taken && ds_is_call;
        bpu_is_ret_r      <= ds_is_bj && ds_real_taken && ds_is_ret;
        bpu_ret_addr_r    <= ds_pc + 32'h4;
      end
      else
      begin
        bpu_is_bj_r       <= 1'b0;
        bpu_real_taken_r  <= 1'b0;
        bpu_real_target_r <= 32'b0;
        bpu_is_call_r     <= 1'b0;
        bpu_is_ret_r      <= 1'b0;
        bpu_ret_addr_r    <= 32'b0;
      end
    end
  end

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
