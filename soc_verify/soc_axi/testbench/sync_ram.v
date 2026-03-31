// ============================================================================
// sync_ram.v - Simulation models for Xilinx IP cores
// Provides: sync_ram, inst_ram, data_ram, axi_ram, axi_crossbar_1x2, clk_pll
// ============================================================================

// ----------------------------------------------------------------------------
// Basic synchronous RAM with byte write enable
// ----------------------------------------------------------------------------
module sync_ram #(
    parameter ADDR_WIDTH = 16,
    parameter DATA_WIDTH = 32,
    parameter DEPTH = 1 << ADDR_WIDTH
  ) (
    clk,
    address,
    rdata,
    wdata,
    we,
    en
  );

  localparam NUM_BYTES = DATA_WIDTH / 8;

  input wire clk;
  input wire [ADDR_WIDTH-1:0] address;
  input wire [NUM_BYTES-1:0] we;
  input wire en;

  output reg  [DATA_WIDTH-1:0] rdata;
  output wire [DATA_WIDTH-1:0] wdata;

  reg [DATA_WIDTH-1:0] ram[DEPTH];

  genvar i;
  for (i = 0; i < NUM_BYTES; i = i + 1)
  begin
    always @(posedge clk)
    begin
      if (we[i] && en)
        ram[address][i*8+:8] <= wdata[i*8+:8];
    end
  end

  always @(posedge clk)
  begin
    if (en)
      rdata <= ram[address];
  end
endmodule

// ----------------------------------------------------------------------------
// Instruction RAM wrapper (for BRAM-based use in sram_wrap, not used in AXI SoC)
// ----------------------------------------------------------------------------
module inst_ram #(
    parameter ADDR_WIDTH = 18,
    parameter DATA_WIDTH = 32,
    parameter DEPTH = 1 << ADDR_WIDTH
  ) (
    input  wire clka,
    input  wire ena,
    input  wire [3:0] wea,
    input  wire [ADDR_WIDTH-1:0] addra,
    input  wire [DATA_WIDTH-1:0] dina,
    output wire [DATA_WIDTH-1:0] douta
  );
  sync_ram #(
             .ADDR_WIDTH(ADDR_WIDTH),
             .DATA_WIDTH(DATA_WIDTH),
             .DEPTH(DEPTH)
           ) sync_ram (
             .clk    (clka),
             .address(addra),
             .rdata  (douta),
             .wdata  (dina),
             .we     (wea),
             .en     (ena)
           );
  initial
  begin
    $readmemb("../../../../../../../../func/obj/inst_ram.mif", sync_ram.ram);
  end
endmodule

// ----------------------------------------------------------------------------
// Data RAM wrapper (for BRAM-based use in sram_wrap, not used in AXI SoC)
// ----------------------------------------------------------------------------
module data_ram #(
    parameter ADDR_WIDTH = 16,
    parameter DATA_WIDTH = 32,
    parameter DEPTH = 1 << ADDR_WIDTH
  ) (
    input  wire clka,
    input  wire ena,
    input  wire [3:0] wea,
    input  wire [ADDR_WIDTH-1:0] addra,
    input  wire [DATA_WIDTH-1:0] dina,
    output wire [DATA_WIDTH-1:0] douta
  );
  sync_ram #(
             .ADDR_WIDTH(ADDR_WIDTH),
             .DATA_WIDTH(DATA_WIDTH),
             .DEPTH(DEPTH)
           ) sync_ram (
             .clk    (clka),
             .address(addra),
             .rdata  (douta),
             .wdata  (dina),
             .we     (wea),
             .en     (ena)
           );
  initial
  begin
    $readmemb("../../../../../../../../func/obj/data_ram.mif", sync_ram.ram);
  end
endmodule


