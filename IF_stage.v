`include "mycpu.vh"

module IF_stage(
    input  wire        clk,
    input  wire        resetn,
    input  wire        ds_allowin,
    input  wire        br_taken,
    input  wire [31:0] br_target,
    input  wire        ws_flush, //异常冲刷
    input  wire [31:0] ws_flush_pc,
    output wire        fs_to_ds_valid,
    output wire [`FS_TO_DS_BUS_WD-1:0] fs_to_ds_bus,
    // 类SRAM 指令接口
    output wire        inst_sram_req,
    output wire        inst_sram_wr,
    output wire [ 1:0] inst_sram_size,
    output wire [ 3:0] inst_sram_wstrb,
    output wire [31:0] inst_sram_addr,
    output wire [31:0] inst_sram_wdata,
    input  wire        inst_sram_addr_ok,
    input  wire        inst_sram_data_ok,
    input  wire [31:0] inst_sram_rdata
  );
  reg         reset;
  always @(posedge clk) reset <= ~resetn;

  // PC 寄存器
  reg  [31:0] pc;
  wire [31:0] seq_pc;
  wire [31:0] nextpc;

  // 握手状态
  reg         fs_wait_data;   // 请求已被接受, 等待 data_ok
  reg  [31:0] fs_pc_r;        // 正在等待返回的请求对应的 PC
  reg         fs_cancel;      // 在途请求需要取消 (分支/冲刷)

  // 指令缓冲 (当 data_ok 到来但 ID 不能接收时)
  reg         fs_buf_valid;
  reg  [31:0] fs_buf_inst;
  reg  [31:0] fs_buf_pc;

  assign seq_pc  = pc + 32'h4;
  assign nextpc  = ws_flush ? ws_flush_pc : (br_taken ? br_target : seq_pc);


  assign inst_sram_req   = !reset && !fs_wait_data && !fs_buf_valid; //不在复位，无在途请求，缓冲区为空
  assign inst_sram_wr    = 1'b0;
  assign inst_sram_size  = 2'b10;       // 始终取 4 字节
  assign inst_sram_wstrb = 4'b0;
  assign inst_sram_addr  = pc;
  assign inst_sram_wdata = 32'b0;

  // 握手成功信号
  wire got_addr_ok = inst_sram_req && inst_sram_addr_ok;
  wire got_data_ok = fs_wait_data  && inst_sram_data_ok; 

  wire fresh_inst_valid = got_data_ok && !fs_cancel; //当数据已返回且数据未被取消

  // 流水线控制
  wire fs_valid    = fs_buf_valid || fresh_inst_valid;
  wire fs_ready_go = 1'b1;
  assign fs_to_ds_valid = fs_valid && fs_ready_go && !br_taken && !ws_flush;

  wire [31:0] fs_pc_out   = fs_buf_valid ? fs_buf_pc   : fs_pc_r;
  wire [31:0] fs_inst_out = fs_buf_valid ? fs_buf_inst  : inst_sram_rdata;

  // ADEF 检测: PC 未对齐 (PC[1:0] != 0)
  wire fs_has_adef = (fs_pc_out[1:0] != 2'b00);

  // ADEF 时使用安全指令, 防止 X 值从未初始化内存进入流水线
  wire [31:0] fs_inst_safe = fs_has_adef ? 32'b0 : fs_inst_out;

  // 输出总线: {fs_pc[31:0], fs_inst[31:0], has_adef}
  assign fs_to_ds_bus = {fs_pc_out, fs_inst_safe, fs_has_adef};

  // PC 更新: 仅在请求被接受时推进
  always @(posedge clk)
  begin
    if (reset)
      pc <= 32'h1c000000;
    else if (ws_flush)
      pc <= ws_flush_pc;
    else if (br_taken)
      pc <= br_target;
    else if (got_addr_ok)
      pc <= seq_pc;
  end

  // 在途请求状态跟踪
  always @(posedge clk)
  begin
    if (reset)
      fs_wait_data <= 1'b0;
    else if (got_addr_ok)
      fs_wait_data <= 1'b1;     // 请求被接受, 开始等待数据
    else if (got_data_ok)
      fs_wait_data <= 1'b0;     // 数据返回
  end

  // 记录在途请求的 PC
  always @(posedge clk)
  begin
    if (reset)
      fs_pc_r <= 32'b0;
    else if (got_addr_ok)
      fs_pc_r <= pc;
  end

  // 取消标志: 请求在途但发生分支/冲刷
  always @(posedge clk)
  begin
    if (reset)
      fs_cancel <= 1'b0;
    else if (got_data_ok)
      fs_cancel <= 1'b0;                   
    else if ((got_addr_ok || fs_wait_data) && (br_taken || ws_flush))
      fs_cancel <= 1'b1;            
  end

  // 指令缓冲管理
  always @(posedge clk)
  begin
    if (reset)
    begin
      fs_buf_valid <= 1'b0;
      fs_buf_pc    <= 32'b0;
      fs_buf_inst  <= 32'b0;
    end
    else if (br_taken || ws_flush)
    begin
      fs_buf_valid <= 1'b0;           // 冲刷缓冲
    end
    else if (fresh_inst_valid && !ds_allowin)
    begin
      // data_ok 到来但 ID 不能接收, 缓存指令
      fs_buf_valid <= 1'b1;
      fs_buf_inst  <= inst_sram_rdata;
      fs_buf_pc    <= fs_pc_r;
    end
    else if (fs_buf_valid && ds_allowin)
    begin
      fs_buf_valid <= 1'b0;           // 缓冲指令被 ID 接收
    end
  end

endmodule
