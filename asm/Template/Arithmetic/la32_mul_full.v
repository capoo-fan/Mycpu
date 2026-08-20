`timescale 1ns / 1ps
`default_nettype none

// 带寄存器的 32x32→64 位乘法器。
// req_signed=0：将两个操作数视为无符号数；rsp_product[31:0] 对应 MUL.W，
//               rsp_product[63:32] 对应 MULH.WU。
// req_signed=1：将两个操作数视为有符号补码；rsp_product[31:0] 对应 MUL.W，
//               rsp_product[63:32] 对应 MULH.W。
module la32_mul_full (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire        req_signed,
    input  wire [31:0] req_operand_a,
    input  wire [31:0] req_operand_b,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [63:0] rsp_product
);

    wire [63:0] unsigned_product = req_operand_a * req_operand_b;

    wire signed [31:0] signed_a = $signed(req_operand_a);
    wire signed [31:0] signed_b = $signed(req_operand_b);
    wire signed [63:0] signed_product = signed_a * signed_b;

    assign req_ready = !rsp_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            rsp_valid   <= 1'b0;
            rsp_product <= 64'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (req_valid && req_ready) begin
                if (req_signed)
                    rsp_product <= signed_product;
                else
                    rsp_product <= unsigned_product;

                rsp_valid <= 1'b1;
            end
        end
    end

endmodule

`default_nettype wire
