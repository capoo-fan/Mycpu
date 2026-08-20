`timescale 1ns / 1ps
`default_nettype none

// LA32S 组合逻辑移位/重排核心。
// 操作编码：0=ROTR.W，1=BITREV.W，2=BITREV.4B，3=REVB.2H，
//           4=BYTEPICK.W。
module la32_bit_permute (
    input  wire [2:0]  operation,
    input  wire [31:0] operand_a,
    input  wire [31:0] operand_b,
    input  wire [4:0]  shift_amount,
    output reg  [31:0] result,
    output reg         invalid_operation
);

    localparam [2:0]
        OP_ROTR       = 3'd0,
        OP_BITREV_W   = 3'd1,
        OP_BITREV_4B  = 3'd2,
        OP_REVB_2H    = 3'd3,
        OP_BYTEPICK_W = 3'd4;

    integer index;

    function [7:0] reverse_byte;
        input [7:0] value;
        integer bit_index;
        begin
            for (bit_index = 0; bit_index < 8; bit_index = bit_index + 1)
                reverse_byte[bit_index] = value[7-bit_index];
        end
    endfunction

    always @(*) begin
        result            = 32'b0;
        invalid_operation = 1'b0;

        case (operation)
            // ROTR.W：将 operand_a 循环右移 shift_amount 位。
            OP_ROTR: begin
                if (shift_amount == 5'd0)
                    result = operand_a;
                else
                    result = (operand_a >> shift_amount) |
                             (operand_a << (6'd32 - shift_amount));
            end

            // BITREV.W：反转 operand_a 中全部 32 位的排列顺序。
            OP_BITREV_W: begin
                for (index = 0; index < 32; index = index + 1)
                    result[index] = operand_a[31-index];
            end

            // BITREV.4B：分别反转 operand_a 四个字节内部的 8 位排列顺序。
            OP_BITREV_4B: begin
                result[7:0]   = reverse_byte(operand_a[7:0]);
                result[15:8]  = reverse_byte(operand_a[15:8]);
                result[23:16] = reverse_byte(operand_a[23:16]);
                result[31:24] = reverse_byte(operand_a[31:24]);
            end

            // REVB.2H：分别交换 operand_a 两个半字内部的高、低字节。
            OP_REVB_2H:
                result = {operand_a[23:16], operand_a[31:24],
                          operand_a[7:0],   operand_a[15:8]};

            OP_BYTEPICK_W: begin
                // BYTEPICK.W：从 operand_a 与 operand_b 的拼接值中选取连续四字节。
                // LA32S BYTEPICK.W 将 rk 拼接在 rj 之后，并选择一个四字节窗口。
                // 此处 operand_a=rj、operand_b=rk、shift_amount[1:0]=sa2。
                case (shift_amount[1:0])
                    2'd0: result = operand_b;
                    2'd1: result = {operand_b[23:0], operand_a[31:24]};
                    2'd2: result = {operand_b[15:0], operand_a[31:16]};
                    2'd3: result = {operand_b[7:0],  operand_a[31:8]};
                endcase
            end

            default:
                invalid_operation = 1'b1;
        endcase
    end

endmodule

`default_nettype wire
