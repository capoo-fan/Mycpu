// ============================================================================
// 32位乘法器 — 基数-4 Booth编码 + Wallace树 + 流水线
// ============================================================================
// 核心思路:
//   1. 将操作数符号/零扩展为 33 位, 统一转化为有符号乘法
//   2. 对乘数 y 做基数-4 (2位) Booth编码, 产生 17 个部分积
//   3. 使用 Wallace 树 (3:2 压缩器) 将 18 个加数压缩为 2 个
//   4. 最终用一次加法 + 流水线寄存器输出结果
//
// 无符号乘法的实现方式:
//   当 mul_signed=0 时, 将 32 位操作数零扩展为 33 位 (MSB=0),
//   作为正的有符号数参与补码乘法, 结果低 64 位即为无符号乘积.
// ============================================================================

// ---------------------------------------------------------------------------
// 3:2 压缩器 (Carry-Save Adder)
// ---------------------------------------------------------------------------
module compressor_3_2 (
    input  [65:0] in1,
    input  [65:0] in2,
    input  [65:0] in3,
    output [65:0] out_sum,
    output [65:0] out_carry
  );
  assign out_sum   = in1 ^ in2 ^ in3;
  assign out_carry = {(in1[64:0] & in2[64:0]) |
                      (in2[64:0] & in3[64:0]) |
                      (in1[64:0] & in3[64:0]), 1'b0};
endmodule

// ---------------------------------------------------------------------------
// 乘法器顶层
// ---------------------------------------------------------------------------
module multiplier(
    input  wire        mul_clk,    // 时钟
    input  wire        resetn,     // 复位
    input  wire        mul_signed, // 1有符号, 0无符号
    input  wire [31:0] x,          // 被乘数
    input  wire [31:0] y,          // 乘数
    output wire [63:0] result      // 64位乘积
  );

  // 加0把无符号数当有符号数操作
  wire [32:0] x_ext = mul_signed ? {x[31], x} : {1'b0, x};
  wire [32:0] y_ext = mul_signed ? {y[31], y} : {1'b0, y};

  // Booth 编码
  // Booth 编码表:
  // y_(i+1) | y_i |  y_(i-1) | 操作
  //    0    |  0  |    0     | 0
  //    0    |  0  |    1     | +x
  //    0    |  1  |    0     | +x
  //    0    |  1  |    1     | +2x
  //    1    |  0  |    0     | -2x
  //    1    |  0  |    1     | -x
  //    1    |  1  |    0     | -x
  //    1    |  1  |    1     | 0


  wire [33:0] y_pad = {y_ext[32], y_ext}; // 34 位 (符号扩展)

  // 被乘数的 1 倍和 2 倍 (均为 34 位)
  wire [33:0] x_1 = {x_ext[32], x_ext};   // sign_extend(x_ext) → 34 位
  wire [33:0] x_2 = {x_ext, 1'b0};        // x_ext << 1        → 34 位

  // ----- Booth 编码信号 -----
  wire [16:0] booth_neg;  // Booth 数字为负
  wire [16:0] booth_one;  // |Booth 数字| = 1
  wire [16:0] booth_two;  // |Booth 数字| = 2

  genvar gi;
  generate
    for (gi = 0; gi < 17; gi = gi + 1)
    begin : booth_enc
      wire y_hi  = y_pad[2*gi+1];
      wire y_mid = y_pad[2*gi];
      wire y_lo  = (gi == 0) ? 1'b0 : y_pad[2*gi-1];

      assign booth_neg[gi] = y_hi;
      assign booth_one[gi] = y_mid ^ y_lo;
      assign booth_two[gi] = (y_hi ^ y_mid) & ~(y_mid ^ y_lo);
    end
  endgenerate

  // 部分积
  // 每个部分积 34 位, 按位异或处理取反 (neg), 再符号扩展+移位到 66 位.
  // 另外收集 17 个 neg 修正位组成第 18 个加数.

  wire [65:0] pp [0:17]; // 0–16: Booth 部分积, 17: 修正字

  generate
    for (gi = 0; gi < 17; gi = gi + 1)
    begin : pp_gen
      // 选择 |d|·x : 0 / x / 2x
      wire [33:0] sel = ({34{booth_one[gi]}} & x_1)
           | ({34{booth_two[gi]}} & x_2);
      // 取反实现取负 (配合修正位 +1)
      wire [33:0] pp_val = sel ^ {34{booth_neg[gi]}};

      // 符号扩展到 66 位并左移 2*gi 位
      if (gi == 0)
      begin : shift_0
        assign pp[0] = {{32{pp_val[33]}}, pp_val};
      end
      else if (gi == 1)
      begin : shift_1
        assign pp[1] = {{30{pp_val[33]}}, pp_val, 2'b0};
      end
      else if (gi == 2)
      begin : shift_2
        assign pp[2] = {{28{pp_val[33]}}, pp_val, 4'b0};
      end
      else if (gi == 3)
      begin : shift_3
        assign pp[3] = {{26{pp_val[33]}}, pp_val, 6'b0};
      end
      else if (gi == 4)
      begin : shift_4
        assign pp[4] = {{24{pp_val[33]}}, pp_val, 8'b0};
      end
      else if (gi == 5)
      begin : shift_5
        assign pp[5] = {{22{pp_val[33]}}, pp_val, 10'b0};
      end
      else if (gi == 6)
      begin : shift_6
        assign pp[6] = {{20{pp_val[33]}}, pp_val, 12'b0};
      end
      else if (gi == 7)
      begin : shift_7
        assign pp[7] = {{18{pp_val[33]}}, pp_val, 14'b0};
      end
      else if (gi == 8)
      begin : shift_8
        assign pp[8] = {{16{pp_val[33]}}, pp_val, 16'b0};
      end
      else if (gi == 9)
      begin : shift_9
        assign pp[9] = {{14{pp_val[33]}}, pp_val, 18'b0};
      end
      else if (gi == 10)
      begin : shift_10
        assign pp[10] = {{12{pp_val[33]}}, pp_val, 20'b0};
      end
      else if (gi == 11)
      begin : shift_11
        assign pp[11] = {{10{pp_val[33]}}, pp_val, 22'b0};
      end
      else if (gi == 12)
      begin : shift_12
        assign pp[12] = {{8{pp_val[33]}}, pp_val, 24'b0};
      end
      else if (gi == 13)
      begin : shift_13
        assign pp[13] = {{6{pp_val[33]}}, pp_val, 26'b0};
      end
      else if (gi == 14)
      begin : shift_14
        assign pp[14] = {{4{pp_val[33]}}, pp_val, 28'b0};
      end
      else if (gi == 15)
      begin : shift_15
        assign pp[15] = {{2{pp_val[33]}}, pp_val, 30'b0};
      end
      else
      begin : shift_16
        assign pp[16] = {pp_val, 32'b0};
      end
    end
  endgenerate

  //  每个 neg 位放在 2*i 的位置上 -----
  assign pp[17] = {33'b0,
                   booth_neg[16], 1'b0, booth_neg[15], 1'b0, booth_neg[14], 1'b0, booth_neg[13], 1'b0,
                   booth_neg[12], 1'b0, booth_neg[11], 1'b0, booth_neg[10], 1'b0, booth_neg[ 9], 1'b0,
                   booth_neg[ 8], 1'b0, booth_neg[ 7], 1'b0, booth_neg[ 6], 1'b0, booth_neg[ 5], 1'b0,
                   booth_neg[ 4], 1'b0, booth_neg[ 3], 1'b0, booth_neg[ 2], 1'b0, booth_neg[ 1], 1'b0,
                   booth_neg[ 0]};

  // =====================================================================
  // 第四步: Wallace 树压缩 (18 个加数 → 2 个)
  // =====================================================================
  //  层级1: 18 → 12  (6 个 CSA)
  //  层级2: 12 →  8  (4 个 CSA)
  //  层级3:  8 →  6  (2 个 CSA + 2 直通)
  //  层级4:  6 →  4  (2 个 CSA)
  //  层级5:  4 →  3  (1 个 CSA + 1 直通)
  //  层级6:  3 →  2  (1 个 CSA)

  // ----- 层级 1: 18 → 12 -----
  wire [65:0] s1_0, c1_0, s1_1, c1_1, s1_2, c1_2;
  wire [65:0] s1_3, c1_3, s1_4, c1_4, s1_5, c1_5;

  compressor_3_2 csa1_0 (.in1(pp[ 0]), .in2(pp[ 1]), .in3(pp[ 2]), .out_sum(s1_0), .out_carry(c1_0));
  compressor_3_2 csa1_1 (.in1(pp[ 3]), .in2(pp[ 4]), .in3(pp[ 5]), .out_sum(s1_1), .out_carry(c1_1));
  compressor_3_2 csa1_2 (.in1(pp[ 6]), .in2(pp[ 7]), .in3(pp[ 8]), .out_sum(s1_2), .out_carry(c1_2));
  compressor_3_2 csa1_3 (.in1(pp[ 9]), .in2(pp[10]), .in3(pp[11]), .out_sum(s1_3), .out_carry(c1_3));
  compressor_3_2 csa1_4 (.in1(pp[12]), .in2(pp[13]), .in3(pp[14]), .out_sum(s1_4), .out_carry(c1_4));
  compressor_3_2 csa1_5 (.in1(pp[15]), .in2(pp[16]), .in3(pp[17]), .out_sum(s1_5), .out_carry(c1_5));

  // ----- 层级 2: 12 → 8 -----
  wire [65:0] s2_0, c2_0, s2_1, c2_1, s2_2, c2_2, s2_3, c2_3;

  compressor_3_2 csa2_0 (.in1(s1_0), .in2(c1_0), .in3(s1_1), .out_sum(s2_0), .out_carry(c2_0));
  compressor_3_2 csa2_1 (.in1(c1_1), .in2(s1_2), .in3(c1_2), .out_sum(s2_1), .out_carry(c2_1));
  compressor_3_2 csa2_2 (.in1(s1_3), .in2(c1_3), .in3(s1_4), .out_sum(s2_2), .out_carry(c2_2));
  compressor_3_2 csa2_3 (.in1(c1_4), .in2(s1_5), .in3(c1_5), .out_sum(s2_3), .out_carry(c2_3));

  // ----- 层级 3: 8 → 6 (2 CSA, 2 直通) -----
  wire [65:0] s3_0, c3_0, s3_1, c3_1;

  compressor_3_2 csa3_0 (.in1(s2_0), .in2(c2_0), .in3(s2_1), .out_sum(s3_0), .out_carry(c3_0));
  compressor_3_2 csa3_1 (.in1(c2_1), .in2(s2_2), .in3(c2_2), .out_sum(s3_1), .out_carry(c3_1));
  // 直通: s2_3, c2_3

  // ----- 层级 4: 6 → 4 -----
  wire [65:0] s4_0, c4_0, s4_1, c4_1;

  compressor_3_2 csa4_0 (.in1(s3_0), .in2(c3_0), .in3(s3_1), .out_sum(s4_0), .out_carry(c4_0));
  compressor_3_2 csa4_1 (.in1(c3_1), .in2(s2_3), .in3(c2_3), .out_sum(s4_1), .out_carry(c4_1));

  // ----- 层级 5: 4 → 3 (1 CSA, 1 直通) -----
  wire [65:0] s5_0, c5_0;

  compressor_3_2 csa5_0 (.in1(s4_0), .in2(c4_0), .in3(s4_1), .out_sum(s5_0), .out_carry(c5_0));
  // 直通: c4_1

  // ----- 层级 6: 3 → 2 -----
  wire [65:0] s6_0, c6_0;

  compressor_3_2 csa6_0 (.in1(s5_0), .in2(c5_0), .in3(c4_1), .out_sum(s6_0), .out_carry(c6_0));

  // =====================================================================
  // 第五步: 最终加法 + 流水线寄存器
  // =====================================================================
  wire [65:0] product = s6_0 + c6_0;

  reg [65:0] result_r;
  always @(posedge mul_clk)
  begin
    if (!resetn)
      result_r <= 66'd0;
    else
      result_r <= product;
  end

  assign result = result_r[63:0];

endmodule
