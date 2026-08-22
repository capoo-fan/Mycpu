`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// Reduction 算法逻辑模板。
//
// array_accel_engine 负责地址、数组遍历、访存、输入缓冲和最终写回；本模块
// 只负责逐项更新 result = reduce(A[i])。
//
// 握手约定：
//   - in_valid && in_ready：接收当前元素；
//   - out_valid：刚刚接收的一个元素处理完成；
//   - 每次输入握手必须按顺序产生且只产生一次 out_valid；
//   - 允许 out_valid 与下一次输入握手同拍发生，以保持单拍吞吐。
// ============================================================================

module accelerator_logic (
    input  wire        clk,
    input  wire        resetn,

    input  wire        run_start,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire        in_first,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] result
);

    reg        working;
    reg        work_first;
    reg [31:0] work_data;

    // ========================================================================
    // >>>>>>>>>>>>>>>>>>> USER MODIFY REGION 1 BEGIN <<<<<<<<<<<<<<<<<<<<<<<<<
    // 算法状态。默认每项用一拍完成无符号最大值归约。
    // 多周期算法可修改 DEMO_CYCLES、增加状态寄存器及完成条件。
    // ========================================================================

`ifdef REDUCTION_DEMO_CYCLES
    localparam [7:0] DEMO_CYCLES = `REDUCTION_DEMO_CYCLES;
`else
    localparam [7:0] DEMO_CYCLES = 8'd1;
`endif

    reg [7:0]  cycles_left;
    reg [31:0] result_reg;

    // 当前项完成的同拍立即重新拉高 ready。这样 DEMO_CYCLES=1 时，
    // 第一个元素之后每拍都能完成旧元素并接收新元素，中间没有空拍。
    wire item_done = working && (cycles_left == 8'd0);

    // ========================================================================
    // >>>>>>>>>>>>>>>>>>> USER MODIFY REGION 1 END <<<<<<<<<<<<<<<<<<<<<<<<<<<
    // ========================================================================

    assign in_ready = !working || item_done;
    assign out_valid = item_done;
    assign result = result_reg;

    always @(posedge clk) begin
        if (!resetn) begin
            working     <= 1'b0;
            work_first  <= 1'b0;
            work_data   <= 32'b0;
            cycles_left <= 8'b0;
            result_reg  <= 32'b0;
        end
        else if (run_start) begin
            working     <= 1'b0;
            work_first  <= 1'b0;
            work_data   <= 32'b0;
            cycles_left <= 8'b0;

            // =================================================================
            // >>>>>>> USER MODIFY REGION 2: RUN START BEGIN <<<<<<<<<<<<<<<<<<<
            // 在这里初始化一次新归约任务的全局状态。
            // =================================================================

            result_reg <= 32'b0;

            // =================================================================
            // >>>>>>> USER MODIFY REGION 2: RUN START END <<<<<<<<<<<<<<<<<<<<<
            // =================================================================
        end
        else begin
            // =================================================================
            // >>>>>>> USER MODIFY REGION 3: ITEM COMPLETE BEGIN <<<<<<<<<<<<<<<
            // item_done 表示旧元素本拍完成。必须在这里提交该元素对全局
            // 归约状态的更新；out_valid 已由固定握手逻辑同拍产生。
            // =================================================================

            if (item_done) begin
                if (work_first || (work_data > result_reg))
                    result_reg <= work_data;
            end

            // =================================================================
            // >>>>>>> USER MODIFY REGION 3: ITEM COMPLETE END <<<<<<<<<<<<<<<<<
            // =================================================================

            // 完成旧元素与接收新元素可以同拍发生。后面的输入分支拥有
            // working/cycles_left 的优先级，从而无气泡启动下一项。
            if (in_valid && in_ready) begin
                working     <= 1'b1;
                work_first  <= in_first;
                work_data   <= in_data;

                // =============================================================
                // >>>>>>> USER MODIFY REGION 4: ITEM START BEGIN <<<<<<<<<<<<<<<
                // 在这里初始化当前元素的多周期状态。
                // =============================================================

                cycles_left <= DEMO_CYCLES - 8'd1;

                // =============================================================
                // >>>>>>> USER MODIFY REGION 4: ITEM START END <<<<<<<<<<<<<<<<<
                // =============================================================
            end
            else if (working) begin
                // =============================================================
                // >>>>>>> USER MODIFY REGION 5: CALCULATE BEGIN <<<<<<<<<<<<<<<<
                // 多周期算法在这里推进状态，并在完成前保持 item_done=0。
                // =============================================================

                if (cycles_left != 8'd0)
                    cycles_left <= cycles_left - 8'd1;
                else
                    working <= 1'b0;

                // =============================================================
                // >>>>>>> USER MODIFY REGION 5: CALCULATE END <<<<<<<<<<<<<<<<<<
                // =============================================================
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
