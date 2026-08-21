`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// Map 型加速器的组合算法逻辑模板。
//
// array_accel_engine 负责地址、数组遍历和 SRAM-like 访存，本模块只实现
// out_data = F(in_data)。固定壳每拍都能接受一个输入，并在同拍给出组合结果，
// 使读响应能够直接衔接写请求。若算法需要寄存流水或多周期计算，请改用
// Template/Handshake/Map。
// ============================================================================

module accelerator_logic (
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output reg  [31:0] out_data
);

    assign in_ready  = 1'b1;
    assign out_valid = in_valid;

    always @(*) begin
        // ====================================================================
        // >>>>>>>>>>>>>>> USER MODIFY REGION BEGIN <<<<<<<<<<<<<<<<<<<<<<<<<<<
        //
        // 当前默认示例：F(x) = x。
        // 这里必须是无状态组合映射，不能改变 out_valid 的同拍返回约定。
        // ====================================================================

        out_data = in_data;

        // ====================================================================
        // >>>>>>>>>>>>>>>> USER MODIFY REGION END <<<<<<<<<<<<<<<<<<<<<<<<<<
        // ====================================================================
    end

    wire unused = &{1'b0, clk, resetn};

endmodule

`default_nettype wire
