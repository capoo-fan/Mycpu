`timescale 1ns / 1ps
`define SerialState 32'hBFD003FC
`define SerialData  32'hBFD003F8

module sram_master(
    // Inputs
    input  wire         clk,
    input  wire         resetn,

    // ICache
    input  wire         ic_req,
    input  wire [31:0]  ic_addr,
    output wire         ic_data_valid,
    output wire [63:0] ic_rdata,

    // DRead
    input  wire         dc_read_req,
    input  wire [31:0]  dc_read_addr,
    output wire         dc_data_valid,
    output wire [31:0]  dc_rdata,

    // DWrite
    input  wire         dc_write_req,
    input  wire [3:0]   dc_write_be,
    input  wire [31:0]  dc_write_addr,
    input  wire [31:0]  dc_write_data,
    output wire         dc_write_resp,

    // BaseRAM
    output wire [19:0]  baseRam_addr,
    output wire [31:0]  baseRam_wdata,
    output wire [3:0]   baseRam_be_n,
    output wire         baseRam_ce_n,
    output wire         baseRam_oe_n,
    output wire         baseRam_we_n,
    input  wire [31:0]  baseRam_rdata,

    // ExtRAM
    output wire [19:0]  extRam_addr,
    output wire [31:0]  extRam_wdata,
    output wire [3:0]   extRam_be_n,
    output wire         extRam_ce_n,
    output wire         extRam_oe_n,
    output wire         extRam_we_n,
    input  wire [31:0]  extRam_rdata,

    // UART
    input  wire         ext_uart_ready,
    input  wire [7:0]   ext_uart_rx,
    input  wire         ext_uart_busy,
    output wire         ext_uart_clear,
    output wire         ext_uart_start,
    output wire [7:0]   ext_uart_tx
);

    localparam S_IDLE           = 3'd0;
    localparam S_DREAD_SINGLE   = 3'd1;
    localparam S_IREAD_BURST    = 3'd2;
    localparam S_DWRITE_SETUP   = 3'd3;
    localparam S_IreadDONE      = 3'd5;
    localparam S_DreadDONE      = 3'd6;
    localparam S_DwriteDONE     = 3'd7;
    localparam U_IDLE           =2'd0;
    localparam U_READ             = 2'd1;
    localparam U_WRITE           =2'd2;
    reg [1:0]uart_state;
    reg [2:0] base_state;
    reg [2:0] ext_state;
    reg [3:0] base_burst_cnt;
    reg [1:0] base_dread_cnt;
    reg [1:0] ext_dread_cnt;
    reg busrt_addr;
    always @(posedge clk or negedge resetn) begin
        if(!resetn)begin
            uart_state <= U_IDLE;   
        end else begin
            case(uart_state)
                U_IDLE:begin
                    if(uart_wants_write)begin
                        uart_state<=U_WRITE;
                    end   else if (uart_wants_read) begin
                        uart_state<=U_READ;
                    end                  
                end
                U_READ:begin
                    uart_state <= U_IDLE;
                end
                U_WRITE:begin
                    uart_state <= U_IDLE;                
                end
                default:begin
                    uart_state <= U_IDLE;
                end
            endcase
        end
    end    
    

    always @(posedge clk or negedge resetn) begin
        if (!resetn) begin
            base_state     <= S_IDLE;
            base_burst_cnt <= 4'b0000;
            base_dread_cnt <= 2'b00;
            busrt_addr     <= 1'b0;
        end else begin
            case (base_state)
                S_IDLE: begin
                    if (base_grant_dread) begin
                        base_state <= S_DREAD_SINGLE;
                       /* base_dread_cnt <= base_dread_cnt+1'b1;*/
                    end else if (base_grant_iread) begin
                        base_state     <= S_IREAD_BURST;
                        base_burst_cnt <= base_burst_cnt + 1'b1;
                        busrt_addr     <= 1'b0;
                    end else if (base_grant_dwrite) begin
                        base_state <= S_DWRITE_SETUP;
                    end
                end
                S_DREAD_SINGLE: begin
                    if(base_dread_cnt == 2'b11)begin
                        base_state <= S_DreadDONE;
                        base_dread_cnt <= 2'b0;
                    end else begin
                        base_dread_cnt <= base_dread_cnt +1'b1;
                    end
                end
                S_IREAD_BURST: begin
                    if(!ic_req)begin
                        base_state     <= S_IDLE;
                        base_burst_cnt <= 4'b0000;                        
                    end  else if (base_burst_cnt == 4'b0100) begin
                        busrt_addr <= 1'b1;
                        base_burst_cnt <= base_burst_cnt + 1'b1;
                    end else if (base_burst_cnt == 4'b1001) begin
                        base_state     <= S_IreadDONE;
                        base_burst_cnt <= 4'b0000;
                        busrt_addr <= 1'b0;
                    end else begin
                        base_burst_cnt <= base_burst_cnt + 1'b1;
                    end
                end
                S_DWRITE_SETUP: begin
                    base_state <= S_IDLE;
                end
                S_DwriteDONE:begin
                    base_state <= S_IDLE;
                end
                default: begin
                    base_state <= S_IDLE;
                end
            endcase
        end
    end

    always @(posedge clk or negedge resetn) begin
        if (!resetn) begin
            ext_state <= S_IDLE;
            ext_dread_cnt <=2'b00;
        end else begin
            case (ext_state)
                S_IDLE: begin
                    if (ext_grant_dread) begin
                        ext_state <= S_DREAD_SINGLE;
                        /*ext_dread_cnt <= ext_dread_cnt +1'b1;*/
                    end else if (ext_grant_dwrite) begin
                        ext_state <= S_DWRITE_SETUP;
                    end
                end
                S_DREAD_SINGLE: begin
                    if(ext_dread_cnt == 2'b11)begin
                        ext_state <= S_DreadDONE;
                        ext_dread_cnt <= 2'b00;
                    end else begin
                        ext_dread_cnt <= ext_dread_cnt +1'b1;                   
                    end
                end
                S_DWRITE_SETUP: begin
                    ext_state <= S_IDLE;
                end
                S_DwriteDONE:begin
                   ext_state <= S_IDLE; 
                end
                default: begin
                    ext_state <= S_IDLE;
                end
            endcase
        end
    end

    reg [31:0]  base_req_addr_reg;
    reg [31:0] base_rdata_burst;
    always @(posedge clk or negedge resetn) begin
        if (!resetn) begin
            base_req_addr_reg <= 32'b0;
            base_rdata_burst  <= 32'b0;
        end else begin
            if (base_grant_iread) begin
                base_req_addr_reg <= ic_addr;
            end
            
            if (base_state == S_IREAD_BURST) begin
                case(base_burst_cnt)
                    4'b0101: base_rdata_burst[31:0]   <= baseRam_rdata;
                endcase
            end
        end
    end

    reg [31:0] base_dwrite_addr_reg;
    reg [31:0] base_dwrite_data_reg;
    reg [3:0]  base_dwrite_be_reg;
    reg [31:0] ext_dwrite_addr_reg;
    reg [31:0] ext_dwrite_data_reg;
    reg [3:0]  ext_dwrite_be_reg;
    always @(posedge clk or negedge resetn) begin
        if (!resetn) begin
            base_dwrite_addr_reg <= 32'b0;
            base_dwrite_data_reg <= 32'b0;
            base_dwrite_be_reg   <= 4'b0;
            ext_dwrite_addr_reg  <= 32'b0;
            ext_dwrite_data_reg  <= 32'b0;
            ext_dwrite_be_reg    <= 4'b0;
        end else begin
            if (base_grant_dwrite) begin
                base_dwrite_addr_reg <= dc_write_addr;
                base_dwrite_data_reg <= dc_write_data;
                base_dwrite_be_reg   <= dc_write_be;
            end else if (ext_grant_dwrite) begin
                ext_dwrite_addr_reg  <= dc_write_addr;
                ext_dwrite_data_reg  <= dc_write_data;
                ext_dwrite_be_reg    <= dc_write_be;
            end
        end
    end

    // 控制信号生成
    wire is_base_busy      = (base_state != S_IDLE);
    wire is_ext_busy       = (ext_state != S_IDLE);

    wire uart_wants_read   = dc_read_req  && (dc_read_addr[29]);
    wire uart_wants_write  = dc_write_req && (dc_write_addr[29]);
    wire is_uart_req       = uart_wants_read || uart_wants_write;

    wire base_wants_dread  = dc_read_req  && !dc_read_addr[22]  && !is_uart_req;
    wire base_wants_iread  = ic_req;
    wire base_wants_dwrite = dc_write_req && !dc_write_addr[22] && !is_uart_req;
    
    wire ext_wants_dread   = dc_read_req  &&  dc_read_addr[22]  && !is_uart_req;
    wire ext_wants_dwrite  = dc_write_req &&  dc_write_addr[22] && !is_uart_req;

    wire base_grant_dread  = base_wants_dread  && !is_base_busy;
    wire base_grant_iread  = base_wants_iread  && !base_wants_dread &&!base_wants_dwrite && !is_base_busy;
    wire base_grant_dwrite = base_wants_dwrite && !base_wants_dread &&!is_base_busy;

    wire ext_grant_dread   = ext_wants_dread   && !is_ext_busy;
    wire ext_grant_dwrite  = ext_wants_dwrite  && !ext_wants_dread && !is_ext_busy;

    wire do_base_dread        = base_grant_dread  || (base_state == S_DREAD_SINGLE) ;
    wire do_base_iread        = base_grant_iread  || (base_state == S_IREAD_BURST);
    wire do_base_dwrite_setup = base_grant_dwrite;
    wire do_base_dwrite_exec  = (base_state == S_DWRITE_SETUP);

    wire do_ext_dread         = ext_grant_dread   || (ext_state == S_DREAD_SINGLE);
    wire do_ext_dwrite_setup  = ext_grant_dwrite;
    wire do_ext_dwrite_exec   = (ext_state == S_DWRITE_SETUP);

// BaseRAM
wire                baseRam_ce_n_next;
wire                baseRam_oe_n_next;
wire                baseRam_we_n_next;
wire [19:0]         baseRam_addr_next;
wire [31:0]         baseRam_wdata_next;
wire [3:0]          baseRam_be_n_next;

// ExtRAM
wire                extRam_ce_n_next;
wire                extRam_oe_n_next;
wire                extRam_we_n_next;
wire [19:0]         extRam_addr_next;
wire [31:0]         extRam_wdata_next;
wire [3:0]          extRam_be_n_next;

// UART
wire                ext_uart_start_next;
wire [7:0]          ext_uart_tx_next;
wire                ext_uart_clear_next;

// BaseRAM
assign baseRam_ce_n_next  = !(do_base_dread || do_base_iread || do_base_dwrite_setup || do_base_dwrite_exec);
assign baseRam_oe_n_next  = !(do_base_dread || do_base_iread);
assign baseRam_we_n_next  = !(do_base_dwrite_exec||do_base_dwrite_setup);
assign baseRam_addr_next  = do_base_dread        ? dc_read_addr[21:2]
                          : do_base_iread        ? {(base_state == S_IDLE ? ic_addr[21:3] : base_req_addr_reg[21:3]), busrt_addr}
                          : do_base_dwrite_setup ? dc_write_addr[21:2]
                          : do_base_dwrite_exec  ? base_dwrite_addr_reg[21:2]
                          : 20'b0;
assign baseRam_wdata_next = do_base_dwrite_setup  ? dc_write_data:do_base_dwrite_exec  ? base_dwrite_data_reg : 32'b0;
assign baseRam_be_n_next  = (do_base_dread || do_base_iread) ? 4'b0000
                          : do_base_dwrite_setup             ? ~dc_write_be
                          : do_base_dwrite_exec              ? ~base_dwrite_be_reg
                          : 4'b1111;

// ExtRAM 
assign extRam_ce_n_next   = !(do_ext_dread || do_ext_dwrite_setup || do_ext_dwrite_exec);
assign extRam_oe_n_next   = !(do_ext_dread);
assign extRam_we_n_next   = !(do_ext_dwrite_exec||do_ext_dwrite_setup);
assign extRam_addr_next   = do_ext_dread         ? dc_read_addr[21:2]
                          : do_ext_dwrite_setup  ? dc_write_addr[21:2]
                          : do_ext_dwrite_exec   ? ext_dwrite_addr_reg[21:2]
                          : 20'b0;
assign extRam_wdata_next  = do_ext_dwrite_setup  ? dc_write_data:do_ext_dwrite_exec   ? ext_dwrite_data_reg : 32'b0;
assign extRam_be_n_next   = do_ext_dread         ? 4'b0000
                          : do_ext_dwrite_setup  ? ~dc_write_be
                          : do_ext_dwrite_exec   ? ~ext_dwrite_be_reg
                          : 4'b1111;

// UART 
assign ext_uart_start_next = uart_wants_write && (uart_state == U_IDLE);
assign ext_uart_tx_next    = dc_write_data[7:0];
assign ext_uart_clear_next = uart_wants_read && (!dc_read_addr[2])&&(uart_state == U_IDLE);


// 响应信号与数据生成
    wire base_iread_done  = (base_state == S_IreadDONE);
    wire base_dread_done  = (base_state == S_DreadDONE);
    wire base_dwrite_done = base_grant_dwrite;
    wire ext_dread_done   = (ext_state == S_DreadDONE);
    wire ext_dwrite_done  = ext_grant_dwrite;

    assign ic_data_valid = base_iread_done;
    assign dc_data_valid = base_dread_done || ext_dread_done || (uart_state == U_READ);
    assign dc_write_resp = (dc_write_addr[22]&&!is_ext_busy)||(!dc_write_addr[22]&&!is_base_busy)|| (uart_state == U_WRITE);

    assign ic_rdata      = {baseRam_rdata, base_rdata_burst[31:0]};

    wire [31:0] uart_rdata = (dc_read_addr[2]) ? {30'b0, ext_uart_ready, !ext_uart_busy}
                                                           : {24'b0, ext_uart_rx};
    reg [31:0] uart_rdata_reg;
always @(posedge clk or negedge resetn) begin
    if (!resetn) begin
        uart_rdata_reg <=32'b0;
    end else begin
        uart_rdata_reg <=uart_rdata;
    end
end
    assign dc_rdata = ({32{base_dread_done}} & baseRam_rdata) |
                      ({32{ext_dread_done}}  & extRam_rdata)  |
                      ({32{(uart_state == U_READ)}} & uart_rdata_reg);


// BaseRAM 
reg                 baseRam_ce_n_reg;
reg                 baseRam_oe_n_reg;
reg                 baseRam_we_n_reg;
reg [19:0]          baseRam_addr_reg;
reg [31:0]          baseRam_wdata_reg;
reg [3:0]           baseRam_be_n_reg;

// ExteRAM 
reg                 extRam_ce_n_reg;
reg                 extRam_oe_n_reg;
reg                 extRam_we_n_reg;
reg [19:0]          extRam_addr_reg;
reg [31:0]          extRam_wdata_reg;
reg [3:0]           extRam_be_n_reg;

// UART
reg                 ext_uart_start_reg;
reg [7:0]           ext_uart_tx_reg;
reg                 ext_uart_clear_reg;

always @(posedge clk or negedge resetn) begin
    if (!resetn) begin
        baseRam_ce_n_reg  <= 1'b1;       
        baseRam_oe_n_reg  <= 1'b1;       
        baseRam_we_n_reg  <= 1'b1;       
        baseRam_addr_reg  <= 20'b0;
        baseRam_wdata_reg <= 32'b0;
        baseRam_be_n_reg  <= 4'b1111;    

        extRam_ce_n_reg   <= 1'b1;       
        extRam_oe_n_reg   <= 1'b1;       
        extRam_we_n_reg   <= 1'b1;       
        extRam_addr_reg   <= 20'b0;
        extRam_wdata_reg  <= 32'b0;
        extRam_be_n_reg   <= 4'b1111;    

        ext_uart_start_reg <= 1'b0;
        ext_uart_tx_reg    <= 8'b0;
        ext_uart_clear_reg <= 1'b0;
    end else begin

        baseRam_ce_n_reg  <= baseRam_ce_n_next;
        baseRam_oe_n_reg  <= baseRam_oe_n_next;
        baseRam_we_n_reg  <= baseRam_we_n_next;
        baseRam_addr_reg  <= baseRam_addr_next;
        baseRam_wdata_reg <= baseRam_wdata_next;
        baseRam_be_n_reg  <= baseRam_be_n_next;

        extRam_ce_n_reg   <= extRam_ce_n_next;
        extRam_oe_n_reg   <= extRam_oe_n_next;
        extRam_we_n_reg   <= extRam_we_n_next;
        extRam_addr_reg   <= extRam_addr_next;
        extRam_wdata_reg  <= extRam_wdata_next;
        extRam_be_n_reg   <= extRam_be_n_next;

        ext_uart_start_reg <= ext_uart_start_next;
        ext_uart_tx_reg    <= ext_uart_tx_next;
        ext_uart_clear_reg <= ext_uart_clear_next;
    end
end

//输出赋值

// BaseRAM
assign baseRam_ce_n  = baseRam_ce_n_reg;
assign baseRam_oe_n  = baseRam_oe_n_reg;
assign baseRam_we_n  = baseRam_we_n_reg;
assign baseRam_addr  = baseRam_addr_reg;
assign baseRam_wdata = baseRam_wdata_reg;
assign baseRam_be_n  = baseRam_be_n_reg;

// ExtRAM
assign extRam_ce_n   = extRam_ce_n_reg;
assign extRam_oe_n   = extRam_oe_n_reg;
assign extRam_we_n   = extRam_we_n_reg;
assign extRam_addr   = extRam_addr_reg;
assign extRam_wdata  = extRam_wdata_reg;
assign extRam_be_n   = extRam_be_n_reg;

// UART
assign ext_uart_start = ext_uart_start_reg;
assign ext_uart_tx    = ext_uart_tx_reg;
assign ext_uart_clear = ext_uart_clear_reg;
endmodule
