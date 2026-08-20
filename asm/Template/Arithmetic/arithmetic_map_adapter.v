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

    // 兼容旧的 3 位算术操作码；所有新接入统一直接使用 accelerator_logic。
    accelerator_logic #(
        .OPERATION       ({5'b0, OPERATION}),
        .OPERAND_B       (OPERAND_B),
        .CONTROL_LSB     (5'b0),
        .CONTROL_MSB     (5'b0),
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
