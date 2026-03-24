`include "mycpu.vh"

module WB_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ms_to_ws_valid,
    input  wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus,
    output wire                         ws_allowin,
    output wire [`WS_FWD_BUS_WD-1:0]    ws_fwd_bus,
    output wire [`WS_TO_RF_BUS_WD-1:0]  ws_to_rf_bus,
    output wire                         ws_flush,
    output wire [31:0]                  ws_flush_pc,
    output wire [31:0]                  debug_wb_pc,
    output wire [ 3:0]                  debug_wb_rf_we,
    output wire [ 4:0]                  debug_wb_rf_wnum,
    output wire [31:0]                  debug_wb_rf_wdata
  );

  // 内部信号
  reg         reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ws_valid;
  reg  [31:0] ws_pc;
  reg  [31:0] ws_alu_result;
  reg  [31:0] ws_mem_result;
  reg         ws_res_from_mem;
  reg         ws_gr_we;
  reg  [ 4:0] ws_dest;
  reg         ws_ld_byte;
  reg         ws_ld_half;
  reg         ws_ld_sign_ext;
  reg         ws_inst_syscall;
  reg         ws_inst_break;
  reg         ws_inst_ertn;
  reg         ws_csr_re;
  reg         ws_csr_we;
  reg  [13:0] ws_csr_num;
  reg  [31:0] ws_csr_wmask;
  reg  [31:0] ws_csr_wdata;
  reg         ws_has_adef;
  reg         ws_has_ine;
  reg         ws_is_rdcnt;
  reg  [ 1:0] ws_rdcnt_sel;
  reg         ws_has_ale;

  // 解包 ms_to_ws_bus
  wire [31:0] ms_pc;
  wire [31:0] ms_alu_result;
  wire        ms_res_from_mem;
  wire        ms_gr_we;
  wire [ 4:0] ms_dest;
  wire        ms_ld_byte;
  wire        ms_ld_half;
  wire        ms_ld_sign_ext;
  wire        ms_inst_syscall;
  wire        ms_inst_break;
  wire        ms_inst_ertn;
  wire        ms_csr_re;
  wire        ms_csr_we;
  wire [13:0] ms_csr_num;
  wire [31:0] ms_csr_wmask;
  wire [31:0] ms_rkd_value;
  wire [31:0] ms_mem_rdata;
  wire        ms_has_adef;
  wire        ms_has_ine;
  wire        ms_is_rdcnt;
  wire [ 1:0] ms_rdcnt_sel;
  wire        ms_has_ale;

  assign {ms_pc, ms_alu_result, ms_res_from_mem, ms_gr_we, ms_dest,
          ms_ld_byte, ms_ld_half, ms_ld_sign_ext,
          ms_inst_syscall, ms_inst_break, ms_inst_ertn,
          ms_csr_re, ms_csr_we, ms_csr_num, ms_csr_wmask,
          ms_rkd_value,
          ms_mem_rdata,
          ms_has_adef, ms_has_ine, ms_is_rdcnt, ms_rdcnt_sel,
          ms_has_ale} = ms_to_ws_bus;

  // 流水线控制
  wire ws_ready_go = 1'b1;
  assign ws_allowin = !ws_valid || ws_ready_go;

  // 异常 / ERTN / 中断处理
  wire        has_int;
  wire [31:0] counter_lo;
  wire [31:0] counter_hi;
  wire [31:0] tid_value;

  // 异常检测 
  wire wb_ex = ws_valid && (has_int || ws_has_adef || ws_has_ine ||
                            ws_inst_syscall || ws_inst_break || ws_has_ale);
  wire ertn_flush_w = ws_valid && ws_inst_ertn && !wb_ex;
  assign ws_flush = wb_ex || ertn_flush_w;

  // 异常码选择 
  wire [5:0] wb_ecode = has_int         ? `ECODE_INT  :
                        ws_has_adef     ? `ECODE_ADEF :
                        ws_has_ine      ? `ECODE_INE  :
                        ws_inst_syscall ? `ECODE_SYS  :
                        ws_inst_break   ? `ECODE_BRK  :
                                          `ECODE_ALE;

  // BADV 值: ADEF -> PC, ALE -> 访存地址
  wire [31:0] wb_vaddr = ws_has_adef ? ws_pc : ws_alu_result;

  // CSR 模块接口
  wire [31:0] csr_rvalue;
  wire [31:0] csr_ex_entry;
  wire [31:0] csr_era_value;

  // 异常冲刷 PC: 异常 -> EENTRY, ERTN -> ERA
  assign ws_flush_pc = wb_ex ? csr_ex_entry : csr_era_value;

  // CSR 写使能: 仅在非异常、非ertn时有效
  wire csr_we_valid = ws_valid && ws_csr_we && !wb_ex && !ertn_flush_w;

  csr u_csr(
        .clk        (clk           ),
        .reset      (reset         ),
        .csr_num    (ws_csr_num    ),
        .csr_rvalue (csr_rvalue    ),
        .csr_we     (csr_we_valid  ),
        .csr_wmask  (ws_csr_wmask  ),
        .csr_wvalue (ws_csr_wdata  ),
        .wb_ex      (wb_ex         ),
        .wb_ecode   (wb_ecode      ),
        .wb_esubcode(9'b0          ),
        .wb_pc      (ws_pc         ),
        .wb_vaddr   (wb_vaddr      ),
        .ertn_flush (ertn_flush_w  ),
        .ex_entry   (csr_ex_entry  ),
        .era_value  (csr_era_value ),
        .has_int    (has_int       ),
        .counter_lo (counter_lo    ),
        .counter_hi (counter_hi    ),
        .tid_value  (tid_value     )
      );

  // Load byte/halfword 提取
  wire [ 1:0] ws_addr_low  = ws_alu_result[1:0];
  wire [ 7:0] ws_load_byte = ws_addr_low[1] ? (ws_addr_low[0] ? ws_mem_result[31:24] : ws_mem_result[23:16]) :
       (ws_addr_low[0] ? ws_mem_result[15:8]  : ws_mem_result[7:0]);
  wire [15:0] ws_load_half = ws_addr_low[1] ? ws_mem_result[31:16] : ws_mem_result[15:0];
  wire [31:0] ws_load_result =
       ws_ld_byte ? (ws_ld_sign_ext ? {{24{ws_load_byte[7]}}, ws_load_byte}
                     : {24'b0, ws_load_byte}) :
       ws_ld_half ? (ws_ld_sign_ext ? {{16{ws_load_half[15]}}, ws_load_half}
                     : {16'b0, ws_load_half}) :
       ws_mem_result;

  // RDCNT 结果选择
  wire [31:0] ws_rdcnt_result = (ws_rdcnt_sel == 2'd1) ? counter_hi :
                                (ws_rdcnt_sel == 2'd2) ? tid_value  :
                                                         counter_lo;

  // 最终结果选择: RDCNT > CSR读 > 内存读 > ALU结果
  wire [31:0] final_result = ws_is_rdcnt     ? ws_rdcnt_result :
                             ws_csr_re       ? csr_rvalue      :
                             ws_res_from_mem ? ws_load_result  :
                                              ws_alu_result;

  // 写回信号 (异常/ertn 不写寄存器)
  wire        ws_rf_we    = ws_gr_we && ws_valid && !wb_ex && !ertn_flush_w;
  wire [ 4:0] ws_rf_waddr = ws_dest;
  wire [31:0] ws_rf_wdata = final_result;

  // 前递信号
  assign ws_fwd_bus = {ws_valid, ws_gr_we, ws_dest, final_result};

  // 写回总线
  assign ws_to_rf_bus = {ws_rf_we, ws_rf_waddr, ws_rf_wdata};

  assign debug_wb_pc       = ws_pc;
  assign debug_wb_rf_we    = {4{ws_rf_we}};
  assign debug_wb_rf_wnum  = ws_dest;
  assign debug_wb_rf_wdata = final_result;

  // 时序逻辑
  always @(posedge clk)
  begin
    if (reset)
      ws_valid <= 1'b0;
    else if (ws_flush)
      ws_valid <= 1'b0;
    else if (ws_allowin)
      ws_valid <= ms_to_ws_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ws_pc           <= 32'b0;
      ws_gr_we        <= 1'b0;
      ws_res_from_mem <= 1'b0;
      ws_dest         <= 5'b0;
      ws_alu_result   <= 32'b0;
      ws_mem_result   <= 32'b0;
      ws_ld_byte      <= 1'b0;
      ws_ld_half      <= 1'b0;
      ws_ld_sign_ext  <= 1'b0;
      ws_inst_syscall <= 1'b0;
      ws_inst_break   <= 1'b0;
      ws_inst_ertn    <= 1'b0;
      ws_csr_re       <= 1'b0;
      ws_csr_we       <= 1'b0;
      ws_csr_num      <= 14'b0;
      ws_csr_wmask    <= 32'b0;
      ws_csr_wdata    <= 32'b0;
      ws_has_adef     <= 1'b0;
      ws_has_ine      <= 1'b0;
      ws_is_rdcnt     <= 1'b0;
      ws_rdcnt_sel    <= 2'b0;
      ws_has_ale      <= 1'b0;
    end
    else if (ws_allowin)
    begin
      if (ms_to_ws_valid)
      begin
        ws_pc           <= ms_pc;
        ws_alu_result   <= ms_alu_result;
        ws_mem_result   <= ms_mem_rdata;
        ws_res_from_mem <= ms_res_from_mem;
        ws_gr_we        <= ms_gr_we;
        ws_dest         <= ms_dest;
        ws_ld_byte      <= ms_ld_byte;
        ws_ld_half      <= ms_ld_half;
        ws_ld_sign_ext  <= ms_ld_sign_ext;
        ws_inst_syscall <= ms_inst_syscall;
        ws_inst_break   <= ms_inst_break;
        ws_inst_ertn    <= ms_inst_ertn;
        ws_csr_re       <= ms_csr_re;
        ws_csr_we       <= ms_csr_we;
        ws_csr_num      <= ms_csr_num;
        ws_csr_wmask    <= ms_csr_wmask;
        ws_csr_wdata    <= ms_rkd_value;
        ws_has_adef     <= ms_has_adef;
        ws_has_ine      <= ms_has_ine;
        ws_is_rdcnt     <= ms_is_rdcnt;
        ws_rdcnt_sel    <= ms_rdcnt_sel;
        ws_has_ale      <= ms_has_ale;
      end
      else
      begin
        ws_gr_we        <= 1'b0;
        ws_inst_syscall <= 1'b0;
        ws_inst_break   <= 1'b0;
        ws_inst_ertn    <= 1'b0;
        ws_csr_re       <= 1'b0;
        ws_csr_we       <= 1'b0;
        ws_has_adef     <= 1'b0;
        ws_has_ine      <= 1'b0;
        ws_is_rdcnt     <= 1'b0;
        ws_has_ale      <= 1'b0;
      end
    end
  end

endmodule
