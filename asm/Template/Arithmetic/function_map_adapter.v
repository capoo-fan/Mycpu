`timescale 1ns / 1ps
`default_nettype none

// 与 Template/Map/accelerator_logic.v 匹配的逐元素适配器。
// in_data 对应 operand_a；operand_b 和控制字段均为编译期常量。
module function_map_adapter #(
    parameter [7:0]  OPERATION = 8'h11,
    parameter [31:0] OPERAND_B = 32'b0,
    parameter [4:0]  CONTROL_LSB = 5'b0,
    parameter [4:0]  CONTROL_MSB = 5'b0,
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
    wire unused_invalid_control;

    assign out_data = USE_AUXILIARY ? auxiliary_result : primary_result;

    // 兼容旧模块名；新的 Map 题目直接选择一个自带 accelerator_logic 的
    // la32_*.v 文件即可。
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
        .rsp_result            (primary_result),
        .rsp_auxiliary         (auxiliary_result),
        .rsp_divide_by_zero    (unused_divide_by_zero),
        .rsp_overflow          (unused_overflow),
        .rsp_invalid_operation (unused_invalid_operation),
        .rsp_invalid_control   (unused_invalid_control)
    );

endmodule

`default_nettype wire
