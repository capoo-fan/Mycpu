`include "mycpu.vh"

module IF_stage(
    input  wire        clk,
    input  wire        resetn,
    input  wire        ds_allowin,
    input  wire        br_taken,     //跳转信号
    input  wire [31:0] br_target,    //跳转目标地址
    input  wire [31:0] pred_target,
    output wire        fs_to_ds_valid,
    output wire [`FS_TO_DS_BUS_WD-1:0] fs_to_ds_bus,

    // 类SRAM 指令接口
    input  wire        inst_sram_addr_ok, // sram 可以接受地址
    input  wire        inst_sram_data_ok,
    input  wire [31:0] inst_sram_rdata,
    output wire        inst_sram_req,
    output wire [31:0] inst_sram_addr
  );
  reg         reset;
  always @(posedge clk)
    reset <= ~resetn;

  // PC 寄存器
  reg  [31:0] pc;
  wire [31:0] nextpc;

  // 握手状态
  reg         fs_wait_data;   // 请求已被接受, 等待 Data
  reg  [31:0] fs_pc_r;        // 锁存在途请求的 PC
  reg  [31:0] fs_pred_target_r; // 锁存在途请求对应的预测目标
  reg         fs_cancel;      // 在途请求需要取消 (遇到分支或冲刷)

  // 指令缓冲区，ID 无法接收时暂存指令
  reg         fs_buf_valid;
  reg  [31:0] fs_buf_inst;
  reg  [31:0] fs_buf_pc;
  reg  [31:0] fs_buf_pred_target;

  assign nextpc  = br_taken ? br_target : pred_target;


  assign inst_sram_req   = !reset && !fs_wait_data && !fs_buf_valid; //不在复位，无在途请求，缓冲区为空
  assign inst_sram_addr  = pc;

  // 握手成功信号
  wire got_addr_ok = inst_sram_req && inst_sram_addr_ok;
  wire got_data_ok = fs_wait_data  && inst_sram_data_ok;

  wire fresh_inst_valid = got_data_ok && !fs_cancel; //指令返回且未被取消
  wire fs_valid    = fs_buf_valid || fresh_inst_valid;
  wire fs_ready_go = 1'b1;
  assign fs_to_ds_valid = fs_valid && fs_ready_go && !br_taken;

  wire [31:0] fs_pc_out   = fs_buf_valid ? fs_buf_pc   : fs_pc_r;
  wire [31:0] fs_inst_out = fs_buf_valid ? fs_buf_inst  : inst_sram_rdata;
  wire [31:0] fs_pred_target_out = fs_buf_valid ? fs_buf_pred_target : fs_pred_target_r;

  // 输出总线: {fs_pc[31:0], fs_inst[31:0], pred_target[31:0]}
  assign fs_to_ds_bus = {fs_pc_out, fs_inst_out, fs_pred_target_out};

  // PC 更新逻辑
  always @(posedge clk)
  begin
    if (reset)
      pc <= 32'h1c000000;
    else if (br_taken)
      pc <= br_target;
    else if (got_addr_ok)
      pc <= nextpc;
  end

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

  // 记录在途请求对应的预测目标
  always @(posedge clk)
  begin
    if (reset)
      fs_pred_target_r <= 32'b0;
    else if (got_addr_ok)
      fs_pred_target_r <= nextpc;
  end

  // 取消标志: 请求在途但发生分支/冲刷
  always @(posedge clk)
  begin
    if (reset)
      fs_cancel <= 1'b0;
    else if (got_data_ok)
      fs_cancel <= 1'b0;
    else if ((got_addr_ok || fs_wait_data) && br_taken)
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
      fs_buf_pred_target <= 32'b0;
    end
    else if (br_taken)
    begin
      fs_buf_valid <= 1'b0;           // 冲刷缓冲
    end
    else if (fresh_inst_valid && !ds_allowin)
    begin
      // data_ok 到来但 ID 不能接收, 缓存指令
      fs_buf_valid <= 1'b1;
      fs_buf_inst  <= inst_sram_rdata;
      fs_buf_pc    <= fs_pc_r;
      fs_buf_pred_target <= fs_pred_target_r;
    end
    else if (fs_buf_valid && ds_allowin)
    begin
      fs_buf_valid <= 1'b0;           // 缓冲指令被 ID 接收
    end
  end

endmodule
