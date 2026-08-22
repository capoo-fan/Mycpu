`timescale 1ns / 1ps
`default_nettype none
`include "la32_arithmetic_ops.vh"

// 与 Template/Map/accelerator_logic.v 逐元素接口匹配的适配器。
// OPERATION 取 contest_arithmetic_unit 的操作码之一。执行 ISQRT 时忽略
// OPERAND_B；执行 DIV/MOD 时，OPERAND_B 提供固定的第二操作数。
module arithmetic_map_adapter #(
    parameter [2:0]  OPERATION = `LA32_ARITH_OP_ISQRT,
    parameter [31:0] OPERAND_B = 32'd1,
    parameter        USE_AUXILIARY = 1'b0
)(
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] out_data
);

    wire [31:0] primary_result;
    wire [31:0] auxiliary_result;
    wire unused_divide_by_zero;
    wire unused_overflow;
    wire unused_invalid_operation;

    assign out_data = USE_AUXILIARY ? auxiliary_result : primary_result;

    // 兼容旧的 3 位算术 Map 入口。
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
        .rsp_result            (primary_result),
        .rsp_auxiliary         (auxiliary_result),
        .rsp_divide_by_zero    (unused_divide_by_zero),
        .rsp_overflow          (unused_overflow),
        .rsp_invalid_operation (unused_invalid_operation)
    );

endmodule

`default_nettype wire
