`timescale 1ns / 1ps
`include "defines.vh"

module mycpu_top(
	input  wire        clock,
	input  wire        reset, // 高电平有效复位信号

    // --- BaseRAM---
    input  wire [31:0] io_baseSram_rspns_rData,
    output wire [31:0] io_baseSram_req_wData,
    output wire [19:0] io_baseSram_req_addr,
    output wire [3:0]  io_baseSram_req_byteSelN,
    output wire        io_baseSram_req_ce,
    output wire        io_baseSram_req_oe,
    output wire        io_baseSram_req_we,

    // --- ExtRAM ---
    input  wire [31:0] io_extSram_rspns_rData,
    output wire [31:0] io_extSram_req_wData,
    output wire [19:0] io_extSram_req_addr,
    output wire [3:0]  io_extSram_req_byteSelN,
    output wire        io_extSram_req_ce,
    output wire        io_extSram_req_oe,
    output wire        io_extSram_req_we,

    // --- UART ---
    input  wire        io_uart_rxd,
    output wire        io_uart_txd

);

    wire aresetn = ~reset;//换成低电平有效的复位信号

    wire [3:0]      ic_req;
    wire [31:0] ic_addr;
    wire        ic_data_valid;
    wire [63:0] ic_rdata;

    wire [3:0]  cpu2dc_ren;
    wire [31:0] cpu2dc_addr;
    wire        dc2cpu_valid;
    wire [31:0] dc2cpu_rdata;
    wire [3:0]  cpu2dc_wen;
    wire [31:0] cpu2dc_wdata;
    wire [31:0] cpu2dc_waddr;
    wire        dc2cpu_wresp;

    wire [3:0]  dc_read_req;
    wire [31:0] dc_read_addr;
    wire        dc_data_valid;
    wire [63:0] dc_rdata;
    wire        dc_write_req;
    wire [3:0]  dc_write_be;
    wire [31:0] dc_write_addr;
    wire [31:0] dc_write_data;
    wire        dc_write_resp;
    

    mycpu u_mycpu (
        .cpu_rstn   (aresetn),
        .cpu_clk    (clock),
        

        .ic2dev_ren         (ic_req),
        .ic2dev_addr        (ic_addr),
        .dev2ic_rrdy        (1'b1),
        .dev2ic_rvalid      (ic_data_valid),
        .dev2ic_rdata       (ic_rdata),
        

        .daccess_ren    (cpu2dc_ren),
        .daccess_addr   (cpu2dc_addr),
        .daccess_valid  (dc2cpu_valid),
        .daccess_rdata  (dc2cpu_rdata),
        .daccess_wen    (cpu2dc_wen),
        .daccess_wdata  (cpu2dc_wdata),
        .daccess_waddr  (cpu2dc_waddr),
        .daccess_wresp  (dc2cpu_wresp)
        
    );
    wire [7:0] master_to_transmiter_tx;
    wire master_to_transmiter_start;
    wire master_to_receiver_clear;
    
    wire uart_receiver_ready;
    wire [7:0]uart_receiver_data;
   
    wire uart_transmitter_busy;

    sram_master u_sram_arbiter (
        .clk    (clock),
        .resetn (aresetn),

        // ICache
        .ic_req         (|ic_req),
        .ic_addr        (ic_addr),
        .ic_data_valid  (ic_data_valid),
        .ic_rdata       (ic_rdata),

        // DRead
        .dc_read_req    (|cpu2dc_ren),
        .dc_read_addr   (cpu2dc_addr),
        .dc_data_valid  (dc2cpu_valid),
        .dc_rdata       (dc2cpu_rdata),
        
        // DWrite
        .dc_write_req   (|cpu2dc_wen),
        .dc_write_be    (cpu2dc_wen),
        .dc_write_addr  (cpu2dc_waddr),
        .dc_write_data  (cpu2dc_wdata),
        .dc_write_resp  (dc2cpu_wresp),

        // BaseRAM
        .baseRam_addr   (io_baseSram_req_addr),
        .baseRam_wdata  (io_baseSram_req_wData),
        .baseRam_be_n   (io_baseSram_req_byteSelN),
        .baseRam_ce_n   (io_baseSram_req_ce),
        .baseRam_oe_n   (io_baseSram_req_oe),
        .baseRam_we_n   (io_baseSram_req_we),
        .baseRam_rdata  (io_baseSram_rspns_rData),

        // ExtRAM
        .extRam_addr    (io_extSram_req_addr),
        .extRam_wdata   (io_extSram_req_wData),
        .extRam_be_n    (io_extSram_req_byteSelN),
        .extRam_ce_n    (io_extSram_req_ce),
        .extRam_oe_n    (io_extSram_req_oe),
        .extRam_we_n    (io_extSram_req_we),
        .extRam_rdata   (io_extSram_rspns_rData),
        
            // --- UART 逻辑接口 (新增) ---
        .ext_uart_ready(uart_receiver_ready), // 来自 async_receiver
        .ext_uart_rx(uart_receiver_data),    // 来自 async_receiver
        .ext_uart_busy(uart_transmitter_busy),  // 来自 async_transmitter
        .ext_uart_clear(master_to_receiver_clear), // 到 async_receiver
        .ext_uart_start(master_to_transmiter_start), // 到 async_transmitter
        .ext_uart_tx(master_to_transmiter_tx)     // 到 async_transmitter
    );
    

   async_receiver #(.ClkFrequency(265000000), .Baud(9600)) uart_receiver_inst (
        .clk(clock),
        .RxD(io_uart_rxd),          // 连接到顶层输入
        .RxD_data_ready(uart_receiver_ready),
        .RxD_clear(master_to_receiver_clear),
        .RxD_data(uart_receiver_data)
    );

    // 发送模块
    async_transmitter #(.ClkFrequency(265000000), .Baud(9600)) uart_transmitter_inst (
        .clk(clock),
        .TxD(io_uart_txd),          // 连接到顶层输出
        .TxD_busy(uart_transmitter_busy),
        .TxD_start(master_to_transmiter_start),
        .TxD_data(master_to_transmiter_tx)
    );
endmodule
