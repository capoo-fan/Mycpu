// ============================================================================
// 除法器模块 (工业级迭代实现)
// ============================================================================
// 采用恢复余数法 (Restoring Division Algorithm)
// 支持有符号和无符号 32 位除法
// 除法运算需要 33 个时钟周期 (1 周期初始化 + 32 周期迭代)
// ============================================================================
module divider(
    input  wire        div_clk,    // 除法器模块时钟信号
    input  wire        resetn,     // 复位信号，低电平有效
    input  wire        div,        // 除法运算命令
    input  wire        div_signed, // 控制有符号除法和无符号除法的信号
    input  wire [31:0] x,          // 被除数
    input  wire [31:0] y,          // 除数
    output wire [31:0] s,          // 除法结果，商
    output wire [31:0] r,          // 除法结果，余数
    output wire        complete    // 除法完成信号，除法内部 count 计算达到 33
  );

  // -----------------------------------------------------------------------
  // 被除数 | 除数 | 商 | 余数
  //  正       正   正    正
  //  正       负   负    正
  //  负       正   负    负
  //  负       负   正    负
  // -----------------------------------------------------------------------
  reg         busy;           // 除法器信号
  reg  [5:0]  cnt;            // 迭代计数器 (0~32)
  reg  [63:0] rq;             // {余数[31:0], 商[31:0]} 移位寄存器
  reg  [31:0] divisor_result; // 锁存的除数绝对值
  reg         sign_q;         // 被除数与除数异号则为负
  reg         sign_result;    // 与被除数同号
  reg         complete_result;// 完成信号
  reg  [31:0] s_result;       // 商
  reg  [31:0] r_result;       // 余数

  // 无符号取绝对值
  wire [31:0] x_abs = (div_signed && x[31]) ? (~x + 32'd1) : x;
  wire [31:0] y_abs = (div_signed && y[31]) ? (~y + 32'd1) : y;

  // 恢复余数法
  // 每次迭代：
  //   1. 将 {余数, 商} 左移 1 位
  //   2. 试减: trial = 移位后余数 - 除数
  //   3. 若 trial >= 0: 余数 = trial, 商最低位 = 1
  //      若 trial <  0: 保持原值(恢复), 商最低位 = 0
  // -----------------------------------------------------------------------
  wire [63:0] rq_shl  = {rq[62:0], 1'b0};                          // 左移
  wire [32:0] trial   = {1'b0, rq_shl[63:32]} - {1'b0, divisor_result}; // 试减

  always @(posedge div_clk)
  begin
    if (!resetn)
    begin
      busy            <= 1'b0;
      cnt             <= 6'd0;
      complete_result <= 1'b0;
      rq              <= 64'd0;
      divisor_result  <= 32'd0;
      sign_q          <= 1'b0;
      sign_result     <= 1'b0;
      s_result        <= 32'd0;
      r_result        <= 32'd0;
    end
    else
    begin
      if (!busy)
      begin
        if (div)
        begin
          busy             <= 1'b1;
          cnt              <= 6'd0;
          rq               <= {32'd0, x_abs};   // 余数初始化为 0，商初始化为被除数绝对值
          divisor_result   <= y_abs;
          sign_q           <= div_signed && (x[31] ^ y[31]);
          sign_result      <= div_signed && x[31];
          complete_result  <= 1'b0;
        end
        else
        begin
          complete_result <= 1'b0; // 不是除法则清零
        end
      end
      else
      begin
        if (cnt < 6'd32) //32个周期迭代
        begin
          cnt <= cnt + 6'd1;
          if (!trial[32])
          begin
            rq <= {trial[31:0], rq_shl[31:1], 1'b1};
          end
          else
          begin
            rq <= rq_shl;
          end
        end
        else
        begin
          busy       <= 1'b0;
          complete_result <= 1'b1;
          // 根据符号标志修正商和余数
          s_result <= sign_q ? (~rq[31:0]  + 32'd1) : rq[31:0];
          r_result <= sign_result ? (~rq[63:32] + 32'd1) : rq[63:32];
        end
      end
    end
  end

  assign s        = s_result;
  assign r        = r_result;
  assign complete = complete_result;

endmodule
