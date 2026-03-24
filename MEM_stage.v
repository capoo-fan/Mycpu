`include "mycpu.vh"

module MEM_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         es_to_ms_valid,
    input  wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus,
    input  wire                         ws_allowin,
    // 异常冲刷
    input  wire                         ws_flush,
    output wire                         ms_allowin,
    output wire                         ms_to_ws_valid,
    output wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus,
    output wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus,
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
  reg         ms_inst_syscall;
  reg         ms_inst_break;
  reg         ms_inst_ertn;
  reg         ms_csr_re;
  reg         ms_csr_we;
  reg  [13:0] ms_csr_num;
  reg  [31:0] ms_csr_wmask;
  reg         ms_has_adef;
  reg         ms_has_ine;
  reg         ms_is_rdcnt;
  reg  [ 1:0] ms_rdcnt_sel;

  // 解包 es_to_ms_bus
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
  wire        es_inst_syscall;
  wire        es_inst_break;
  wire        es_inst_ertn;
  wire        es_csr_re;
  wire        es_csr_we;
  wire [13:0] es_csr_num;
  wire [31:0] es_csr_wmask;
  wire        es_has_adef;
  wire        es_has_ine;
  wire        es_is_rdcnt;
  wire [ 1:0] es_rdcnt_sel;

  assign {es_pc, es_final_result, es_rkd_value,
          es_res_from_mem, es_gr_we, es_mem_we, es_dest,
          es_ld_byte, es_ld_half, es_ld_sign_ext,
          es_st_byte, es_st_half,
          es_inst_syscall, es_inst_break, es_inst_ertn,
          es_csr_re, es_csr_we, es_csr_num, es_csr_wmask,
          es_has_adef, es_has_ine, es_is_rdcnt, es_rdcnt_sel} = es_to_ms_bus;

  // 握手状态跟踪
  // ALE 检测: 地址对齐异常
  wire ms_ld_word = ms_res_from_mem && !ms_ld_byte && !ms_ld_half;
  wire ms_st_word = ms_mem_we && !ms_st_byte && !ms_st_half;
  wire ms_has_ale = (ms_ld_word || ms_st_word) ? (ms_alu_result[1:0] != 2'b00) :
                    (ms_ld_half || ms_st_half) ? (ms_alu_result[0] != 1'b0) :
                    1'b0;

  // 异常检测: 有异常时不发起访存请求
  wire ms_has_any_ex = ms_has_adef || ms_has_ine || ms_inst_syscall || ms_inst_break || ms_has_ale;
  wire ms_has_mem_op = ms_valid && (ms_res_from_mem || ms_mem_we) && !ms_has_any_ex;

  // ms_addr_sent: 本条指令的请求是否已被接受
  reg  ms_addr_sent;

  // ms_data_pending: sram_wrap 中是否有未返回的数据
  //   (跨冲刷保持, 防止新请求与旧响应混淆)
  reg  ms_data_pending;

  // 数据返回缓冲: 当 data_ok 到来但 WB 不能接收时, 缓存 rdata
  reg         ms_rdata_buf_valid;
  reg  [31:0] ms_rdata_buf;

  // 请求握手
  wire got_addr_ok = data_sram_req && data_sram_addr_ok;
  // 当前指令的数据返回
  wire ms_data_ok  = ms_addr_sent && data_sram_data_ok;

  // 流水线控制
  wire   ms_ready_go    = !ms_has_mem_op || ms_rdata_buf_valid || ms_data_ok;// 命令不访存或数据已经缓冲或数据准备好
  assign ms_allowin     = !ms_valid || ms_ready_go && ws_allowin;
  assign ms_to_ws_valid = ms_valid && ms_ready_go;

  assign ms_fwd_bus = {ms_valid, ms_gr_we, (ms_res_from_mem | ms_csr_re | ms_is_rdcnt), ms_dest, ms_alu_result};

  // Store 数据通道 & 写使能
  wire [31:0] ms_st_data = ms_st_byte ? {4{ms_rkd_value[7:0]}} :
       ms_st_half ? {2{ms_rkd_value[15:0]}} :
       ms_rkd_value;
  wire [ 3:0] ms_st_strb = ms_st_byte ? (4'b0001 << ms_alu_result[1:0]) :
       ms_st_half ? (ms_alu_result[1] ? 4'b1100 : 4'b0011) :
       4'b1111;

  // 访问大小
  wire [ 1:0] ms_mem_size = (ms_ld_byte || ms_st_byte) ? 2'b00 :
       (ms_ld_half || ms_st_half) ? 2'b01 :
       2'b10;

  // 发请求条件: 有访存操作, 本条地址未被接受, 无旧数据未返, 未冲刷
  assign data_sram_req   = ms_has_mem_op && !ms_addr_sent && !ms_data_pending && !ws_flush;
  assign data_sram_wr    = ms_mem_we;
  assign data_sram_size  = ms_mem_size;
  assign data_sram_wstrb = ms_mem_we ? ms_st_strb : 4'b0;
  assign data_sram_addr  = ms_alu_result;
  assign data_sram_wdata = ms_st_data;


  // 优先使用缓冲的 rdata, 否则直接使用 data_sram_rdata
  wire [31:0] ms_final_rdata = ms_rdata_buf_valid ? ms_rdata_buf : data_sram_rdata;

  assign ms_to_ws_bus = {ms_pc,
                         ms_alu_result,
                         ms_res_from_mem,
                         ms_gr_we,
                         ms_dest,
                         ms_ld_byte,
                         ms_ld_half,
                         ms_ld_sign_ext,
                         ms_inst_syscall,
                         ms_inst_break,
                         ms_inst_ertn,
                         ms_csr_re,
                         ms_csr_we,
                         ms_csr_num,
                         ms_csr_wmask,
                         ms_rkd_value,
                         ms_final_rdata,
                         ms_has_adef,
                         ms_has_ine,
                         ms_is_rdcnt,
                         ms_rdcnt_sel,
                         ms_has_ale
                        };

  // 时序逻辑

  // ms_valid
  always @(posedge clk)
  begin
    if (reset)
      ms_valid <= 1'b0;
    else if (ws_flush)
      ms_valid <= 1'b0;
    else if (ms_allowin)
      ms_valid <= es_to_ms_valid;
  end

  // ms_addr_sent: 本条指令的请求是否已被接受 
  always @(posedge clk)
  begin
    if (reset)
      ms_addr_sent <= 1'b0;
    else if (ms_allowin || ws_flush)
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
    else if (ms_allowin || ws_flush)
      ms_rdata_buf_valid <= 1'b0;
    else if (ms_data_ok)
      ms_rdata_buf_valid <= 1'b1;
  end

  // ms_rdata_buf: 缓冲 data_sram_rdata
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
      ms_inst_syscall <= 1'b0;
      ms_inst_break   <= 1'b0;
      ms_inst_ertn    <= 1'b0;
      ms_csr_re       <= 1'b0;
      ms_csr_we       <= 1'b0;
      ms_csr_num      <= 14'b0;
      ms_csr_wmask    <= 32'b0;
      ms_has_adef     <= 1'b0;
      ms_has_ine      <= 1'b0;
      ms_is_rdcnt     <= 1'b0;
      ms_rdcnt_sel    <= 2'b0;
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
        ms_inst_syscall <= es_inst_syscall;
        ms_inst_break   <= es_inst_break;
        ms_inst_ertn    <= es_inst_ertn;
        ms_csr_re       <= es_csr_re;
        ms_csr_we       <= es_csr_we;
        ms_csr_num      <= es_csr_num;
        ms_csr_wmask    <= es_csr_wmask;
        ms_has_adef     <= es_has_adef;
        ms_has_ine      <= es_has_ine;
        ms_is_rdcnt     <= es_is_rdcnt;
        ms_rdcnt_sel    <= es_rdcnt_sel;
      end
      else
      begin
        ms_gr_we  <= 1'b0;
        ms_mem_we <= 1'b0;
        ms_inst_syscall <= 1'b0;
        ms_inst_break   <= 1'b0;
        ms_inst_ertn    <= 1'b0;
        ms_csr_re       <= 1'b0;
        ms_csr_we       <= 1'b0;
        ms_has_adef     <= 1'b0;
        ms_has_ine      <= 1'b0;
        ms_is_rdcnt     <= 1'b0;
        ms_res_from_mem <= 1'b0;
      end
    end
  end

endmodule