module axi_ram(
    input  wire        s_aclk,
    input  wire        s_aresetn,
    // AR
    input  wire [ 3:0] s_axi_arid,
    input  wire [31:0] s_axi_araddr,
    input  wire [ 7:0] s_axi_arlen,
    input  wire [ 2:0] s_axi_arsize,
    input  wire [ 1:0] s_axi_arburst,
    input  wire        s_axi_arvalid,
    output wire        s_axi_arready,
    // R
    output wire [ 3:0] s_axi_rid,
    output wire [31:0] s_axi_rdata,
    output wire [ 1:0] s_axi_rresp,
    output wire        s_axi_rlast,
    output wire        s_axi_rvalid,
    input  wire        s_axi_rready,
    // AW
    input  wire [ 3:0] s_axi_awid,
    input  wire [31:0] s_axi_awaddr,
    input  wire [ 7:0] s_axi_awlen,
    input  wire [ 2:0] s_axi_awsize,
    input  wire [ 1:0] s_axi_awburst,
    input  wire        s_axi_awvalid,
    output wire        s_axi_awready,
    // W
    input  wire [31:0] s_axi_wdata,
    input  wire [ 3:0] s_axi_wstrb,
    input  wire        s_axi_wlast,
    input  wire        s_axi_wvalid,
    output wire        s_axi_wready,
    // B
    output wire [ 3:0] s_axi_bid,
    output wire [ 1:0] s_axi_bresp,
    output wire        s_axi_bvalid,
    input  wire        s_axi_bready
  );

  // 262144 words = 1MB address space, 18-bit word address
  localparam ADDR_WIDTH = 18;
  localparam DEPTH = 1 << ADDR_WIDTH;

  reg [31:0] mem [0:DEPTH-1];

  // Initialize from inst_ram.mif
  initial
  begin
    $readmemb("../../../../../../../../func/obj/inst_ram.mif", mem);
  end

  // ---- Read channel (supports INCR burst) ----
  reg        rd_busy;
  reg [ 3:0] rd_id;
  reg [31:0] rd_addr;
  reg [ 7:0] rd_len;
  reg [ 7:0] rd_cnt;
  reg [ 1:0] rd_burst;

  assign s_axi_arready = !rd_busy;
  assign s_axi_rid     = rd_id;
  assign s_axi_rdata   = mem[rd_addr[ADDR_WIDTH+1:2]];
  assign s_axi_rresp   = 2'b00;
  assign s_axi_rlast   = (rd_cnt == rd_len);
  assign s_axi_rvalid  = rd_busy;

  always @(posedge s_aclk)
  begin
    if (!s_aresetn)
    begin
      rd_busy  <= 1'b0;
      rd_id    <= 4'd0;
      rd_addr  <= 32'd0;
      rd_len   <= 8'd0;
      rd_cnt   <= 8'd0;
      rd_burst <= 2'b01;
    end
    else if (!rd_busy && s_axi_arvalid)
    begin
      rd_busy  <= 1'b1;
      rd_id    <= s_axi_arid;
      rd_addr  <= s_axi_araddr;
      rd_len   <= s_axi_arlen;
      rd_cnt   <= 8'd0;
      rd_burst <= s_axi_arburst;
    end
    else if (rd_busy && s_axi_rvalid && s_axi_rready)
    begin
      if (rd_cnt == rd_len)
      begin
        rd_busy <= 1'b0;
      end
      else
      begin
        rd_cnt <= rd_cnt + 8'd1;
        if (rd_burst == 2'b01)
          rd_addr <= rd_addr + 32'd4;
      end
    end
  end

  // ---- Write channel (supports INCR burst) ----
  reg        wr_busy;
  reg [ 3:0] wr_id;
  reg [31:0] wr_addr;
  reg [ 7:0] wr_len;
  reg [ 7:0] wr_cnt;
  reg [ 1:0] wr_burst;
  reg        aw_done;
  reg        b_busy;

  assign s_axi_awready = !wr_busy;
  assign s_axi_wready  = wr_busy && aw_done;
  assign s_axi_bid     = wr_id;
  assign s_axi_bresp   = 2'b00;
  assign s_axi_bvalid  = b_busy;

  always @(posedge s_aclk)
  begin
    if (!s_aresetn)
    begin
      wr_busy  <= 1'b0;
      wr_id    <= 4'd0;
      wr_addr  <= 32'd0;
      wr_len   <= 8'd0;
      wr_cnt   <= 8'd0;
      wr_burst <= 2'b01;
      aw_done  <= 1'b0;
      b_busy   <= 1'b0;
    end
    else
    begin
      if (!wr_busy && s_axi_awvalid && s_axi_awready)
      begin
        wr_busy  <= 1'b1;
        wr_id    <= s_axi_awid;
        wr_addr  <= s_axi_awaddr;
        wr_len   <= s_axi_awlen;
        wr_cnt   <= 8'd0;
        wr_burst <= s_axi_awburst;
        aw_done  <= 1'b1;
      end

      if (wr_busy && aw_done && s_axi_wvalid && s_axi_wready)
      begin
        if (s_axi_wstrb[0])
          mem[wr_addr[ADDR_WIDTH+1:2]][ 7: 0] <= s_axi_wdata[ 7: 0];
        if (s_axi_wstrb[1])
          mem[wr_addr[ADDR_WIDTH+1:2]][15: 8] <= s_axi_wdata[15: 8];
        if (s_axi_wstrb[2])
          mem[wr_addr[ADDR_WIDTH+1:2]][23:16] <= s_axi_wdata[23:16];
        if (s_axi_wstrb[3])
          mem[wr_addr[ADDR_WIDTH+1:2]][31:24] <= s_axi_wdata[31:24];

        if (wr_cnt == wr_len)
        begin
          wr_busy <= 1'b0;
          b_busy  <= 1'b1;
        end
        else
        begin
          wr_cnt <= wr_cnt + 8'd1;
          if (wr_burst == 2'b01)
            wr_addr <= wr_addr + 32'd4;
        end
      end

      if (b_busy && s_axi_bready)
      begin
        b_busy <= 1'b0;
      end
    end
  end

endmodule

// ============================================================================
// AXI crossbar 1x2 simulation model
// Slave port (S00): from CPU
// Master port 0 (M00): confreg, base=0x1faf0000, 64KB
// Master port 1 (M01): RAM, base=0x1c000000, 16MB
// ============================================================================
module axi_crossbar_1x2(
    input  wire        aclk,
    input  wire        aresetn,
    // Slave port (from CPU)
    input  wire [ 3:0] s_axi_arid,
    input  wire [31:0] s_axi_araddr,
    input  wire [ 3:0] s_axi_arlen,
    input  wire [ 2:0] s_axi_arsize,
    input  wire [ 1:0] s_axi_arburst,
    input  wire [ 1:0] s_axi_arlock,
    input  wire [ 3:0] s_axi_arcache,
    input  wire [ 2:0] s_axi_arprot,
    input  wire [ 3:0] s_axi_arqos,
    input  wire        s_axi_arvalid,
    output wire        s_axi_arready,
    output wire [ 3:0] s_axi_rid,
    output wire [31:0] s_axi_rdata,
    output wire [ 1:0] s_axi_rresp,
    output wire        s_axi_rlast,
    output wire        s_axi_rvalid,
    input  wire        s_axi_rready,
    input  wire [ 3:0] s_axi_awid,
    input  wire [31:0] s_axi_awaddr,
    input  wire [ 3:0] s_axi_awlen,
    input  wire [ 2:0] s_axi_awsize,
    input  wire [ 1:0] s_axi_awburst,
    input  wire [ 1:0] s_axi_awlock,
    input  wire [ 3:0] s_axi_awcache,
    input  wire [ 2:0] s_axi_awprot,
    input  wire [ 3:0] s_axi_awqos,
    input  wire        s_axi_awvalid,
    output wire        s_axi_awready,
    input  wire [ 3:0] s_axi_wid,
    input  wire [31:0] s_axi_wdata,
    input  wire [ 3:0] s_axi_wstrb,
    input  wire        s_axi_wlast,
    input  wire        s_axi_wvalid,
    output wire        s_axi_wready,
    output wire [ 3:0] s_axi_bid,
    output wire [ 1:0] s_axi_bresp,
    output wire        s_axi_bvalid,
    input  wire        s_axi_bready,
    // Master ports: {M01(ram), M00(conf)}
    output wire [ 7:0] m_axi_arid,
    output wire [63:0] m_axi_araddr,
    output wire [ 7:0] m_axi_arlen,
    output wire [ 5:0] m_axi_arsize,
    output wire [ 3:0] m_axi_arburst,
    output wire [ 3:0] m_axi_arlock,
    output wire [ 7:0] m_axi_arcache,
    output wire [ 5:0] m_axi_arprot,
    output wire [ 7:0] m_axi_arqos,
    output wire [ 1:0] m_axi_arvalid,
    input  wire [ 1:0] m_axi_arready,
    input  wire [ 7:0] m_axi_rid,
    input  wire [63:0] m_axi_rdata,
    input  wire [ 3:0] m_axi_rresp,
    input  wire [ 1:0] m_axi_rlast,
    input  wire [ 1:0] m_axi_rvalid,
    output wire [ 1:0] m_axi_rready,
    output wire [ 7:0] m_axi_awid,
    output wire [63:0] m_axi_awaddr,
    output wire [ 7:0] m_axi_awlen,
    output wire [ 5:0] m_axi_awsize,
    output wire [ 3:0] m_axi_awburst,
    output wire [ 3:0] m_axi_awlock,
    output wire [ 7:0] m_axi_awcache,
    output wire [ 5:0] m_axi_awprot,
    output wire [ 7:0] m_axi_awqos,
    output wire [ 1:0] m_axi_awvalid,
    input  wire [ 1:0] m_axi_awready,
    output wire [ 7:0] m_axi_wid,
    output wire [63:0] m_axi_wdata,
    output wire [ 7:0] m_axi_wstrb,
    output wire [ 1:0] m_axi_wlast,
    output wire [ 1:0] m_axi_wvalid,
    input  wire [ 1:0] m_axi_wready,
    input  wire [ 7:0] m_axi_bid,
    input  wire [ 3:0] m_axi_bresp,
    input  wire [ 1:0] m_axi_bvalid,
    output wire [ 1:0] m_axi_bready
  );

  // Address decoding:
  // M00 (conf): 0x1faf_0000 ~ 0x1faf_ffff (matches 0x1faf or 0xbfaf)
  // M01 (ram) : everything else

  // ---- Read path: simple passthrough with routing ----
  wire ar_hit_conf = (s_axi_araddr[31:16] == 16'h1faf) ||
       (s_axi_araddr[31:16] == 16'hbfaf);

  reg rd_route_conf;
  reg rd_active;

  assign m_axi_arvalid = rd_active ? 2'b00 :
         {!ar_hit_conf & s_axi_arvalid, ar_hit_conf & s_axi_arvalid};
  assign s_axi_arready = !rd_active &
         (ar_hit_conf ? m_axi_arready[0] : m_axi_arready[1]);

  assign m_axi_arid    = {s_axi_arid,    s_axi_arid};
  assign m_axi_araddr  = {s_axi_araddr,  s_axi_araddr};
  assign m_axi_arlen   = {s_axi_arlen,   s_axi_arlen};
  assign m_axi_arsize  = {s_axi_arsize,  s_axi_arsize};
  assign m_axi_arburst = {s_axi_arburst, s_axi_arburst};
  assign m_axi_arlock  = {s_axi_arlock,  s_axi_arlock};
  assign m_axi_arcache = {s_axi_arcache, s_axi_arcache};
  assign m_axi_arprot  = {s_axi_arprot,  s_axi_arprot};
  assign m_axi_arqos   = {s_axi_arqos,   s_axi_arqos};

  assign s_axi_rid   = rd_route_conf ? m_axi_rid[3:0]   : m_axi_rid[7:4];
  assign s_axi_rdata = rd_route_conf ? m_axi_rdata[31:0] : m_axi_rdata[63:32];
  assign s_axi_rresp = rd_route_conf ? m_axi_rresp[1:0]  : m_axi_rresp[3:2];
  assign s_axi_rlast = rd_route_conf ? m_axi_rlast[0]    : m_axi_rlast[1];
  assign s_axi_rvalid = rd_route_conf ? m_axi_rvalid[0]  : m_axi_rvalid[1];
  assign m_axi_rready = {!rd_route_conf & s_axi_rready,
                         rd_route_conf & s_axi_rready};

  always @(posedge aclk)
  begin
    if (!aresetn)
    begin
      rd_active     <= 1'b0;
      rd_route_conf <= 1'b0;
    end
    else
    begin
      if (s_axi_arvalid && s_axi_arready)
      begin
        rd_active     <= 1'b1;
        rd_route_conf <= ar_hit_conf;
      end
      if (s_axi_rvalid && s_axi_rready && s_axi_rlast)
        rd_active <= 1'b0;
    end
  end

  // ---- Write path: route AW/W/B based on address ----
  wire aw_hit_conf = (s_axi_awaddr[31:16] == 16'h1faf) ||
       (s_axi_awaddr[31:16] == 16'hbfaf);

  // Track the write route once AW is accepted
  reg wr_route_conf;
  reg wr_active;     // a write transaction is in progress
  reg wr_aw_done;    // AW phase done
  reg wr_w_done;     // W phase done
  reg wr_b_wait;     // waiting for B response

  // Route selection: use registered route if active, else decode from address
  wire wr_sel = wr_active ? wr_route_conf : aw_hit_conf;

  // AW channel
  wire aw_forward = s_axi_awvalid && !(wr_active && wr_aw_done);
  assign m_axi_awvalid = {!wr_sel & aw_forward, wr_sel & aw_forward};
  assign s_axi_awready = wr_sel ? m_axi_awready[0] : m_axi_awready[1];

  assign m_axi_awid    = {s_axi_awid,    s_axi_awid};
  assign m_axi_awaddr  = {s_axi_awaddr,  s_axi_awaddr};
  assign m_axi_awlen   = {s_axi_awlen,   s_axi_awlen};
  assign m_axi_awsize  = {s_axi_awsize,  s_axi_awsize};
  assign m_axi_awburst = {s_axi_awburst, s_axi_awburst};
  assign m_axi_awlock  = {s_axi_awlock,  s_axi_awlock};
  assign m_axi_awcache = {s_axi_awcache, s_axi_awcache};
  assign m_axi_awprot  = {s_axi_awprot,  s_axi_awprot};
  assign m_axi_awqos   = {s_axi_awqos,   s_axi_awqos};

  // W channel
  wire w_forward = s_axi_wvalid && !(wr_active && wr_w_done);
  assign m_axi_wvalid = {!wr_sel & w_forward, wr_sel & w_forward};
  assign s_axi_wready = wr_sel ? m_axi_wready[0] : m_axi_wready[1];

  assign m_axi_wid    = {s_axi_wid,   s_axi_wid};
  assign m_axi_wdata  = {s_axi_wdata, s_axi_wdata};
  assign m_axi_wstrb  = {s_axi_wstrb, s_axi_wstrb};
  assign m_axi_wlast  = {s_axi_wlast, s_axi_wlast};

  // B channel
  assign s_axi_bid    = wr_route_conf ? m_axi_bid[3:0]   : m_axi_bid[7:4];
  assign s_axi_bresp  = wr_route_conf ? m_axi_bresp[1:0]  : m_axi_bresp[3:2];
  assign s_axi_bvalid = wr_route_conf ? m_axi_bvalid[0]   : m_axi_bvalid[1];
  assign m_axi_bready = {!wr_route_conf & s_axi_bready,
                         wr_route_conf & s_axi_bready};

  // Track write transaction state
  wire aw_handshake = s_axi_awvalid && s_axi_awready;
  wire w_handshake  = s_axi_wvalid  && s_axi_wready && s_axi_wlast;
  wire b_handshake  = s_axi_bvalid  && s_axi_bready;

  always @(posedge aclk)
  begin
    if (!aresetn)
    begin
      wr_active     <= 1'b0;
      wr_route_conf <= 1'b0;
      wr_aw_done    <= 1'b0;
      wr_w_done     <= 1'b0;
    end
    else
    begin
      if (!wr_active)
      begin
        if (aw_handshake || w_handshake)
        begin
          wr_active     <= 1'b1;
          wr_route_conf <= aw_hit_conf;
          wr_aw_done    <= aw_handshake;
          wr_w_done     <= w_handshake;
        end
      end
      else
      begin
        if (aw_handshake)
          wr_aw_done <= 1'b1;
        if (w_handshake)
          wr_w_done  <= 1'b1;
        if (b_handshake)
        begin
          wr_active  <= 1'b0;
          wr_aw_done <= 1'b0;
          wr_w_done  <= 1'b0;
        end
      end
    end
  end

endmodule

// ============================================================================
// Clock PLL simulation model (passthrough in simulation)
// ============================================================================
module clk_pll(
    input  wire clk_in1,
    output wire cpu_clk,
    output wire timer_clk
  );
  assign cpu_clk   = clk_in1;
  assign timer_clk = clk_in1;
endmodule
