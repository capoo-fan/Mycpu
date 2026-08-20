`timescale 1ns / 1ps
`default_nettype none
`include "la32_function_ops.vh"

// Arithmetic 目录中所有操作的统一 Map 接入层。
//
// 无论选择哪一种操作，调用方始终使用同一组源码和以下固定接口。OPERATION、
// OPERAND_B、CONTROL_LSB、CONTROL_MSB 均为编译期参数；in_data 固定映射到
// operand_a。每接受一个输入，最终恰好返回一个输出。
//
// USE_AUXILIARY=0 返回操作的主结果；USE_AUXILIARY=1 返回辅助结果。例如：
// DIV 返回余数、ISQRT 返回平方余数、MUL*_FULL 返回乘积高 32 位。
module accelerator_logic #(
    parameter [7:0]  OPERATION = `LA32_FUNC_OP_ISQRT,
    parameter [31:0] OPERAND_B = 32'b0,
    parameter [4:0]  CONTROL_LSB = 5'b0,
    parameter [4:0]  CONTROL_MSB = 5'b0,
    parameter        USE_AUXILIARY = 1'b0
) (
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] out_data
);

    generate
        if ((OPERATION >= `LA32_FUNC_OP_UDIV) &&
            (OPERATION <= `LA32_FUNC_OP_SMOD)) begin : gen_divmod
            localparam RETURN_REMAINDER =
                (OPERATION == `LA32_FUNC_OP_UMOD) ||
                (OPERATION == `LA32_FUNC_OP_SMOD);

            wire [31:0] quotient;
            wire [31:0] remainder;
            wire [31:0] primary_result =
                RETURN_REMAINDER ? remainder : quotient;
            wire [31:0] auxiliary_result =
                RETURN_REMAINDER ? quotient : remainder;
            wire unused_divide_by_zero;
            wire unused_overflow;

            assign out_data = USE_AUXILIARY ?
                auxiliary_result : primary_result;

            la32_divmod u_selected_operation (
                .clk                (clk),
                .resetn             (resetn),
                .req_valid          (in_valid),
                .req_ready          (in_ready),
                .req_signed         ((OPERATION == `LA32_FUNC_OP_SDIV) ||
                                     (OPERATION == `LA32_FUNC_OP_SMOD)),
                .req_dividend       (in_data),
                .req_divisor        (OPERAND_B),
                .rsp_valid          (out_valid),
                .rsp_ready          (1'b1),
                .rsp_quotient       (quotient),
                .rsp_remainder      (remainder),
                .rsp_divide_by_zero (unused_divide_by_zero),
                .rsp_overflow       (unused_overflow)
            );
        end
        else if (OPERATION == `LA32_FUNC_OP_ISQRT) begin : gen_isqrt
            wire [15:0] root;
            wire [31:0] remainder;

            assign out_data = USE_AUXILIARY ?
                remainder : {16'b0, root};

            la32_isqrt u_selected_operation (
                .clk           (clk),
                .resetn        (resetn),
                .req_valid     (in_valid),
                .req_ready     (in_ready),
                .req_radicand  (in_data),
                .rsp_valid     (out_valid),
                .rsp_ready     (1'b1),
                .rsp_root      (root),
                .rsp_remainder (remainder)
            );
        end
        else if (OPERATION == `LA32_FUNC_OP_GCD) begin : gen_gcd
            wire [31:0] gcd_result;

            assign out_data = USE_AUXILIARY ? 32'b0 : gcd_result;

            la32_gcd u_selected_operation (
                .clk       (clk),
                .resetn    (resetn),
                .req_valid (in_valid),
                .req_ready (in_ready),
                .req_a     (in_data),
                .req_b     (OPERAND_B),
                .rsp_valid (out_valid),
                .rsp_ready (1'b1),
                .rsp_gcd   (gcd_result)
            );
        end
        else if ((OPERATION >= `LA32_FUNC_OP_CLZ) &&
                 (OPERATION <= `LA32_FUNC_OP_POPCOUNT)) begin : gen_count
            wire [31:0] core_result;
            wire [31:0] selected_result =
                USE_AUXILIARY ? 32'b0 : core_result;
            wire unused_invalid_operation;

            la32_bit_count u_selected_operation (
                .operation         (OPERATION[2:0]),
                .operand           (in_data),
                .result            (core_result),
                .invalid_operation (unused_invalid_operation)
            );

            arithmetic_map_result_register u_result_register (
                .clk        (clk),
                .resetn     (resetn),
                .in_valid   (in_valid),
                .in_ready   (in_ready),
                .in_result  (selected_result),
                .out_valid  (out_valid),
                .out_data   (out_data)
            );
        end
        else if ((OPERATION >= `LA32_FUNC_OP_ROTR) &&
                 (OPERATION <= `LA32_FUNC_OP_BYTEPICK_W)) begin : gen_permute
            wire [31:0] core_result;
            wire [31:0] selected_result =
                USE_AUXILIARY ? 32'b0 : core_result;
            wire unused_invalid_operation;

            la32_bit_permute u_selected_operation (
                .operation         (OPERATION[2:0]),
                .operand_a         (in_data),
                .operand_b         (OPERAND_B),
                .shift_amount      (CONTROL_LSB),
                .result            (core_result),
                .invalid_operation (unused_invalid_operation)
            );

            arithmetic_map_result_register u_result_register (
                .clk        (clk),
                .resetn     (resetn),
                .in_valid   (in_valid),
                .in_ready   (in_ready),
                .in_result  (selected_result),
                .out_valid  (out_valid),
                .out_data   (out_data)
            );
        end
        else if ((OPERATION >= `LA32_FUNC_OP_BSTRPICK_W) &&
                 (OPERATION <= `LA32_FUNC_OP_BSTRINS_W)) begin : gen_bitfield
            wire [31:0] core_result;
            wire [31:0] selected_result =
                USE_AUXILIARY ? 32'b0 : core_result;
            wire unused_invalid_control;

            la32_bitfield u_selected_operation (
                .operation       (OPERATION == `LA32_FUNC_OP_BSTRINS_W),
                .operand_a       (in_data),
                .operand_b       (OPERAND_B),
                .msb             (CONTROL_MSB),
                .lsb             (CONTROL_LSB),
                .result          (core_result),
                .invalid_control (unused_invalid_control)
            );

            arithmetic_map_result_register u_result_register (
                .clk        (clk),
                .resetn     (resetn),
                .in_valid   (in_valid),
                .in_ready   (in_ready),
                .in_result  (selected_result),
                .out_valid  (out_valid),
                .out_data   (out_data)
            );
        end
        else if ((OPERATION >= `LA32_FUNC_OP_MULU_FULL) &&
                 (OPERATION <= `LA32_FUNC_OP_MULS_FULL)) begin : gen_multiply
            wire [63:0] product;

            assign out_data = USE_AUXILIARY ?
                product[63:32] : product[31:0];

            la32_mul_full u_selected_operation (
                .clk           (clk),
                .resetn        (resetn),
                .req_valid     (in_valid),
                .req_ready     (in_ready),
                .req_signed    (OPERATION == `LA32_FUNC_OP_MULS_FULL),
                .req_operand_a (in_data),
                .req_operand_b (OPERAND_B),
                .rsp_valid     (out_valid),
                .rsp_ready     (1'b1),
                .rsp_product   (product)
            );
        end
        else if (((OPERATION >= `LA32_FUNC_OP_CRC32_B) &&
                  (OPERATION <= `LA32_FUNC_OP_CRC32_W)) ||
                 ((OPERATION >= `LA32_FUNC_OP_CRC32C_B) &&
                  (OPERATION <= `LA32_FUNC_OP_CRC32C_W))) begin : gen_crc
            localparam [1:0] CRC_WIDTH =
                ((OPERATION == `LA32_FUNC_OP_CRC32_B) ||
                 (OPERATION == `LA32_FUNC_OP_CRC32C_B)) ? 2'd0 :
                ((OPERATION == `LA32_FUNC_OP_CRC32_H) ||
                 (OPERATION == `LA32_FUNC_OP_CRC32C_H)) ? 2'd1 : 2'd2;

            wire [31:0] checksum;
            wire unused_invalid_width;

            assign out_data = USE_AUXILIARY ? 32'b0 : checksum;

            la32_crc32 u_selected_operation (
                .clk               (clk),
                .resetn            (resetn),
                .req_valid         (in_valid),
                .req_ready         (in_ready),
                .req_castagnoli    ((OPERATION >= `LA32_FUNC_OP_CRC32C_B) &&
                                    (OPERATION <= `LA32_FUNC_OP_CRC32C_W)),
                .req_width         (CRC_WIDTH),
                .req_message       (in_data),
                .req_seed          (OPERAND_B),
                .rsp_valid         (out_valid),
                .rsp_ready         (1'b1),
                .rsp_checksum      (checksum),
                .rsp_invalid_width (unused_invalid_width)
            );
        end
        else if ((OPERATION >= `LA32_FUNC_OP_ANDN) &&
                 (OPERATION <= `LA32_FUNC_OP_EXT_W_H)) begin : gen_simple
            wire [31:0] core_result;
            wire [31:0] selected_result =
                USE_AUXILIARY ? 32'b0 : core_result;
            wire unused_invalid_operation;

            la32_simple_ops u_selected_operation (
                .operation         (OPERATION[2:0]),
                .operand_a         (in_data),
                .operand_b         (OPERAND_B),
                .shift_amount      (CONTROL_LSB[1:0]),
                .result            (core_result),
                .invalid_operation (unused_invalid_operation)
            );

            arithmetic_map_result_register u_result_register (
                .clk        (clk),
                .resetn     (resetn),
                .in_valid   (in_valid),
                .in_ready   (in_ready),
                .in_result  (selected_result),
                .out_valid  (out_valid),
                .out_data   (out_data)
            );
        end
        else begin : gen_invalid_operation
            wire [31:0] invalid_result = in_data & 32'b0;

            arithmetic_map_result_register u_result_register (
                .clk        (clk),
                .resetn     (resetn),
                .in_valid   (in_valid),
                .in_ready   (in_ready),
                .in_result  (invalid_result),
                .out_valid  (out_valid),
                .out_data   (out_data)
            );
        end
    endgenerate

endmodule


// 组合操作共用的单入口结果寄存器，使其握手行为与迭代操作保持一致。
/* verilator lint_off DECLFILENAME */
module arithmetic_map_result_register (
    input  wire        clk,
    input  wire        resetn,
    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_result,
    output reg         out_valid,
    output reg  [31:0] out_data
);

    assign in_ready = !out_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            out_valid <= 1'b0;
            out_data  <= 32'b0;
        end
        else begin
            if (out_valid)
                out_valid <= 1'b0;

            if (in_valid && in_ready) begin
                out_valid <= 1'b1;
                out_data  <= in_result;
            end
        end
    end

endmodule
/* verilator lint_on DECLFILENAME */

`default_nettype wire
