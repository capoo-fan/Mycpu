`timescale 1ns / 1ps
`default_nettype none

// Arithmetic 目录中所有操作的统一 Map 接入层。
//
// 无论选择哪一种操作，调用方始终使用同一组源码和以下固定接口。OPERATION、
// OPERAND_B、CONTROL_LSB、CONTROL_MSB 均为编译期参数；in_data 固定映射到
// operand_a。每接受一个输入，最终恰好返回一个输出。
//
// USE_AUXILIARY=0 返回操作的主结果；USE_AUXILIARY=1 返回辅助结果。例如：
// DIV 返回余数、ISQRT 返回平方余数、MUL*_FULL 返回乘积高 32 位。
module accelerator_logic
 (
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] out_data
);

 wire [15:0] root;
 wire [31:0] remainder;

  assign out_data = {16'b0, root};

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
endmodule






`default_nettype wire
