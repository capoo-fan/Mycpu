`timescale 1ns / 1ps
`default_nettype none

// Combinational bit-count core.
// operation: 0=CLZ, 1=CLO, 2=CTZ, 3=CTO, 4=POPCOUNT.
// CLZ/CTZ of zero and CLO/CTO of all-ones return 32.
module la32_bit_count (
    input  wire [2:0]  operation,
    input  wire [31:0] operand,
    output reg  [31:0] result,
    output reg         invalid_operation
);

    localparam [2:0]
        OP_CLZ      = 3'd0,
        OP_CLO      = 3'd1,
        OP_CTZ      = 3'd2,
        OP_CTO      = 3'd3,
        OP_POPCOUNT = 3'd4;

    function [5:0] count_leading_zeros;
        input [31:0] value;
        reg [31:0] shifted;
        begin
            if (value == 32'b0) begin
                count_leading_zeros = 6'd32;
            end
            else begin
                count_leading_zeros = 6'd0;
                shifted = value;

                if (shifted[31:16] == 16'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd16;
                    shifted = shifted << 16;
                end
                if (shifted[31:24] == 8'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd8;
                    shifted = shifted << 8;
                end
                if (shifted[31:28] == 4'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd4;
                    shifted = shifted << 4;
                end
                if (shifted[31:30] == 2'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd2;
                    shifted = shifted << 2;
                end
                if (!shifted[31])
                    count_leading_zeros = count_leading_zeros + 6'd1;
            end
        end
    endfunction

    function [5:0] count_trailing_zeros;
        input [31:0] value;
        reg [31:0] shifted;
        begin
            if (value == 32'b0) begin
                count_trailing_zeros = 6'd32;
            end
            else begin
                count_trailing_zeros = 6'd0;
                shifted = value;

                if (shifted[15:0] == 16'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd16;
                    shifted = shifted >> 16;
                end
                if (shifted[7:0] == 8'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd8;
                    shifted = shifted >> 8;
                end
                if (shifted[3:0] == 4'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd4;
                    shifted = shifted >> 4;
                end
                if (shifted[1:0] == 2'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd2;
                    shifted = shifted >> 2;
                end
                if (!shifted[0])
                    count_trailing_zeros = count_trailing_zeros + 6'd1;
            end
        end
    endfunction

    function [5:0] population_count;
        input [31:0] value;
        reg [31:0] partial;
        begin
            // SWAR adder tree: pair, nibble, byte, halfword, word.
            partial = value - ((value >> 1) & 32'h5555_5555);
            partial = (partial & 32'h3333_3333) +
                      ((partial >> 2) & 32'h3333_3333);
            partial = (partial + (partial >> 4)) & 32'h0f0f_0f0f;
            partial = partial + (partial >> 8);
            partial = partial + (partial >> 16);
            population_count = partial[5:0];
        end
    endfunction

    always @(*) begin
        result            = 32'b0;
        invalid_operation = 1'b0;

        case (operation)
            OP_CLZ:
                result = {26'b0, count_leading_zeros(operand)};
            OP_CLO:
                result = {26'b0, count_leading_zeros(~operand)};
            OP_CTZ:
                result = {26'b0, count_trailing_zeros(operand)};
            OP_CTO:
                result = {26'b0, count_trailing_zeros(~operand)};
            OP_POPCOUNT:
                result = {26'b0, population_count(operand)};
            default:
                invalid_operation = 1'b1;
        endcase
    end

endmodule

`default_nettype wire
