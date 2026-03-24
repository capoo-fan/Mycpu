`include "mycpu.vh"

module EXE_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ds_to_es_valid,
    input  wire [`DS_TO_ES_BUS_WD-1:0]  ds_to_es_bus,
    input  wire                         ms_allowin,
    input  wire                         ws_flush,
    output wire                         es_allowin,
    output wire                         es_to_ms_valid,
    output wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus,
    output wire [`ES_FWD_BUS_WD-1:0]    es_fwd_bus
  );

  reg         reset;
  always @(posedge clk) reset <= ~resetn;

  // EX 级寄存器
  reg         es_valid;
  reg  [31:0] es_pc;
  reg  [11:0] es_alu_op;
  reg  [31:0] es_alu_src1;
  reg  [31:0] es_alu_src2;
  reg  [31:0] es_rkd_value;
  reg         es_res_from_mem;
  reg         es_gr_we;
  reg         es_mem_we;
  reg  [ 4:0] es_dest;
  reg         es_is_mul;
  reg         es_is_div;
  reg         es_mul_signed;
  reg         es_mul_hi;
  reg         es_div_signed;
  reg         es_is_mod;
  reg         mul_cnt;
  reg         es_ld_byte;
  reg         es_ld_half;
  reg         es_ld_sign_ext;
  reg         es_st_byte;
  reg         es_st_half;
  reg         es_inst_syscall;
  reg         es_inst_ertn;
  reg         es_csr_re;
  reg         es_csr_we;
  reg  [13:0] es_csr_num;
  reg  [31:0] es_csr_wmask;
  reg         es_inst_break;
  reg         es_has_adef;
  reg         es_has_ine;
  reg         es_is_rdcnt;
  reg  [ 1:0] es_rdcnt_sel;


  wire [31:0] ds_pc;
  wire [11:0] ds_alu_op;
  wire [31:0] ds_alu_src1;
  wire [31:0] ds_alu_src2;
  wire [31:0] ds_rkd_value;
  wire        ds_res_from_mem;
  wire        ds_gr_we;
  wire        ds_mem_we;
  wire [ 4:0] ds_dest;
  wire        ds_is_mul;
  wire        ds_is_div;
  wire        ds_mul_signed;
  wire        ds_mul_hi;
  wire        ds_div_signed;
  wire        ds_is_mod;
  wire        ds_ld_byte;
  wire        ds_ld_half;
  wire        ds_ld_sign_ext;
  wire        ds_st_byte;
  wire        ds_st_half;
  wire        ds_inst_syscall;
  wire        ds_inst_break;
  wire        ds_inst_ertn;
  wire        ds_csr_re;
  wire        ds_csr_we;
  wire [13:0] ds_csr_num;
  wire [31:0] ds_csr_wmask;
  wire        ds_has_adef;
  wire        ds_has_ine;
  wire        ds_is_rdcnt;
  wire [ 1:0] ds_rdcnt_sel;
  assign {ds_pc, ds_alu_op, ds_alu_src1, ds_alu_src2, ds_rkd_value,
          ds_res_from_mem, ds_gr_we, ds_mem_we, ds_dest,
          ds_is_mul, ds_is_div, ds_mul_signed, ds_mul_hi,
          ds_div_signed, ds_is_mod,
          ds_ld_byte, ds_ld_half, ds_ld_sign_ext,
          ds_st_byte, ds_st_half,
          ds_inst_syscall, ds_inst_break, ds_inst_ertn,
          ds_csr_re, ds_csr_we, ds_csr_num, ds_csr_wmask,
          ds_has_adef, ds_has_ine, ds_is_rdcnt, ds_rdcnt_sel} = ds_to_es_bus;


  wire [31:0] alu_result;

  // 乘除法
  wire [63:0] mul_product;
  wire [31:0] div_quotient;
  wire [31:0] div_remainder;
  wire        div_complete;
  wire        div_en;


  // 流水线控制
  wire   mul_result_ready = !es_is_mul       || mul_cnt;
  wire   div_result_ready = !es_is_div       || div_complete;
  wire   es_ready_go      = mul_result_ready && div_result_ready;
  assign es_allowin       = !es_valid        || (es_ready_go && ms_allowin);
  assign es_to_ms_valid   = es_valid         && es_ready_go;

  // EXE 的结果
  wire [31:0] es_final_result = es_is_mul ? (es_mul_hi ? mul_product[63:32] : mul_product[31:0]) :
       es_is_div ? (es_is_mod ? div_remainder : div_quotient) :
       alu_result;

  // 前递信号
  wire es_fwd_valid = !es_res_from_mem && !es_csr_re && !es_is_rdcnt &&
       !(es_is_mul && !mul_cnt) && !(es_is_div && !div_complete);
  assign es_fwd_bus = {es_valid, es_gr_we, es_fwd_valid,
                       (es_res_from_mem | es_csr_re), es_dest, es_final_result};
  assign es_to_ms_bus = {es_pc,
                         es_final_result,
                         es_rkd_value,
                         es_res_from_mem,
                         es_gr_we,
                         es_mem_we,
                         es_dest,
                         es_ld_byte,
                         es_ld_half,
                         es_ld_sign_ext,
                         es_st_byte,
                         es_st_half,
                         es_inst_syscall,
                         es_inst_break,
                         es_inst_ertn,
                         es_csr_re,
                         es_csr_we,
                         es_csr_num,
                         es_csr_wmask,
                         es_has_adef,
                         es_has_ine,
                         es_is_rdcnt,
                         es_rdcnt_sel
                        };

  // 异常检测: 有异常时不启动乘除法
  wire es_has_any_ex = es_has_adef || es_has_ine || es_inst_syscall || es_inst_break;

  // 除法器使能
  assign div_en = es_valid && es_is_div && !div_complete && !es_has_any_ex;


  always @(posedge clk)
  begin
    if (reset)
      es_valid <= 1'b0;
    else if (ws_flush)
      es_valid <= 1'b0;
    else if (es_allowin)
      es_valid <= ds_to_es_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      es_pc           <= 32'b0;
      es_gr_we        <= 1'b0;
      es_mem_we       <= 1'b0;
      es_res_from_mem <= 1'b0;
      es_dest         <= 5'b0;
      es_alu_op       <= 12'b0;
      es_alu_src1     <= 32'b0;
      es_alu_src2     <= 32'b0;
      es_rkd_value    <= 32'b0;
      es_is_mul       <= 1'b0;
      es_is_div       <= 1'b0;
      es_mul_signed   <= 1'b0;
      es_mul_hi       <= 1'b0;
      es_div_signed   <= 1'b0;
      es_is_mod       <= 1'b0;
      es_ld_byte      <= 1'b0;
      es_ld_half      <= 1'b0;
      es_ld_sign_ext  <= 1'b0;
      es_st_byte      <= 1'b0;
      es_st_half      <= 1'b0;
      es_inst_syscall <= 1'b0;
      es_inst_ertn    <= 1'b0;
      es_csr_re       <= 1'b0;
      es_csr_we       <= 1'b0;
      es_csr_num      <= 14'b0;
      es_csr_wmask    <= 32'b0;
      es_inst_break   <= 1'b0;
      es_has_adef     <= 1'b0;
      es_has_ine      <= 1'b0;
      es_is_rdcnt     <= 1'b0;
      es_rdcnt_sel    <= 2'b0;
    end
    else if (es_allowin)
    begin
      if (ds_to_es_valid)
      begin
        es_pc           <= ds_pc;
        es_alu_op       <= ds_alu_op;
        es_alu_src1     <= ds_alu_src1;
        es_alu_src2     <= ds_alu_src2;
        es_rkd_value    <= ds_rkd_value;
        es_res_from_mem <= ds_res_from_mem;
        es_gr_we        <= ds_gr_we;
        es_mem_we       <= ds_mem_we;
        es_dest         <= ds_dest;
        es_is_mul       <= ds_is_mul;
        es_is_div       <= ds_is_div;
        es_mul_signed   <= ds_mul_signed;
        es_mul_hi       <= ds_mul_hi;
        es_div_signed   <= ds_div_signed;
        es_is_mod       <= ds_is_mod;
        es_ld_byte      <= ds_ld_byte;
        es_ld_half      <= ds_ld_half;
        es_ld_sign_ext  <= ds_ld_sign_ext;
        es_st_byte      <= ds_st_byte;
        es_st_half      <= ds_st_half;
        es_inst_syscall <= ds_inst_syscall;
        es_inst_break   <= ds_inst_break;
        es_inst_ertn    <= ds_inst_ertn;
        es_csr_re       <= ds_csr_re;
        es_csr_we       <= ds_csr_we;
        es_csr_num      <= ds_csr_num;
        es_csr_wmask    <= ds_csr_wmask;
        es_has_adef     <= ds_has_adef;
        es_has_ine      <= ds_has_ine;
        es_is_rdcnt     <= ds_is_rdcnt;
        es_rdcnt_sel    <= ds_rdcnt_sel;
      end
      else //如果没有新信号，赋0防止误操作
      begin
        es_gr_we        <= 1'b0;
        es_mem_we       <= 1'b0;
        es_is_mul       <= 1'b0;
        es_is_div       <= 1'b0;
        es_inst_syscall <= 1'b0;
        es_inst_break   <= 1'b0;
        es_inst_ertn    <= 1'b0;
        es_csr_re       <= 1'b0;
        es_csr_we       <= 1'b0;
        es_has_adef     <= 1'b0;
        es_has_ine      <= 1'b0;
        es_is_rdcnt     <= 1'b0;
      end
    end
  end

  //乘法流水线计数器
  always @(posedge clk)
  begin
    if (reset)
      mul_cnt <= 1'b0;
    else if (es_allowin)
      mul_cnt <= 1'b0;
    else if (es_is_mul && !mul_cnt)
      mul_cnt <= 1'b1;
  end

  alu u_alu(
        .alu_op     (es_alu_op  ),
        .alu_src1   (es_alu_src1),
        .alu_src2   (es_alu_src2),
        .alu_result (alu_result )
      );

  multiplier u_mul(
               .mul_clk   (clk          ),
               .resetn    (resetn       ),
               .mul_signed(es_mul_signed),
               .x         (es_alu_src1  ),
               .y         (es_alu_src2  ),
               .result    (mul_product  )
             );

  divider u_div(
            .div_clk   (clk          ),
            .resetn    (resetn       ),
            .div       (div_en       ),
            .div_signed(es_div_signed),
            .x         (es_alu_src1  ),
            .y         (es_alu_src2  ),
            .s         (div_quotient ),
            .r         (div_remainder),
            .complete  (div_complete )
          );

endmodule
