`include "mycpu.vh"

module csr(
    input  wire        clk,
    input  wire        resetn,
    input  wire [13:0] raddr,
    output wire [31:0] rdata,
    input  wire        we,
    input  wire [13:0] waddr,
    input  wire [31:0] wmask,
    input  wire [31:0] wdata,
    output wire [31:0] crmd,
    output wire [31:0] dmw0,
    output wire [31:0] dmw1,
    output wire [`TRANS_CTX_WD-1:0] trans_ctx
  );

  localparam [13:0] CSR_CRMD = 14'h0000;
  localparam [13:0] CSR_DMW0 = 14'h0180;
  localparam [13:0] CSR_DMW1 = 14'h0181;

  localparam [31:0] CRMD_WRITABLE = 32'h0000_01ff;
  localparam [31:0] DMW_WRITABLE  = 32'hee00_0039;

  reg [8:0]  crmd_reg;
  reg [31:0] dmw0_reg;
  reg [31:0] dmw1_reg;
  reg [`TRANS_CTX_WD-1:0] trans_ctx_reg;

  wire [31:0] crmd_value = {23'b0, crmd_reg};
  wire [31:0] dmw0_value = dmw0_reg & DMW_WRITABLE;
  wire [31:0] dmw1_value = dmw1_reg & DMW_WRITABLE;

  wire [31:0] crmd_mask = wmask & CRMD_WRITABLE;
  wire [31:0] dmw_mask  = wmask & DMW_WRITABLE;

  wire [8:0] crmd_next = (we && (waddr == CSR_CRMD)) ?
       ((wdata[8:0] & crmd_mask[8:0]) |
        (crmd_reg & ~crmd_mask[8:0])) : crmd_reg;
  wire [31:0] dmw0_next = (we && (waddr == CSR_DMW0)) ?
       ((wdata & dmw_mask) | (dmw0_value & ~dmw_mask)) : dmw0_reg;
  wire [31:0] dmw1_next = (we && (waddr == CSR_DMW1)) ?
       ((wdata & dmw_mask) | (dmw1_value & ~dmw_mask)) : dmw1_reg;

  wire [1:0] next_plv = crmd_next[1:0];
  wire next_mapped_mode = !crmd_next[3] && crmd_next[4];
  wire dmw0_active_next = next_mapped_mode &&
       (((next_plv == 2'd0) && dmw0_next[0]) ||
        ((next_plv == 2'd3) && dmw0_next[3]));
  wire dmw1_active_next = next_mapped_mode &&
       (((next_plv == 2'd0) && dmw1_next[0]) ||
        ((next_plv == 2'd3) && dmw1_next[3]));
  wire [`TRANS_CTX_WD-1:0] trans_ctx_next = {
       dmw1_active_next, dmw1_next[31:29], dmw1_next[27:25],
       dmw0_active_next, dmw0_next[31:29], dmw0_next[27:25]
  };

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      crmd_reg <= 9'h008;
      dmw0_reg <= 32'b0;
      dmw1_reg <= 32'b0;
      trans_ctx_reg <= {`TRANS_CTX_WD{1'b0}};
    end
    else if (we)
    begin
      crmd_reg      <= crmd_next;
      dmw0_reg      <= dmw0_next;
      dmw1_reg      <= dmw1_next;
      trans_ctx_reg <= trans_ctx_next;
    end
  end

  assign rdata = (raddr == CSR_CRMD) ? crmd_value :
         (raddr == CSR_DMW0) ? dmw0_value :
         (raddr == CSR_DMW1) ? dmw1_value :
         32'b0;

  assign crmd = crmd_value;
  assign dmw0 = dmw0_value;
  assign dmw1 = dmw1_value;
  assign trans_ctx = trans_ctx_reg;

endmodule
