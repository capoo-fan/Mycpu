`timescale 1ns / 1ps
`include "defines.vh"
module RF (
    input  wire         cpu_clk,
    input  wire         cpu_rstn,

    // --- Read Ports (4 ports) ---
    input  wire [ 4:0]  rR1,            // Read address 1
    input  wire [ 4:0]  rR2,            // Read address 2
    input  wire [ 4:0]  rR3,            // Read address 3
    input  wire [ 4:0]  rR4,            // Read address 4
    output reg  [31:0]  rD1,            // Read data 1 (with forwarding)
    output reg  [31:0]  rD2,            // Read data 2 (with forwarding)
    output reg  [31:0]  rD3,            // Read data 3 (with forwarding)
    output reg  [31:0]  rD4,            // Read data 4 (with forwarding)

    // --- Write Ports (2 ports) ---
    input  wire         we1,            // Write enable 1
    input  wire [ 4:0]  wR1,            // Write address 1
    input  wire [31:0]  wD1,            // Write data 1
    input  wire         we2,            // Write enable 2
    input  wire [ 4:0]  wR2,            // Write address 2
    input  wire [31:0]  wD2             // Write data 2
);


reg [31:0] r [31:1];
integer i;
always @(posedge cpu_clk or negedge cpu_rstn) begin
    if (!cpu_rstn) begin
        for (i = 1; i <= 31; i = i + 1) begin
            r[i] <= 32'h0;
        end
    end else begin
        if (we1 && (wR1 != 5'h0)) begin
            r[wR1] <= wD1;
        end
        if (we2 && (wR2 != 5'h0)) begin
            r[wR2] <= wD2;
        end
    end
end

always @(*) begin
    if (rR1 == 5'h0) begin
        rD1 = 32'h0;
    end else if (we2 && (wR2 == rR1)) begin
        rD1 = wD2;
    end else if (we1 && (wR1 == rR1)) begin
        rD1 = wD1;
    end else begin
        rD1 = r[rR1];
    end


    if (rR2 == 5'h0) begin
        rD2 = 32'h0;
    end else if (we2 && (wR2 == rR2)) begin
        rD2 = wD2;
    end else if (we1 && (wR1 == rR2)) begin
        rD2 = wD1;
    end else begin
        rD2 = r[rR2];
    end


    if (rR3 == 5'h0) begin
        rD3 = 32'h0;
    end else if (we2 && (wR2 == rR3)) begin
        rD3 = wD2;
    end else if (we1 && (wR1 == rR3)) begin
        rD3 = wD1;
    end else begin
        rD3 = r[rR3];
    end


    if (rR4 == 5'h0) begin
        rD4 = 32'h0;
    end else if (we2 && (wR2 == rR4)) begin
        rD4 = wD2;
    end else if (we1 && (wR1 == rR4)) begin
        rD4 = wD1;
    end else begin
        rD4 = r[rR4];
    end
end

endmodule
