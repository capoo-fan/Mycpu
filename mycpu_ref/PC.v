`timescale 1ns / 1ps
`include "defines.vh"
module PC (
    input  wire         cpu_rstn,
    input  wire         cpu_clk,
    input  wire         flush,
    input  wire [31:0]  flush_pc,
    input  wire         suspend,        // 流水线暂停信号
    input  wire [31:0]  din,          // 下一条指令PC
    output reg  [31:0]  pc,          // 当前程序计数器PC
    output wire        inst_rreq
);
always @(posedge cpu_clk or negedge cpu_rstn) begin
    if (!cpu_rstn)begin
        pc <= `PC_INIT_VAL;
    end else if (flush)begin
        pc <= flush_pc; 
    end else if(suspend) begin
        pc <= pc;
    end else begin
        pc <= din;
    end
end
assign inst_rreq = suspend?1'b0:1'b1;

endmodule
