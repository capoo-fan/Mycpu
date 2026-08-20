`timescale 1ns / 1ps
`default_nettype none

module tb_array_map_engine;
    localparam [31:0] SRC = 32'h0000_1000;
`ifdef TEST_OVERLAP
    localparam [31:0] DST = SRC + 32'd4;
`else
    localparam [31:0] DST = 32'h0000_2000;
`endif
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
    reg mem_data_ok = 1'b0;
    reg [31:0] mem_rdata = 32'b0;

    reg [31:0] memory [0:4095];
    reg pending = 1'b0;
    reg pending_wr = 1'b0;
    reg [31:0] pending_addr = 32'b0;
    reg [31:0] pending_wdata = 32'b0;
    integer pending_delay = 0;
    integer cycles = 0;
    integer reads = 0;
    integer writes = 0;
    integer i;

    assign mem_addr_ok = mem_req && !pending;

    array_map_engine #(
        .SRC_BEGIN(SRC),
        .SRC_END(SRC + WORDS * 4),
        .DST_BEGIN(DST)
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

        if (mem_req && mem_addr_ok) begin
            pending       <= 1'b1;
            pending_wr    <= mem_wr;
            pending_addr  <= mem_addr;
            pending_wdata <= mem_wdata;
            pending_delay <= 2;
            if (mem_wr)
                writes <= writes + 1;
            else
                reads <= reads + 1;
        end

        if (pending) begin
            if (pending_delay == 0) begin
                pending    <= 1'b0;
                mem_data_ok <= 1'b1;
                if (pending_wr)
                    memory[pending_addr[13:2]] <= pending_wdata;
                else
                    mem_rdata <= memory[pending_addr[13:2]];
            end
            else begin
                pending_delay <= pending_delay - 1;
            end
        end

        if (busy)
            cycles <= cycles + 1;
    end

    initial begin
        for (i = 0; i < 4096; i = i + 1)
            memory[i] = 32'hdead_beef;
        for (i = 0; i < WORDS; i = i + 1) begin
            memory[(SRC >> 2) + i] = 32'h1357_0000 + i * 32'h1021;
`ifndef TEST_OVERLAP
            memory[(DST >> 2) + i] = 32'b0;
`endif
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
                $fatal(1, "Map engine timeout");
            end
        join_any
        disable fork;

        @(posedge clk);
        if (reads != WORDS || writes != WORDS)
            $fatal(1, "transaction count mismatch: reads=%0d writes=%0d",
                   reads, writes);
        for (i = 0; i < WORDS; i = i + 1) begin
`ifdef TEST_OVERLAP
            // identity 且 dst=src+4 时，严格逐项读后写会把第一个 word
            // 依次传播到整个目标区间；预取若未自动关闭就会失败。
            if (memory[(DST >> 2) + i] !== 32'h1357_0000)
                $fatal(1, "overlap Map mismatch at word %0d", i);
`else
            if (memory[(DST >> 2) + i] !== memory[(SRC >> 2) + i])
                $fatal(1, "Map mismatch at word %0d", i);
`endif
        end

        $display("PASS map words=%0d cycles=%0d", WORDS, cycles);
        $finish;
    end

    wire unused = &{1'b0, mem_size, mem_wstrb};
endmodule

`default_nettype wire
