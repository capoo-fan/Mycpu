`timescale 1ns / 1ps
`default_nettype none
`include "la32_arithmetic_ops.vh"

// Unified contest-oriented arithmetic interface.
//
// OP_UDIV / OP_SDIV: result = quotient, auxiliary = remainder
// OP_UMOD / OP_SMOD: result = remainder, auxiliary = quotient
// OP_ISQRT:          result = floor(sqrt(a)), auxiliary = a - result^2
// OP_GCD:            result = gcd(a, b), auxiliary = 0
module contest_arithmetic_unit (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output reg         req_ready,
    input  wire [2:0]  req_operation,
    input  wire [31:0] req_operand_a,
    input  wire [31:0] req_operand_b,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_result,
    output reg  [31:0] rsp_auxiliary,
    output reg         rsp_divide_by_zero,
    output reg         rsp_overflow,
    output reg         rsp_invalid_operation
);

    localparam [2:0]
        OP_UDIV  = `LA32_ARITH_OP_UDIV,
        OP_SDIV  = `LA32_ARITH_OP_SDIV,
        OP_UMOD  = `LA32_ARITH_OP_UMOD,
        OP_SMOD  = `LA32_ARITH_OP_SMOD,
        OP_ISQRT = `LA32_ARITH_OP_ISQRT,
        OP_GCD   = `LA32_ARITH_OP_GCD;

    localparam [1:0]
        STATE_IDLE = 2'd0,
        STATE_DIV  = 2'd1,
        STATE_SQRT = 2'd2,
        STATE_GCD  = 2'd3;

    reg [1:0] state;
    reg [2:0] active_operation;

    wire operation_is_div =
        (req_operation == OP_UDIV) || (req_operation == OP_SDIV) ||
        (req_operation == OP_UMOD) || (req_operation == OP_SMOD);
    wire operation_is_sqrt = req_operation == OP_ISQRT;
    wire operation_is_gcd  = req_operation == OP_GCD;
    wire div_req_ready;
    wire div_rsp_valid;
    wire [31:0] div_quotient;
    wire [31:0] div_remainder;
    wire div_by_zero;
    wire div_overflow;

    wire sqrt_req_ready;
    wire sqrt_rsp_valid;
    wire [15:0] sqrt_root;
    wire [31:0] sqrt_remainder;

    wire gcd_req_ready;
    wire gcd_rsp_valid;
    wire [31:0] gcd_result;

    wire request_fire = req_valid && req_ready;

    wire div_req_valid  = request_fire && operation_is_div;
    wire sqrt_req_valid = request_fire && operation_is_sqrt;
    wire gcd_req_valid  = request_fire && operation_is_gcd;

    wire div_rsp_ready  = (state == STATE_DIV)  && !rsp_valid;
    wire sqrt_rsp_ready = (state == STATE_SQRT) && !rsp_valid;
    wire gcd_rsp_ready  = (state == STATE_GCD)  && !rsp_valid;

    la32_divmod u_divmod (
        .clk                (clk),
        .resetn             (resetn),
        .req_valid          (div_req_valid),
        .req_ready          (div_req_ready),
        .req_signed         ((req_operation == OP_SDIV) ||
                             (req_operation == OP_SMOD)),
        .req_dividend       (req_operand_a),
        .req_divisor        (req_operand_b),
        .rsp_valid          (div_rsp_valid),
        .rsp_ready          (div_rsp_ready),
        .rsp_quotient       (div_quotient),
        .rsp_remainder      (div_remainder),
        .rsp_divide_by_zero (div_by_zero),
        .rsp_overflow       (div_overflow)
    );

    la32_isqrt u_isqrt (
        .clk           (clk),
        .resetn        (resetn),
        .req_valid     (sqrt_req_valid),
        .req_ready     (sqrt_req_ready),
        .req_radicand  (req_operand_a),
        .rsp_valid     (sqrt_rsp_valid),
        .rsp_ready     (sqrt_rsp_ready),
        .rsp_root      (sqrt_root),
        .rsp_remainder (sqrt_remainder)
    );

    la32_gcd u_gcd (
        .clk       (clk),
        .resetn    (resetn),
        .req_valid (gcd_req_valid),
        .req_ready (gcd_req_ready),
        .req_a     (req_operand_a),
        .req_b     (req_operand_b),
        .rsp_valid (gcd_rsp_valid),
        .rsp_ready (gcd_rsp_ready),
        .rsp_gcd   (gcd_result)
    );

    always @(*) begin
        req_ready = 1'b0;

        if ((state == STATE_IDLE) && !rsp_valid) begin
            if (operation_is_div)
                req_ready = div_req_ready;
            else if (operation_is_sqrt)
                req_ready = sqrt_req_ready;
            else if (operation_is_gcd)
                req_ready = gcd_req_ready;
            else
                // Invalid operations are accepted and reported, preventing a
                // malformed command from deadlocking its caller.
                req_ready = 1'b1;
        end
    end

    always @(posedge clk) begin
        if (!resetn) begin
            state                 <= STATE_IDLE;
            active_operation      <= OP_UDIV;
            rsp_valid             <= 1'b0;
            rsp_result            <= 32'b0;
            rsp_auxiliary         <= 32'b0;
            rsp_divide_by_zero    <= 1'b0;
            rsp_overflow          <= 1'b0;
            rsp_invalid_operation <= 1'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (request_fire) begin
                active_operation      <= req_operation;
                rsp_divide_by_zero    <= 1'b0;
                rsp_overflow          <= 1'b0;
                rsp_invalid_operation <= 1'b0;

                if (operation_is_div)
                    state <= STATE_DIV;
                else if (operation_is_sqrt)
                    state <= STATE_SQRT;
                else if (operation_is_gcd)
                    state <= STATE_GCD;
                else begin
                    state                 <= STATE_IDLE;
                    rsp_result            <= 32'b0;
                    rsp_auxiliary         <= 32'b0;
                    rsp_invalid_operation <= 1'b1;
                    rsp_valid             <= 1'b1;
                end
            end

            if ((state == STATE_DIV) && div_rsp_valid) begin
                state              <= STATE_IDLE;
                rsp_divide_by_zero <= div_by_zero;
                rsp_overflow       <= div_overflow;

                if ((active_operation == OP_UMOD) ||
                    (active_operation == OP_SMOD)) begin
                    rsp_result    <= div_remainder;
                    rsp_auxiliary <= div_quotient;
                end
                else begin
                    rsp_result    <= div_quotient;
                    rsp_auxiliary <= div_remainder;
                end

                rsp_valid <= 1'b1;
            end
            else if ((state == STATE_SQRT) && sqrt_rsp_valid) begin
                state         <= STATE_IDLE;
                rsp_result    <= {16'b0, sqrt_root};
                rsp_auxiliary <= sqrt_remainder;
                rsp_valid     <= 1'b1;
            end
            else if ((state == STATE_GCD) && gcd_rsp_valid) begin
                state         <= STATE_IDLE;
                rsp_result    <= gcd_result;
                rsp_auxiliary <= 32'b0;
                rsp_valid     <= 1'b1;
            end
        end
    end

endmodule

`default_nettype wire
