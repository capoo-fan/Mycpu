module data_txn_tracker(
    input  wire        clk,
    input  wire        resetn,
    input  wire        txn_accept,
    input  wire        txn_store,
    input  wire [31:0] txn_paddr,
    input  wire        txn_data_ok,
    output wire        store_inv_valid,
    output wire [31:0] store_inv_addr
  );

  
  reg        data_txn_valid;
  reg        data_txn_store;
  reg        data_txn_is_base;
  reg [27:0] data_txn_line;

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      data_txn_valid   <= 1'b0;
      data_txn_store   <= 1'b0;
      data_txn_is_base <= 1'b0;
      data_txn_line    <= 28'b0;
    end
    else if (txn_accept)
    begin
      data_txn_valid   <= 1'b1;
      data_txn_store   <= txn_store;
      // 合法窗口中bit25=0表示 SRAM，bit22=0表示 BaseRAM。
      data_txn_is_base <= ~txn_paddr[25] && ~txn_paddr[22];
      data_txn_line    <= txn_paddr[31:4];
    end
    else if (txn_data_ok)
      data_txn_valid <= 1'b0;
  end

  assign store_inv_valid = txn_data_ok && data_txn_valid &&
       data_txn_store && data_txn_is_base;
  assign store_inv_addr = {data_txn_line, 4'b0};

endmodule
