`include "mycpu.vh"

module WB_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ms_to_ws_valid,
    input  wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus,
    output wire                         ws_allowin,
    output wire [`WS_FWD_BUS_WD-1:0]    ws_fwd_bus,
    output wire [`WS_TO_RF_BUS_WD-1:0]  ws_to_rf_bus,
    output wire [31:0]                  debug_wb_pc,
    output wire [ 3:0]                  debug_wb_rf_we,
    output wire [ 4:0]                  debug_wb_rf_wnum,
    output wire [31:0]                  debug_wb_rf_wdata
  );
  reg         reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ws_valid;
  reg  [31:0] ws_pc;
  reg  [31:0] ws_alu_result;
  reg  [31:0] ws_mem_result;
  reg         ws_res_from_mem;
  reg         ws_gr_we;
  reg  [ 4:0] ws_dest;
  reg         ws_ld_byte;
  reg         ws_ld_half;
  reg         ws_ld_sign_ext;

  // 总线解包
  wire [31:0] ms_pc;
  wire [31:0] ms_alu_result;
  wire        ms_res_from_mem;
  wire        ms_gr_we;
  wire [ 4:0] ms_dest;
  wire        ms_ld_byte;
  wire        ms_ld_half;
  wire        ms_ld_sign_ext;
  wire [31:0] ms_mem_rdata;

  assign {ms_pc, ms_alu_result, ms_res_from_mem, ms_gr_we, ms_dest,
          ms_ld_byte, ms_ld_half, ms_ld_sign_ext,
          ms_mem_rdata} = ms_to_ws_bus;


  wire ws_ready_go = 1'b1;
  assign ws_allowin = !ws_valid || ws_ready_go;


  wire [ 1:0] ws_addr_low  = ws_alu_result[1:0];
  wire [ 7:0] ws_load_byte = ws_addr_low[1] ? (ws_addr_low[0] ? ws_mem_result[31:24] : ws_mem_result[23:16]) :(ws_addr_low[0] ? ws_mem_result[15:8]  : ws_mem_result[7:0]);
  wire [15:0] ws_load_half = ws_addr_low[1] ? ws_mem_result[31:16] : ws_mem_result[15:0];
  wire [31:0] ws_load_result =
       ws_ld_byte ? (ws_ld_sign_ext ? {{24{ws_load_byte[7]}}, ws_load_byte}
                     : {24'b0, ws_load_byte}) :
       ws_ld_half ? (ws_ld_sign_ext ? {{16{ws_load_half[15]}}, ws_load_half}
                     : {16'b0, ws_load_half}) :
       ws_mem_result;

  wire [31:0] final_result = ws_res_from_mem ? ws_load_result : ws_alu_result;

  wire        ws_rf_we    = ws_gr_we && ws_valid;
  wire [ 4:0] ws_rf_waddr = ws_dest;
  wire [31:0] ws_rf_wdata = final_result;

  // 总线信号
  assign ws_fwd_bus = {ws_valid, ws_gr_we, ws_dest, final_result};
  assign ws_to_rf_bus = {ws_rf_we, ws_rf_waddr, ws_rf_wdata};

  assign debug_wb_pc       = ws_pc;
  assign debug_wb_rf_we    = {4{ws_rf_we}};
  assign debug_wb_rf_wnum  = ws_dest;
  assign debug_wb_rf_wdata = final_result;


  always @(posedge clk)
  begin
    if (reset)
      ws_valid <= 1'b0;
    else if (ws_allowin)
      ws_valid <= ms_to_ws_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ws_pc           <= 32'b0;
      ws_gr_we        <= 1'b0;
      ws_res_from_mem <= 1'b0;
      ws_dest         <= 5'b0;
      ws_alu_result   <= 32'b0;
      ws_mem_result   <= 32'b0;
      ws_ld_byte      <= 1'b0;
      ws_ld_half      <= 1'b0;
      ws_ld_sign_ext  <= 1'b0;
    end
    else if (ws_allowin)
    begin
      if (ms_to_ws_valid)
      begin
        ws_pc           <= ms_pc;
        ws_alu_result   <= ms_alu_result;
        ws_mem_result   <= ms_mem_rdata;
        ws_res_from_mem <= ms_res_from_mem;
        ws_gr_we        <= ms_gr_we;
        ws_dest         <= ms_dest;
        ws_ld_byte      <= ms_ld_byte;
        ws_ld_half      <= ms_ld_half;
        ws_ld_sign_ext  <= ms_ld_sign_ext;
      end
      else
      begin
        ws_gr_we        <= 1'b0;
      end
    end
  end

endmodule
