`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// Reduction 算法逻辑模板。一次只接收并处理一个元素。
//
// 默认示例用 4 个计算周期更新无符号最大值。out_valid 表示当前
// 元素已经完成归约，engine 此后才能读下一个元素。
// ============================================================================

module reduction_handshake_logic (
    input  wire        clk,
    input  wire        resetn,

    input  wire        run_start,
    input  wire        in_valid,
    output wire        in_ready,
    input  wire        in_first,
    input  wire [31:0] in_data,

    output reg         out_valid,
    output wire [31:0] result
);

    reg        working;
    reg        work_first;
    reg [31:0] work_data;

    // ========================================================================
    // >>>>>>>>>>>>>>>>>>> USER MODIFY REGION 1 BEGIN <<<<<<<<<<<<<<<<<<<<<<<<<
    // 全局归约状态与每个元素的多周期状态。
    // ========================================================================

    localparam [7:0] DEMO_CYCLES = 8'd4;
    reg [7:0] cycles_left;
    reg [31:0] result_reg;

    // ========================================================================
    // >>>>>>>>>>>>>>>>>>> USER MODIFY REGION 1 END <<<<<<<<<<<<<<<<<<<<<<<<<<<
    // ========================================================================

    assign in_ready = !working;
    assign result   = result_reg;

    always @(posedge clk) begin
        if (!resetn) begin
            working     <= 1'b0;
            work_first  <= 1'b0;
            work_data   <= 32'b0;
            cycles_left <= 8'b0;
            result_reg  <= 32'b0;
            out_valid   <= 1'b0;
        end
        else begin
            out_valid <= 1'b0;

            if (run_start) begin
                working    <= 1'b0;
                result_reg <= 32'b0;

                // ============================================================
                // >>>>>>> USER MODIFY REGION 2: RUN START BEGIN <<<<<<<<<<<<<<
                // 在这里初始化一次新归约任务的全局状态。
                // ============================================================

                cycles_left <= 8'b0;

                // ============================================================
                // >>>>>>> USER MODIFY REGION 2: RUN START END <<<<<<<<<<<<<<<<
                // ============================================================
            end
            else if (in_valid && in_ready) begin
                working    <= 1'b1;
                work_first <= in_first;
                work_data  <= in_data;

                // ============================================================
                // >>>>>>> USER MODIFY REGION 3: ITEM START BEGIN <<<<<<<<<<<<<<
                // 在这里初始化当前元素的多周期状态。
                // ============================================================

                cycles_left <= DEMO_CYCLES - 8'd1;

                // ============================================================
                // >>>>>>> USER MODIFY REGION 3: ITEM START END <<<<<<<<<<<<<<<<
                // ============================================================
            end
            else if (working) begin
                // ============================================================
                // >>>>>>> USER MODIFY REGION 4: CALCULATE BEGIN <<<<<<<<<<<<<<
                // 完成当前元素时必须同时：
                //   更新 result_reg；
                //   out_valid <= 1'b1;
                //   working   <= 1'b0;
                // ============================================================

                if (cycles_left != 8'd0) begin
                    cycles_left <= cycles_left - 8'd1;
                end
                else begin
                    if (work_first || (work_data > result_reg))
                        result_reg <= work_data;
                    out_valid <= 1'b1;
                    working   <= 1'b0;
                end

                // ============================================================
                // >>>>>>> USER MODIFY REGION 4: CALCULATE END <<<<<<<<<<<<<<<<
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
