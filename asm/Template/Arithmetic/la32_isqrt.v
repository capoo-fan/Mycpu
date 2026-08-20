`timescale 1ns / 1ps
`default_nettype none

// 无符号 32 位整数平方根。
//
// 结果：result = floor(sqrt(radicand))
// 平方余数：remainder = radicand - result * result
//
// 四进制逐位算法每拍处理被开方数的两个比特，因此每个普通请求需要 16 轮迭代，
// 且不使用乘法器。

module la32_isqrt (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire [31:0] req_radicand,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [15:0] rsp_root,
    output reg  [31:0] rsp_remainder
);

    reg        running;
    reg [4:0]  iteration;
    reg [31:0] radicand_shift;
    reg [15:0] root_work;
    // 寄存的部分余数可由 32 位表示；移入下一组被开方数位时，再由组合逻辑扩展两位。
    reg [31:0] remainder_work;

    wire [33:0] shifted_remainder =
        {remainder_work, radicand_shift[31:30]};
    wire [33:0] trial_subtrahend = {16'b0, root_work, 2'b01};
    wire        root_bit = shifted_remainder >= trial_subtrahend;
    wire [31:0] next_remainder = root_bit ?
        (shifted_remainder[31:0] - trial_subtrahend[31:0]) :
        shifted_remainder[31:0];
    wire [15:0] next_root = {root_work[14:0], root_bit};

    assign req_ready = !running && !rsp_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            running        <= 1'b0;
            iteration      <= 5'd0;
            radicand_shift <= 32'b0;
            root_work      <= 16'b0;
            remainder_work <= 32'b0;

            rsp_valid      <= 1'b0;
            rsp_root       <= 16'b0;
            rsp_remainder  <= 32'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (req_valid && req_ready) begin
                running        <= 1'b1;
                iteration      <= 5'd0;
                radicand_shift <= req_radicand;
                root_work      <= 16'b0;
                remainder_work <= 32'b0;
            end
            else if (running) begin
                radicand_shift <= {radicand_shift[29:0], 2'b00};
                root_work      <= next_root;
                remainder_work <= next_remainder;

                if (iteration == 5'd15) begin
                    running       <= 1'b0;
                    rsp_root      <= next_root;
                    rsp_remainder <= next_remainder;
                    rsp_valid     <= 1'b1;
                end
                else begin
                    iteration <= iteration + 5'd1;
                end
            end
        end
    end

endmodule

`default_nettype wire
