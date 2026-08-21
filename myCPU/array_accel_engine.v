`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// array_accel_engine.v
//
// 通用 Reduction 加速器：顺序读取数组，由 accelerator_logic 归约，
// 最后只写一个 32-bit 结果。
//
// 本实现把“地址发出”和“数据返回”完全解耦：获得总线后，只要数组尚未
// 发完，就持续保持读请求；mem_addr_ok 每接受一拍，地址递增一个 word。
// 引擎不再人为限制 outstanding 数量，也不会在连续读之间主动插入空拍。
//
// 重要：多个读响应必须保持请求顺序。接口没有 transaction ID，不能接到
// 会乱序返回的主端口。
// ============================================================================

module array_accel_engine #(
    parameter [31:0] ARRAY_BEGIN = 32'h1c40_0000,
    parameter [31:0] ARRAY_END   = 32'h1c70_0000, // exclusive
    parameter [31:0] RESULT_ADDR = 32'h1c70_0000
)(
    input  wire        clk,
    input  wire        resetn,

    input  wire        start,
    output reg         busy,
    output reg         done,

    output wire        takeover_req,
    input  wire        takeover_grant,

    output reg         mem_req,
    output reg         mem_wr,
    output reg  [1:0]  mem_size,
    output reg  [3:0]  mem_wstrb,
    output reg  [31:0] mem_addr,
    output reg  [31:0] mem_wdata,

    input  wire        mem_addr_ok,
    input  wire        mem_data_ok,
    input  wire [31:0] mem_rdata
);

    localparam [2:0]
        S_IDLE       = 3'd0,
        S_WAIT_BUS   = 3'd1,
        S_SCAN       = 3'd2,
        S_WRITE_REQ  = 3'd3,
        S_WRITE_WAIT = 3'd4;

    reg [2:0] state;

    // issue_addr 指向下一笔尚未接受的地址；return_addr 指向下一笔返回
    // 对应的地址。返回严格有序时无需为每笔请求保存完整地址 FIFO。
    reg [31:0] issue_addr;
    reg [31:0] return_addr;

    wire        algo_run_start;
    wire        algo_first_valid;
    wire        algo_data_valid;
    wire [31:0] algo_result;

    assign algo_run_start = (state == S_IDLE) && start;

    accelerator_logic u_accelerator_logic (
        .clk         (clk),
        .resetn      (resetn),
        .run_start   (algo_run_start),
        .first_valid (algo_first_valid),
        .data_valid  (algo_data_valid),
        .data        (mem_rdata),
        .result      (algo_result)
    );

    assign takeover_req = busy;

    wire have_more_requests = (issue_addr < ARRAY_END);

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        case (state)
            S_SCAN: begin
                if (takeover_grant && have_more_requests) begin
                    mem_req  = 1'b1;
                    mem_wr   = 1'b0;
                    mem_addr = issue_addr;
                end
            end

            S_WRITE_REQ: begin
                if (takeover_grant) begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = RESULT_ADDR;
                    mem_wdata = algo_result;
                end
            end

            default: begin
            end
        endcase
    end

    wire read_request_fire = (state == S_SCAN) && mem_req && mem_addr_ok;

    // 支持最后一级在同一拍接受并返回（常规 SRAM bridge 通常至少晚一拍）。
    wire read_response = (state == S_SCAN) && mem_data_ok &&
                         ((return_addr < issue_addr) || read_request_fire);

    assign algo_first_valid = read_response && (return_addr == ARRAY_BEGIN);
    assign algo_data_valid  = read_response && (return_addr != ARRAY_BEGIN);

    wire response_is_last = ((return_addr + 32'd4) >= ARRAY_END);

    always @(posedge clk) begin
        if (!resetn) begin
            state             <= S_IDLE;
            busy              <= 1'b0;
            done              <= 1'b0;
            issue_addr        <= ARRAY_BEGIN;
            return_addr       <= ARRAY_BEGIN;
        end
        else begin
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;

                    if (start) begin
                        busy              <= 1'b1;
                        issue_addr        <= ARRAY_BEGIN;
                        return_addr       <= ARRAY_BEGIN;
                        state             <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        // 空区间的归约结果采用 accelerator_logic 的初值。
                        if (ARRAY_BEGIN >= ARRAY_END)
                            state <= S_WRITE_REQ;
                        else
                            state <= S_SCAN;
                    end
                end

                S_SCAN: begin
                    if (read_request_fire)
                        issue_addr <= issue_addr + 32'd4;

                    if (read_response) begin
                        return_addr <= return_addr + 32'd4;

                        // algo_result 在这个时钟沿更新；状态随后进入
                        // S_WRITE_REQ，组合写数据会看到更新后的结果。
                        if (response_is_last)
                            state <= S_WRITE_REQ;
                    end

                end

                S_WRITE_REQ: begin
                    if (mem_req && mem_addr_ok) begin
                        // 同拍完成的零等待写也必须产生 done。
                        if (mem_data_ok) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            state <= S_WRITE_WAIT;
                        end
                    end
                end

                S_WRITE_WAIT: begin
                    if (mem_data_ok) begin
                        busy  <= 1'b0;
                        done  <= 1'b1;
                        state <= S_IDLE;
                    end
                end

                default: begin
                    state <= S_IDLE;
                    busy  <= 1'b0;
                end
            endcase
        end
    end

endmodule

`default_nettype wire
