`timescale 1ns / 1ps
`include "mycpu.vh"

module inst_buffer_timing_tb;
  reg clk;
  reg resetn;
  reg flush;
  reg push_valid_0;
  reg push_valid_1;
  reg [`FS_TO_DS_BUS_WD-1:0] push_bus_0;
  reg [`FS_TO_DS_BUS_WD-1:0] push_bus_1;
  reg pop_0;
  reg pop_1;
  wire push_ready;
  wire full;
  wire front_valid_0;
  wire front_valid_1;
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1;

  inst_buffer dut(
    .clk(clk), .resetn(resetn), .flush(flush),
    .push_valid_0(push_valid_0), .push_bus_0(push_bus_0),
    .push_valid_1(push_valid_1), .push_bus_1(push_bus_1),
    .push_ready(push_ready), .full(full),
    .pop_0(pop_0), .pop_1(pop_1),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1)
  );

  always #5 clk = ~clk;

  function [`FS_TO_DS_BUS_WD-1:0] make_fetch;
    input [7:0] id;
    reg [31:0] pc;
    reg [31:0] inst;
    reg [31:0] target;
    begin
      pc = 32'h1c00_0000 + ({24'b0, id} << 2);
      inst = 32'h0280_0000 | {24'b0, id};
      target = 32'h1c10_0000 + ({24'b0, id} << 2);
      make_fetch = {pc, inst, id[0], target};
    end
  endfunction

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "inst_buffer_timing_tb failed");
    end
  endtask

  task check_front;
    input expected_valid_0;
    input [7:0] expected_id_0;
    input expected_valid_1;
    input [7:0] expected_id_1;
    input [511:0] name;
    begin
      #1;
      if (front_valid_0 !== expected_valid_0 ||
          front_valid_1 !== expected_valid_1)
        fail(name);
      if (expected_valid_0 &&
          front_bus_0[`FS_TO_DS_BUS_WD-1:0] !== make_fetch(expected_id_0))
        fail(name);
      if (expected_valid_1 &&
          front_bus_1[`FS_TO_DS_BUS_WD-1:0] !== make_fetch(expected_id_1))
        fail(name);
      if (front_valid_1 && !front_valid_0)
        fail("front1 valid without front0");
      if (full === push_ready)
        fail("full and push_ready are not complements");
    end
  endtask

  task drive_cycle;
    input do_push_0;
    input [7:0] push_id_0;
    input do_push_1;
    input [7:0] push_id_1;
    input do_pop_0;
    input do_pop_1;
    begin
      @(negedge clk);
      push_valid_0 = do_push_0;
      push_valid_1 = do_push_1;
      push_bus_0 = make_fetch(push_id_0);
      push_bus_1 = make_fetch(push_id_1);
      pop_0 = do_pop_0;
      pop_1 = do_pop_1;
      if ((do_push_0 || do_push_1) && !push_ready)
        fail("test attempted push while buffer was not ready");
      @(posedge clk);
      #1;
      @(negedge clk);
      push_valid_0 = 1'b0;
      push_valid_1 = 1'b0;
      pop_0 = 1'b0;
      pop_1 = 1'b0;
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    flush = 1'b0;
    push_valid_0 = 1'b0;
    push_valid_1 = 1'b0;
    push_bus_0 = {`FS_TO_DS_BUS_WD{1'b0}};
    push_bus_1 = {`FS_TO_DS_BUS_WD{1'b0}};
    pop_0 = 1'b0;
    pop_1 = 1'b0;

    repeat (3) @(posedge clk);
    @(negedge clk);
    resetn = 1'b1;
    @(posedge clk);
    check_front(1'b0, 8'd0, 1'b0, 8'd0, "reset state");

    // Empty push is first stored in FIFO, then refilled into the two front slots.
    drive_cycle(1'b1, 8'd1, 1'b1, 8'd2, 1'b0, 1'b0);
    check_front(1'b0, 8'd0, 1'b0, 8'd0, "push latency");
    drive_cycle(1'b0, 8'd0, 1'b0, 8'd0, 1'b0, 1'b0);
    check_front(1'b1, 8'd1, 1'b1, 8'd2, "initial refill");

    // Keep two entries behind front and consume only lane0.
    drive_cycle(1'b1, 8'd3, 1'b1, 8'd4, 1'b0, 1'b0);
    check_front(1'b1, 8'd1, 1'b1, 8'd2, "queued pair");
    drive_cycle(1'b0, 8'd0, 1'b0, 8'd0, 1'b1, 1'b0);
    check_front(1'b1, 8'd2, 1'b1, 8'd3, "single pop shift");

    // Simultaneous single pop and dual push exercises head/tail/count updates.
    drive_cycle(1'b1, 8'd5, 1'b1, 8'd6, 1'b1, 1'b0);
    check_front(1'b1, 8'd3, 1'b1, 8'd4, "simultaneous pop and push");

    // The timing-critical dual pop must directly load the FIFO head pair.
    drive_cycle(1'b0, 8'd0, 1'b0, 8'd0, 1'b1, 1'b1);
    check_front(1'b1, 8'd5, 1'b1, 8'd6, "dual pop direct refill");

    // Repeat across the four-entry FIFO wrap boundary.
    drive_cycle(1'b1, 8'd7, 1'b1, 8'd8, 1'b0, 1'b0);
    drive_cycle(1'b0, 8'd0, 1'b0, 8'd0, 1'b1, 1'b1);
    check_front(1'b1, 8'd7, 1'b1, 8'd8, "first wrapped refill");
    drive_cycle(1'b1, 8'd9, 1'b1, 8'd10, 1'b0, 1'b0);
    drive_cycle(1'b0, 8'd0, 1'b0, 8'd0, 1'b1, 1'b1);
    check_front(1'b1, 8'd9, 1'b1, 8'd10, "second wrapped refill");

    // Flush discards both front and queued entries and restores push readiness.
    drive_cycle(1'b1, 8'd11, 1'b1, 8'd12, 1'b0, 1'b0);
    @(negedge clk);
    flush = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    flush = 1'b0;
    check_front(1'b0, 8'd0, 1'b0, 8'd0, "flush state");
    if (!push_ready)
      fail("buffer did not become ready after flush");

    $display("PASS inst_buffer_timing_tb");
    $finish;
  end
endmodule
