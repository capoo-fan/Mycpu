`timescale 1ns / 1ps
`default_nettype none

module tb_array_map_engine;
    localparam [31:0] SRC = 32'h0000_1000;
    localparam [31:0] DST = 32'h0000_2000;
    localparam integer WORDS = 32;

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

    reg [31:0] memory [0:4095];
    reg response_valid = 1'b0;
    reg response_wr = 1'b0;
    reg [31:0] response_addr = 32'b0;
    reg [31:0] response_wdata = 32'b0;
    reg [31:0] response_rdata = 32'b0;
    integer cycles = 0;
    integer reads = 0;
    integer writes = 0;
    integer i;
    reg stream_started = 1'b0;
    reg held_request = 1'b0;
    reg held_wr = 1'b0;
    reg [3:0] held_wstrb = 4'b0;
    reg [31:0] held_addr = 32'b0;
    reg [31:0] held_wdata = 32'b0;

    // 周期性制造 addr_ok 背压，验证请求保持；响应固定晚一拍且严格有序。
    wire force_stall = ((cycles % 7) == 3);
    assign mem_addr_ok = mem_req && !force_stall;
    assign mem_data_ok = response_valid;
    assign mem_rdata   = response_rdata;

    wire request_fire = mem_req && mem_addr_ok;

    array_accel_engine #(
        .ARRAY_BEGIN(SRC),
        .ARRAY_END(SRC + WORDS * 4),
        .RESULT_ADDR(DST)
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
        cycles <= cycles + 1;

        // 一旦首笔请求出现，在最后一笔写请求被接受前，engine 自身不得
        // 拉低 mem_req。addr_ok=0 时仍必须保持当前请求。
        if (stream_started && (writes < WORDS) && !mem_req)
            $fatal(1, "Map request bubble at cycle %0d", cycles);
        if (mem_req)
            stream_started <= 1'b1;

        if (held_request &&
            (!mem_req || (mem_wr !== held_wr) ||
             (mem_wstrb !== held_wstrb) || (mem_addr !== held_addr) ||
             (mem_wdata !== held_wdata)))
            $fatal(1, "Map request payload changed under backpressure");

        held_request <= mem_req && !mem_addr_ok;
        if (mem_req && !mem_addr_ok) begin
            held_wr    <= mem_wr;
            held_wstrb <= mem_wstrb;
            held_addr  <= mem_addr;
            held_wdata <= mem_wdata;
        end

        response_valid <= request_fire;
        if (request_fire) begin
            response_wr    <= mem_wr;
            response_addr  <= mem_addr;
            response_wdata <= mem_wdata;

            if (mem_size !== 2'b10)
                $fatal(1, "Map request size is not word");

            if (mem_wr) begin
                if (reads != (writes + 1))
                    $fatal(1, "Map request order is not read/write alternating");
                if (mem_addr !== (DST + writes * 4))
                    $fatal(1, "Map write address mismatch: got=%h", mem_addr);
                if (mem_wstrb !== 4'b1111)
                    $fatal(1, "Map write strobe mismatch");
                writes <= writes + 1;
            end
            else begin
                if (reads != writes)
                    $fatal(1, "Map issued a second read before its write");
                if (mem_addr !== (SRC + reads * 4))
                    $fatal(1, "Map read address mismatch: got=%h", mem_addr);
                if (mem_wstrb !== 4'b0000)
                    $fatal(1, "Map read strobe mismatch");
                response_rdata <= memory[mem_addr[13:2]];
                reads <= reads + 1;
            end
        end

        if (response_valid && response_wr)
            memory[response_addr[13:2]] <= response_wdata;
    end

    initial begin
        for (i = 0; i < 4096; i = i + 1)
            memory[i] = 32'hdead_beef;
        for (i = 0; i < WORDS; i = i + 1) begin
            memory[(SRC >> 2) + i] = 32'h1357_0000 + i * 32'h1021;
            memory[(DST >> 2) + i] = 32'b0;
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
                repeat (1000) @(posedge clk);
                $fatal(1, "Map engine timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (reads != WORDS || writes != WORDS)
            $fatal(1, "transaction count mismatch: reads=%0d writes=%0d",
                   reads, writes);
        for (i = 0; i < WORDS; i = i + 1) begin
            if (memory[(DST >> 2) + i] !== memory[(SRC >> 2) + i])
                $fatal(1, "Map mismatch at word %0d", i);
        end

        $display("PASS map words=%0d cycles=%0d continuous_requests=1",
                 WORDS, cycles);
        $finish;
    end
endmodule

`default_nettype wire
