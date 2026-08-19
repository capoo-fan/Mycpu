`timescale 1ns / 1ps
`default_nettype none
`include "la32_function_ops.vh"

// Unified reusable function unit for contest accelerators.
//
// Fast bit/field/logic operations are registered on request acceptance.
// Division, square root, GCD, full multiply and CRC use their dedicated cores.
// At most one request is active, and every accepted request produces exactly
// one response that remains stable until rsp_ready is asserted.
module contest_function_unit (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output reg         req_ready,
    input  wire [7:0]  req_operation,
    input  wire [31:0] req_operand_a,
    input  wire [31:0] req_operand_b,
    input  wire [4:0]  req_lsb,
    input  wire [4:0]  req_msb,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_result,
    output reg  [31:0] rsp_auxiliary,
    output reg         rsp_divide_by_zero,
    output reg         rsp_overflow,
    output reg         rsp_invalid_operation,
    output reg         rsp_invalid_control
);

    localparam [1:0]
        STATE_IDLE  = 2'd0,
        STATE_ARITH = 2'd1,
        STATE_MUL   = 2'd2,
        STATE_CRC   = 2'd3;

    reg [1:0] state;

    wire operation_is_arithmetic =
        req_operation <= `LA32_FUNC_OP_GCD;
    wire operation_is_count =
        (req_operation >= `LA32_FUNC_OP_CLZ) &&
        (req_operation <= `LA32_FUNC_OP_POPCOUNT);
    wire operation_is_permute =
        (req_operation >= `LA32_FUNC_OP_ROTR) &&
        (req_operation <= `LA32_FUNC_OP_BYTEPICK_W);
    wire operation_is_bitfield =
        (req_operation >= `LA32_FUNC_OP_BSTRPICK_W) &&
        (req_operation <= `LA32_FUNC_OP_BSTRINS_W);
    wire operation_is_multiply =
        (req_operation >= `LA32_FUNC_OP_MULU_FULL) &&
        (req_operation <= `LA32_FUNC_OP_MULS_FULL);
    wire operation_is_crc =
        ((req_operation >= `LA32_FUNC_OP_CRC32_B) &&
         (req_operation <= `LA32_FUNC_OP_CRC32_W)) ||
        ((req_operation >= `LA32_FUNC_OP_CRC32C_B) &&
         (req_operation <= `LA32_FUNC_OP_CRC32C_W));
    wire operation_is_simple =
        (req_operation >= `LA32_FUNC_OP_ANDN) &&
        (req_operation <= `LA32_FUNC_OP_EXT_W_H);
    wire operation_is_fast = operation_is_count || operation_is_permute ||
                             operation_is_bitfield || operation_is_simple;
    wire operation_is_valid = operation_is_arithmetic || operation_is_fast ||
                              operation_is_multiply || operation_is_crc;

    wire request_fire = req_valid && req_ready;

    // ---------------------------------------------------------------------
    // Existing arithmetic unit
    // ---------------------------------------------------------------------
    wire        arithmetic_req_ready;
    wire        arithmetic_rsp_valid;
    wire [31:0] arithmetic_result;
    wire [31:0] arithmetic_auxiliary;
    wire        arithmetic_divide_by_zero;
    wire        arithmetic_overflow;
    wire        arithmetic_invalid_operation;

    wire arithmetic_req_valid = request_fire && operation_is_arithmetic;
    wire arithmetic_rsp_ready =
        (state == STATE_ARITH) && !rsp_valid;

    contest_arithmetic_unit u_arithmetic (
        .clk                   (clk),
        .resetn                (resetn),
        .req_valid             (arithmetic_req_valid),
        .req_ready             (arithmetic_req_ready),
        .req_operation         (req_operation[2:0]),
        .req_operand_a         (req_operand_a),
        .req_operand_b         (req_operand_b),
        .rsp_valid             (arithmetic_rsp_valid),
        .rsp_ready             (arithmetic_rsp_ready),
        .rsp_result            (arithmetic_result),
        .rsp_auxiliary         (arithmetic_auxiliary),
        .rsp_divide_by_zero    (arithmetic_divide_by_zero),
        .rsp_overflow          (arithmetic_overflow),
        .rsp_invalid_operation (arithmetic_invalid_operation)
    );

    // ---------------------------------------------------------------------
    // Fast combinational cores
    // ---------------------------------------------------------------------
    wire [31:0] count_result;
    wire count_invalid_operation;

    la32_bit_count u_bit_count (
        .operation         (req_operation[2:0]),
        .operand           (req_operand_a),
        .result            (count_result),
        .invalid_operation (count_invalid_operation)
    );

    wire [31:0] permute_result;
    wire permute_invalid_operation;

    la32_bit_permute u_bit_permute (
        .operation         (req_operation[2:0]),
        .operand_a         (req_operand_a),
        .operand_b         (req_operand_b),
        .shift_amount      (req_lsb),
        .result            (permute_result),
        .invalid_operation (permute_invalid_operation)
    );

    wire [31:0] bitfield_result;
    wire bitfield_invalid_control;

    la32_bitfield u_bitfield (
        .operation       (req_operation == `LA32_FUNC_OP_BSTRINS_W),
        .operand_a       (req_operand_a),
        .operand_b       (req_operand_b),
        .msb             (req_msb),
        .lsb             (req_lsb),
        .result          (bitfield_result),
        .invalid_control (bitfield_invalid_control)
    );

    wire [31:0] simple_result;
    wire simple_invalid_operation;

    la32_simple_ops u_simple_ops (
        .operation         (req_operation[2:0]),
        .operand_a         (req_operand_a),
        .operand_b         (req_operand_b),
        .shift_amount      (req_lsb[1:0]),
        .result            (simple_result),
        .invalid_operation (simple_invalid_operation)
    );

    // ---------------------------------------------------------------------
    // Full multiplier
    // ---------------------------------------------------------------------
    wire        multiply_req_ready;
    wire        multiply_rsp_valid;
    wire [63:0] multiply_product;

    wire multiply_req_valid = request_fire && operation_is_multiply;
    wire multiply_rsp_ready = (state == STATE_MUL) && !rsp_valid;

    la32_mul_full u_mul_full (
        .clk           (clk),
        .resetn        (resetn),
        .req_valid     (multiply_req_valid),
        .req_ready     (multiply_req_ready),
        .req_signed    (req_operation == `LA32_FUNC_OP_MULS_FULL),
        .req_operand_a (req_operand_a),
        .req_operand_b (req_operand_b),
        .rsp_valid     (multiply_rsp_valid),
        .rsp_ready     (multiply_rsp_ready),
        .rsp_product   (multiply_product)
    );

    // ---------------------------------------------------------------------
    // CRC core
    // ---------------------------------------------------------------------
    reg  [1:0] crc_request_width;
    wire       crc_req_ready;
    wire       crc_rsp_valid;
    wire [31:0] crc_checksum;
    wire       crc_invalid_width;

    wire crc_req_valid = request_fire && operation_is_crc;
    wire crc_rsp_ready = (state == STATE_CRC) && !rsp_valid;
    wire crc_is_castagnoli =
        (req_operation >= `LA32_FUNC_OP_CRC32C_B) &&
        (req_operation <= `LA32_FUNC_OP_CRC32C_W);

    always @(*) begin
        if ((req_operation == `LA32_FUNC_OP_CRC32_B) ||
            (req_operation == `LA32_FUNC_OP_CRC32C_B))
            crc_request_width = 2'd0;
        else if ((req_operation == `LA32_FUNC_OP_CRC32_H) ||
                 (req_operation == `LA32_FUNC_OP_CRC32C_H))
            crc_request_width = 2'd1;
        else
            crc_request_width = 2'd2;
    end

    la32_crc32 u_crc32 (
        .clk               (clk),
        .resetn            (resetn),
        .req_valid         (crc_req_valid),
        .req_ready         (crc_req_ready),
        .req_castagnoli    (crc_is_castagnoli),
        .req_width         (crc_request_width),
        .req_message       (req_operand_a),
        .req_seed          (req_operand_b),
        .rsp_valid         (crc_rsp_valid),
        .rsp_ready         (crc_rsp_ready),
        .rsp_checksum      (crc_checksum),
        .rsp_invalid_width (crc_invalid_width)
    );

    // ---------------------------------------------------------------------
    // Request selection and response collection
    // ---------------------------------------------------------------------
    always @(*) begin
        req_ready = 1'b0;

        if ((state == STATE_IDLE) && !rsp_valid) begin
            if (operation_is_arithmetic)
                req_ready = arithmetic_req_ready;
            else if (operation_is_multiply)
                req_ready = multiply_req_ready;
            else if (operation_is_crc)
                req_ready = crc_req_ready;
            else
                // Fast and invalid operations are consumed immediately.
                req_ready = 1'b1;
        end
    end

    always @(posedge clk) begin
        if (!resetn) begin
            state                 <= STATE_IDLE;
            rsp_valid             <= 1'b0;
            rsp_result            <= 32'b0;
            rsp_auxiliary         <= 32'b0;
            rsp_divide_by_zero    <= 1'b0;
            rsp_overflow          <= 1'b0;
            rsp_invalid_operation <= 1'b0;
            rsp_invalid_control   <= 1'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (request_fire) begin
                rsp_divide_by_zero    <= 1'b0;
                rsp_overflow          <= 1'b0;
                rsp_invalid_operation <= 1'b0;
                rsp_invalid_control   <= 1'b0;
                rsp_auxiliary         <= 32'b0;

                if (operation_is_arithmetic) begin
                    state <= STATE_ARITH;
                end
                else if (operation_is_multiply) begin
                    state <= STATE_MUL;
                end
                else if (operation_is_crc) begin
                    state <= STATE_CRC;
                end
                else if (operation_is_count) begin
                    state                 <= STATE_IDLE;
                    rsp_result            <= count_result;
                    rsp_invalid_operation <= count_invalid_operation;
                    rsp_valid             <= 1'b1;
                end
                else if (operation_is_permute) begin
                    state                 <= STATE_IDLE;
                    rsp_result            <= permute_result;
                    rsp_invalid_operation <= permute_invalid_operation;
                    rsp_valid             <= 1'b1;
                end
                else if (operation_is_bitfield) begin
                    state               <= STATE_IDLE;
                    rsp_result          <= bitfield_result;
                    rsp_invalid_control <= bitfield_invalid_control;
                    rsp_valid           <= 1'b1;
                end
                else if (operation_is_simple) begin
                    state                 <= STATE_IDLE;
                    rsp_result            <= simple_result;
                    rsp_invalid_operation <= simple_invalid_operation;
                    rsp_valid             <= 1'b1;
                end
                else begin
                    state                 <= STATE_IDLE;
                    rsp_result            <= 32'b0;
                    rsp_invalid_operation <= !operation_is_valid;
                    rsp_valid             <= 1'b1;
                end
            end

            if ((state == STATE_ARITH) && arithmetic_rsp_valid) begin
                state                 <= STATE_IDLE;
                rsp_result            <= arithmetic_result;
                rsp_auxiliary         <= arithmetic_auxiliary;
                rsp_divide_by_zero    <= arithmetic_divide_by_zero;
                rsp_overflow          <= arithmetic_overflow;
                rsp_invalid_operation <= arithmetic_invalid_operation;
                rsp_valid             <= 1'b1;
            end
            else if ((state == STATE_MUL) && multiply_rsp_valid) begin
                state         <= STATE_IDLE;
                rsp_result    <= multiply_product[31:0];
                rsp_auxiliary <= multiply_product[63:32];
                rsp_valid     <= 1'b1;
            end
            else if ((state == STATE_CRC) && crc_rsp_valid) begin
                state               <= STATE_IDLE;
                rsp_result          <= crc_checksum;
                rsp_auxiliary       <= 32'b0;
                rsp_invalid_control <= crc_invalid_width;
                rsp_valid           <= 1'b1;
            end
        end
    end

endmodule

`default_nettype wire
