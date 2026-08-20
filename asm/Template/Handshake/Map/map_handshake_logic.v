`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// Map 算法逻辑模板。一次只接收并处理一个元素。
//
// 默认示例用 4 个计算周期完成 F(x)=x，用于验证 engine 确实
// 会等待 out_valid。比赛时只修改 USER MODIFY REGION。
// ============================================================================

module map_handshake_logic (
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output reg         out_valid,
    output reg  [31:0] out_data
);

    reg        working;
    reg [31:0] work_data;

    // ========================================================================
    // >>>>>>>>>>>>>>>>>>> USER MODIFY REGION 1 BEGIN <<<<<<<<<<<<<<<<<<<<<<<<<
    // 算法寄存器及演示延迟。DEMO_CYCLES 必须至少为 1。
    // ========================================================================

    localparam [7:0] DEMO_CYCLES = 8'd4;
    reg [7:0] cycles_left;

    // ========================================================================
    // >>>>>>>>>>>>>>>>>>> USER MODIFY REGION 1 END <<<<<<<<<<<<<<<<<<<<<<<<<<<
    // ========================================================================

    assign in_ready = !working;

    always @(posedge clk) begin
        if (!resetn) begin
            working     <= 1'b0;
            work_data   <= 32'b0;
            cycles_left <= 8'b0;
            out_valid   <= 1'b0;
            out_data    <= 32'b0;
        end
        else begin
            out_valid <= 1'b0;

            if (in_valid && in_ready) begin
                working   <= 1'b1;
                work_data <= in_data;

                // ============================================================
                // >>>>>>> USER MODIFY REGION 2: START BEGIN <<<<<<<<<<<<<<<<<<
                // 在这里初始化当前元素的多周期算法状态。
                // ============================================================

                cycles_left <= DEMO_CYCLES - 8'd1;

                // ============================================================
                // >>>>>>> USER MODIFY REGION 2: START END <<<<<<<<<<<<<<<<<<<<
                // ============================================================
            end
            else if (working) begin
                // ============================================================
                // >>>>>>> USER MODIFY REGION 3: CALCULATE BEGIN <<<<<<<<<<<<<<
                // 完成时必须同时：
                //   out_data  <= F(work_data);
                //   out_valid <= 1'b1;
                //   working   <= 1'b0;
                // ============================================================

                if (cycles_left != 8'd0) begin
                    cycles_left <= cycles_left - 8'd1;
                end
                else begin
                    out_data  <= work_data;
                    out_valid <= 1'b1;
                    working   <= 1'b0;
                end

                // ============================================================
                // >>>>>>> USER MODIFY REGION 3: CALCULATE END <<<<<<<<<<<<<<<<
                // ============================================================
            end
        end
    end

`ifndef SYNTHESIS
    initial begin
        if (DEMO_CYCLES < 1)
            $error("DEMO_CYCLES must be at least 1");
    end
`endif

endmodule

`default_nettype wire
