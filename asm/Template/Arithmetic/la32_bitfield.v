`timescale 1ns / 1ps
`default_nettype none

// Combinational LA32S bit-field core.
// operation: 0=BSTRPICK.W, 1=BSTRINS.W.
//
// For BSTRPICK.W: operand_a is rj.
// For BSTRINS.W:  operand_a is the old rd and operand_b is rj.
module la32_bitfield (
    input  wire        operation,
    input  wire [31:0] operand_a,
    input  wire [31:0] operand_b,
    input  wire [4:0]  msb,
    input  wire [4:0]  lsb,
    output reg  [31:0] result,
    output reg         invalid_control
);

    localparam OP_BSTRPICK = 1'b0;
    localparam OP_BSTRINS  = 1'b1;

    reg [5:0]  field_width;
    reg [31:0] low_mask;
    reg [31:0] field_mask;

    always @(*) begin
        result          = 32'b0;
        invalid_control = 1'b0;
        field_width     = 6'd0;
        low_mask        = 32'b0;
        field_mask      = 32'b0;

        if (msb < lsb) begin
            invalid_control = 1'b1;
        end
        else begin
            field_width   = {1'b0, msb} - {1'b0, lsb} + 6'd1;
            // A 32-bit shift by 32 produces zero; subtracting one then gives
            // the required all-ones mask for a full-width field.
            low_mask      = (32'b1 << field_width) - 32'b1;
            field_mask    = low_mask << lsb;

            case (operation)
                OP_BSTRPICK:
                    result = (operand_a >> lsb) & low_mask;
                OP_BSTRINS:
                    result = (operand_a & ~field_mask) |
                             ((operand_b << lsb) & field_mask);
            endcase
        end
    end

endmodule

`default_nettype wire
