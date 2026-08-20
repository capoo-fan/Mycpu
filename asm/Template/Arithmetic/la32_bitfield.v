`timescale 1ns / 1ps
`default_nettype none

// LA32S 组合逻辑位域核心。
// 操作编码：0=BSTRPICK.W，1=BSTRINS.W。
//
// 对 BSTRPICK.W：operand_a 为 rj。
// 对 BSTRINS.W： operand_a 为 rd 的旧值，operand_b 为 rj。
module la32_bitfield (
    input  wire        operation,
    input  wire [31:0] operand_a,
    input  wire [31:0] operand_b,
    input  wire [4:0]  msb,
    input  wire [4:0]  lsb,
    output reg  [31:0] result,
    output reg         invalid_control
);

    localparam OP_BSTRPICK = 1'b0;
    localparam OP_BSTRINS  = 1'b1;

    reg [5:0]  field_width;
    reg [31:0] low_mask;
    reg [31:0] field_mask;

    always @(*) begin
        result          = 32'b0;
        invalid_control = 1'b0;
        field_width     = 6'd0;
        low_mask        = 32'b0;
        field_mask      = 32'b0;

        if (msb < lsb) begin
            invalid_control = 1'b1;
        end
        else begin
            field_width   = {1'b0, msb} - {1'b0, lsb} + 6'd1;
            // 32 位数左移 32 位得到零，再减一即可得到全宽字段所需的全一掩码。
            low_mask      = (32'b1 << field_width) - 32'b1;
            field_mask    = low_mask << lsb;

            case (operation)
                // BSTRPICK.W：提取 operand_a[msb:lsb] 并右对齐、零扩展。
                OP_BSTRPICK:
                    result = (operand_a >> lsb) & low_mask;
                // BSTRINS.W：以 operand_b 的低 field_width 位替换
                // operand_a[msb:lsb]，其余位保持 operand_a 原值。
                OP_BSTRINS:
                    result = (operand_a & ~field_mask) |
                             ((operand_b << lsb) & field_mask);
            endcase
        end
    end

endmodule

`default_nettype wire
