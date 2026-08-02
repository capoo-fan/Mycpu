module alu #(
    parameter HAS_MUL = 1
  )(
    input  wire        clk,
    input  wire        resetn,
    input  wire [11:0] alu_op,
    input  wire [31:0] alu_src1,
    input  wire [31:0] alu_src2,
    input  wire [31:0] mul_src1,
    input  wire [31:0] mul_src2,
    output wire [31:0] alu_result,
    output wire [31:0] alu_fast_result,
    output wire [31:0] mul_result
  );

  wire op_add;
  wire op_sub;
  wire op_slt;
  wire op_sltu;
  wire op_and;
  wire op_nor;
  wire op_or;
  wire op_xor;
  wire op_sll;
  wire op_srl;
  wire op_sra;
  wire op_lui;


  assign op_add  = alu_op[ 0];
  assign op_sub  = alu_op[ 1];
  assign op_slt  = alu_op[ 2];
  assign op_sltu = alu_op[ 3];
  assign op_and  = alu_op[ 4];
  assign op_nor  = alu_op[ 5];
  assign op_or   = alu_op[ 6];
  assign op_xor  = alu_op[ 7];
  assign op_sll  = alu_op[ 8];
  assign op_srl  = alu_op[ 9];
  assign op_sra  = alu_op[10];
  assign op_lui  = alu_op[11];

  wire [31:0] add_sub_result;
  wire [31:0] slt_result;
  wire [31:0] sltu_result;
  wire [31:0] and_result;
  wire [31:0] nor_result;
  wire [31:0] or_result;
  wire [31:0] xor_result;
  wire [31:0] lui_result;
  wire [31:0] sll_result;
  wire [63:0] sr64_result;
  wire [31:0] sr_result;

  wire [31:0] mul_low_result;


  wire        do_sub;
  wire [31:0] addsub_b;
  wire        signed_less;
  wire        unsigned_less;

  assign do_sub         = op_sub;
  assign addsub_b       = do_sub ? ~alu_src2 : alu_src2;
  assign add_sub_result = alu_src1 + addsub_b + do_sub;

  assign signed_less    = $signed(alu_src1) < $signed(alu_src2);
  assign unsigned_less  = alu_src1 < alu_src2;
  assign slt_result     = {31'b0, signed_less};
  assign sltu_result    = {31'b0, unsigned_less};


  assign and_result = alu_src1 & alu_src2;
  assign or_result  = alu_src1 | alu_src2 ;
  assign nor_result = ~or_result;
  assign xor_result = alu_src1 ^ alu_src2;
  assign lui_result = alu_src2;

  // SLL result
  assign sll_result = alu_src1 << alu_src2[4:0];   //rj << i5

  // SRL, SRA result
  assign sr64_result = {{32{op_sra & alu_src1[31]}}, alu_src1[31:0]} >> alu_src2[4:0]; //rj >> i5

  assign sr_result   = sr64_result[31:0];

  // 两个 lane 使用同构的三拍 Xilinx 乘法 IP。MUL.W 只保留乘积低
  // 32 位，因此 IP 配置为 32x32 无符号乘法；是否实例化由 EX 参数决定。
  generate
    if (HAS_MUL)
    begin: gen_multiplier
      mult_gen_0 u_mult_gen_0 (
                   .CLK (clk     ),
                   .A   (mul_src1),
                   .B   (mul_src2),
                   .P   (mul_low_result)
                 );
    end
    else
    begin: gen_no_multiplier
      assign mul_low_result = 32'b0;
    end
  endgenerate


  assign mul_result = mul_low_result;

  // ADD/SUB 是 EX->ISSUE->EX 零气泡前递的主导关键路径。保留一条
  // 不经过十路 ALU 结果归并树的等价旁路，供 EX 前递使用；完整的
  // alu_result 仍送往 MEM/WB，因而不改变流水级或提交语义。
  assign alu_fast_result = add_sub_result;

  // final result mux
  assign alu_result = ({32{op_add|op_sub}} & add_sub_result)
         | ({32{op_slt       }} & slt_result)
         | ({32{op_sltu      }} & sltu_result)
         | ({32{op_and       }} & and_result)
         | ({32{op_nor       }} & nor_result)
         | ({32{op_or        }} & or_result)
         | ({32{op_xor       }} & xor_result)
         | ({32{op_lui       }} & lui_result)
         | ({32{op_sll       }} & sll_result)
         | ({32{op_srl|op_sra}} & sr_result);

endmodule
