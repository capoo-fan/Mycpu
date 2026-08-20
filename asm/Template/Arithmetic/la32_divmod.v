`timescale 1ns / 1ps
`default_nettype none

// 用于 LA32 风格整数操作数的 32 位迭代除法器。
//
// 一个请求同时产生商和余数，因此 DIV 与 MOD 可以复用同一套硬件。数据通路采用
// 恢复余数除法，不包含可综合的“/”或“%”运算符。
module la32_divmod (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire        req_signed,
    input  wire [31:0] req_dividend,
    input  wire [31:0] req_divisor,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_quotient,
    output reg  [31:0] rsp_remainder,
    output reg         rsp_divide_by_zero,
    output reg         rsp_overflow
);

    reg        running;
    reg [5:0]  iteration;
    reg [31:0] divisor_mag;
    reg [31:0] dividend_shift;
    // 只有部分商的低 31 位送入下一轮迭代；最终最高位在最后一拍由
    // next_quotient 形成。
    reg [30:0] quotient_tail;
    // 每次减法后的部分余数均小于 32 位除数，因此其寄存形式只需 32 位。
    reg [31:0] remainder_work;
    reg        quotient_negative;
    reg        remainder_negative;

    wire dividend_negative = req_signed && req_dividend[31];
    wire divisor_negative  = req_signed && req_divisor[31];

    wire [31:0] dividend_magnitude =
        dividend_negative ? (~req_dividend + 32'd1) : req_dividend;
    wire [31:0] divisor_magnitude =
        divisor_negative ? (~req_divisor + 32'd1) : req_divisor;

    // 一轮恢复余数除法迭代，被除数从最高位开始处理。
    wire [32:0] shifted_remainder =
        {remainder_work, dividend_shift[31]};
    wire        quotient_bit =
        shifted_remainder >= {1'b0, divisor_mag};
    // 减法后的精确结果必定可由 32 位表示。当 shifted_remainder[32] 有效时，
    // 仅计算其低 32 位同样正确，因为二进制补码减法以 2^32 为模。
    wire [31:0] next_remainder = quotient_bit ?
        (shifted_remainder[31:0] - divisor_mag) :
        shifted_remainder[31:0];
    wire [31:0] next_quotient = {quotient_tail, quotient_bit};

    wire [31:0] signed_quotient = quotient_negative ?
        (~next_quotient + 32'd1) : next_quotient;
    wire [31:0] unsigned_remainder = next_remainder;
    wire [31:0] signed_remainder = remainder_negative ?
        (~unsigned_remainder + 32'd1) : unsigned_remainder;

    assign req_ready = !running && !rsp_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            running            <= 1'b0;
            iteration          <= 6'd0;
            divisor_mag        <= 32'b0;
            dividend_shift     <= 32'b0;
            quotient_tail      <= 31'b0;
            remainder_work     <= 32'b0;
            quotient_negative  <= 1'b0;
            remainder_negative <= 1'b0;

            rsp_valid          <= 1'b0;
            rsp_quotient       <= 32'b0;
            rsp_remainder      <= 32'b0;
            rsp_divide_by_zero <= 1'b0;
            rsp_overflow       <= 1'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (req_valid && req_ready) begin
                rsp_divide_by_zero <= 1'b0;
                rsp_overflow       <= 1'b0;

                // 异常情况返回确定的结果，并同时设置标志。
                // 除零时 q=0xffffffff，r=被除数。
                if (req_divisor == 32'b0) begin
                    rsp_quotient       <= 32'hffff_ffff;
                    rsp_remainder      <= req_dividend;
                    rsp_divide_by_zero <= 1'b1;
                    rsp_valid          <= 1'b1;
                end
                // 有符号 INT_MIN/-1 的结果无法用 32 位表示。
                else if (req_signed &&
                         (req_dividend == 32'h8000_0000) &&
                         (req_divisor  == 32'hffff_ffff)) begin
                    rsp_quotient  <= 32'h8000_0000;
                    rsp_remainder <= 32'b0;
                    rsp_overflow  <= 1'b1;
                    rsp_valid     <= 1'b1;
                end
                else begin
                    running            <= 1'b1;
                    iteration          <= 6'd0;
                    divisor_mag        <= divisor_magnitude;
                    dividend_shift     <= dividend_magnitude;
                    quotient_tail      <= 31'b0;
                    remainder_work     <= 32'b0;
                    quotient_negative  <= dividend_negative ^ divisor_negative;
                    remainder_negative <= dividend_negative;
                end
            end
            else if (running) begin
                dividend_shift <= {dividend_shift[30:0], 1'b0};
                quotient_tail  <= next_quotient[30:0];
                remainder_work <= next_remainder;

                if (iteration == 6'd31) begin
                    running       <= 1'b0;
                    rsp_quotient  <= signed_quotient;
                    rsp_remainder <= signed_remainder;
                    rsp_valid     <= 1'b1;
                end
                else begin
                    iteration <= iteration + 6'd1;
                end
            end
        end
    end

endmodule

`default_nettype wire
