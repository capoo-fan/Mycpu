`timescale 1ns / 1ps
`default_nettype none
`include "la32_function_ops.vh"

// 与 Template/Map/accelerator_logic.v 匹配的逐元素适配器。
// in_data 对应 operand_a；operand_b 和控制字段均为编译期常量。
module function_map_adapter #(
    parameter [7:0]  OPERATION = `LA32_FUNC_OP_BITREV_W,
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

    // 兼容旧模块名；所有新接入统一直接使用 accelerator_logic。
    accelerator_logic #(
        .OPERATION       (OPERATION),
        .OPERAND_B       (OPERAND_B),
        .CONTROL_LSB     (CONTROL_LSB),
        .CONTROL_MSB     (CONTROL_MSB),
        .USE_AUXILIARY   (USE_AUXILIARY)
    ) u_accelerator_logic (
        .clk       (clk),
        .resetn    (resetn),
        .in_valid  (in_valid),
        .in_ready  (in_ready),
        .in_data   (in_data),
        .out_valid (out_valid),
        .out_data  (out_data)
    );

endmodule

`default_nettype wire
