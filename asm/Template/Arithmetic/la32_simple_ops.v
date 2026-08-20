`timescale 1ns / 1ps
`default_nettype none

// 小型 LA32S 组合逻辑辅助单元。
// 操作编码：0=ANDN，1=ORN，2=MASKEQZ，3=MASKNEZ，4=ALSL.W，
//           5=EXT.W.B，6=EXT.W.H。
module la32_simple_ops (
    input  wire [2:0]  operation,
    input  wire [31:0] operand_a,
    input  wire [31:0] operand_b,
    input  wire [1:0]  shift_amount,
    output reg  [31:0] result,
    output reg         invalid_operation
);

    always @(*) begin
        result            = 32'b0;
        invalid_operation = 1'b0;

        case (operation)
            // ANDN：operand_a 与 operand_b 按位取反后的结果进行按位与。
            3'd0: result = operand_a & ~operand_b;
            // ORN：operand_a 与 operand_b 按位取反后的结果进行按位或。
            3'd1: result = operand_a | ~operand_b;
            // MASKEQZ：operand_b 等于 0 时结果清零，否则保留 operand_a。
            3'd2: result = (operand_b == 32'b0) ? 32'b0 : operand_a;
            // MASKNEZ：operand_b 不等于 0 时结果清零，否则保留 operand_a。
            3'd3: result = (operand_b != 32'b0) ? 32'b0 : operand_a;
            // ALSL.W：operand_a 左移 shift_amount+1 位后与 operand_b 相加。
            3'd4: result =
                (operand_a << ({1'b0, shift_amount} + 3'd1)) + operand_b;
            // EXT.W.B：将 operand_a 的低 8 位符号扩展为 32 位。
            3'd5: result = {{24{operand_a[7]}}, operand_a[7:0]};
            // EXT.W.H：将 operand_a 的低 16 位符号扩展为 32 位。
            3'd6: result = {{16{operand_a[15]}}, operand_a[15:0]};
            default: invalid_operation = 1'b1;
        endcase
    end

endmodule

`default_nettype wire
