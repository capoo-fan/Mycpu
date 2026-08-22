`timescale 1ns / 1ps
`default_nettype none

module tb_radix_sort_engine #(
    parameter integer WORDS = 13
);
    localparam [31:0] SRC = 32'h0000_1000;
    localparam [31:0] TMP = 32'h0000_2000;
    localparam integer MAX_WORDS = 16;

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

    reg [31:0] memory [0:8191];
    reg [31:0] expected [0:MAX_WORDS-1];
    reg pending = 1'b0;
    reg pending_wr = 1'b0;
    reg [31:0] pending_addr = 32'b0;
    reg [31:0] pending_wdata = 32'b0;
    integer pending_delay = 0;
    integer cycles = 0;
    integer reads = 0;
    integer writes = 0;
    integer i;
    integer j;
    reg [31:0] temp;

    reg held_request = 1'b0;
    reg held_wr = 1'b0;
    reg [3:0] held_wstrb = 4'b0;
    reg [31:0] held_addr = 32'b0;
    reg [31:0] held_wdata = 32'b0;

    function [31:0] sample;
        input integer index;
        begin
            case (index)
                0: sample = 32'hffff_ffff;
                1: sample = 32'h0000_0000;
                2: sample = 32'h8000_0000;
                3: sample = 32'h0000_0007;
                4: sample = 32'h0000_0007;
                5: sample = 32'h1234_5678;
                6: sample = 32'h0000_0001;
                7: sample = 32'h7fff_ffff;
                8: sample = 32'h0102_0304;
                9: sample = 32'h0001_0000;
                10: sample = 32'h00ff_00ff;
                11: sample = 32'hff00_ff00;
                default: sample = 32'h3141_0000 ^ index;
            endcase
        end
    endfunction

    wire force_stall = ((cycles % 5) == 1) || ((cycles % 11) == 4);
    assign mem_addr_ok = mem_req && !pending && !force_stall;
    wire request_fire = mem_req && mem_addr_ok;

    array_accel_engine #(
        .ARRAY_BEGIN(SRC),
        .ARRAY_END(SRC + WORDS * 4),
        .RESULT_ADDR(TMP),
        .RADIX_BITS(4)
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
        mem_data_ok <= 1'b0;

        if (held_request &&
            (!mem_req || (mem_wr !== held_wr) ||
             (mem_wstrb !== held_wstrb) || (mem_addr !== held_addr) ||
             (mem_wdata !== held_wdata)))
            $fatal(1, "radix request changed under backpressure");

        held_request <= mem_req && !mem_addr_ok;
        if (mem_req && !mem_addr_ok) begin
            held_wr    <= mem_wr;
            held_wstrb <= mem_wstrb;
            held_addr  <= mem_addr;
            held_wdata <= mem_wdata;
        end

        if (request_fire) begin
            if (pending)
                $fatal(1, "radix issued more than one outstanding request");
            if (mem_size !== 2'b10)
                $fatal(1, "radix request is not a word access");
            if (!(((mem_addr >= SRC) && (mem_addr < SRC + WORDS * 4)) ||
                  ((mem_addr >= TMP) && (mem_addr < TMP + WORDS * 4))))
                $fatal(1, "radix access outside source/scratch: %h", mem_addr);
            if (mem_wr && (mem_wstrb !== 4'b1111))
                $fatal(1, "radix write strobe mismatch");
            if (!mem_wr && (mem_wstrb !== 4'b0000))
                $fatal(1, "radix read strobe mismatch");

            pending       <= 1'b1;
            pending_wr    <= mem_wr;
            pending_addr  <= mem_addr;
            pending_wdata <= mem_wdata;
            pending_delay <= cycles % 4;
            if (mem_wr)
                writes <= writes + 1;
            else
                reads <= reads + 1;
        end

        if (pending) begin
            if (pending_delay == 0) begin
                pending     <= 1'b0;
                mem_data_ok <= 1'b1;
                if (pending_wr)
                    memory[pending_addr[14:2]] <= pending_wdata;
                else
                    mem_rdata <= memory[pending_addr[14:2]];
            end
            else begin
                pending_delay <= pending_delay - 1;
            end
        end

        if (cycles > 20000)
            $fatal(1, "radix engine timeout");
    end

    initial begin
        if ((WORDS < 0) || (WORDS > MAX_WORDS))
            $fatal(1, "WORDS must be in 0..%0d", MAX_WORDS);

        for (i = 0; i < 8192; i = i + 1)
            memory[i] = 32'hdead_beef;
        for (i = 0; i < MAX_WORDS; i = i + 1)
            expected[i] = sample(i);
        for (i = 0; i < WORDS; i = i + 1) begin
            memory[(SRC >> 2) + i] = expected[i];
            memory[(TMP >> 2) + i] = 32'hcccc_cccc;
        end

        for (i = 0; i < WORDS; i = i + 1) begin
            for (j = i + 1; j < WORDS; j = j + 1) begin
                if (expected[i] > expected[j]) begin
                    temp = expected[i];
                    expected[i] = expected[j];
                    expected[j] = temp;
                end
            end
        end

        memory[(SRC >> 2) - 1] = 32'ha5a5_5a5a;
        memory[(SRC >> 2) + WORDS] = 32'h5a5a_a5a5;
        memory[(TMP >> 2) - 1] = 32'h1122_3344;
        memory[(TMP >> 2) + WORDS] = 32'h4433_2211;

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
                repeat (20000) @(posedge clk);
                $fatal(1, "radix done timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (busy || takeover_req)
            $fatal(1, "radix did not release the bus");
        for (i = 0; i < WORDS; i = i + 1) begin
            if (memory[(SRC >> 2) + i] !== expected[i])
                $fatal(1, "radix mismatch at word %0d", i);
        end
        if (memory[(SRC >> 2) - 1] !== 32'ha5a5_5a5a ||
            memory[(SRC >> 2) + WORDS] !== 32'h5a5a_a5a5 ||
            memory[(TMP >> 2) - 1] !== 32'h1122_3344 ||
            memory[(TMP >> 2) + WORDS] !== 32'h4433_2211)
            $fatal(1, "radix wrote outside source/scratch arrays");
        if (WORDS >= 2) begin
            if (reads != WORDS * 16)
                $fatal(1, "radix read count mismatch: %0d", reads);
            if (writes != WORDS * 8)
                $fatal(1, "radix write count mismatch: %0d", writes);
        end

        $display("PASS radix words=%0d reads=%0d writes=%0d cycles=%0d",
                 WORDS, reads, writes, cycles);
        $finish;
    end
endmodule

`default_nettype wire
