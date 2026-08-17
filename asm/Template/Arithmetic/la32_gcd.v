`timescale 1ns / 1ps
`default_nettype none

// Unsigned 32-bit greatest common divisor using Stein's binary GCD algorithm.
// This avoids division and modulo hardware.  gcd(0, 0) is defined as zero.
module la32_gcd (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire [31:0] req_a,
    input  wire [31:0] req_b,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_gcd
);

    reg        running;
    reg [31:0] u;
    reg [31:0] v;
    reg [5:0]  common_shift;

    assign req_ready = !running && !rsp_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            running      <= 1'b0;
            u            <= 32'b0;
            v            <= 32'b0;
            common_shift <= 6'b0;
            rsp_valid    <= 1'b0;
            rsp_gcd      <= 32'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (req_valid && req_ready) begin
                if (req_a == 32'b0) begin
                    rsp_gcd   <= req_b;
                    rsp_valid <= 1'b1;
                end
                else if (req_b == 32'b0) begin
                    rsp_gcd   <= req_a;
                    rsp_valid <= 1'b1;
                end
                else begin
                    running      <= 1'b1;
                    u            <= req_a;
                    v            <= req_b;
                    common_shift <= 6'd0;
                end
            end
            else if (running) begin
                if (u == v) begin
                    running   <= 1'b0;
                    rsp_gcd   <= u << common_shift;
                    rsp_valid <= 1'b1;
                end
                else if (!u[0] && !v[0]) begin
                    u            <= u >> 1;
                    v            <= v >> 1;
                    common_shift <= common_shift + 6'd1;
                end
                else if (!u[0]) begin
                    u <= u >> 1;
                end
                else if (!v[0]) begin
                    v <= v >> 1;
                end
                else if (u > v) begin
                    u <= (u - v) >> 1;
                end
                else begin
                    v <= (v - u) >> 1;
                end
            end
        end
    end

endmodule

`default_nettype wire
