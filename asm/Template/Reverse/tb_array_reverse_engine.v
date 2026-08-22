`timescale 1ns / 1ps
`default_nettype none

module tb_array_reverse_engine #(
    parameter integer WORDS = 9
);
    localparam [31:0] SRC = 32'h0000_1000;
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

    reg [31:0] memory [0:2047];
    reg [31:0] original [0:MAX_WORDS-1];

    reg pending = 1'b0;
    reg pending_wr = 1'b0;
    reg [31:0] pending_addr = 32'b0;
    reg [31:0] pending_wdata = 32'b0;
    integer pending_delay = 0;

    reg held_request = 1'b0;
    reg held_wr = 1'b0;
    reg [3:0] held_wstrb = 4'b0;
    reg [31:0] held_addr = 32'b0;
    reg [31:0] held_wdata = 32'b0;

    integer cycles = 0;
    integer transactions = 0;
    integer reads = 0;
    integer writes = 0;
    integer i;

    // Backpressure is independent of the response delay.  The memory accepts
    // only one outstanding transaction, exactly the contract needed here.
    wire force_stall = ((cycles % 7) == 3) || ((cycles % 11) == 5);
    assign mem_addr_ok = mem_req && !pending && !force_stall;
    wire request_fire = mem_req && mem_addr_ok;

    array_accel_engine #(
        .ARRAY_BEGIN(SRC),
        .ARRAY_END(SRC + WORDS * 4),
        .RESULT_ADDR(SRC)
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
            $fatal(1, "request payload changed under backpressure");

        held_request <= mem_req && !mem_addr_ok;
        if (mem_req && !mem_addr_ok) begin
            held_wr    <= mem_wr;
            held_wstrb <= mem_wstrb;
            held_addr  <= mem_addr;
            held_wdata <= mem_wdata;
        end

        if (request_fire) begin
            if (pending)
                $fatal(1, "more than one outstanding transaction");
            if (mem_size !== 2'b10)
                $fatal(1, "request is not a 32-bit word access");

            // Every pair must perform R(left), R(right), W(left), W(right).
            case (transactions % 4)
                0: begin
                    if (mem_wr ||
                        (mem_addr !== SRC + (transactions / 4) * 4))
                        $fatal(1, "left read order/address mismatch");
                end
                1: begin
                    if (mem_wr ||
                        (mem_addr !== SRC + (WORDS - 1 -
                                             transactions / 4) * 4))
                        $fatal(1, "right read order/address mismatch");
                end
                2: begin
                    if (!mem_wr || mem_wstrb !== 4'b1111 ||
                        (mem_addr !== SRC + (transactions / 4) * 4) ||
                        (mem_wdata !== original[WORDS - 1 -
                                               transactions / 4]))
                        $fatal(1, "left write payload mismatch");
                end
                3: begin
                    if (!mem_wr || mem_wstrb !== 4'b1111 ||
                        (mem_addr !== SRC + (WORDS - 1 -
                                             transactions / 4) * 4) ||
                        (mem_wdata !== original[transactions / 4]))
                        $fatal(1, "right write payload mismatch");
                end
            endcase

            transactions  <= transactions + 1;
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
                    memory[pending_addr[12:2]] <= pending_wdata;
                else
                    mem_rdata <= memory[pending_addr[12:2]];
            end
            else begin
                pending_delay <= pending_delay - 1;
            end
        end

        if (cycles > 2000)
            $fatal(1, "reverse engine timeout");
    end

    initial begin
        if ((WORDS < 0) || (WORDS > MAX_WORDS))
            $fatal(1, "WORDS must be in 0..%0d", MAX_WORDS);

        for (i = 0; i < 2048; i = i + 1)
            memory[i] = 32'hdead_beef;
        for (i = 0; i < MAX_WORDS; i = i + 1)
            original[i] = 32'h5a00_0000 + i * 32'h0001_1021;
        for (i = 0; i < WORDS; i = i + 1)
            memory[(SRC >> 2) + i] = original[i];

        memory[(SRC >> 2) - 1] = 32'ha5a5_5a5a;
        memory[(SRC >> 2) + WORDS] = 32'h5a5a_a5a5;

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
                $fatal(1, "done timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (busy || takeover_req)
            $fatal(1, "bus was not released after done");
        if (reads != (WORDS / 2) * 2 || writes != (WORDS / 2) * 2)
            $fatal(1, "transaction count mismatch: reads=%0d writes=%0d",
                   reads, writes);
        for (i = 0; i < WORDS; i = i + 1) begin
            if (memory[(SRC >> 2) + i] !== original[WORDS - 1 - i])
                $fatal(1, "reverse mismatch at word %0d", i);
        end
        if (memory[(SRC >> 2) - 1] !== 32'ha5a5_5a5a ||
            memory[(SRC >> 2) + WORDS] !== 32'h5a5a_a5a5)
            $fatal(1, "accelerator wrote outside the array");

        $display("PASS reverse words=%0d reads=%0d writes=%0d cycles=%0d",
                 WORDS, reads, writes, cycles);
        $finish;
    end
endmodule

`default_nettype wire
