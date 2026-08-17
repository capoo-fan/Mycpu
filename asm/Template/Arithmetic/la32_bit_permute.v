`timescale 1ns / 1ps
`default_nettype none

// Combinational LA32S shift/permutation core.
// operation: 0=ROTR.W, 1=BITREV.W, 2=BITREV.4B, 3=REVB.2H,
//            4=BYTEPICK.W.
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
            OP_ROTR: begin
                if (shift_amount == 5'd0)
                    result = operand_a;
                else
                    result = (operand_a >> shift_amount) |
                             (operand_a << (6'd32 - shift_amount));
            end

            OP_BITREV_W: begin
                for (index = 0; index < 32; index = index + 1)
                    result[index] = operand_a[31-index];
            end

            OP_BITREV_4B: begin
                result[7:0]   = reverse_byte(operand_a[7:0]);
                result[15:8]  = reverse_byte(operand_a[15:8]);
                result[23:16] = reverse_byte(operand_a[23:16]);
                result[31:24] = reverse_byte(operand_a[31:24]);
            end

            OP_REVB_2H:
                result = {operand_a[23:16], operand_a[31:24],
                          operand_a[7:0],   operand_a[15:8]};

            OP_BYTEPICK_W: begin
                // LA32S BYTEPICK.W concatenates rk behind rj and selects a
                // four-byte window.  Here operand_a=rj, operand_b=rk and
                // shift_amount[1:0]=sa2.
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
