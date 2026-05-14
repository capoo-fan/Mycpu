module PC (
    input  wire        clk,
    input  wire        resetn,
    input  wire        flush,        // 分支冲刷 br_taken
    input  wire [31:0] flush_pc,     // 冲刷目标地址 br_target
    input  wire        suspend,      // 流水线暂停 if_suspend
    input  wire [31:0] din,          // 下一条指令 PC (bpu_pred_target)
    output reg  [31:0] pc,           // 当前 PC 
    output wire        inst_req      // 取指请求有效
);

reg reset;
always @(posedge clk)
    reset <= ~resetn;

always @(posedge clk) begin
    if (reset)
        pc <= 32'h1c000000;
    else if (flush)
        pc <= flush_pc;
    else if (!suspend)
        pc <= din;
end

assign inst_req = !reset && !suspend;

endmodule
