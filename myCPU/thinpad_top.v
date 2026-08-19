`timescale 1ns / 1ps
`default_nettype none

module thinpad_top(
    input  wire        clk_50M,
    input  wire        clk_11M0592,

    input  wire        clock_btn,
    input  wire        reset_btn,

    input  wire [3:0]  touch_btn,
    input  wire [31:0] dip_sw,
    output wire [15:0] leds,
    output wire [7:0]  dpy0,
    output wire [7:0]  dpy1,

    // BaseRAM
    (* IBUF_LOW_PWR = "FALSE" *) inout wire [31:0] base_ram_data,
    output wire [19:0] base_ram_addr,
    output wire [3:0]  base_ram_be_n,
    output wire        base_ram_ce_n,
    output wire        base_ram_oe_n,
    output wire        base_ram_we_n,

    // ExtRAM
    (* IBUF_LOW_PWR = "FALSE" *) inout wire [31:0] ext_ram_data,
    output wire [19:0] ext_ram_addr,
    output wire [3:0]  ext_ram_be_n,
    output wire        ext_ram_ce_n,
    output wire        ext_ram_oe_n,
    output wire        ext_ram_we_n,

    // UART
    output wire        txd,
    input  wire        rxd,

    // Flash, unused
    output wire [22:0] flash_a,
    inout  wire [15:0] flash_d,
    output wire        flash_rp_n,
    output wire        flash_vpen,
    output wire        flash_ce_n,
    output wire        flash_oe_n,
    output wire        flash_we_n,
    output wire        flash_byte_n,

    // VGA
    output wire [2:0]  video_red,
    output wire [2:0]  video_green,
    output wire [1:0]  video_blue,
    output wire        video_hsync,
    output wire        video_vsync,
    output wire        video_clk,
    output wire        video_de
);


localparam integer CPU_CLK_FREQ = 153400000;


