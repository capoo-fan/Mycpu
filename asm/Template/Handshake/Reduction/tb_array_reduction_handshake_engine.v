`timescale 1ns / 1ps
`default_nettype none

module tb_array_reduction_handshake_engine;
    localparam [31:0] SRC = 32'h0000_1000;
    localparam [31:0] RESULT = 32'h0000_2000;
    localparam integer WORDS = 24;

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
    reg mem_data_ok = 1'b0;
    reg [31:0] mem_rdata = 32'b0;

    reg [31:0] source [0:WORDS-1];
    reg pending = 1'b0;
    reg pending_wr = 1'b0;
    reg [31:0] pending_addr = 32'b0;
    reg [31:0] pending_wdata = 32'b0;
    reg [31:0] result_word = 32'b0;
    reg [31:0] expected_max = 32'b0;
    integer pending_delay = 0;
    integer cycles = 0;
    integer reads = 0;
    integer writes = 0;
    integer algo_accept_cycle = 0;
    integer algo_completions = 0;
    integer i;
    reg element_active = 1'b0;

    assign mem_addr_ok = mem_req && !pending;

    array_reduction_handshake_engine #(
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

    always @(posedge clk) begin
        mem_data_ok <= 1'b0;
        cycles <= cycles + 1;

        if (mem_req && mem_addr_ok) begin
            pending       <= 1'b1;
            pending_wr    <= mem_wr;
            pending_addr  <= mem_addr;
            pending_wdata <= mem_wdata;
            pending_delay <= 2;

            if (mem_wr) begin
                writes <= writes + 1;
            end
            else begin
                if (element_active)
                    $fatal(1, "next read issued before previous reduction completed");
                element_active <= 1'b1;
                reads <= reads + 1;
            end
        end

        if (pending) begin
            if (pending_delay == 0) begin
                pending     <= 1'b0;
                mem_data_ok <= 1'b1;
                if (pending_wr)
                    result_word <= pending_wdata;
                else
                    mem_rdata <= source[(pending_addr - SRC) >> 2];
            end
            else begin
                pending_delay <= pending_delay - 1;
            end
        end

        if (dut.algo_in_valid && dut.algo_in_ready)
            algo_accept_cycle <= cycles;

        if (dut.algo_out_valid) begin
            if (!element_active)
                $fatal(1, "algorithm completed without an active element");
            if ((cycles - algo_accept_cycle) < 4)
                $fatal(1, "multi-cycle reduction completed too early");
            element_active <= 1'b0;
            algo_completions <= algo_completions + 1;
        end
    end

    initial begin
        for (i = 0; i < WORDS; i = i + 1) begin
            source[i] = (i * 97) ^ (i << 16) ^ 32'h1020_3040;
            if (i == 17)
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
                repeat (3000) @(posedge clk);
                $fatal(1, "handshake Reduction engine timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (result_word !== expected_max)
            $fatal(1, "Reduction mismatch: got=%h expected=%h",
                   result_word, expected_max);
        if (reads != WORDS || writes != 1 || algo_completions != WORDS)
            $fatal(1, "count mismatch: reads=%0d writes=%0d algo=%0d",
                   reads, writes, algo_completions);

        $display("PASS handshake reduction words=%0d cycles=%0d", WORDS, cycles);
        $finish;
    end

    wire unused = &{1'b0, mem_size, mem_wstrb, pending_addr};
endmodule

`default_nettype wire
