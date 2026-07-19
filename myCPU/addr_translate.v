`include "mycpu.vh"

module addr_translate(
    input  wire        clk,
    input  wire        resetn,
    input  wire        ctx_update,
    input  wire [`TRANS_CTX_WD-1:0] ctx_in,
    input  wire [31:0] vaddr,
    output wire [31:0] paddr
  );

  (* keep = "true" *) reg [`TRANS_CTX_WD-1:0] ctx_reg;

  always @(posedge clk)
  begin
    if (!resetn)
      ctx_reg <= {`TRANS_CTX_WD{1'b0}};
    else if (ctx_update)
      ctx_reg <= ctx_in;
  end

  wire       dmw1_active;
  wire [2:0] dmw1_vseg;
  wire [2:0] dmw1_pseg;
  wire       dmw0_active;
  wire [2:0] dmw0_vseg;
  wire [2:0] dmw0_pseg;
  assign {dmw1_active, dmw1_vseg, dmw1_pseg,
          dmw0_active, dmw0_vseg, dmw0_pseg} = ctx_reg;

  wire dmw0_hit = dmw0_active && (vaddr[31:29] == dmw0_vseg);
  wire dmw1_hit = dmw1_active && (vaddr[31:29] == dmw1_vseg);

  assign paddr[28:0] = vaddr[28:0];
  assign paddr[31:29] = dmw0_hit ? dmw0_pseg :
         dmw1_hit ? dmw1_pseg : vaddr[31:29];

endmodule
