`timescale 1ns / 1ps
`default_nettype none

// Small combinational LA32S helpers.
// operation: 0=ANDN, 1=ORN, 2=MASKEQZ, 3=MASKNEZ, 4=ALSL.W,
//            5=EXT.W.B, 6=EXT.W.H.
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
            3'd0: result = operand_a & ~operand_b;
            3'd1: result = operand_a | ~operand_b;
            3'd2: result = (operand_b == 32'b0) ? 32'b0 : operand_a;
            3'd3: result = (operand_b != 32'b0) ? 32'b0 : operand_a;
            3'd4: result =
                (operand_a << ({1'b0, shift_amount} + 3'd1)) + operand_b;
            3'd5: result = {{24{operand_a[7]}}, operand_a[7:0]};
            3'd6: result = {{16{operand_a[15]}}, operand_a[15:0]};
            default: invalid_operation = 1'b1;
        endcase
    end

endmodule

`default_nettype wire
