`include "mycpu.vh"

module MEM_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         es_to_ms_valid,
    input  wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus,
    input  wire                         ws_allowin,
    output wire                         ms_allowin,
    output wire                         ms_to_ws_valid,
    output wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus,
    output wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus,
    output wire                         br_taken,
    output wire [31:0]                  br_target,
    output wire                         bpu_valid,
    output wire                         bpu_is_bj,
    output wire [31:0]                  bpu_pc,
    output wire                         bpu_real_taken,
    output wire [31:0]                  bpu_real_target,
    output wire                         bpu_is_call,
    output wire                         bpu_is_ret,
    output wire [31:0]                  bpu_ret_addr,
    // 类SRAM 数据接口
    output wire                         data_sram_req,
    output wire                         data_sram_wr,
    output wire [ 1:0]                  data_sram_size,
    output wire [ 3:0]                  data_sram_wstrb,
    output wire [31:0]                  data_sram_addr,
    output wire [31:0]                  data_sram_wdata,
    input  wire                         data_sram_addr_ok,
    input  wire                         data_sram_data_ok,
    input  wire [31:0]                  data_sram_rdata
  );

  // 内部信号
  reg         reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ms_valid;
  reg  [31:0] ms_pc;
  reg  [31:0] ms_alu_result;
  reg  [31:0] ms_rkd_value;
  reg         ms_res_from_mem;
  reg         ms_gr_we;
  reg         ms_mem_we;
  reg  [ 4:0] ms_dest;
  reg         ms_ld_byte;
  reg         ms_ld_half;
  reg         ms_ld_sign_ext;
  reg         ms_st_byte;
  reg         ms_st_half;
  reg  [31:0] ms_alu_src1;
  reg         ms_pred_taken;
  reg  [31:0] ms_pred_target;
  reg  [ 3:0] ms_br_op;
  reg  [31:0] ms_br_offs;
  reg         ms_is_call;
  reg         ms_is_ret;

  // 总线解包
  wire [31:0] es_pc;
  wire [31:0] es_final_result;
  wire [31:0] es_rkd_value;
  wire        es_res_from_mem;
  wire        es_gr_we;
  wire        es_mem_we;
  wire [ 4:0] es_dest;
  wire        es_ld_byte;
  wire        es_ld_half;
  wire        es_ld_sign_ext;
  wire        es_st_byte;
  wire        es_st_half;
  wire [31:0] es_alu_src1;
  wire        es_pred_taken;
  wire [31:0] es_pred_target;
  wire [ 3:0] es_br_op;
  wire [31:0] es_br_offs;
  wire        es_is_call;
  wire        es_is_ret;

  assign {es_pc, es_final_result, es_rkd_value,
          es_res_from_mem, es_gr_we, es_mem_we, es_dest,
          es_ld_byte, es_ld_half, es_ld_sign_ext,
          es_st_byte, es_st_half,
          es_alu_src1, es_pred_taken, es_pred_target, es_br_op, es_br_offs,
          es_is_call, es_is_ret} = es_to_ms_bus;

  wire ms_has_mem_op = ms_valid && (ms_res_from_mem || ms_mem_we);

  // ms_addr_sent: 本条指令的请求是否已被接受
  reg  ms_addr_sent;

  // 已发出但没返回的数据
  reg  ms_data_pending;

  // 缓存 rdata
  reg         ms_rdata_buf_valid;
  reg  [31:0] ms_rdata_buf;

  // 请求握手
  wire got_addr_ok = data_sram_req && data_sram_addr_ok;
  // 当前指令的数据返回
  wire ms_data_ok  = ms_addr_sent && data_sram_data_ok;

  // 流水线控制
  wire   ms_ready_go    = !ms_has_mem_op || ms_rdata_buf_valid || ms_data_ok;
  assign ms_allowin     = !ms_valid || (ms_ready_go && ws_allowin);
  assign ms_to_ws_valid = ms_valid && ms_ready_go;
  wire   ms_fire        = ms_valid && ms_ready_go && ws_allowin;

  assign ms_fwd_bus = {ms_valid, ms_gr_we, ms_res_from_mem, ms_dest, ms_alu_result};

  wire ms_is_bj = (ms_br_op != `BR_NONE);
  wire ms_rj_eq_rkd          = (ms_alu_src1 == ms_rkd_value);
  wire ms_rj_lt_rkd_signed   = ($signed(ms_alu_src1) < $signed(ms_rkd_value));
  wire ms_rj_lt_rkd_unsigned = (ms_alu_src1 < ms_rkd_value);

  wire ms_real_taken = ((ms_br_op == `BR_BEQ)  &&  ms_rj_eq_rkd          ||
                        (ms_br_op == `BR_BNE)  && !ms_rj_eq_rkd          ||
                        (ms_br_op == `BR_BLT)  &&  ms_rj_lt_rkd_signed   ||
                        (ms_br_op == `BR_BGE)  && !ms_rj_lt_rkd_signed   ||
                        (ms_br_op == `BR_BLTU) &&  ms_rj_lt_rkd_unsigned ||
                        (ms_br_op == `BR_BGEU) && !ms_rj_lt_rkd_unsigned ||
                        (ms_br_op == `BR_JIRL) ||
                        (ms_br_op == `BR_BL)   ||
                        (ms_br_op == `BR_B)) && ms_is_bj;
  wire [31:0] ms_pc_br_target   = ms_pc + ms_br_offs;
  wire [31:0] ms_jirl_br_target = ms_rkd_value + ms_br_offs;
  wire [31:0] ms_real_target    = (ms_br_op == `BR_JIRL) ? ms_jirl_br_target :
       ms_pc_br_target;
  wire [31:0] ms_next_pc        = ms_pc + 32'h4;

  wire ms_taken_miss  = ms_real_taken ^ ms_pred_taken;
  wire ms_target_miss = ms_real_taken && ms_pred_taken &&
       (ms_real_target != ms_pred_target);
  wire ms_redirect    = ms_fire && ms_is_bj && (ms_taken_miss || ms_target_miss);

  assign br_taken  = ms_redirect;
  assign br_target = ms_redirect ? (ms_real_taken ? ms_real_target : ms_next_pc) :
         32'b0;

  assign bpu_valid       = ms_fire;
  assign bpu_is_bj       = ms_fire && ms_is_bj;
  assign bpu_pc          = ms_pc;
  assign bpu_real_taken  = ms_real_taken;
  assign bpu_real_target = ms_real_target;
  assign bpu_is_call     = ms_fire && ms_is_bj && ms_real_taken && ms_is_call;
  assign bpu_is_ret      = ms_fire && ms_is_bj && ms_real_taken && ms_is_ret;
  assign bpu_ret_addr    = ms_next_pc;

  // Store 数据通道和写使能
  wire [31:0] ms_st_data = ms_st_byte ? {4{ms_rkd_value[7:0]}} :
       ms_st_half ? {2{ms_rkd_value[15:0]}} :
       ms_rkd_value;
  wire [ 3:0] ms_st_strb = ms_st_byte ? (4'b0001 << ms_alu_result[1:0]) :
       ms_st_half ? (ms_alu_result[1] ? 4'b1100 : 4'b0011) :
       4'b1111;
  wire [ 1:0] ms_mem_size = (ms_ld_byte || ms_st_byte) ? 2'b00 :
       (ms_ld_half || ms_st_half) ? 2'b01 :
       2'b10;

  // 发请求条件: 有访存操作, 本条地址未被接受, 无旧数据未返
  assign data_sram_req   = ms_has_mem_op && !ms_addr_sent && !ms_data_pending;
  assign data_sram_wr    = ms_mem_we;
  assign data_sram_size  = ms_mem_size;
  assign data_sram_wstrb = ms_mem_we ? ms_st_strb : 4'b0;
  assign data_sram_addr  = ms_alu_result;
  assign data_sram_wdata = ms_st_data;


  wire [31:0] ms_final_rdata = ms_rdata_buf_valid ? ms_rdata_buf : data_sram_rdata;

  assign ms_to_ws_bus = {ms_pc,
                         ms_alu_result,
                         ms_res_from_mem,
                         ms_gr_we,
                         ms_dest,
                         ms_ld_byte,
                         ms_ld_half,
                         ms_ld_sign_ext,
                         ms_final_rdata
                        };


  // ms_valid
  always @(posedge clk)
  begin
    if (reset)
      ms_valid <= 1'b0;
    else if (ms_allowin)
      ms_valid <= es_to_ms_valid;
  end


  always @(posedge clk)
  begin
    if (reset)
      ms_addr_sent <= 1'b0;
    else if (ms_allowin)
      ms_addr_sent <= 1'b0;
    else if (got_addr_ok)
      ms_addr_sent <= 1'b1;
  end

  // ms_data_pending: sram_wrap 中是否有未返回的数据
  always @(posedge clk)
  begin
    if (reset)
      ms_data_pending <= 1'b0;
    else if (got_addr_ok)
      ms_data_pending <= 1'b1;
    else if (ms_data_pending && data_sram_data_ok)
      ms_data_pending <= 1'b0;
  end

  // ms_rdata_buf_valid: 缓冲数据有效标志
  // data_ok 到来时设置, 新指令进入或冲刷时清除
  always @(posedge clk)
  begin
    if (reset)
      ms_rdata_buf_valid <= 1'b0;
    else if (ms_allowin)
      ms_rdata_buf_valid <= 1'b0;
    else if (ms_data_ok)
      ms_rdata_buf_valid <= 1'b1;
  end

  // 缓存 Data
  always @(posedge clk)
  begin
    if (ms_data_ok)
      ms_rdata_buf <= data_sram_rdata;
  end

  // 流水线寄存器
  always @(posedge clk)
  begin
    if (reset)
    begin
      ms_pc           <= 32'b0;
      ms_gr_we        <= 1'b0;
      ms_mem_we       <= 1'b0;
      ms_res_from_mem <= 1'b0;
      ms_dest         <= 5'b0;
      ms_alu_result   <= 32'b0;
      ms_rkd_value    <= 32'b0;
      ms_ld_byte      <= 1'b0;
      ms_ld_half      <= 1'b0;
      ms_ld_sign_ext  <= 1'b0;
      ms_st_byte      <= 1'b0;
      ms_st_half      <= 1'b0;
      ms_alu_src1     <= 32'b0;
      ms_pred_taken   <= 1'b0;
      ms_pred_target  <= 32'b0;
      ms_br_op        <= `BR_NONE;
      ms_br_offs      <= 32'b0;
      ms_is_call      <= 1'b0;
      ms_is_ret       <= 1'b0;
    end
    else if (ms_allowin)
    begin
      if (es_to_ms_valid)
      begin
        ms_pc           <= es_pc;
        ms_alu_result   <= es_final_result;
        ms_rkd_value    <= es_rkd_value;
        ms_res_from_mem <= es_res_from_mem;
        ms_gr_we        <= es_gr_we;
        ms_mem_we       <= es_mem_we;
        ms_dest         <= es_dest;
        ms_ld_byte      <= es_ld_byte;
        ms_ld_half      <= es_ld_half;
        ms_ld_sign_ext  <= es_ld_sign_ext;
        ms_st_byte      <= es_st_byte;
        ms_st_half      <= es_st_half;
        ms_alu_src1     <= es_alu_src1;
        ms_pred_taken   <= es_pred_taken;
        ms_pred_target  <= es_pred_target;
        ms_br_op        <= es_br_op;
        ms_br_offs      <= es_br_offs;
        ms_is_call      <= es_is_call;
        ms_is_ret       <= es_is_ret;
      end
      else
      begin
        ms_gr_we        <= 1'b0;
        ms_mem_we       <= 1'b0;
        ms_res_from_mem <= 1'b0;
        ms_br_op        <= `BR_NONE;
        ms_is_call      <= 1'b0;
        ms_is_ret       <= 1'b0;
      end
    end
  end

endmodule
