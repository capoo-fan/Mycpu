`timescale 1ns / 1ps
`default_nettype none
`include "la32_arithmetic_ops.vh"

// Adapter matching Template/Map/accelerator_logic.v's per-element interface.
// OPERATION is one of contest_arithmetic_unit's operation codes.  For ISQRT,
// OPERAND_B is ignored; for DIV/MOD it supplies the constant second operand.
module arithmetic_map_adapter #(
    parameter [2:0]  OPERATION = `LA32_ARITH_OP_ISQRT,
    parameter [31:0] OPERAND_B = 32'd1
)(
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] out_data
);

    wire [31:0] unused_auxiliary;
    wire unused_divide_by_zero;
    wire unused_overflow;
    wire unused_invalid_operation;

    contest_arithmetic_unit u_arithmetic_unit (
        .clk                   (clk),
        .resetn                (resetn),
        .req_valid             (in_valid),
        .req_ready             (in_ready),
        .req_operation         (OPERATION),
        .req_operand_a         (in_data),
        .req_operand_b         (OPERAND_B),
        .rsp_valid             (out_valid),
        .rsp_ready             (1'b1),
        .rsp_result            (out_data),
        .rsp_auxiliary         (unused_auxiliary),
        .rsp_divide_by_zero    (unused_divide_by_zero),
        .rsp_overflow          (unused_overflow),
        .rsp_invalid_operation (unused_invalid_operation)
    );

endmodule

`default_nettype wire