wire cpu_clk;
wire pll_locked;
pll_example clock_gen 
 (
  // Clock in ports
  .clk_in1(clk_50M),  // 外部时钟输入
  // Clock out ports
  .clk_out1(cpu_clk), // 时钟输出1，频率在IP配置界面中设置
  // Status and control signals
  .reset(reset_btn), // PLL复位输入
  .locked(pll_locked)    // PLL锁定指示输出，"1"表示时钟稳定，
                     // 后级电路复位信号应当由它生成（见下）
 );

 wire reset_async = reset_btn | ~pll_locked;
    reg  [1:0] resetn_sync;

    always @(posedge cpu_clk or posedge reset_async) begin
        if (reset_async)
            resetn_sync <= 2'b00;
        else
            resetn_sync <= {resetn_sync[0], 1'b1};
    end

    wire cpu_resetn = resetn_sync[1];

    wire        inst_sram_req;
    wire        inst_sram_wr;
    wire [1:0]  inst_sram_size;
    wire [3:0]  inst_sram_wstrb;
    wire [31:0] inst_sram_addr;
    wire [31:0] inst_sram_wdata;
    wire        inst_sram_addr_ok;
    wire        inst_sram_data_ok;
    wire [31:0] inst_sram_rdata;

    wire        data_sram_req;
    wire        data_sram_wr;
    wire [1:0]  data_sram_size;
    wire [3:0]  data_sram_wstrb;
    wire [31:0] data_sram_addr;
    wire [31:0] data_sram_wdata;
    wire        data_sram_addr_ok;
    wire        data_sram_data_ok;
    wire [31:0] data_sram_rdata;
    wire        data_sram_fast_ready;
    wire        data_sram_fast_data_ok;
    wire [31:0] data_sram_fast_rdata;
    wire        data_sram_store_ready;

    mycpu_top u_cpu (
        .clk                (cpu_clk),
        .resetn             (cpu_resetn),

        .inst_sram_req      (inst_sram_req),
        .inst_sram_wr       (inst_sram_wr),
        .inst_sram_size     (inst_sram_size),
        .inst_sram_wstrb    (inst_sram_wstrb),
        .inst_sram_addr     (inst_sram_addr),
        .inst_sram_wdata    (inst_sram_wdata),
        .inst_sram_addr_ok  (inst_sram_addr_ok),
        .inst_sram_data_ok  (inst_sram_data_ok),
        .inst_sram_rdata    (inst_sram_rdata),

        .data_sram_req      (data_sram_req),
        .data_sram_wr       (data_sram_wr),
        .data_sram_size     (data_sram_size),
        .data_sram_wstrb    (data_sram_wstrb),
        .data_sram_addr     (data_sram_addr),
        .data_sram_wdata    (data_sram_wdata),
        .data_sram_addr_ok  (data_sram_addr_ok),
        .data_sram_data_ok  (data_sram_data_ok),
        .data_sram_rdata    (data_sram_rdata),
        .data_sram_fast_ready(data_sram_fast_ready),
        .data_sram_fast_data_ok(data_sram_fast_data_ok),
        .data_sram_fast_rdata(data_sram_fast_rdata),
        .data_sram_store_ready(data_sram_store_ready),

        .debug_wb_pc        (),
        .debug_wb_rf_we     (),
        .debug_wb_rf_wnum   (),
        .debug_wb_rf_wdata  ()
    );

    wire [31:0] base_ram_rdata = base_ram_data;
    wire [31:0] base_ram_wdata;
    wire [31:0] ext_ram_rdata  = ext_ram_data;
    wire [31:0] ext_ram_wdata;

    assign base_ram_data = !base_ram_we_n ? base_ram_wdata : 32'hzzzz_zzzz;
    assign ext_ram_data  = !ext_ram_we_n  ? ext_ram_wdata  : 32'hzzzz_zzzz;

    wire       uart_rx_ready;
    wire [7:0] uart_rx_data;
    wire       uart_rx_clear;
    wire       uart_tx_busy;
    wire       uart_tx_start;
    wire [7:0] uart_tx_data;

    thinpad_sram_uart_bridge u_bridge (
        .clk                (cpu_clk),
        .resetn             (cpu_resetn),

        .inst_sram_req      (inst_sram_req),
        .inst_sram_wr       (inst_sram_wr),
        .inst_sram_size     (inst_sram_size),
        .inst_sram_wstrb    (inst_sram_wstrb),
        .inst_sram_addr     (inst_sram_addr),
        .inst_sram_wdata    (inst_sram_wdata),
        .inst_sram_addr_ok  (inst_sram_addr_ok),
        .inst_sram_data_ok  (inst_sram_data_ok),
        .inst_sram_rdata    (inst_sram_rdata),

        .data_sram_req      (data_sram_req),
        .data_sram_wr       (data_sram_wr),
        .data_sram_size     (data_sram_size),
        .data_sram_wstrb    (data_sram_wstrb),
        .data_sram_addr     (data_sram_addr),
        .data_sram_wdata    (data_sram_wdata),
        .data_sram_addr_ok  (data_sram_addr_ok),
        .data_sram_data_ok  (data_sram_data_ok),
        .data_sram_rdata    (data_sram_rdata),
        .data_sram_fast_ready(data_sram_fast_ready),
        .data_sram_fast_data_ok(data_sram_fast_data_ok),
        .data_sram_fast_rdata(data_sram_fast_rdata),
        .data_sram_store_ready(data_sram_store_ready),

        .base_ram_addr      (base_ram_addr),
        .base_ram_wdata     (base_ram_wdata),
        .base_ram_be_n      (base_ram_be_n),
        .base_ram_ce_n      (base_ram_ce_n),
        .base_ram_oe_n      (base_ram_oe_n),
        .base_ram_we_n      (base_ram_we_n),
        .base_ram_rdata     (base_ram_rdata),

        .ext_ram_addr       (ext_ram_addr),
        .ext_ram_wdata      (ext_ram_wdata),
        .ext_ram_be_n       (ext_ram_be_n),
        .ext_ram_ce_n       (ext_ram_ce_n),
        .ext_ram_oe_n       (ext_ram_oe_n),
        .ext_ram_we_n       (ext_ram_we_n),
        .ext_ram_rdata      (ext_ram_rdata),

        .uart_rx_ready      (uart_rx_ready),
        .uart_rx_data       (uart_rx_data),
        .uart_tx_busy       (uart_tx_busy),
        .uart_rx_clear      (uart_rx_clear),
        .uart_tx_start      (uart_tx_start),
        .uart_tx_data       (uart_tx_data)
    );

    async_receiver #(
        .ClkFrequency(CPU_CLK_FREQ),
        .Baud(115200)
    ) u_uart_rx (
        .clk            (cpu_clk),
        .RxD            (rxd),
        .RxD_data_ready (uart_rx_ready),
        .RxD_clear      (uart_rx_clear),
        .RxD_data       (uart_rx_data)
    );

    async_transmitter #(
        .ClkFrequency(CPU_CLK_FREQ),
        .Baud(115200)
    ) u_uart_tx (
        .clk       (cpu_clk),
        .TxD_start (uart_tx_start),
        .TxD_data  (uart_tx_data),
        .TxD       (txd),
        .TxD_busy  (uart_tx_busy)
    );

    assign flash_a      = 23'b0;
    assign flash_d      = 16'hzzzz;
    assign flash_rp_n   = 1'b1;
    assign flash_vpen   = 1'b0;
    assign flash_ce_n   = 1'b1;
    assign flash_oe_n   = 1'b1;
    assign flash_we_n   = 1'b1;
    assign flash_byte_n = 1'b1;

    wire [7:0] number = 8'b0;
    SEG7_LUT segL(.oSEG1(dpy0), .iDIG(number[3:0]));
    SEG7_LUT segH(.oSEG1(dpy1), .iDIG(number[7:4]));

    assign leds = 16'b0;

    wire [11:0] hdata;
    assign video_red   = hdata < 12'd266 ? 3'b111 : 3'b000;
    assign video_green = hdata < 12'd532 && hdata >= 12'd266 ? 3'b111 : 3'b000;
    assign video_blue  = hdata >= 12'd532 ? 2'b11  : 2'b00;
    assign video_clk   = clk_50M;

    vga #(12, 800, 856, 976, 1040, 600, 637, 643, 666, 1, 1) vga800x600at75 (
        .clk         (clk_50M),
        .hdata       (hdata),
        .vdata       (),
        .hsync       (video_hsync),
        .vsync       (video_vsync),
        .data_enable (video_de)
    );

    wire unused_inputs = clk_11M0592 | clock_btn | (|touch_btn) | (|dip_sw);
endmodule

`default_nettype wire
