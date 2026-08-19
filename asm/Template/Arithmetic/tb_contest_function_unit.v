`timescale 1ns / 1ps
`default_nettype none
`include "la32_function_ops.vh"

module tb_contest_function_unit;

    reg         clk;
    reg         resetn;
    reg         req_valid;
    wire        req_ready;
    reg  [7:0]  req_operation;
    reg  [31:0] req_operand_a;
    reg  [31:0] req_operand_b;
    reg  [4:0]  req_lsb;
    reg  [4:0]  req_msb;
    wire        rsp_valid;
    reg         rsp_ready;
    wire [31:0] rsp_result;
    wire [31:0] rsp_auxiliary;
    wire        rsp_divide_by_zero;
    wire        rsp_overflow;
    wire        rsp_invalid_operation;
    wire        rsp_invalid_control;

    integer tests;
    integer index;
    integer seed;
    reg [31:0] random_a;
    reg [31:0] random_b;
    reg [4:0]  random_lsb;
    reg [4:0]  random_msb;
    integer random_offset;
    reg [31:0] reference_mask;
    reg [63:0] reference_product;
    reg [31:0] crc_seed;

    contest_function_unit dut (
        .clk                   (clk),
        .resetn                (resetn),
        .req_valid             (req_valid),
        .req_ready             (req_ready),
        .req_operation         (req_operation),
        .req_operand_a         (req_operand_a),
        .req_operand_b         (req_operand_b),
        .req_lsb               (req_lsb),
        .req_msb               (req_msb),
        .rsp_valid             (rsp_valid),
        .rsp_ready             (rsp_ready),
        .rsp_result            (rsp_result),
        .rsp_auxiliary         (rsp_auxiliary),
        .rsp_divide_by_zero    (rsp_divide_by_zero),
        .rsp_overflow          (rsp_overflow),
        .rsp_invalid_operation (rsp_invalid_operation),
        .rsp_invalid_control   (rsp_invalid_control)
    );

    always #5 clk = ~clk;

    function [31:0] clz_reference;
        input [31:0] value;
        integer bit_index;
        reg found;
        begin
            clz_reference = 32'b0;
            found = 1'b0;
            for (bit_index = 31; bit_index >= 0; bit_index = bit_index - 1) begin
                if (!found) begin
                    if (value[bit_index])
                        found = 1'b1;
                    else
                        clz_reference = clz_reference + 32'd1;
                end
            end
        end
    endfunction

    function [31:0] ctz_reference;
        input [31:0] value;
        integer bit_index;
        reg found;
        begin
            ctz_reference = 32'b0;
            found = 1'b0;
            for (bit_index = 0; bit_index < 32; bit_index = bit_index + 1) begin
                if (!found) begin
                    if (value[bit_index])
                        found = 1'b1;
                    else
                        ctz_reference = ctz_reference + 32'd1;
                end
            end
        end
    endfunction

    function [31:0] popcount_reference;
        input [31:0] value;
        integer bit_index;
        begin
            popcount_reference = 32'b0;
            for (bit_index = 0; bit_index < 32; bit_index = bit_index + 1)
                popcount_reference = popcount_reference + value[bit_index];
        end
    endfunction

    function [31:0] rotr_reference;
        input [31:0] value;
        input [4:0] amount;
        begin
            if (amount == 5'd0)
                rotr_reference = value;
            else
                rotr_reference = (value >> amount) |
                                 (value << (6'd32 - amount));
        end
    endfunction

    function [7:0] reverse_byte_reference;
        input [7:0] value;
        integer bit_index;
        begin
            for (bit_index = 0; bit_index < 8; bit_index = bit_index + 1)
                reverse_byte_reference[bit_index] = value[7-bit_index];
        end
    endfunction

    function [31:0] bitrev_reference;
        input [31:0] value;
        integer bit_index;
        begin
            for (bit_index = 0; bit_index < 32; bit_index = bit_index + 1)
                bitrev_reference[bit_index] = value[31-bit_index];
        end
    endfunction

    function [31:0] bitrev_4b_reference;
        input [31:0] value;
        begin
            bitrev_4b_reference = {
                reverse_byte_reference(value[31:24]),
                reverse_byte_reference(value[23:16]),
                reverse_byte_reference(value[15:8]),
                reverse_byte_reference(value[7:0])
            };
        end
    endfunction

    function [31:0] bytepick_reference;
        input [23:0] rj_upper;
        input [31:0] rk;
        input [1:0] amount;
        begin
            case (amount)
                2'd0: bytepick_reference = rk;
                2'd1: bytepick_reference = {rk[23:0], rj_upper[23:16]};
                2'd2: bytepick_reference = {rk[15:0], rj_upper[23:8]};
                2'd3: bytepick_reference = {rk[7:0],  rj_upper};
            endcase
        end
    endfunction

    function [31:0] field_mask_reference;
        input [4:0] msb;
        input [4:0] lsb;
        reg [5:0] width;
        begin
            width = {1'b0, msb} - {1'b0, lsb} + 6'd1;
            field_mask_reference = ((32'b1 << width) - 32'b1) << lsb;
        end
    endfunction

    function [63:0] unsigned_product_reference;
        input [31:0] a;
        input [31:0] b;
        begin
            unsigned_product_reference = a * b;
        end
    endfunction

    function [63:0] signed_product_reference;
        input [31:0] a;
        input [31:0] b;
        reg signed [63:0] signed_a;
        reg signed [63:0] signed_b;
        reg signed [63:0] product;
        begin
            signed_a = {{32{a[31]}}, a};
            signed_b = {{32{b[31]}}, b};
            product = signed_a * signed_b;
            signed_product_reference = product;
        end
    endfunction

    function [31:0] crc_reference;
        input [31:0] message;
        input [31:0] old_checksum;
        input [5:0] bit_count;
        input [31:0] polynomial;
        integer bit_index;
        reg [31:0] checksum;
        reg [31:0] masked_message;
        begin
            case (bit_count)
                6'd8:  masked_message = {24'b0, message[7:0]};
                6'd16: masked_message = {16'b0, message[15:0]};
                default: masked_message = message;
            endcase

            checksum = old_checksum ^ masked_message;
            for (bit_index = 0; bit_index < bit_count;
                 bit_index = bit_index + 1) begin
                if (checksum[0])
                    checksum = (checksum >> 1) ^ polynomial;
                else
                    checksum = checksum >> 1;
            end
            crc_reference = checksum;
        end
    endfunction

    task check_operation;
        input [7:0]  operation;
        input [31:0] operand_a;
        input [31:0] operand_b;
        input [4:0]  lsb;
        input [4:0]  msb;
        input [31:0] expected_result;
        input [31:0] expected_auxiliary;
        input        expected_divide_by_zero;
        input        expected_overflow;
        input        expected_invalid_operation;
        input        expected_invalid_control;
        integer wait_cycles;
        reg [31:0] held_result;
        reg [31:0] held_auxiliary;
        begin
            @(negedge clk);
            req_operation = operation;
            req_operand_a = operand_a;
            req_operand_b = operand_b;
            req_lsb       = lsb;
            req_msb       = msb;
            req_valid     = 1'b1;

            wait_cycles = 0;
            while (!req_ready) begin
                @(negedge clk);
                wait_cycles = wait_cycles + 1;
                if (wait_cycles > 20)
                    $fatal(1, "request timeout op=%h", operation);
            end

            @(negedge clk);
            req_valid = 1'b0;

            wait_cycles = 0;
            while (!rsp_valid) begin
                @(negedge clk);
                wait_cycles = wait_cycles + 1;
                if (wait_cycles > 2000)
                    $fatal(1, "response timeout op=%h a=%h b=%h",
                           operation, operand_a, operand_b);
            end

            if ((rsp_result !== expected_result) ||
                (rsp_auxiliary !== expected_auxiliary) ||
                (rsp_divide_by_zero !== expected_divide_by_zero) ||
                (rsp_overflow !== expected_overflow) ||
                (rsp_invalid_operation !== expected_invalid_operation) ||
                (rsp_invalid_control !== expected_invalid_control)) begin
                $display("FAIL op=%h a=%h b=%h lsb=%0d msb=%0d",
                         operation, operand_a, operand_b, lsb, msb);
                $display("  got result=%h aux=%h div0=%b ovf=%b invop=%b invctl=%b",
                         rsp_result, rsp_auxiliary, rsp_divide_by_zero,
                         rsp_overflow, rsp_invalid_operation,
                         rsp_invalid_control);
                $display("  exp result=%h aux=%h div0=%b ovf=%b invop=%b invctl=%b",
                         expected_result, expected_auxiliary,
                         expected_divide_by_zero, expected_overflow,
                         expected_invalid_operation, expected_invalid_control);
                $fatal(1, "function-unit mismatch");
            end

            held_result    = rsp_result;
            held_auxiliary = rsp_auxiliary;
            repeat (2) begin
                @(negedge clk);
                if (!rsp_valid || (rsp_result !== held_result) ||
                    (rsp_auxiliary !== held_auxiliary))
                    $fatal(1, "response changed while backpressured");
            end

            rsp_ready = 1'b1;
            @(negedge clk);
            rsp_ready = 1'b0;
            if (rsp_valid)
                $fatal(1, "response valid did not clear");

            tests = tests + 1;
        end
    endtask

    task check_crc_byte_step;
        input [7:0] message_byte;
        input       castagnoli;
        inout [31:0] current_seed;
        reg [31:0] polynomial;
        reg [31:0] expected;
        reg [7:0] operation;
        begin
            polynomial = castagnoli ? 32'h82f6_3b78 : 32'hedb8_8320;
            operation  = castagnoli ?
                `LA32_FUNC_OP_CRC32C_B : `LA32_FUNC_OP_CRC32_B;
            expected = crc_reference({24'b0, message_byte}, current_seed,
                                     6'd8, polynomial);
            check_operation(operation, {24'b0, message_byte}, current_seed,
                            5'b0, 5'b0, expected, 32'b0,
                            1'b0, 1'b0, 1'b0, 1'b0);
            current_seed = expected;
        end
    endtask

    initial begin
        clk           = 1'b0;
        resetn        = 1'b0;
        req_valid     = 1'b0;
        req_operation = 8'b0;
        req_operand_a = 32'b0;
        req_operand_b = 32'b0;
        req_lsb       = 5'b0;
        req_msb       = 5'b0;
        rsp_ready     = 1'b0;
        tests         = 0;
        seed          = 32'h5a32_2026;

        repeat (4) @(posedge clk);
        @(negedge clk);
        resetn = 1'b1;

        // Existing arithmetic-unit integration.
        check_operation(`LA32_FUNC_OP_UDIV, 32'd100, 32'd7, 0, 0,
                        32'd14, 32'd2, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_ISQRT, 32'hffff_ffff, 0, 0, 0,
                        32'd65535, 32'h0001_fffe, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_GCD, 32'd48, 32'd18, 0, 0,
                        32'd6, 32'b0, 0, 0, 0, 0);

        // Count operations and corner cases.
        check_operation(`LA32_FUNC_OP_CLZ, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_CLZ, 1, 0, 0, 0, 31, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_CLO, 32'hffff_ffff, 0, 0, 0,
                        32, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_CTZ, 32'h0000_0100, 0, 0, 0,
                        8, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_CTO, 32'h0000_0007, 0, 0, 0,
                        3, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_POPCOUNT, 32'hf0f0_5555, 0, 0, 0,
                        16, 0, 0, 0, 0, 0);

        // Shift and permutation examples, including all BYTEPICK windows.
        check_operation(`LA32_FUNC_OP_ROTR, 32'h1234_5678, 0, 8, 0,
                        32'h7812_3456, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BITREV_W, 32'h0000_0001, 0, 0, 0,
                        32'h8000_0000, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BITREV_4B, 32'h0123_4567, 0, 0, 0,
                        32'h80c4_a2e6, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_REVB_2H, 32'h1122_3344, 0, 0, 0,
                        32'h2211_4433, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BYTEPICK_W,
                        32'h1122_3344, 32'haabb_ccdd, 0, 0,
                        32'haabb_ccdd, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BYTEPICK_W,
                        32'h1122_3344, 32'haabb_ccdd, 1, 0,
                        32'hbbcc_dd11, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BYTEPICK_W,
                        32'h1122_3344, 32'haabb_ccdd, 2, 0,
                        32'hccdd_1122, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BYTEPICK_W,
                        32'h1122_3344, 32'haabb_ccdd, 3, 0,
                        32'hdd11_2233, 0, 0, 0, 0, 0);

        // Bit-field extraction/insertion, full width, and invalid controls.
        check_operation(`LA32_FUNC_OP_BSTRPICK_W, 32'hdead_beef, 0, 8, 15,
                        32'h0000_00be, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BSTRINS_W,
                        32'hdead_beef, 32'h1234_5678, 8, 15,
                        32'hdead_78ef, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BSTRPICK_W,
                        32'hdead_beef, 0, 0, 31,
                        32'hdead_beef, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BSTRINS_W,
                        32'hdead_beef, 32'h1234_5678, 0, 31,
                        32'h1234_5678, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_BSTRPICK_W,
                        32'hdead_beef, 0, 20, 10,
                        0, 0, 0, 0, 0, 1);

        // Full multiply boundary cases.
        reference_product = unsigned_product_reference(
            32'hffff_ffff, 32'hffff_ffff);
        check_operation(`LA32_FUNC_OP_MULU_FULL,
                        32'hffff_ffff, 32'hffff_ffff, 0, 0,
                        reference_product[31:0], reference_product[63:32],
                        0, 0, 0, 0);
        reference_product = signed_product_reference(
            32'h8000_0000, 32'hffff_ffff);
        check_operation(`LA32_FUNC_OP_MULS_FULL,
                        32'h8000_0000, 32'hffff_ffff, 0, 0,
                        reference_product[31:0], reference_product[63:32],
                        0, 0, 0, 0);

        // Small logic helpers.
        check_operation(`LA32_FUNC_OP_ANDN,
                        32'hffff_00ff, 32'h0f0f_0f0f, 0, 0,
                        32'hf0f0_00f0, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_ORN,
                        32'h0000_00ff, 32'h0f0f_0f0f, 0, 0,
                        32'hf0f0_f0ff, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_MASKEQZ, 32'h1234_5678, 0, 0, 0,
                        0, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_MASKEQZ,
                        32'h1234_5678, 1, 0, 0,
                        32'h1234_5678, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_MASKNEZ,
                        32'h1234_5678, 0, 0, 0,
                        32'h1234_5678, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_ALSL, 32'h0000_0010, 5, 3, 0,
                        32'h0000_0105, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_EXT_W_B, 32'h0000_0080, 0, 0, 0,
                        32'hffff_ff80, 0, 0, 0, 0, 0);
        check_operation(`LA32_FUNC_OP_EXT_W_H, 32'h0000_8000, 0, 0, 0,
                        32'hffff_8000, 0, 0, 0, 0, 0);

        // Standard "123456789" check values validate polynomial and bit order.
        crc_seed = 32'hffff_ffff;
        check_crc_byte_step(8'h31, 0, crc_seed);
        check_crc_byte_step(8'h32, 0, crc_seed);
        check_crc_byte_step(8'h33, 0, crc_seed);
        check_crc_byte_step(8'h34, 0, crc_seed);
        check_crc_byte_step(8'h35, 0, crc_seed);
        check_crc_byte_step(8'h36, 0, crc_seed);
        check_crc_byte_step(8'h37, 0, crc_seed);
        check_crc_byte_step(8'h38, 0, crc_seed);
        check_crc_byte_step(8'h39, 0, crc_seed);
        if ((crc_seed ^ 32'hffff_ffff) != 32'hcbf4_3926)
            $fatal(1, "CRC-32 standard check mismatch");

        crc_seed = 32'hffff_ffff;
        check_crc_byte_step(8'h31, 1, crc_seed);
        check_crc_byte_step(8'h32, 1, crc_seed);
        check_crc_byte_step(8'h33, 1, crc_seed);
        check_crc_byte_step(8'h34, 1, crc_seed);
        check_crc_byte_step(8'h35, 1, crc_seed);
        check_crc_byte_step(8'h36, 1, crc_seed);
        check_crc_byte_step(8'h37, 1, crc_seed);
        check_crc_byte_step(8'h38, 1, crc_seed);
        check_crc_byte_step(8'h39, 1, crc_seed);
        if ((crc_seed ^ 32'hffff_ffff) != 32'he306_9283)
            $fatal(1, "CRC-32C standard check mismatch");

        // Fixed-seed random differential testing.
        for (index = 0; index < 100; index = index + 1) begin
            random_a = $urandom(seed);
            random_b = $urandom(seed);

            check_operation(`LA32_FUNC_OP_CLZ, random_a, 0, 0, 0,
                            clz_reference(random_a), 0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_CLO, random_a, 0, 0, 0,
                            clz_reference(~random_a), 0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_CTZ, random_a, 0, 0, 0,
                            ctz_reference(random_a), 0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_CTO, random_a, 0, 0, 0,
                            ctz_reference(~random_a), 0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_POPCOUNT, random_a, 0, 0, 0,
                            popcount_reference(random_a), 0, 0, 0, 0, 0);

            random_lsb = random_b[4:0];
            check_operation(`LA32_FUNC_OP_ROTR, random_a, random_b,
                            random_lsb, 0,
                            rotr_reference(random_a, random_lsb),
                            0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_BITREV_W, random_a, 0, 0, 0,
                            bitrev_reference(random_a), 0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_BITREV_4B, random_a, 0, 0, 0,
                            bitrev_4b_reference(random_a), 0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_REVB_2H, random_a, 0, 0, 0,
                            {random_a[23:16], random_a[31:24],
                             random_a[7:0], random_a[15:8]},
                            0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_BYTEPICK_W,
                            random_a, random_b, random_lsb, 0,
                            bytepick_reference(random_a[31:8], random_b,
                                               random_lsb[1:0]),
                            0, 0, 0, 0, 0);

            random_lsb = random_a[4:0];
            random_offset = random_b %
                (32'd32 - {27'b0, random_lsb});
            if ((random_offset < 0) || (random_offset > 31))
                $fatal(1, "random field offset escaped valid range");
            random_msb = random_lsb + random_offset[4:0];
            reference_mask = field_mask_reference(random_msb, random_lsb);
            check_operation(`LA32_FUNC_OP_BSTRPICK_W,
                            random_a, random_b, random_lsb, random_msb,
                            (random_a >> random_lsb) &
                                (reference_mask >> random_lsb),
                            0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_BSTRINS_W,
                            random_a, random_b, random_lsb, random_msb,
                            (random_a & ~reference_mask) |
                                ((random_b << random_lsb) & reference_mask),
                            0, 0, 0, 0, 0);

            reference_product = unsigned_product_reference(random_a, random_b);
            check_operation(`LA32_FUNC_OP_MULU_FULL,
                            random_a, random_b, 0, 0,
                            reference_product[31:0],
                            reference_product[63:32], 0, 0, 0, 0);
            reference_product = signed_product_reference(random_a, random_b);
            check_operation(`LA32_FUNC_OP_MULS_FULL,
                            random_a, random_b, 0, 0,
                            reference_product[31:0],
                            reference_product[63:32], 0, 0, 0, 0);

            check_operation(`LA32_FUNC_OP_CRC32_H,
                            random_a, random_b, 0, 0,
                            crc_reference(random_a, random_b, 16,
                                          32'hedb8_8320),
                            0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_CRC32_W,
                            random_a, random_b, 0, 0,
                            crc_reference(random_a, random_b, 32,
                                          32'hedb8_8320),
                            0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_CRC32C_H,
                            random_a, random_b, 0, 0,
                            crc_reference(random_a, random_b, 16,
                                          32'h82f6_3b78),
                            0, 0, 0, 0, 0);
            check_operation(`LA32_FUNC_OP_CRC32C_W,
                            random_a, random_b, 0, 0,
                            crc_reference(random_a, random_b, 32,
                                          32'h82f6_3b78),
                            0, 0, 0, 0, 0);
        end

        check_operation(8'hff, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0);

        $display("PASS contest_function_unit tests=%0d", tests);
        $finish;
    end

endmodule

`default_nettype wire
