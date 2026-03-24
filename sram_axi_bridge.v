module sram_axi_bridge(
    input  wire        aclk,
    input  wire        aresetn,

    // ICache miss 访问接口
    input  wire        cache_rd_req,
    input  wire [ 2:0] cache_rd_type,
    input  wire [31:0] cache_rd_addr,
    output wire        cache_rd_rdy,
    output wire        cache_ret_valid,
    output wire [ 1:0] cache_ret_last,
    output wire [31:0] cache_ret_data,

    input  wire        cache_wr_req,
    input  wire [ 2:0] cache_wr_type,
    input  wire [31:0] cache_wr_addr,
    input  wire [ 3:0] cache_wr_wstrb,
    input  wire [127:0] cache_wr_data,
    output wire        cache_wr_rdy,

    // data SRAM-like 接口
    input  wire        data_sram_req,
    input  wire        data_sram_wr,
    input  wire [ 1:0] data_sram_size,
    input  wire [ 3:0] data_sram_wstrb,
    input  wire [31:0] data_sram_addr,
    input  wire [31:0] data_sram_wdata,
    output wire        data_sram_addr_ok,
    output wire        data_sram_data_ok,
    output wire [31:0] data_sram_rdata,

    // AXI
    output wire [ 3:0] arid,
    output wire [31:0] araddr,
    output wire [ 7:0] arlen,
    output wire [ 2:0] arsize,
    output wire [ 1:0] arburst,
    output wire [ 1:0] arlock,
    output wire [ 3:0] arcache,
    output wire [ 2:0] arprot,
    output wire        arvalid,
    input  wire        arready,

    input  wire [ 3:0] rid,
    input  wire [31:0] rdata,
    input  wire [ 1:0] rresp,
    input  wire        rlast,
    input  wire        rvalid,
    output wire        rready,

    output wire [ 3:0] awid,
    output wire [31:0] awaddr,
    output wire [ 7:0] awlen,
    output wire [ 2:0] awsize,
    output wire [ 1:0] awburst,
    output wire [ 1:0] awlock,
    output wire [ 3:0] awcache,
    output wire [ 2:0] awprot,
    output wire        awvalid,
    input  wire        awready,

    output wire [ 3:0] wid,
    output wire [31:0] wdata,
    output wire [ 3:0] wstrb,
    output wire        wlast,
    output wire        wvalid,
    input  wire        wready,

    input  wire [ 3:0] bid,
    input  wire [ 1:0] bresp,
    input  wire        bvalid,
    output wire        bready
  );

  // ----------------------------
  // 请求拆分
  // ----------------------------
  wire data_rd_req = data_sram_req && !data_sram_wr;
  wire data_wr_req = data_sram_req && data_sram_wr;

  wire ar_hs = arvalid && arready;
  wire r_hs  = rvalid && rready;
  wire aw_hs = awvalid && awready;
  wire w_hs  = wvalid && wready;
  wire b_hs  = bvalid && bready;

  // ----------------------------
  // AR: 支持 cache burst read
  // ----------------------------
  reg        ar_busy;
  reg [ 3:0] ar_id_r;
  reg [31:0] ar_addr_r;
  reg [ 7:0] ar_len_r;
  reg [ 2:0] ar_size_r;

  reg cache_rd_pending;
  reg data_rd_pending;

  wire [2:0] cache_rd_size = (cache_rd_type == 3'b011) ? 3'b010 : cache_rd_type;
  wire [7:0] cache_rd_len  = (cache_rd_type == 3'b011) ? 8'd3   : 8'd0;

  wire accept_ar_cache = !ar_busy && cache_rd_req && !cache_rd_pending;
  wire accept_ar_data  = !ar_busy && !accept_ar_cache && data_rd_req && !data_rd_pending;

  always @(posedge aclk)
  begin
    if (!aresetn)
    begin
      ar_busy   <= 1'b0;
      ar_id_r   <= 4'd0;
      ar_addr_r <= 32'd0;
      ar_len_r  <= 8'd0;
      ar_size_r <= 3'd0;
    end
    else if (accept_ar_cache)
    begin
      ar_busy   <= 1'b1;
      ar_id_r   <= 4'd0;
      ar_addr_r <= cache_rd_addr;
      ar_len_r  <= cache_rd_len;
      ar_size_r <= cache_rd_size;
    end
    else if (accept_ar_data)
    begin
      ar_busy   <= 1'b1;
      ar_id_r   <= 4'd1;
      ar_addr_r <= data_sram_addr;
      ar_len_r  <= 8'd0;
      ar_size_r <= {1'b0, data_sram_size};
    end
    else if (ar_hs)
    begin
      ar_busy <= 1'b0;
    end
  end

  always @(posedge aclk)
  begin
    if (!aresetn)
      cache_rd_pending <= 1'b0;
    else if (accept_ar_cache)
      cache_rd_pending <= 1'b1;
    else if (r_hs && (rid == 4'd0) && rlast)
      cache_rd_pending <= 1'b0;
  end

  always @(posedge aclk)
  begin
    if (!aresetn)
      data_rd_pending <= 1'b0;
    else if (accept_ar_data)
      data_rd_pending <= 1'b1;
    else if (r_hs && (rid == 4'd1) && rlast)
      data_rd_pending <= 1'b0;
  end

  assign arvalid = ar_busy;
  assign arid    = ar_id_r;
  assign araddr  = ar_addr_r;
  assign arlen   = ar_len_r;
  assign arsize  = ar_size_r;
  assign arburst = 2'b01;
  assign arlock  = 2'b0;
  assign arcache = 4'b0;
  assign arprot  = 3'b0;

  assign rready = cache_rd_pending || data_rd_pending;


  // AW/W: 统一处理 cache burst write 与 data single write
  reg        wr_active;
  reg        wr_is_cache;
  reg [31:0] wr_addr_r;
  reg [ 7:0] wr_len_r;
  reg [ 2:0] wr_size_r;
  reg [ 3:0] wr_strb_r;
  reg [127:0] wr_line_r;
  reg [ 2:0] wr_total_beats;
  reg [ 2:0] wr_beat_cnt;
  reg        aw_sent;
  reg        w_done;

  wire [2:0] cache_wr_size = (cache_wr_type == 3'b011) ? 3'b010 : cache_wr_type;
  wire [7:0] cache_wr_len  = (cache_wr_type == 3'b011) ? 8'd3   : 8'd0;

  wire write_idle = !wr_active;
  wire accept_wr_cache = write_idle && cache_wr_req;
  wire accept_wr_data  = write_idle && !accept_wr_cache && data_wr_req;

  wire [31:0] wr_data_mux = (wr_beat_cnt == 3'd0) ? wr_line_r[31:0] :
       (wr_beat_cnt == 3'd1) ? wr_line_r[63:32] :
       (wr_beat_cnt == 3'd2) ? wr_line_r[95:64] :
       wr_line_r[127:96];

  always @(posedge aclk)
  begin
    if (!aresetn)
    begin
      wr_active      <= 1'b0;
      wr_is_cache    <= 1'b0;
      wr_addr_r      <= 32'd0;
      wr_len_r       <= 8'd0;
      wr_size_r      <= 3'd0;
      wr_strb_r      <= 4'd0;
      wr_line_r      <= 128'd0;
      wr_total_beats <= 3'd0;
      wr_beat_cnt    <= 3'd0;
      aw_sent        <= 1'b0;
      w_done         <= 1'b0;
    end
    else if (accept_wr_cache)
    begin
      wr_active      <= 1'b1;
      wr_is_cache    <= 1'b1;
      wr_addr_r      <= cache_wr_addr;
      wr_len_r       <= cache_wr_len;
      wr_size_r      <= cache_wr_size;
      wr_strb_r      <= cache_wr_wstrb;
      wr_line_r      <= cache_wr_data;
      wr_total_beats <= cache_wr_len + 8'd1;
      wr_beat_cnt    <= 3'd0;
      aw_sent        <= 1'b0;
      w_done         <= 1'b0;
    end
    else if (accept_wr_data)
    begin
      wr_active      <= 1'b1;
      wr_is_cache    <= 1'b0;
      wr_addr_r      <= data_sram_addr;
      wr_len_r       <= 8'd0;
      wr_size_r      <= {1'b0, data_sram_size};
      wr_strb_r      <= data_sram_wstrb;
      wr_line_r      <= {96'd0, data_sram_wdata};
      wr_total_beats <= 3'd1;
      wr_beat_cnt    <= 3'd0;
      aw_sent        <= 1'b0;
      w_done         <= 1'b0;
    end
    else if (wr_active)
    begin
      if (!aw_sent && aw_hs)
        aw_sent <= 1'b1;

      if (!w_done && w_hs)
      begin
        if (wr_beat_cnt + 3'd1 >= wr_total_beats)
          w_done <= 1'b1;
        wr_beat_cnt <= wr_beat_cnt + 3'd1;
      end

      if (b_hs)
      begin
        wr_active <= 1'b0;
      end
    end
  end

  assign awvalid = wr_active && !aw_sent;
  assign awid    = wr_is_cache ? 4'd0 : 4'd1;
  assign awaddr  = wr_addr_r;
  assign awlen   = wr_len_r;
  assign awsize  = wr_size_r;
  assign awburst = 2'b01;
  assign awlock  = 2'b0;
  assign awcache = 4'b0;
  assign awprot  = 3'b0;

  assign wvalid = wr_active && aw_sent && !w_done;
  assign wid    = wr_is_cache ? 4'd0 : 4'd1;
  assign wdata  = wr_data_mux;
  assign wstrb  = wr_strb_r;
  assign wlast  = (wr_beat_cnt + 3'd1 >= wr_total_beats);

  assign bready = wr_active;

  // 对外返回
  assign cache_rd_rdy   = accept_ar_cache;
  assign cache_ret_valid = r_hs && (rid == 4'd0);
  assign cache_ret_last  = {1'b0, (r_hs && (rid == 4'd0) && rlast)};
  assign cache_ret_data  = rdata;
  // cache 要求 wr_rdy 先于 wr_req 置起，空闲时即宣告可接收写回
  assign cache_wr_rdy    = write_idle;

  assign data_sram_addr_ok = accept_ar_data || accept_wr_data;
  assign data_sram_data_ok = (r_hs && (rid == 4'd1) && rlast) || (b_hs && (bid == 4'd1));
  assign data_sram_rdata   = rdata;

endmodule
