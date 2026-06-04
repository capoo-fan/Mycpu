`include "mycpu.vh"

module ID_stage(
    input  wire                           clk,
    input  wire                           resetn,
    input  wire                           fs_to_ds_valid,
    input  wire [`FS_TO_DS_BUS_WD-1:0]    fs_to_ds_bus,
    output wire                           ds_allowin,
    output wire                           ds_pop_ready,
    input  wire                           br_taken,

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
  wire [31:0] rf_rdata1;
  wire [31:0] rf_rdata2;

  assign {alu_op, imm, br_offs, jirl_offs,
          rf_raddr1, rf_raddr2, dest,
          src1_is_pc, src2_is_imm, res_from_mem, gr_we, mem_we,
          is_mul, mul_signed, mul_hi,
          ld_byte, ld_half, ld_sign_ext, st_byte, st_half,
          ds_need_rj, ds_need_rkd, ds_is_bj,
          inst_beq, inst_bne, inst_blt, inst_bge, inst_bltu, inst_bgeu,
          inst_jirl, inst_bl, inst_b} = ds_dec_bus;

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

  // 流水线控制
  wire   ds_ready_go    = !load_use_stall;
  assign ds_pop_ready   = !ds_valid || (ds_ready_go && es_allowin);
  assign ds_allowin     = br_taken || ds_pop_ready;
  assign ds_to_es_valid = ds_valid && ds_ready_go && !br_taken;

  // ALU 源操作数
  wire [31:0] ds_alu_src1 = src1_is_pc ? ds_pc : rj_value;
  wire [31:0] ds_alu_src2 = src2_is_imm ? imm : rkd_value;
  wire [31:0] ds_rkd_value = inst_jirl ? rj_value : rkd_value;

  // 分支指令信息
  wire [ 3:0] ds_br_op = inst_beq  ? `BR_BEQ  :
                         inst_bne  ? `BR_BNE  :
                         inst_blt  ? `BR_BLT  :
                         inst_bge  ? `BR_BGE  :
                         inst_bltu ? `BR_BLTU :
                         inst_bgeu ? `BR_BGEU :
                         inst_jirl ? `BR_JIRL :
                         inst_bl   ? `BR_BL   :
                         inst_b    ? `BR_B    :
                                      `BR_NONE;
  wire [31:0] ds_br_offs = inst_jirl ? jirl_offs : br_offs;

  // 总线打包
  assign ds_to_es_bus = {ds_pc,
                         alu_op,
                         ds_alu_src1,
                         ds_alu_src2,
                         ds_rkd_value,
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
                         st_half,
                         ds_pred_taken,
                         ds_pred_target,
                         ds_br_op,
                         ds_br_offs
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
