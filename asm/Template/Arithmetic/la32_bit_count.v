`timescale 1ns / 1ps
`default_nettype none

// Map 模板的单文件接入层。
// OPERATION：0=CLZ，1=CLO，2=CTZ，3=CTO，4=POPCOUNT。
`ifndef LA32_CORE_ONLY
module accelerator_logic #(
    parameter [2:0] OPERATION = 3'd0
) (
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] out_data
);

    wire [31:0] core_result;
    wire unused_invalid_operation;
    reg         result_valid;
    reg  [31:0] result_data;

    assign in_ready  = !result_valid;
    assign out_valid = result_valid;
    assign out_data  = result_data;

    la32_bit_count u_selected_operation (
        .operation         (OPERATION),
        .operand           (in_data),
        .result            (core_result),
        .invalid_operation (unused_invalid_operation)
    );

    always @(posedge clk) begin
        if (!resetn) begin
            result_valid <= 1'b0;
            result_data  <= 32'b0;
        end
        else begin
            if (result_valid)
                result_valid <= 1'b0;

            if (in_valid && in_ready) begin
                result_valid <= 1'b1;
                result_data  <= core_result;
            end
        end
    end

endmodule
`endif

// 组合逻辑位计数核心。
// 操作编码：0=CLZ，1=CLO，2=CTZ，3=CTO，4=POPCOUNT。
// 对零执行 CLZ/CTZ、对全一执行 CLO/CTO 时返回 32。
module la32_bit_count (
    input  wire [2:0]  operation,
    input  wire [31:0] operand,
    output reg  [31:0] result,
    output reg         invalid_operation
);

    localparam [2:0]
        OP_CLZ      = 3'd0,
        OP_CLO      = 3'd1,
        OP_CTZ      = 3'd2,
        OP_CTO      = 3'd3,
        OP_POPCOUNT = 3'd4;

    function [5:0] count_leading_zeros;
        input [31:0] value;
        reg [31:0] shifted;
        begin
            if (value == 32'b0) begin
                count_leading_zeros = 6'd32;
            end
            else begin
                count_leading_zeros = 6'd0;
                shifted = value;

                if (shifted[31:16] == 16'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd16;
                    shifted = shifted << 16;
                end
                if (shifted[31:24] == 8'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd8;
                    shifted = shifted << 8;
                end
                if (shifted[31:28] == 4'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd4;
                    shifted = shifted << 4;
                end
                if (shifted[31:30] == 2'b0) begin
                    count_leading_zeros = count_leading_zeros + 6'd2;
                    shifted = shifted << 2;
                end
                if (!shifted[31])
                    count_leading_zeros = count_leading_zeros + 6'd1;
            end
        end
    endfunction

    function [5:0] count_trailing_zeros;
        input [31:0] value;
        reg [31:0] shifted;
        begin
            if (value == 32'b0) begin
                count_trailing_zeros = 6'd32;
            end
            else begin
                count_trailing_zeros = 6'd0;
                shifted = value;

                if (shifted[15:0] == 16'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd16;
                    shifted = shifted >> 16;
                end
                if (shifted[7:0] == 8'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd8;
                    shifted = shifted >> 8;
                end
                if (shifted[3:0] == 4'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd4;
                    shifted = shifted >> 4;
                end
                if (shifted[1:0] == 2'b0) begin
                    count_trailing_zeros = count_trailing_zeros + 6'd2;
                    shifted = shifted >> 2;
                end
                if (!shifted[0])
                    count_trailing_zeros = count_trailing_zeros + 6'd1;
            end
        end
    endfunction

    function [5:0] population_count;
        input [31:0] value;
        reg [31:0] partial;
        begin
            // SWAR 加法树：位对、半字节、字节、半字、字。
            partial = value - ((value >> 1) & 32'h5555_5555);
            partial = (partial & 32'h3333_3333) +
                      ((partial >> 2) & 32'h3333_3333);
            partial = (partial + (partial >> 4)) & 32'h0f0f_0f0f;
            partial = partial + (partial >> 8);
            partial = partial + (partial >> 16);
            population_count = partial[5:0];
        end
    endfunction

    always @(*) begin
        result            = 32'b0;
        invalid_operation = 1'b0;

        case (operation)
            // CLZ：统计 operand 从最高位开始连续为 0 的位数。
            OP_CLZ:
                result = {26'b0, count_leading_zeros(operand)};
            // CLO：统计 operand 从最高位开始连续为 1 的位数。
            OP_CLO:
                result = {26'b0, count_leading_zeros(~operand)};
            // CTZ：统计 operand 从最低位开始连续为 0 的位数。
            OP_CTZ:
                result = {26'b0, count_trailing_zeros(operand)};
            // CTO：统计 operand 从最低位开始连续为 1 的位数。
            OP_CTO:
                result = {26'b0, count_trailing_zeros(~operand)};
            // POPCOUNT：统计 operand 的 32 个比特中值为 1 的比特总数。
            OP_POPCOUNT:
                result = {26'b0, population_count(operand)};
            default:
                invalid_operation = 1'b1;
        endcase
    end

endmodule

`default_nettype wire
