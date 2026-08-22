`timescale 1ns / 1ps
`default_nettype none

module tb_array_accel_engine;
    localparam [31:0] SRC = 32'h0000_1000;
    localparam [31:0] RESULT = 32'h0000_2000;
    localparam integer WORDS = 64;
`ifdef REDUCTION_DEMO_CYCLES
    localparam integer ALGO_CYCLES = `REDUCTION_DEMO_CYCLES;
`else
    localparam integer ALGO_CYCLES = 1;
`endif

    reg clk = 1'b0;
    reg resetn = 1'b0;
    reg start = 1'b0;
    wire busy;
    wire done;
    wire takeover_req;
    wire takeover_grant = takeover_req;
    wire mem_req;
    wire mem_wr;
    wire [1:0] mem_size;
    wire [3:0] mem_wstrb;
    wire [31:0] mem_addr;
    wire [31:0] mem_wdata;
    wire mem_addr_ok;
    wire mem_data_ok;
    wire [31:0] mem_rdata;

    reg [31:0] source [0:WORDS-1];
    reg response_valid = 1'b0;
    reg response_wr = 1'b0;
    reg [31:0] response_addr = 32'b0;
    reg [31:0] response_data = 32'b0;
    reg [31:0] result_word = 32'b0;
    reg [31:0] expected_max = 32'b0;

    integer cycles = 0;
    integer reads = 0;
    integer writes = 0;
    integer algo_accepts = 0;
    integer algo_completions = 0;
    integer addr_stalls = 0;
    integer last_accept_cycle = -1;
    integer i;
    reg algo_element_active = 1'b0;
    reg held_request = 1'b0;
    reg held_wr = 1'b0;
    reg [3:0] held_wstrb = 4'b0;
    reg [31:0] held_addr = 32'b0;
    reg [31:0] held_wdata = 32'b0;

`ifdef REDUCTION_TEST_ADDR_STALL
    // 每五笔读请求制造一次单拍 addr_ok 背压；held_request 置位后放行，
    // 因而既能覆盖请求保持，也不会把同一请求永久阻塞。
    wire force_addr_stall = !mem_wr && !held_request &&
                            ((reads % 5) == 2);
`else
    wire force_addr_stall = 1'b0;
`endif
    wire request_fire = mem_req && mem_addr_ok;
    assign mem_addr_ok = mem_req && !force_addr_stall;
    assign mem_data_ok = response_valid;
    assign mem_rdata   = response_data;

    array_accel_engine #(
        .ARRAY_BEGIN(SRC),
        .ARRAY_END(SRC + WORDS * 4),
        .RESULT_ADDR(RESULT)
    ) dut (
        .clk(clk), .resetn(resetn),
        .start(start), .busy(busy), .done(done),
        .takeover_req(takeover_req),
        .takeover_grant(takeover_grant),
        .mem_req(mem_req), .mem_wr(mem_wr), .mem_size(mem_size),
        .mem_wstrb(mem_wstrb), .mem_addr(mem_addr),
        .mem_wdata(mem_wdata), .mem_addr_ok(mem_addr_ok),
        .mem_data_ok(mem_data_ok), .mem_rdata(mem_rdata)
    );

    always #5 clk = ~clk;

    // 一拍响应、严格有序，并允许响应旧请求的同拍接受下一请求。
    always @(posedge clk) begin
        cycles <= cycles + 1;
        response_valid <= request_fire;

        if (held_request &&
            (!mem_req || (mem_wr !== held_wr) ||
             (mem_wstrb !== held_wstrb) || (mem_addr !== held_addr) ||
             (mem_wdata !== held_wdata)))
            $fatal(1, "Reduction request payload changed under backpressure");

        held_request <= mem_req && !mem_addr_ok;
        if (mem_req && !mem_addr_ok) begin
            addr_stalls <= addr_stalls + 1;
            held_wr    <= mem_wr;
            held_wstrb <= mem_wstrb;
            held_addr  <= mem_addr;
            held_wdata <= mem_wdata;
        end

        if (request_fire) begin
            response_wr   <= mem_wr;
            response_addr <= mem_addr;

            if (mem_size !== 2'b10)
                $fatal(1, "Reduction request size is not word");

            if (mem_wr) begin
                if (mem_addr !== RESULT || mem_wstrb !== 4'b1111)
                    $fatal(1, "Reduction write request mismatch");
                response_data <= mem_wdata;
                writes <= writes + 1;
            end
            else begin
                if (mem_addr !== (SRC + reads * 4))
                    $fatal(1, "Reduction read address mismatch: got=%h", mem_addr);
                if (mem_wstrb !== 4'b0000)
                    $fatal(1, "Reduction read strobe mismatch");
                response_data <= source[(mem_addr - SRC) >> 2];
                reads <= reads + 1;
            end
        end

        if (response_valid && response_wr)
            result_word <= response_data;

        if (dut.algo_accept) begin
            if (algo_element_active && !dut.algo_out_valid)
                $fatal(1, "next element entered before previous completion");

            // 没有存储器背压时，相邻元素恰好隔 ALGO_CYCLES 拍进入。
            // ALGO_CYCLES=1 因而必须做到逐拍接收、零算法气泡。
`ifndef REDUCTION_TEST_ADDR_STALL
            if ((last_accept_cycle >= 0) &&
                ((cycles - last_accept_cycle) != ALGO_CYCLES))
                $fatal(1, "algorithm input bubble: gap=%0d expected=%0d",
                       cycles - last_accept_cycle, ALGO_CYCLES);
