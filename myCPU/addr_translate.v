module addr_translate(
    input  wire [31:0] vaddr,
    input  wire [31:0] crmd,
    input  wire [31:0] dmw0,
    input  wire [31:0] dmw1,
    output wire [31:0] paddr
  );

  wire [1:0] plv = crmd[1:0];
  wire       direct_mode = crmd[3] && !crmd[4];
  wire       mapped_mode = !crmd[3] && crmd[4];

  wire dmw0_plv_ok = ((plv == 2'd0) && dmw0[0]) ||
       ((plv == 2'd3) && dmw0[3]);
  wire dmw1_plv_ok = ((plv == 2'd0) && dmw1[0]) ||
       ((plv == 2'd3) && dmw1[3]);

  wire dmw0_hit = mapped_mode && dmw0_plv_ok &&
       (vaddr[31:29] == dmw0[31:29]);
  wire dmw1_hit = mapped_mode && dmw1_plv_ok &&
       (vaddr[31:29] == dmw1[31:29]);

  assign paddr = direct_mode ? vaddr :
         dmw0_hit ? {dmw0[27:25], vaddr[28:0]} :
         dmw1_hit ? {dmw1[27:25], vaddr[28:0]} :
         vaddr;

endmodule
