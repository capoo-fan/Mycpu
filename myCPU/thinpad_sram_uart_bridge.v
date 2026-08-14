`timescale 1ns / 1ps
`default_nettype none

module thinpad_sram_uart_bridge(
    input  wire        clk,
    input  wire        resetn,

    input  wire        inst_sram_req,
    input  wire        inst_sram_wr,
    input  wire [1:0]  inst_sram_size,
    input  wire [3:0]  inst_sram_wstrb,
    input  wire [31:0] inst_sram_addr,
    input  wire [31:0] inst_sram_wdata,
    output wire        inst_sram_addr_ok,
    output wire        inst_sram_data_ok,
    output wire [31:0] inst_sram_rdata,

    input  wire        data_sram_req,
    input  wire        data_sram_wr,
    input  wire [1:0]  data_sram_size,
    input  wire [3:0]  data_sram_wstrb,
    input  wire [31:0] data_sram_addr,
    input  wire [31:0] data_sram_wdata,
    input  wire        early_sram_load_req,
    input  wire [22:0] early_sram_load_addr,
    output wire        data_sram_addr_ok,
    output wire        data_sram_data_ok,
    output wire [31:0] data_sram_rdata,
    output wire        data_sram_fast_ready,
    output wire        data_sram_fast_data_ok,
    output wire [31:0] data_sram_fast_rdata,
    output wire        data_sram_store_ready,
    output wire        data_sram_early_read_accept,
    input  wire        data_sram_store_is_ext,

    output wire [19:0] base_ram_addr,
    output wire [31:0] base_ram_wdata,
    output wire [3:0]  base_ram_be_n,
    output wire        base_ram_ce_n,
    output wire        base_ram_oe_n,
    output wire        base_ram_we_n,
    input  wire [31:0] base_ram_rdata,

    output wire [19:0] ext_ram_addr,
    output wire [31:0] ext_ram_wdata,
    output wire [3:0]  ext_ram_be_n,
    output wire        ext_ram_ce_n,
    output wire        ext_ram_oe_n,
    output wire        ext_ram_we_n,
    input  wire [31:0] ext_ram_rdata,

    input  wire        uart_rx_ready,
    input  wire [7:0]  uart_rx_data,
    input  wire        uart_tx_busy,
    output wire        uart_rx_clear,
    output wire        uart_tx_start,
    output wire [7:0]  uart_tx_data
);
    localparam [1:0] S_IDLE   = 2'd0;
    localparam [1:0] S_ACCESS = 2'd1;
    localparam [1:0] S_DONE   = 2'd2;
    localparam [1:0] SRAM_WAIT_LAST = 2'd0;

    // CPU 导出翻译后的物理地址。
    //解码完整的窗口，以便 UART 和未映射的外设不能与 SRAM 别名。
    wire inst_is_base = (inst_sram_addr & 32'hffc0_0000) == 32'h1c00_0000;
    wire data_is_base = (data_sram_addr & 32'hffc0_0000) == 32'h1c00_0000;
    wire data_is_ext  = (data_sram_addr & 32'hffc0_0000) == 32'h1c40_0000;
    wire data_is_uart = (data_sram_addr & 32'hfff0_0000) == 32'h1f00_0000;
    wire data_is_unmapped = ~(data_is_base | data_is_ext | data_is_uart);

    reg  [1:0]  base_state;
    reg  [1:0]  base_cnt;
    reg         base_client_data;
    (* keep = "true", equivalent_register_removal = "no" *)
    reg         base_fast_data_ok_reg;
    (* keep = "true", equivalent_register_removal = "no" *)
    reg         base_fast_ready_reg;
    reg         base_wr_reg;
    reg  [31:0] base_addr_reg;
    reg  [31:0] base_wdata_reg;
    reg  [3:0]  base_wstrb_reg;

    // 单入口寄存化 posted-store。接受请求时只写入本地寄存器；下一
    // 个完整周期再驱动异步 SRAM。排空拍允许同时接收下一笔 store，
    // 因而连续写吞吐率为一拍一笔。
    reg         base_store_valid;
    reg  [31:0] base_store_addr;
    reg  [31:0] base_store_wdata;
    reg  [3:0]  base_store_wstrb;
    reg         base_store_resp_valid;

    wire base_data_req   = data_sram_req & data_is_base;
    wire base_data_store = base_data_req & data_sram_wr;
    wire base_store_drain = (base_state == S_IDLE) & base_store_valid;
    wire base_store_ready = ~base_store_valid | base_store_drain;
    wire base_store_accept = base_data_store & base_store_ready;
    wire base_data_read  = base_data_req & ~data_sram_wr;
    wire base_inst_req   = inst_sram_req & ~inst_sram_wr & inst_is_base;
    wire base_grant_data = (base_state == S_IDLE) & ~base_store_valid &
                           base_data_read;
    wire base_grant_inst = (base_state == S_IDLE) & ~base_store_valid &
                           ~base_data_read & base_inst_req;
    wire base_grant      = base_grant_data | base_grant_inst;
    wire base_done       = (base_state == S_DONE);

    wire        base_cur_wr    = base_grant_data ? data_sram_wr    :
                                 base_grant_inst ? 1'b0            : base_wr_reg;
    wire [31:0] base_cur_addr  = base_grant_data ? data_sram_addr  :
                                 base_grant_inst ? inst_sram_addr  : base_addr_reg;
    wire [31:0] base_cur_wdata = base_grant_data ? data_sram_wdata :
                                 base_grant_inst ? 32'b0           : base_wdata_reg;
    wire [3:0]  base_cur_wstrb = base_grant_data ? data_sram_wstrb :
                                 base_grant_inst ? 4'b0            : base_wstrb_reg;
    wire        base_read_active = base_grant | (base_state == S_ACCESS) |
                                 (base_done & ~base_wr_reg);
    wire        base_active    = base_store_drain | base_read_active;

    always @(posedge clk) begin
        if (!resetn) begin
            base_state       <= S_IDLE;
            base_cnt         <= 2'b0;
            base_client_data <= 1'b0;
            base_fast_data_ok_reg <= 1'b0;
            base_fast_ready_reg <= 1'b0;
            base_wr_reg      <= 1'b0;
            base_addr_reg    <= 32'b0;
            base_wdata_reg   <= 32'b0;
            base_wstrb_reg   <= 4'b0;
            base_store_valid <= 1'b0;
            base_store_addr  <= 32'b0;
            base_store_wdata <= 32'b0;
            base_store_wstrb <= 4'b0;
            base_store_resp_valid <= 1'b0;
        end else begin
            base_fast_data_ok_reg <= 1'b0;
            base_fast_ready_reg <= 1'b0;
            base_store_resp_valid <= base_store_accept;

            if (base_store_accept) begin
                base_store_valid <= 1'b1;
                base_store_addr  <= data_sram_addr;
                base_store_wdata <= data_sram_wdata;
                base_store_wstrb <= data_sram_wstrb;
            end else if (base_store_drain) begin
                base_store_valid <= 1'b0;
            end
            case (base_state)
                S_IDLE: begin
                    base_cnt <= 2'b0;
                    if (base_grant) begin
                        base_state       <= S_ACCESS;
                        base_client_data <= base_grant_data;
                        base_wr_reg      <= base_grant_data ? data_sram_wr    : 1'b0;
                        base_addr_reg    <= base_grant_data ? data_sram_addr  : inst_sram_addr;
                        base_wdata_reg   <= base_grant_data ? data_sram_wdata : 32'b0;
                        base_wstrb_reg   <= base_grant_data ? data_sram_wstrb : 4'b0;
                    end
                end

                S_ACCESS: begin
                    if (base_cnt == SRAM_WAIT_LAST) begin
                        base_state <= S_DONE;
                        base_cnt   <= 2'b0;
                        base_fast_data_ok_reg <= base_client_data;
                        base_fast_ready_reg <= base_client_data;
                    end else begin
                        base_cnt <= base_cnt + 2'b01;
                    end
                end

                S_DONE: begin
                    base_state <= S_IDLE;
                end

                default: begin
                    base_state <= S_IDLE;
                end
            endcase
        end
    end

    assign base_ram_addr  = base_store_drain ? base_store_addr[21:2] :
                            base_read_active ? base_cur_addr[21:2] : 20'b0;
    assign base_ram_wdata = base_store_drain ? base_store_wdata : base_cur_wdata;
    assign base_ram_be_n  = base_store_drain ? ~base_store_wstrb :
                            base_read_active ? 4'b0000 : 4'b1111;
    assign base_ram_ce_n  = ~base_active;
    assign base_ram_oe_n  = ~base_read_active;
    assign base_ram_we_n  = ~base_store_drain;

    wire base_data_addr_ok = base_store_accept | base_grant_data;
    wire base_data_data_ok = base_store_resp_valid |
                             (base_done & base_client_data);
    wire base_inst_data_ok = base_done & ~base_client_data;

 
    // 不支持的指令地址返回零，而不是死锁 类SRAM 接口。监视代码本身始终位于 BaseRAM 中。
    wire inst_unmapped_grant = inst_sram_req & ~inst_sram_wr & ~inst_is_base;
    reg  inst_unmapped_resp_valid;

    always @(posedge clk) begin
        if (!resetn)
            inst_unmapped_resp_valid <= 1'b0;
        else
            inst_unmapped_resp_valid <= inst_unmapped_grant;
    end

    assign inst_sram_addr_ok = base_grant_inst | inst_unmapped_grant;
    assign inst_sram_data_ok = base_inst_data_ok | inst_unmapped_resp_valid;
    assign inst_sram_rdata   = base_inst_data_ok ? base_ram_rdata : 32'b0;

    reg  [1:0]  ext_state;
    reg  [1:0]  ext_cnt;
    (* keep = "true", equivalent_register_removal = "no" *)
    reg         ext_fast_data_ok_reg;
    (* keep = "true", equivalent_register_removal = "no" *)
    reg         ext_fast_ready_reg;
    reg  [31:0] ext_addr_reg;
    reg         ext_store_valid;
    reg  [31:0] ext_store_addr;
    reg  [31:0] ext_store_wdata;
    reg  [3:0]  ext_store_wstrb;
    reg         ext_store_resp_valid;

    wire ext_data_req = data_sram_req & data_is_ext;
    wire ext_data_store = ext_data_req & data_sram_wr;
    wire ext_store_drain = (ext_state == S_IDLE) & ext_store_valid;
    wire ext_store_ready = ~ext_store_valid | ext_store_drain;
    wire ext_store_accept = ext_data_store & ext_store_ready;
    wire ext_data_read = ext_data_req & ~data_sram_wr;
    // 提前读只覆盖 ExtRAM；标准 data_sram 请求保持最高优先级。
    // 地址低 22 位已经是 DMW 不变的 SRAM bank 内地址。
    wire ext_early_read = early_sram_load_req & early_sram_load_addr[22];
    wire ext_grant_data = (ext_state == S_IDLE) & ~ext_store_valid &
                          ext_data_read;
    wire ext_grant_early = ((ext_state == S_IDLE) ||
                            (ext_state == S_DONE)) &
                           (~ext_store_valid | ext_store_drain) &
                           ~ext_data_req &
                           ext_early_read;
    wire ext_grant = ext_grant_data | ext_grant_early;
    wire ext_done  = (ext_state == S_DONE);

    // S_DONE 上的提前请求只在边沿锁存；边沿前仍用旧地址完成当前响应。
    wire [31:0] ext_cur_addr  = ext_grant_data ? data_sram_addr :
                                 (ext_grant_early &&
                                  (ext_state == S_IDLE)) ?
                                 {9'h038, early_sram_load_addr} :
                                 ext_addr_reg;
    wire        ext_read_active = ext_grant | (ext_state == S_ACCESS) |
                                ext_done;
    wire        ext_active    = ext_store_drain | ext_read_active;

    always @(posedge clk) begin
        if (!resetn) begin
            ext_state     <= S_IDLE;
            ext_cnt       <= 2'b0;
            ext_fast_data_ok_reg <= 1'b0;
            ext_fast_ready_reg <= 1'b0;
            ext_addr_reg  <= 32'b0;
            ext_store_valid <= 1'b0;
            ext_store_addr  <= 32'b0;
            ext_store_wdata <= 32'b0;
            ext_store_wstrb <= 4'b0;
            ext_store_resp_valid <= 1'b0;
        end else begin
            ext_fast_data_ok_reg <= 1'b0;
            ext_fast_ready_reg <= 1'b0;
            ext_store_resp_valid <= ext_store_accept;

            if (ext_store_accept) begin
                ext_store_valid <= 1'b1;
                ext_store_addr  <= data_sram_addr;
                ext_store_wdata <= data_sram_wdata;
                ext_store_wstrb <= data_sram_wstrb;
            end else if (ext_store_drain) begin
                ext_store_valid <= 1'b0;
            end

            case (ext_state)
                S_IDLE: begin
                    ext_cnt <= 2'b0;
                    if (ext_grant) begin
                        ext_state     <= S_ACCESS;
                        ext_addr_reg  <= ext_grant_data ? data_sram_addr :
                                         {9'h038, early_sram_load_addr};
                    end
                end

                S_ACCESS: begin
                    if (ext_cnt == SRAM_WAIT_LAST) begin
                        ext_state <= S_DONE;
                        ext_cnt   <= 2'b0;
                        ext_fast_data_ok_reg <= 1'b1;
                        ext_fast_ready_reg <= 1'b1;
                    end else begin
                        ext_cnt <= ext_cnt + 2'b01;
                    end
                end

                S_DONE: begin
                    if (ext_grant_early) begin
                        ext_state     <= S_ACCESS;
                        ext_addr_reg  <= {9'h038, early_sram_load_addr};
                    end else begin
                        ext_state <= S_IDLE;
                    end
                end

                default: begin
                    ext_state <= S_IDLE;
                end
            endcase
        end
    end

    assign ext_ram_addr  = ext_store_drain ? ext_store_addr[21:2] :
                           ext_read_active ? ext_cur_addr[21:2] : 20'b0;
    // ExtRAM 写操作全部由 posted-store 槽执行；读事务无需锁存写数据和
    // 字节使能，避免 EX 提前读 grant 进入无关的写数据寄存器 D 端。
    assign ext_ram_wdata = ext_store_drain ? ext_store_wdata : 32'b0;
    assign ext_ram_be_n  = ext_store_drain ? ~ext_store_wstrb :
                           ext_read_active ? 4'b0000 : 4'b1111;
    assign ext_ram_ce_n  = ~ext_active;
    // store 排空拍可以在结束边沿锁存下一笔提前读，但该拍 SRAM 引脚
    // 仍是纯写周期，OE 必须保持关闭。
    assign ext_ram_oe_n  = ext_store_drain ? 1'b1 : ~ext_read_active;
    assign ext_ram_we_n  = ~ext_store_drain;

    wire ext_data_addr_ok = ext_store_accept | ext_grant_data;
    wire ext_data_data_ok = ext_store_resp_valid | ext_done;

    // MEM 用一拍后的确认把已经启动的 EX 请求归入当前 load。确认不
    // 参与任何 ready 回环，避免 EX 地址经 bridge 再返回 ISSUE。
    reg ext_early_read_accept_reg;
    always @(posedge clk) begin
        if (!resetn)
            ext_early_read_accept_reg <= 1'b0;
        else
            ext_early_read_accept_reg <= ext_grant_early;
    end
    assign data_sram_early_read_accept = ext_early_read_accept_reg;

    wire [2:0] uart_offset = data_sram_addr[2:0];
    reg        uart_dlab;

    wire [7:0] uart_write_byte = data_sram_wstrb[0] ? data_sram_wdata[ 7: 0] :
                                  data_sram_wstrb[1] ? data_sram_wdata[15: 8] :
                                  data_sram_wstrb[2] ? data_sram_wdata[23:16] :
                                                        data_sram_wdata[31:24];
    wire       uart_req       = data_sram_req & data_is_uart;
    wire       uart_tx_write  = data_sram_wr & (uart_offset == 3'd0) & ~uart_dlab;

    // UART 请求先在桥接器边界锁存，再由本地寄存状态执行。这样来自
    // MEM lane 选择和地址翻译的长组合路径只到达请求寄存器，不再继续
    // 穿过 byte-lane/状态译码到 UART 响应和副作用寄存器。
    reg        uart_req_pending;
    reg        uart_req_wr;
    reg        uart_req_tx_write;
    reg  [2:0] uart_req_offset;
    reg  [7:0] uart_req_write_byte;

    wire uart_grant = uart_req & ~uart_req_pending &
         (~uart_tx_write | ~uart_tx_busy);
    wire uart_exec = uart_req_pending;
    wire [7:0] uart_status =
         {2'b0, ~uart_tx_busy, 4'b0, uart_rx_ready};
    wire [7:0] uart_read_byte =
         (uart_req_offset == 3'd0) ? uart_rx_data :
         (uart_req_offset == 3'd5) ? uart_status : 8'b0;

    function [31:0] place_uart_byte;
        input [7:0] byte_value;
        input [1:0] byte_offset;
        begin
            case (byte_offset)
                2'd0: place_uart_byte = {24'b0, byte_value};
                2'd1: place_uart_byte = {16'b0, byte_value, 8'b0};
                2'd2: place_uart_byte = {8'b0, byte_value, 16'b0};
                default: place_uart_byte = {byte_value, 24'b0};
            endcase
        end
    endfunction

    reg        uart_resp_valid;
    reg [31:0] uart_rdata_reg;
    reg        uart_tx_start_reg;
    reg [7:0]  uart_tx_data_reg;
    reg        uart_rx_clear_reg;

    always @(posedge clk) begin
        if (!resetn) begin
            uart_req_pending  <= 1'b0;
            uart_req_wr       <= 1'b0;
            uart_req_tx_write <= 1'b0;
            uart_req_offset   <= 3'b0;
            uart_req_write_byte <= 8'b0;
            uart_resp_valid   <= 1'b0;
            uart_rdata_reg    <= 32'b0;
            uart_tx_start_reg <= 1'b0;
            uart_tx_data_reg  <= 8'b0;
            uart_rx_clear_reg <= 1'b0;
            uart_dlab         <= 1'b0;
        end else begin
            uart_req_pending <= uart_grant;
            uart_resp_valid  <= uart_exec;

            if (uart_grant) begin
                uart_req_wr         <= data_sram_wr;
                uart_req_tx_write   <= uart_tx_write;
                uart_req_offset     <= uart_offset;
                uart_req_write_byte <= uart_write_byte;
            end

            uart_tx_start_reg <= uart_exec & uart_req_tx_write;
            uart_rx_clear_reg <= uart_exec & ~uart_req_wr &
                                 (uart_req_offset == 3'd0) &
                                 uart_rx_ready;

            if (uart_exec & uart_req_tx_write)
                uart_tx_data_reg <= uart_req_write_byte;

            if (uart_exec & uart_req_wr && (uart_req_offset == 3'd3))
                uart_dlab <= uart_req_write_byte[7];

            if (uart_exec & ~uart_req_wr)
                uart_rdata_reg <= place_uart_byte(uart_read_byte,
                                                   uart_req_offset[1:0]);
        end
    end

    assign uart_tx_start = uart_tx_start_reg;
    assign uart_tx_data  = uart_tx_data_reg;
    assign uart_rx_clear = uart_rx_clear_reg;

    wire uart_data_addr_ok = uart_grant;
    wire uart_data_data_ok = uart_resp_valid;

  
    wire unmapped_grant = data_sram_req & data_is_unmapped;
    reg  unmapped_resp_valid;

    always @(posedge clk) begin
        if (!resetn)
            unmapped_resp_valid <= 1'b0;
        else
            unmapped_resp_valid <= unmapped_grant;
    end

    assign data_sram_addr_ok = base_data_addr_ok | ext_data_addr_ok |
                               uart_data_addr_ok | unmapped_grant;
    assign data_sram_data_ok = base_data_data_ok | ext_data_data_ok |
                               uart_data_data_ok | unmapped_resp_valid;
    assign data_sram_rdata   = base_data_data_ok ? base_ram_rdata :
                               ext_data_data_ok  ? ext_ram_rdata  :
                               uart_data_data_ok ? uart_rdata_reg  : 32'b0;
    assign data_sram_fast_ready =
        base_fast_ready_reg | ext_fast_ready_reg;
    assign data_sram_fast_data_ok =
        base_fast_data_ok_reg | ext_fast_data_ok_reg;
    assign data_sram_fast_rdata = base_data_data_ok ? base_ram_rdata :
                                  ext_ram_rdata;
    // BaseRAM/ExtRAM 是连续的两个 4 MiB 窗口，bit22 直接选择对应的
    // posted-store 槽。该信号只反映槽状态，不穿过请求、UART 或响应
    // OR 树，供 MEM 在已确认物理地址属于 SRAM 后快速退休 store。
    assign data_sram_store_ready = data_sram_store_is_ext ?
                                   ext_store_ready : base_store_ready;

    wire unused_cpu_bus = inst_sram_size[0] | inst_sram_size[1] |
                          (|inst_sram_wstrb) | (|inst_sram_wdata) |
                          data_sram_size[0] | data_sram_size[1];
endmodule

`default_nettype wire