`endif

            // 除最后一项外，接收当前项的同拍必须预取下一项。
            if ((algo_accepts < (WORDS - 1)) &&
                (!mem_req || mem_wr))
                $fatal(1, "next read was not chained to algorithm acceptance");

            last_accept_cycle <= cycles;
            algo_accepts <= algo_accepts + 1;
        end

        if (dut.algo_out_valid) begin
            if (!algo_element_active)
                $fatal(1, "algorithm completed without an active element");
            algo_completions <= algo_completions + 1;
        end

        case ({dut.algo_accept, dut.algo_out_valid})
            2'b10: algo_element_active <= 1'b1;
            2'b01: algo_element_active <= 1'b0;
            2'b11: algo_element_active <= 1'b1;
            default: algo_element_active <= algo_element_active;
        endcase
    end

    initial begin
        for (i = 0; i < WORDS; i = i + 1) begin
            source[i] = (i * 97) ^ (i << 16) ^ 32'h1020_3040;
            if (i == 37)
                source[i] = 32'hffff_ff00;
            if (source[i] > expected_max)
                expected_max = source[i];
        end

        repeat (4) @(posedge clk);
        resetn <= 1'b1;
        @(posedge clk);
        start <= 1'b1;
        @(posedge clk);
        start <= 1'b0;

        fork
            begin
                wait (done);
            end
            begin
                repeat (4000) @(posedge clk);
                $fatal(1, "Reduction engine timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (result_word !== expected_max)
            $fatal(1, "Reduction mismatch: got=%h expected=%h",
                   result_word, expected_max);
        if (reads != WORDS || writes != 1 ||
            algo_accepts != WORDS || algo_completions != WORDS)
            $fatal(1, "count mismatch: reads=%0d writes=%0d accepts=%0d completions=%0d",
                   reads, writes, algo_accepts, algo_completions);
`ifdef REDUCTION_TEST_ADDR_STALL
        if (addr_stalls == 0)
            $fatal(1, "addr_ok backpressure was not exercised");
`endif

        $display("PASS reduction words=%0d algo_cycles=%0d cycles=%0d",
                 WORDS, ALGO_CYCLES, cycles);
        $finish;
    end

    wire unused = &{1'b0, response_addr};
endmodule

`default_nettype wire
