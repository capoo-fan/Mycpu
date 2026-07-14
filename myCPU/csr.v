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
    output wire [31:0] dmw1
  );

  localparam [13:0] CSR_CRMD = 14'h0000;
  localparam [13:0] CSR_DMW0 = 14'h0180;
  localparam [13:0] CSR_DMW1 = 14'h0181;

  localparam [31:0] CRMD_WRITABLE = 32'h0000_01ff;
  localparam [31:0] DMW_WRITABLE  = 32'hee00_0039;

  reg [8:0]  crmd_reg;
  reg [31:0] dmw0_reg;
  reg [31:0] dmw1_reg;

  wire [31:0] crmd_value = {23'b0, crmd_reg};
  wire [31:0] dmw0_value = dmw0_reg & DMW_WRITABLE;
  wire [31:0] dmw1_value = dmw1_reg & DMW_WRITABLE;

  wire [31:0] crmd_mask = wmask & CRMD_WRITABLE;
  wire [31:0] dmw_mask  = wmask & DMW_WRITABLE;

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      crmd_reg <= 9'h008;
      dmw0_reg <= 32'b0;
      dmw1_reg <= 32'b0;
    end
    else if (we)
    begin
      case (waddr)
        CSR_CRMD:
          crmd_reg <= (wdata[8:0] & crmd_mask[8:0]) |
          (crmd_reg & ~crmd_mask[8:0]);
        CSR_DMW0:
          dmw0_reg <= (wdata & dmw_mask) | (dmw0_value & ~dmw_mask);
        CSR_DMW1:
          dmw1_reg <= (wdata & dmw_mask) | (dmw1_value & ~dmw_mask);
        default:
          ;
      endcase
    end
  end

  assign rdata = (raddr == CSR_CRMD) ? crmd_value :
         (raddr == CSR_DMW0) ? dmw0_value :
         (raddr == CSR_DMW1) ? dmw1_value :
         32'b0;

  assign crmd = crmd_value;
  assign dmw0 = dmw0_value;
  assign dmw1 = dmw1_value;

endmodule
