module icache_refill(
    input  wire        clk,
    input  wire        resetn,

    // ICache miss refill request
    input  wire        icache_rd_req,
    input  wire [31:0] icache_rd_addr,
    output wire        icache_rd_rdy,
    output wire        icache_ret_valid,
    output wire [ 1:0] icache_ret_last,
    output wire [31:0] icache_ret_data,

    // 外部指令类 SRAM 接口
    output wire        inst_sram_req,
    output wire        inst_sram_wr,
    output wire [ 1:0] inst_sram_size,
    output wire [ 3:0] inst_sram_wstrb,
    output wire [31:0] inst_sram_addr,
    output wire [31:0] inst_sram_wdata,
    input  wire        inst_sram_addr_ok,
    input  wire        inst_sram_data_ok,
    input  wire [31:0] inst_sram_rdata
  );

  localparam IC_REFILL_IDLE = 2'd0;
  localparam IC_REFILL_REQ  = 2'd1;
  localparam IC_REFILL_WAIT = 2'd2;

  reg [1:0]  ic_refill_state;
  reg [31:0] ic_refill_base_addr;
  reg [1:0]  ic_refill_beat;

  reg        icache_ret_valid_r;
  reg [1:0]  icache_ret_last_r;
  reg [31:0] icache_ret_data_r;

  wire icache_rd_fire   = (ic_refill_state == IC_REFILL_IDLE) && icache_rd_req;
  wire inst_addr_fire   = (ic_refill_state == IC_REFILL_REQ)  && inst_sram_addr_ok;
  wire inst_data_fire   = (ic_refill_state == IC_REFILL_WAIT) && inst_sram_data_ok;
  wire icache_last_beat = (ic_refill_beat == 2'd3);

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      ic_refill_state     <= IC_REFILL_IDLE;
      ic_refill_base_addr <= 32'b0;
      ic_refill_beat      <= 2'b0;
      icache_ret_valid_r  <= 1'b0;
      icache_ret_last_r   <= 2'b0;
      icache_ret_data_r   <= 32'b0;
    end
    else
    begin
      icache_ret_valid_r <= 1'b0;
      icache_ret_last_r  <= 2'b0;

      case (ic_refill_state)
        IC_REFILL_IDLE:
        begin
          if (icache_rd_fire)
          begin
            ic_refill_state     <= IC_REFILL_REQ;
            ic_refill_base_addr <= {icache_rd_addr[31:4], 4'b0000};
            ic_refill_beat      <= 2'b0;
          end
        end

        IC_REFILL_REQ:
        begin
          if (inst_addr_fire)
          begin
            ic_refill_state <= IC_REFILL_WAIT;
          end
        end

        IC_REFILL_WAIT:
        begin
          if (inst_data_fire)
          begin
            icache_ret_valid_r <= 1'b1;
            icache_ret_last_r  <= {1'b0, icache_last_beat};
            icache_ret_data_r  <= inst_sram_rdata;
            if (icache_last_beat)
            begin
              ic_refill_state <= IC_REFILL_IDLE;
            end
            else
            begin
              ic_refill_state <= IC_REFILL_REQ;
              ic_refill_beat  <= ic_refill_beat + 2'd1;
            end
          end
        end

        default:
        begin
          ic_refill_state <= IC_REFILL_IDLE;
        end
      endcase
    end
  end

  assign inst_sram_req   = (ic_refill_state == IC_REFILL_REQ);
  assign inst_sram_wr    = 1'b0;
  assign inst_sram_size  = 2'b10;
  assign inst_sram_wstrb = 4'b0;
  assign inst_sram_addr  = ic_refill_base_addr + {28'b0, ic_refill_beat, 2'b00};
  assign inst_sram_wdata = 32'b0;

  assign icache_rd_rdy    = (ic_refill_state == IC_REFILL_IDLE);
  assign icache_ret_valid = icache_ret_valid_r;
  assign icache_ret_last  = icache_ret_last_r;
  assign icache_ret_data  = icache_ret_data_r;

endmodule
