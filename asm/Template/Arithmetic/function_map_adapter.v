`timescale 1ns / 1ps
`default_nettype none
`include "la32_function_ops.vh"

// Per-element adapter matching Template/Map/accelerator_logic.v.
// in_data is operand_a; operand_b and control fields are compile-time constants.
module function_map_adapter #(
    parameter [7:0]  OPERATION = `LA32_FUNC_OP_BITREV_W,
    parameter [31:0] OPERAND_B = 32'b0,
    parameter [4:0]  CONTROL_LSB = 5'b0,
    parameter [4:0]  CONTROL_MSB = 5'b0
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
    wire unused_invalid_control;

    contest_function_unit u_function_unit (
        .clk                   (clk),
        .resetn                (resetn),
        .req_valid             (in_valid),
        .req_ready             (in_ready),
        .req_operation         (OPERATION),
        .req_operand_a         (in_data),
        .req_operand_b         (OPERAND_B),
        .req_lsb               (CONTROL_LSB),
        .req_msb               (CONTROL_MSB),
        .rsp_valid             (out_valid),
        .rsp_ready             (1'b1),
        .rsp_result            (out_data),
        .rsp_auxiliary         (unused_auxiliary),
        .rsp_divide_by_zero    (unused_divide_by_zero),
        .rsp_overflow          (unused_overflow),
        .rsp_invalid_operation (unused_invalid_operation),
        .rsp_invalid_control   (unused_invalid_control)
    );

endmodule

`default_nettype wire
