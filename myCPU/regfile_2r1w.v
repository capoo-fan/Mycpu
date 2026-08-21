`timescale 1ns / 1ps
`default_nettype none

module regfile_2r1w(
    input  wire        clk,
    input  wire [ 4:0] raddr1,
    output wire [31:0] rdata1,
    input  wire [ 4:0] raddr2,
    output wire [31:0] rdata2,
    input  wire        we,
    input  wire [ 4:0] waddr,
    input  wire [31:0] wdata
);
    reg [31:0] rf [31:1];
    always @(posedge clk) begin
        if (we && (waddr != 5'b0))
            rf[waddr] <= wdata;
    end
    assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];
    assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];
endmodule

`default_nettype wire
