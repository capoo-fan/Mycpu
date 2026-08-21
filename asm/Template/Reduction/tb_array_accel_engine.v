`timescale 1ns / 1ps
`default_nettype none

module tb_array_accel_engine;
    localparam [31:0] SRC = 32'h0000_1000;
    localparam [31:0] RESULT = 32'h0000_2000;
    localparam integer WORDS = 64;
    localparam integer LATENCY = 6;

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
    wire mem_addr_ok = mem_req;
    wire mem_data_ok;
    wire [31:0] mem_rdata;

    reg pipe_valid [0:LATENCY-1];
    reg pipe_wr [0:LATENCY-1];
    reg [31:0] pipe_addr [0:LATENCY-1];
    reg [31:0] pipe_data [0:LATENCY-1];
    reg [31:0] source [0:WORDS-1];
    reg [31:0] result_word = 32'b0;
    integer outstanding = 0;
    integer max_outstanding = 0;
    integer cycles = 0;
    integer reads = 0;
    integer writes = 0;
    integer i;
    reg [31:0] expected_max = 32'b0;
    reg read_stream_started = 1'b0;

    wire request_fire = mem_req && mem_addr_ok;
    wire response_fire = mem_data_ok;

    assign mem_data_ok = pipe_valid[LATENCY-1];
    assign mem_rdata   = pipe_data[LATENCY-1];

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

    always @(posedge clk) begin
        for (i = LATENCY-1; i > 0; i = i - 1) begin
            pipe_valid[i] <= pipe_valid[i-1];
            pipe_wr[i]    <= pipe_wr[i-1];
            pipe_addr[i]  <= pipe_addr[i-1];
            pipe_data[i]  <= pipe_data[i-1];
        end

        pipe_valid[0] <= request_fire;
        pipe_wr[0]    <= mem_wr;
        pipe_addr[0]  <= mem_addr;
        if (mem_wr)
            pipe_data[0] <= mem_wdata;
        else if (request_fire)
            pipe_data[0] <= source[(mem_addr - SRC) >> 2];

        if (read_stream_started && (reads < WORDS) &&
            (!mem_req || mem_wr))
            $fatal(1, "Reduction read-request bubble at cycle %0d", cycles);

        if (request_fire) begin
            if (mem_size !== 2'b10)
                $fatal(1, "Reduction request size is not word");

            if (mem_wr) begin
                if (mem_addr !== RESULT || mem_wstrb !== 4'b1111)
                    $fatal(1, "Reduction write request mismatch");
                writes <= writes + 1;
            end
            else begin
                read_stream_started <= 1'b1;
                if (mem_addr !== (SRC + reads * 4))
                    $fatal(1, "Reduction read address mismatch: got=%h", mem_addr);
                if (mem_wstrb !== 4'b0000)
                    $fatal(1, "Reduction read strobe mismatch");
                reads <= reads + 1;
            end
        end

        if (response_fire && pipe_wr[LATENCY-1])
            result_word <= pipe_data[LATENCY-1];

        case ({request_fire, response_fire})
            2'b10: outstanding <= outstanding + 1;
            2'b01: outstanding <= outstanding - 1;
            default: outstanding <= outstanding;
        endcase

        if (request_fire && !response_fire &&
            ((outstanding + 1) > max_outstanding))
            max_outstanding <= outstanding + 1;

        if (busy)
            cycles <= cycles + 1;
    end

    initial begin
        for (i = 0; i < LATENCY; i = i + 1) begin
            pipe_valid[i] = 1'b0;
            pipe_wr[i] = 1'b0;
            pipe_addr[i] = 32'b0;
            pipe_data[i] = 32'b0;
        end
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
                repeat (2000) @(posedge clk);
                $fatal(1, "Reduction engine timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (result_word !== expected_max)
            $fatal(1, "Reduction mismatch: got=%h expected=%h",
                   result_word, expected_max);
        if (reads != WORDS || writes != 1)
            $fatal(1, "transaction count mismatch: reads=%0d writes=%0d",
                   reads, writes);
        if (max_outstanding < LATENCY)
            $fatal(1, "continuous read pipeline was not filled");

        $display("PASS reduction words=%0d cycles=%0d max_outstanding=%0d continuous_reads=1",
                 WORDS, cycles, max_outstanding);
        $finish;
    end

    wire unused = &{1'b0, pipe_addr[LATENCY-1]};
endmodule

`default_nettype wire
