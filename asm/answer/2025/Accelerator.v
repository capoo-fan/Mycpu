module array_accelerator #(
    parameter [31:0] ARRAY_BEGIN = 32'h8040_0000,
    parameter [31:0] ARRAY_END   = 32'h8070_0000, // 不包含
    parameter [31:0] RESULT_ADDR = 32'h8070_0000
)(
    input  wire        clk,
    input  wire        resetn,

    // ============================================================
    // CPU / Accelerator control
    // ============================================================

    // EXE 阶段检测到特殊 div 指令时，产生 1 拍 start
    input  wire        start,

    // 加速器正在工作
    // CPU 可以使用 busy 来暂停前端/发射
    output reg         busy,

    // 加速器完成，脉冲 1 个周期
    output reg         done,

    // 请求获得 ExtRAM 独占权
    output wire        takeover_req,

    // 总线仲裁器确认：
    // 1. CPU 原有访存已经全部完成
    // 2. ExtRAM 已交给 Accelerator
    input  wire        takeover_grant,

    // ============================================================
    // ExtRAM request interface
    //
    // 接口形式按照常见 SRAM-like 接口设计：
    //
    // req + addr_ok : 请求被接受
    // data_ok       : 本次事务完成
    // ============================================================

    output reg         mem_req,
    output reg         mem_wr,

    output reg  [31:0] mem_addr,
    output reg  [3:0]  mem_wstrb,
    output reg  [31:0] mem_wdata,

    input  wire        mem_addr_ok,
    input  wire        mem_data_ok,
    input  wire [31:0] mem_rdata
);

    // ============================================================
    // State machine
    // ============================================================

    localparam [3:0]
        S_IDLE       = 4'd0,
        S_WAIT_BUS   = 4'd1,

        S_KEY_REQ    = 4'd2,
        S_KEY_WAIT   = 4'd3,

        S_SCAN_REQ   = 4'd4,
        S_SCAN_WAIT  = 4'd5,

        S_WRITE_REQ  = 4'd6,
        S_WRITE_WAIT = 4'd7;

    reg [3:0] state;

    // ============================================================
    // Accelerator registers
    // ============================================================

    // 数组第一个元素
    reg [31:0] key;

    // 当前扫描地址
    reg [31:0] scan_addr;

    // 统计结果
    reg [31:0] count;

    // ============================================================
    // 总线所有权请求
    // ============================================================

    // 从 start 开始，一直到最终结果写完之前，
    // 加速器都要求独占 ExtRAM。
    assign takeover_req = busy;


    // ============================================================
    // ExtRAM combinational request generation
    // ============================================================

    always @(*) begin

        // 默认不访问
        mem_req   = 1'b0;
        mem_wr    = 1'b0;

        mem_addr  = 32'b0;
        mem_wstrb = 4'b0000;
        mem_wdata = 32'b0;

        case (state)

            // ----------------------------------------------------
            // 读取第一个元素
            // ----------------------------------------------------
            S_KEY_REQ: begin
                mem_req   = 1'b1;
                mem_wr    = 1'b0;
                mem_addr  = ARRAY_BEGIN;
                mem_wstrb = 4'b0000;
            end


            // ----------------------------------------------------
            // 顺序扫描数组
            // ----------------------------------------------------
            S_SCAN_REQ: begin
                mem_req   = 1'b1;
                mem_wr    = 1'b0;
                mem_addr  = scan_addr;
                mem_wstrb = 4'b0000;
            end


            // ----------------------------------------------------
            // 将结果写回 RESULT_ADDR
            // ----------------------------------------------------
            S_WRITE_REQ: begin
                mem_req   = 1'b1;
                mem_wr    = 1'b1;

                mem_addr  = RESULT_ADDR;

                mem_wstrb = 4'b1111;
                mem_wdata = count;
            end

            default: begin
            end

        endcase
    end


    // ============================================================
    // Main FSM
    // ============================================================

    always @(posedge clk) begin

        if (!resetn) begin

            state     <= S_IDLE;

            busy      <= 1'b0;
            done      <= 1'b0;

            key       <= 32'b0;
            scan_addr <= ARRAY_BEGIN;
            count     <= 32'b0;

        end
        else begin

            // done 默认只有 1 拍
            done <= 1'b0;

            case (state)

                // =================================================
                // IDLE
                // =================================================

                S_IDLE: begin

                    busy <= 1'b0;

                    if (start) begin

                        // 捕获 accelerator start
                        busy <= 1'b1;

                        key       <= 32'b0;
                        count     <= 32'b0;
                        scan_addr <= ARRAY_BEGIN;

                        // 先等待 ExtRAM 总线真正交给 accelerator
                        state <= S_WAIT_BUS;
                    end
                end


                // =================================================
                // 等待 CPU 老访存全部完成，然后获得 ExtRAM
                // =================================================

                S_WAIT_BUS: begin

                    if (takeover_grant) begin
                        state <= S_KEY_REQ;
                    end
                end


                // =================================================
                // 发起读取第一个元素
                // =================================================

                S_KEY_REQ: begin

                    if (mem_addr_ok) begin
                        state <= S_KEY_WAIT;
                    end
                end


                // =================================================
                // 等待第一个元素返回
                //
                // 第一个元素一定等于自身，
                // 因此直接 count = 1。
                // 下一地址从 ARRAY_BEGIN + 4 开始。
                // =================================================

                S_KEY_WAIT: begin

                    if (mem_data_ok) begin

                        key   <= mem_rdata;
                        count <= 32'd1;

                        scan_addr <= ARRAY_BEGIN + 32'd4;

                        // 正常题目肯定不止一个元素
                        if ((ARRAY_BEGIN + 32'd4) >= ARRAY_END)
                            state <= S_WRITE_REQ;
                        else
                            state <= S_SCAN_REQ;

                    end
                end


                // =================================================
                // 发起读取当前元素
                // =================================================

                S_SCAN_REQ: begin

                    if (mem_addr_ok) begin
                        state <= S_SCAN_WAIT;
                    end
                end


                // =================================================
                // 等待数据
                //
                // data == key:
                //      count++
                //
                // 然后继续读取下一个 word。
                // =================================================

                S_SCAN_WAIT: begin

                    if (mem_data_ok) begin

                        // 统计
                        if (mem_rdata == key)
                            count <= count + 32'd1;


                        // 当前元素处理完以后，如果已经到末尾
                        if ((scan_addr + 32'd4) >= ARRAY_END) begin

                            // 注意：
                            // count 的非阻塞赋值会在本周期末生效，
                            // 下一周期进入 WRITE_REQ 时看到的是
                            // 已经更新后的 count。
                            state <= S_WRITE_REQ;

                        end
                        else begin

                            scan_addr <= scan_addr + 32'd4;

                            state <= S_SCAN_REQ;

                        end

                    end
                end


                // =================================================
                // 写结果
                // =================================================

                S_WRITE_REQ: begin

                    if (mem_addr_ok) begin
                        state <= S_WRITE_WAIT;
                    end
                end


                // =================================================
                // 等待结果真正写入 SRAM
                // =================================================

                S_WRITE_WAIT: begin

                    if (mem_data_ok) begin

                        busy <= 1'b0;
                        done <= 1'b1;

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