`timescale 1ns / 1ps
`default_nettype none

// 32-bit iterative divider for LA32-style integer operands.
//
// One request produces quotient and remainder together, so DIV and MOD can
// share the same hardware.  The datapath uses restoring division and contains
// no synthesizable '/' or '%' operator.
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
    // Only the lower 31 partial-quotient bits feed the next iteration.  The
    // final MSB is formed by next_quotient on the last cycle.
    reg [30:0] quotient_tail;
    // After every subtraction the partial remainder is less than a 32-bit
    // divisor, so its registered form needs only 32 bits.
    reg [31:0] remainder_work;
    reg        quotient_negative;
    reg        remainder_negative;

    wire dividend_negative = req_signed && req_dividend[31];
    wire divisor_negative  = req_signed && req_divisor[31];

    wire [31:0] dividend_magnitude =
        dividend_negative ? (~req_dividend + 32'd1) : req_dividend;
    wire [31:0] divisor_magnitude =
        divisor_negative ? (~req_divisor + 32'd1) : req_divisor;

    // One restoring-division iteration.  The dividend is consumed MSB first.
    wire [32:0] shifted_remainder =
        {remainder_work, dividend_shift[31]};
    wire        quotient_bit =
        shifted_remainder >= {1'b0, divisor_mag};
    // The exact post-subtraction value is known to fit in 32 bits.  Computing
    // its low word is also correct when shifted_remainder[32] is set because
    // two's-complement subtraction is modulo 2^32.
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

                // Deterministic exceptional results, accompanied by flags.
                // q = 0xffffffff and r = dividend for division by zero.
                if (req_divisor == 32'b0) begin
                    rsp_quotient       <= 32'hffff_ffff;
                    rsp_remainder      <= req_dividend;
                    rsp_divide_by_zero <= 1'b1;
                    rsp_valid          <= 1'b1;
                end
                // Signed INT_MIN / -1 cannot be represented in 32 bits.
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
