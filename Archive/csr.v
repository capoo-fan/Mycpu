`include "mycpu.vh"

module csr(
    input  wire        clk,
    input  wire        reset,
    input  wire [13:0] csr_num,
    output wire [31:0] csr_rvalue,
    input  wire        csr_we,
    input  wire [31:0] csr_wmask,
    input  wire [31:0] csr_wvalue,
    input  wire        wb_ex,
    input  wire [ 5:0] wb_ecode,
    input  wire [ 8:0] wb_esubcode,
    input  wire [31:0] wb_pc,
    input  wire [31:0] wb_vaddr,
    input  wire        ertn_flush,
    output wire [31:0] ex_entry,
    output wire [31:0] era_value,
    output wire        has_int,
    output wire [31:0] counter_lo,
    output wire [31:0] counter_hi,
    output wire [31:0] tid_value
  );

  // CSR 编号定义
  localparam CSR_CRMD   = 14'h0000;
  localparam CSR_PRMD   = 14'h0001;
  localparam CSR_ECFG   = 14'h0004;
  localparam CSR_ESTAT  = 14'h0005;
  localparam CSR_ERA    = 14'h0006;
  localparam CSR_BADV   = 14'h0007;
  localparam CSR_EENTRY = 14'h000c;
  localparam CSR_SAVE0  = 14'h0030;
  localparam CSR_SAVE1  = 14'h0031;
  localparam CSR_SAVE2  = 14'h0032;
  localparam CSR_SAVE3  = 14'h0033;
  localparam CSR_TID    = 14'h0040;
  localparam CSR_TCFG   = 14'h0041;
  localparam CSR_TVAL   = 14'h0042;
  localparam CSR_TICLR  = 14'h0044;

  // ========================================================================
  // CRMD (0x0)
  // ========================================================================
  reg  [ 1:0] csr_crmd_plv;
  reg         csr_crmd_ie;
  reg         csr_crmd_da;
  reg         csr_crmd_pg;
  reg  [ 1:0] csr_crmd_datf;
  reg  [ 1:0] csr_crmd_datm;

  wire [31:0] csr_crmd = {23'b0, csr_crmd_datm, csr_crmd_datf,
                          csr_crmd_pg, csr_crmd_da, csr_crmd_ie, csr_crmd_plv};

  always @(posedge clk)
  begin
    if (reset)
    begin
      csr_crmd_plv  <= 2'b0;
      csr_crmd_ie   <= 1'b0;
      csr_crmd_da   <= 1'b1;
      csr_crmd_pg   <= 1'b0;
      csr_crmd_datf <= 2'b0;
      csr_crmd_datm <= 2'b0;
    end
    else if (wb_ex)
    begin
      csr_crmd_plv <= 2'b0;
      csr_crmd_ie  <= 1'b0;
    end
    else if (ertn_flush)
    begin
      csr_crmd_plv <= csr_prmd_pplv;
      csr_crmd_ie  <= csr_prmd_pie;
    end
    else if (csr_we && csr_num == CSR_CRMD)
    begin
      csr_crmd_plv  <= (csr_wvalue[ 1:0] & csr_wmask[ 1:0]) | (csr_crmd_plv  & ~csr_wmask[ 1:0]);
      csr_crmd_ie   <= (csr_wvalue[   2] & csr_wmask[   2]) | (csr_crmd_ie   & ~csr_wmask[   2]);
      csr_crmd_da   <= (csr_wvalue[   3] & csr_wmask[   3]) | (csr_crmd_da   & ~csr_wmask[   3]);
      csr_crmd_pg   <= (csr_wvalue[   4] & csr_wmask[   4]) | (csr_crmd_pg   & ~csr_wmask[   4]);
      csr_crmd_datf <= (csr_wvalue[ 6:5] & csr_wmask[ 6:5]) | (csr_crmd_datf & ~csr_wmask[ 6:5]);
      csr_crmd_datm <= (csr_wvalue[ 8:7] & csr_wmask[ 8:7]) | (csr_crmd_datm & ~csr_wmask[ 8:7]);
    end
  end

  // ========================================================================
  // PRMD (0x1)
  // ========================================================================
  reg  [ 1:0] csr_prmd_pplv;
  reg         csr_prmd_pie;

  wire [31:0] csr_prmd = {29'b0, csr_prmd_pie, csr_prmd_pplv};

  always @(posedge clk)
  begin
    if (reset)
    begin
      csr_prmd_pplv <= 2'b0;
      csr_prmd_pie  <= 1'b0;
    end
    else if (wb_ex)
    begin
      csr_prmd_pplv <= csr_crmd_plv;
      csr_prmd_pie  <= csr_crmd_ie;
    end
    else if (csr_we && csr_num == CSR_PRMD)
    begin
      csr_prmd_pplv <= (csr_wvalue[1:0] & csr_wmask[1:0]) | (csr_prmd_pplv & ~csr_wmask[1:0]);
      csr_prmd_pie  <= (csr_wvalue[  2] & csr_wmask[  2]) | (csr_prmd_pie  & ~csr_wmask[  2]);
    end
  end

  // ========================================================================
  // ECFG (0x4) - Local Interrupt Enable
  // ========================================================================
  reg  [12:0] csr_ecfg_lie;

  wire [31:0] csr_ecfg = {19'b0, csr_ecfg_lie};

  always @(posedge clk)
  begin
    if (reset)
      csr_ecfg_lie <= 13'b0;
    else if (csr_we && csr_num == CSR_ECFG)
    begin
      csr_ecfg_lie[ 9: 0] <= (csr_wvalue[ 9: 0] & csr_wmask[ 9: 0]) | (csr_ecfg_lie[ 9: 0] & ~csr_wmask[ 9: 0]);
      // bit 10 is reserved, always 0
      csr_ecfg_lie[12:11] <= (csr_wvalue[12:11] & csr_wmask[12:11]) | (csr_ecfg_lie[12:11] & ~csr_wmask[12:11]);
    end
  end

  // ========================================================================
  // ESTAT (0x5) - Exception Status
  // ========================================================================
  reg  [ 1:0] csr_estat_is_sw;
  reg         csr_estat_ti;
  reg  [ 5:0] csr_estat_ecode;
  reg  [ 8:0] csr_estat_esubcode;

  wire [12:0] csr_estat_is = {1'b0, csr_estat_ti, 1'b0, 8'b0, csr_estat_is_sw};
  wire [31:0] csr_estat = {1'b0, csr_estat_esubcode, csr_estat_ecode,
                           3'b0, csr_estat_is};

  always @(posedge clk)
  begin
    if (reset)
    begin
      csr_estat_is_sw    <= 2'b0;
      csr_estat_ecode    <= 6'b0;
      csr_estat_esubcode <= 9'b0;
    end
    else
    begin
      if (wb_ex)
      begin
        csr_estat_ecode    <= wb_ecode;
        csr_estat_esubcode <= wb_esubcode;
      end
      if (csr_we && csr_num == CSR_ESTAT)
      begin
        csr_estat_is_sw <= (csr_wvalue[1:0] & csr_wmask[1:0]) | (csr_estat_is_sw & ~csr_wmask[1:0]);
      end
    end
  end

  // Timer interrupt flag
  always @(posedge clk)
  begin
    if (reset)
      csr_estat_ti <= 1'b0;
    else if (csr_we && csr_num == CSR_TICLR && csr_wvalue[0] && csr_wmask[0])
      csr_estat_ti <= 1'b0;
    else if (csr_tcfg_en && timer_cnt == 32'd1)
      csr_estat_ti <= 1'b1;
    else if (csr_we && csr_num == CSR_TCFG && tcfg_next[0] && tcfg_next[31:2] == 30'b0)
      csr_estat_ti <= 1'b1;  // initval=0: immediate fire
  end

  // ========================================================================
  // ERA (0x6) - Exception Return Address
  // ========================================================================
  reg  [31:0] csr_era_pc;

  always @(posedge clk)
  begin
    if (reset)
      csr_era_pc <= 32'b0;
    else if (wb_ex)
      csr_era_pc <= wb_pc;
    else if (csr_we && csr_num == CSR_ERA)
      csr_era_pc <= (csr_wvalue & csr_wmask) | (csr_era_pc & ~csr_wmask);
  end

  // ========================================================================
  // BADV (0x7) - Bad Virtual Address
  // ========================================================================
  reg  [31:0] csr_badv_vaddr;

  always @(posedge clk)
  begin
    if (reset)
      csr_badv_vaddr <= 32'b0;
    else if (wb_ex && (wb_ecode == `ECODE_ADEF || wb_ecode == `ECODE_ALE))
      csr_badv_vaddr <= wb_vaddr;
    else if (csr_we && csr_num == CSR_BADV)
      csr_badv_vaddr <= (csr_wvalue & csr_wmask) | (csr_badv_vaddr & ~csr_wmask);
  end

  // ========================================================================
  // EENTRY (0xC) - Exception Entry Address
  // ========================================================================
  reg  [25:0] csr_eentry_va;

  wire [31:0] csr_eentry = {csr_eentry_va, 6'b0};

  always @(posedge clk)
  begin
    if (reset)
      csr_eentry_va <= 26'b0;
    else if (csr_we && csr_num == CSR_EENTRY)
      csr_eentry_va <= (csr_wvalue[31:6] & csr_wmask[31:6]) | (csr_eentry_va & ~csr_wmask[31:6]);
  end

  // ========================================================================
  // SAVE0 ~ SAVE3 (0x30 ~ 0x33)
  // ========================================================================
  reg  [31:0] csr_save0;
  reg  [31:0] csr_save1;
  reg  [31:0] csr_save2;
  reg  [31:0] csr_save3;

  always @(posedge clk)
  begin
    if (reset)
    begin
      csr_save0 <= 32'b0;
      csr_save1 <= 32'b0;
      csr_save2 <= 32'b0;
      csr_save3 <= 32'b0;
    end
    else if (csr_we)
    begin
      case (csr_num)
        CSR_SAVE0:
          csr_save0 <= (csr_wvalue & csr_wmask) | (csr_save0 & ~csr_wmask);
        CSR_SAVE1:
          csr_save1 <= (csr_wvalue & csr_wmask) | (csr_save1 & ~csr_wmask);
        CSR_SAVE2:
          csr_save2 <= (csr_wvalue & csr_wmask) | (csr_save2 & ~csr_wmask);
        CSR_SAVE3:
          csr_save3 <= (csr_wvalue & csr_wmask) | (csr_save3 & ~csr_wmask);
        default:
          ;
      endcase
    end
  end

  // ========================================================================
  // TID (0x40) - Timer Identifier
  // ========================================================================
  reg  [31:0] csr_tid_val;

  always @(posedge clk)
  begin
    if (reset)
      csr_tid_val <= 32'b0;
    else if (csr_we && csr_num == CSR_TID)
      csr_tid_val <= (csr_wvalue & csr_wmask) | (csr_tid_val & ~csr_wmask);
  end

  // ========================================================================
  // TCFG (0x41) - Timer Configuration
  // ========================================================================
  reg         csr_tcfg_en;
  reg         csr_tcfg_periodic;
  reg  [29:0] csr_tcfg_initval;

  wire [31:0] csr_tcfg = {csr_tcfg_initval, csr_tcfg_periodic, csr_tcfg_en};

  always @(posedge clk)
  begin
    if (reset)
    begin
      csr_tcfg_en       <= 1'b0;
      csr_tcfg_periodic <= 1'b0;
      csr_tcfg_initval  <= 30'b0;
    end
    else if (csr_we && csr_num == CSR_TCFG)
    begin
      csr_tcfg_en       <= (csr_wvalue[   0] & csr_wmask[   0]) | (csr_tcfg_en       & ~csr_wmask[   0]);
      csr_tcfg_periodic <= (csr_wvalue[   1] & csr_wmask[   1]) | (csr_tcfg_periodic & ~csr_wmask[   1]);
      csr_tcfg_initval  <= (csr_wvalue[31:2] & csr_wmask[31:2]) | (csr_tcfg_initval  & ~csr_wmask[31:2]);
    end
  end

  // ========================================================================
  // TVAL (0x42) - Timer Counter Value
  // ========================================================================
  reg  [31:0] timer_cnt;

  wire [31:0] tcfg_next = (csr_wvalue & csr_wmask) | (csr_tcfg & ~csr_wmask);

  always @(posedge clk)
  begin
    if (reset)
      timer_cnt <= 32'hffffffff;
    else if (csr_we && csr_num == CSR_TCFG && tcfg_next[0])
      timer_cnt <= {tcfg_next[31:2], 2'b0};
    else if (csr_tcfg_en)
    begin
      if (timer_cnt == 32'b0)
      begin
        if (csr_tcfg_periodic)
          timer_cnt <= {csr_tcfg_initval, 2'b0};
      end
      else
        timer_cnt <= timer_cnt - 1'b1;
    end
  end

  // ========================================================================
  // Stable Counter (64-bit)
  // ========================================================================
  reg  [63:0] stable_counter;

  always @(posedge clk)
  begin
    if (reset)
      stable_counter <= 64'b0;
    else
      stable_counter <= stable_counter + 1'b1;
  end

  // ========================================================================
  // Interrupt detection
  // ========================================================================
  assign has_int = csr_crmd_ie && (|(csr_ecfg_lie[12:0] & csr_estat_is[12:0]));

  // ========================================================================
  // Read mux
  // ========================================================================
  assign csr_rvalue = {32{csr_num == CSR_CRMD  }} & csr_crmd
         | {32{csr_num == CSR_PRMD  }} & csr_prmd
         | {32{csr_num == CSR_ECFG  }} & csr_ecfg
         | {32{csr_num == CSR_ESTAT }} & csr_estat
         | {32{csr_num == CSR_ERA   }} & csr_era_pc
         | {32{csr_num == CSR_BADV  }} & csr_badv_vaddr
         | {32{csr_num == CSR_EENTRY}} & csr_eentry
         | {32{csr_num == CSR_SAVE0 }} & csr_save0
         | {32{csr_num == CSR_SAVE1 }} & csr_save1
         | {32{csr_num == CSR_SAVE2 }} & csr_save2
         | {32{csr_num == CSR_SAVE3 }} & csr_save3
         | {32{csr_num == CSR_TID   }} & csr_tid_val
         | {32{csr_num == CSR_TCFG  }} & csr_tcfg
         | {32{csr_num == CSR_TVAL  }} & timer_cnt;

  assign ex_entry   = csr_eentry;
  assign era_value  = csr_era_pc;
  assign counter_lo = stable_counter[31: 0];
  assign counter_hi = stable_counter[63:32];
  assign tid_value  = csr_tid_val;

endmodule
