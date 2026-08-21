`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// array_accel_engine.v
//
// 通用 Map 加速器：RESULT_ADDR[i] = F(ARRAY_BEGIN[i])。
//
// 本模块与 Reduction 模板使用完全相同的模块名、参数和 CPU/存储器端口。
// Map 中 RESULT_ADDR 表示结果数组首地址，ARRAY_END 是源数组独占上界。
//
// 连续请求约定：
//   - 获得总线后，引擎不会在相邻元素之间主动插入请求空拍；
//   - 一拍返回的读数据可在同拍形成写请求，写响应拍可同时请求下一元素；
//   - mem_addr_ok 拉低时，mem_req 以及全部请求载荷保持稳定；
//   - 下游造成的背压不计为引擎插入的气泡。
//   - mem_data_ok 最早在对应请求被接受后的下一拍返回，不支持零延迟响应。
//
// accelerator_logic 必须能在读响应拍组合返回结果；寄存流水、多周期或会
// 拉低 in_ready 的算法请使用 Template/Handshake/Map。
// 源/目标区间只支持互不重叠或完全原地映射，部分重叠与连续流水语义冲突。
// ============================================================================

module array_accel_engine #(
    parameter [31:0] ARRAY_BEGIN = 32'h1c40_0000,
    parameter [31:0] ARRAY_END   = 32'h1c50_0000, // exclusive
    parameter [31:0] RESULT_ADDR = 32'h1c50_0000
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
        S_READ_REQ   = 3'd2,
        S_READ_WAIT  = 3'd3,
        S_ALGO_WAIT  = 3'd4,
        S_WRITE_REQ  = 3'd5,
        S_WRITE_WAIT = 3'd6;

    reg [2:0] state;
    reg [31:0] array_addr;
    reg [31:0] result_addr;
    reg [31:0] result_data;

    wire        algo_in_valid;
    wire        algo_in_ready;
    wire [31:0] algo_out_data;
    wire        algo_out_valid;

    // 读响应没有 ready，因此只允许在算法空闲时发起当前元素的读取。
    assign algo_in_valid = (state == S_READ_WAIT) && mem_data_ok;

    accelerator_logic u_accelerator_logic (
        .clk      (clk),
        .resetn   (resetn),
        .in_valid (algo_in_valid),
        .in_ready (algo_in_ready),
        .in_data  (mem_rdata),
        .out_valid(algo_out_valid),
        .out_data (algo_out_data)
    );

    assign takeover_req = busy;

    wire current_is_last = ((array_addr + 32'd4) >= ARRAY_END);

    // 算法结果出现的当拍直接尝试写出；若下游背压，时钟沿锁存到
    // result_data，随后由 S_WRITE_REQ 保持稳定。
    wire direct_write = ((state == S_READ_WAIT) ||
                         (state == S_ALGO_WAIT)) && algo_out_valid;

    // 写响应到达的当拍直接提出下一元素读请求，消除状态切换气泡。
    wire chain_next_read = (state == S_WRITE_WAIT) && mem_data_ok &&
                           !current_is_last;

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        if (takeover_grant) begin
            case (state)
                S_READ_REQ: begin
                    mem_req  = 1'b1;
                    mem_addr = array_addr;
                end

                S_READ_WAIT,
                S_ALGO_WAIT: begin
                    if (direct_write) begin
                        mem_req   = 1'b1;
                        mem_wr    = 1'b1;
                        mem_wstrb = 4'b1111;
                        mem_addr  = result_addr;
                        mem_wdata = algo_out_data;
                    end
                end

                S_WRITE_REQ: begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = result_addr;
                    mem_wdata = result_data;
                end

                S_WRITE_WAIT: begin
                    if (chain_next_read) begin
                        mem_req  = 1'b1;
                        mem_addr = array_addr + 32'd4;
                    end
                end

                default: begin
                end
            endcase
        end
    end

    wire request_fire = mem_req && mem_addr_ok;

    always @(posedge clk) begin
        if (!resetn) begin
            state       <= S_IDLE;
            busy        <= 1'b0;
            done        <= 1'b0;
            array_addr  <= ARRAY_BEGIN;
            result_addr <= RESULT_ADDR;
            result_data <= 32'b0;
        end
        else begin
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;

                    if (start) begin
                        busy        <= 1'b1;
                        array_addr  <= ARRAY_BEGIN;
                        result_addr <= RESULT_ADDR;
                        state       <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        if (ARRAY_BEGIN >= ARRAY_END) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            state <= S_READ_REQ;
                        end
                    end
                end

                S_READ_REQ: begin
                    if (request_fire) begin
                        state <= S_READ_WAIT;
                    end
                end

                S_READ_WAIT: begin
                    if (mem_data_ok) begin
                        if (!algo_in_ready) begin
                            // 接口没有读响应反压能力；仿真断言会报告该错误。
                            state <= S_READ_WAIT;
                        end
                        else if (algo_out_valid) begin
                            if (request_fire) begin
                                state <= S_WRITE_WAIT;
                            end
                            else begin
                                result_data <= algo_out_data;
                                state       <= S_WRITE_REQ;
                            end
                        end
                        else begin
                            state <= S_ALGO_WAIT;
                        end
                    end
                end

                S_ALGO_WAIT: begin
                    if (algo_out_valid) begin
                        if (request_fire) begin
                            state <= S_WRITE_WAIT;
                        end
                        else begin
                            result_data <= algo_out_data;
                            state       <= S_WRITE_REQ;
                        end
                    end
                end

                S_WRITE_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            if (current_is_last) begin
                                busy  <= 1'b0;
                                done  <= 1'b1;
                                state <= S_IDLE;
                            end
                            else begin
                                array_addr  <= array_addr + 32'd4;
                                result_addr <= result_addr + 32'd4;
                                state       <= S_READ_REQ;
                            end
                        end
                        else begin
                            state <= S_WRITE_WAIT;
                        end
                    end
                end

                S_WRITE_WAIT: begin
                    if (mem_data_ok) begin
                        if (current_is_last) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            array_addr  <= array_addr + 32'd4;
                            result_addr <= result_addr + 32'd4;
                            state       <= request_fire ? S_READ_WAIT :
                                                          S_READ_REQ;
                        end
                    end
                end

                default: begin
                    state <= S_IDLE;
                    busy  <= 1'b0;
                end
            endcase
        end
    end

`ifndef SYNTHESIS
    localparam [31:0] RESULT_END = RESULT_ADDR + (ARRAY_END - ARRAY_BEGIN);
    initial begin
        if ((ARRAY_BEGIN < ARRAY_END) &&
            (RESULT_ADDR != ARRAY_BEGIN) &&
            (RESULT_ADDR < ARRAY_END) && (RESULT_END > ARRAY_BEGIN))
            $error("Map source/result ranges must not partially overlap");
    end

    always @(posedge clk) begin
        if (resetn && algo_in_valid && !algo_in_ready)
            $error("Map accelerator_logic was not ready for a read response");
    end
`endif

endmodule

`default_nettype wire
