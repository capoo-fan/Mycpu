`timescale 1ns / 1ps
`default_nettype none
`include "la32_arithmetic_ops.vh"

module tb_contest_arithmetic_unit;

    localparam [2:0]
        OP_UDIV  = `LA32_ARITH_OP_UDIV,
        OP_SDIV  = `LA32_ARITH_OP_SDIV,
        OP_UMOD  = `LA32_ARITH_OP_UMOD,
        OP_SMOD  = `LA32_ARITH_OP_SMOD,
        OP_ISQRT = `LA32_ARITH_OP_ISQRT,
        OP_GCD   = `LA32_ARITH_OP_GCD;

    reg         clk;
    reg         resetn;
    reg         req_valid;
    wire        req_ready;
    reg  [2:0]  req_operation;
    reg  [31:0] req_operand_a;
    reg  [31:0] req_operand_b;
    wire        rsp_valid;
    reg         rsp_ready;
    wire [31:0] rsp_result;
    wire [31:0] rsp_auxiliary;
    wire        rsp_divide_by_zero;
    wire        rsp_overflow;
    wire        rsp_invalid_operation;

    integer tests;
    integer index;
    integer seed;
    reg [31:0] random_a;
    reg [31:0] random_b;
    reg [31:0] reference_root;
    reg [31:0] reference_square;

    contest_arithmetic_unit dut (
        .clk                   (clk),
        .resetn                (resetn),
        .req_valid             (req_valid),
        .req_ready             (req_ready),
        .req_operation         (req_operation),
        .req_operand_a         (req_operand_a),
        .req_operand_b         (req_operand_b),
        .rsp_valid             (rsp_valid),
        .rsp_ready             (rsp_ready),
        .rsp_result            (rsp_result),
        .rsp_auxiliary         (rsp_auxiliary),
        .rsp_divide_by_zero    (rsp_divide_by_zero),
        .rsp_overflow          (rsp_overflow),
        .rsp_invalid_operation (rsp_invalid_operation)
    );

    always #5 clk = ~clk;

    function [31:0] signed_divide_reference;
        input [31:0] a;
        input [31:0] b;
        reg signed [31:0] signed_a;
        reg signed [31:0] signed_b;
        reg signed [31:0] signed_result;
        begin
            signed_a = a;
            signed_b = b;
            if (b == 32'b0)
                signed_divide_reference = 32'hffff_ffff;
            else if ((a == 32'h8000_0000) && (b == 32'hffff_ffff))
                signed_divide_reference = 32'h8000_0000;
            else begin
                signed_result = signed_a / signed_b;
                signed_divide_reference = signed_result;
            end
        end
    endfunction

    function [31:0] signed_modulo_reference;
        input [31:0] a;
        input [31:0] b;
        reg signed [31:0] signed_a;
        reg signed [31:0] signed_b;
        reg signed [31:0] signed_result;
        begin
            signed_a = a;
            signed_b = b;
            if (b == 32'b0)
                signed_modulo_reference = a;
            else if ((a == 32'h8000_0000) && (b == 32'hffff_ffff))
                signed_modulo_reference = 32'b0;
            else begin
                signed_result = signed_a % signed_b;
                signed_modulo_reference = signed_result;
            end
        end
    endfunction

    function [31:0] isqrt_reference;
        input [31:0] value;
        integer bit_index;
        reg [31:0] root;
        reg [31:0] trial;
        reg [63:0] square;
        begin
            root = 32'b0;
            for (bit_index = 15; bit_index >= 0; bit_index = bit_index - 1) begin
                trial  = root | (32'b1 << bit_index);
                square = trial * trial;
                if (square <= {32'b0, value})
                    root = trial;
            end
            isqrt_reference = root;
        end
    endfunction

    function [31:0] gcd_reference;
        input [31:0] a;
        input [31:0] b;
        reg [31:0] u;
        reg [31:0] v;
        reg [31:0] temporary;
        begin
            u = a;
            v = b;
            while (v != 32'b0) begin
                temporary = u % v;
                u = v;
                v = temporary;
            end
            gcd_reference = u;
        end
    endfunction

    task check_operation;
        input [2:0]  operation;
        input [31:0] operand_a;
        input [31:0] operand_b;
        input [31:0] expected_result;
        input [31:0] expected_auxiliary;
        input        expected_divide_by_zero;
        input        expected_overflow;
        input        expected_invalid_operation;
        integer wait_cycles;
        reg [31:0] held_result;
        reg [31:0] held_auxiliary;
        begin
            @(negedge clk);
            req_operation = operation;
            req_operand_a = operand_a;
            req_operand_b = operand_b;
            req_valid     = 1'b1;

            wait_cycles = 0;
            while (!req_ready) begin
                @(negedge clk);
                wait_cycles = wait_cycles + 1;
                if (wait_cycles > 20)
                    $fatal(1, "request timeout op=%0d", operation);
            end

            // The request is accepted at the intervening positive edge.
            @(negedge clk);
            req_valid = 1'b0;

            wait_cycles = 0;
            while (!rsp_valid) begin
                @(negedge clk);
                wait_cycles = wait_cycles + 1;
                if (wait_cycles > 1000)
                    $fatal(1, "response timeout op=%0d a=%h b=%h",
                           operation, operand_a, operand_b);
            end

            if ((rsp_result !== expected_result) ||
                (rsp_auxiliary !== expected_auxiliary) ||
                (rsp_divide_by_zero !== expected_divide_by_zero) ||
                (rsp_overflow !== expected_overflow) ||
                (rsp_invalid_operation !== expected_invalid_operation)) begin
                $display("FAIL op=%0d a=%h b=%h", operation, operand_a, operand_b);
                $display("  got result=%h aux=%h div0=%b ovf=%b invalid=%b",
                         rsp_result, rsp_auxiliary, rsp_divide_by_zero,
                         rsp_overflow, rsp_invalid_operation);
                $display("  exp result=%h aux=%h div0=%b ovf=%b invalid=%b",
                         expected_result, expected_auxiliary,
                         expected_divide_by_zero, expected_overflow,
                         expected_invalid_operation);
                $fatal(1, "arithmetic mismatch");
            end

            // Exercise response backpressure and require stable data.
            held_result    = rsp_result;
            held_auxiliary = rsp_auxiliary;
            repeat (2) begin
                @(negedge clk);
                if (!rsp_valid || (rsp_result !== held_result) ||
                    (rsp_auxiliary !== held_auxiliary))
                    $fatal(1, "response changed while rsp_ready=0");
            end

            rsp_ready = 1'b1;
            @(negedge clk);
            rsp_ready = 1'b0;
            if (rsp_valid)
                $fatal(1, "response valid did not clear after handshake");

            tests = tests + 1;
        end
    endtask

    task check_unsigned_pair;
        input [31:0] a;
        input [31:0] b;
        reg [31:0] quotient;
        reg [31:0] remainder;
        begin
            if (b == 32'b0) begin
                quotient  = 32'hffff_ffff;
                remainder = a;
            end
            else begin
                quotient  = a / b;
                remainder = a % b;
            end

            check_operation(OP_UDIV, a, b, quotient, remainder,
                            b == 32'b0, 1'b0, 1'b0);
            check_operation(OP_UMOD, a, b, remainder, quotient,
                            b == 32'b0, 1'b0, 1'b0);
        end
    endtask

    task check_signed_pair;
        input [31:0] a;
        input [31:0] b;
        reg [31:0] quotient;
        reg [31:0] remainder;
        reg overflow;
        begin
            quotient  = signed_divide_reference(a, b);
            remainder = signed_modulo_reference(a, b);
            overflow  = (a == 32'h8000_0000) && (b == 32'hffff_ffff);

            check_operation(OP_SDIV, a, b, quotient, remainder,
                            b == 32'b0, overflow, 1'b0);
            check_operation(OP_SMOD, a, b, remainder, quotient,
                            b == 32'b0, overflow, 1'b0);
        end
    endtask

    task check_sqrt;
        input [31:0] value;
        begin
            reference_root   = isqrt_reference(value);
            reference_square = reference_root * reference_root;
            check_operation(OP_ISQRT, value, 32'b0, reference_root,
                            value - reference_square,
                            1'b0, 1'b0, 1'b0);
        end
    endtask

    task check_gcd;
        input [31:0] a;
        input [31:0] b;
        begin
            check_operation(OP_GCD, a, b, gcd_reference(a, b), 32'b0,
                            1'b0, 1'b0, 1'b0);
        end
    endtask

    initial begin
        clk           = 1'b0;
        resetn        = 1'b0;
        req_valid     = 1'b0;
        req_operation = OP_UDIV;
        req_operand_a = 32'b0;
        req_operand_b = 32'b0;
        rsp_ready     = 1'b0;
        tests         = 0;
        seed          = 32'h1a32_2026;

        repeat (4) @(posedge clk);
        @(negedge clk);
        resetn = 1'b1;

        // Unsigned division/modulo boundaries.
        check_unsigned_pair(32'd0,          32'd1);
        check_unsigned_pair(32'd1,          32'd1);
        check_unsigned_pair(32'd1,          32'd2);
        check_unsigned_pair(32'hffff_ffff,  32'd1);
        check_unsigned_pair(32'hffff_ffff,  32'hffff_ffff);
        check_unsigned_pair(32'hffff_ffff,  32'h8000_0000);
        check_unsigned_pair(32'h1234_5678,  32'b0);

        // Signed quotient truncates toward zero; remainder follows dividend.
        check_signed_pair(32'd7,           32'd3);
        check_signed_pair(-32'sd7,         32'd3);
        check_signed_pair(32'd7,          -32'sd3);
        check_signed_pair(-32'sd7,        -32'sd3);
        check_signed_pair(32'h8000_0000,   32'hffff_ffff);
        check_signed_pair(32'h8000_0000,   32'd1);
        check_signed_pair(32'hffff_ffff,   32'b0);

        // Integer square-root boundaries and perfect-square neighbors.
        check_sqrt(32'd0);
        check_sqrt(32'd1);
        check_sqrt(32'd2);
        check_sqrt(32'd3);
        check_sqrt(32'd4);
        check_sqrt(32'd15);
        check_sqrt(32'd16);
        check_sqrt(32'd17);
        check_sqrt(32'hfffe_0001); // 65535^2
        check_sqrt(32'hffff_ffff);

        // GCD boundaries and representative inputs.
        check_gcd(32'd0,         32'd0);
        check_gcd(32'd0,         32'd27);
        check_gcd(32'd48,        32'd18);
        check_gcd(32'hffff_ffff, 32'hffff_ffff);
        check_gcd(32'h8000_0000, 32'h4000_0000);
        check_gcd(32'd1836311903, 32'd1134903170);

        // Invalid commands return a flagged response instead of deadlocking.
        check_operation(3'd6, 32'd1, 32'd2, 32'b0, 32'b0,
                        1'b0, 1'b0, 1'b1);
        check_operation(3'd7, 32'd1, 32'd2, 32'b0, 32'b0,
                        1'b0, 1'b0, 1'b1);

        for (index = 0; index < 200; index = index + 1) begin
            random_a = $urandom(seed);
            random_b = $urandom(seed);
            check_unsigned_pair(random_a, random_b);

            random_a = $urandom(seed);
            random_b = $urandom(seed);
            check_signed_pair(random_a, random_b);

            random_a = $urandom(seed);
            check_sqrt(random_a);

            random_a = $urandom(seed);
            random_b = $urandom(seed);
            check_gcd(random_a, random_b);
        end

        $display("PASS contest_arithmetic_unit tests=%0d", tests);
        $finish;
    end

endmodule

`default_nettype wire
