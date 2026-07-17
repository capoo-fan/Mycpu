`include "mycpu.vh"

module WB_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ms_to_ws_valid_0,
    input  wire                         ms_to_ws_valid_1,
    input  wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_0,
    input  wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_1,

    output wire                         ws_allowin,
    output wire [`WS_TO_RF_BUS_WD-1:0]  ws_to_rf_bus,
    output wire                         csr_busy,
    output wire                         csr_we,
    output wire [13:0]                  csr_waddr,
    output wire [31:0]                  csr_wmask,
    output wire [31:0]                  csr_wdata,
    output wire                         csr_flush,
    output wire [31:0]                  csr_flush_target
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ws_valid_0;
  reg  [31:0] ws_pc_0;
  reg  [31:0] ws_alu_result_0;
  reg  [31:0] ws_mem_result_0;
  reg         ws_res_from_mem_0;
  reg         ws_gr_we_0;
  reg  [ 4:0] ws_dest_0;
  reg         ws_ld_byte_0;
  reg         ws_ld_half_0;
  reg         ws_ld_sign_ext_0;
  reg         ws_is_csr_0;
  reg  [13:0] ws_csr_num_0;
  reg  [31:0] ws_csr_wmask_0;
  reg  [31:0] ws_csr_wvalue_0;

  reg         ws_valid_1;
  reg  [31:0] ws_alu_result_1;
  reg  [31:0] ws_mem_result_1;
  reg         ws_res_from_mem_1;
  reg         ws_gr_we_1;
  reg  [ 4:0] ws_dest_1;
  reg         ws_ld_byte_1;
  reg         ws_ld_half_1;
  reg         ws_ld_sign_ext_1;
  reg         ws_is_csr_1;
  reg  [13:0] ws_csr_num_1;
  reg  [31:0] ws_csr_wmask_1;
  reg  [31:0] ws_csr_wvalue_1;

  wire [31:0] ms_pc_0;
  wire [31:0] ms_alu_result_0;
  wire        ms_res_from_mem_0;
  wire        ms_gr_we_0;
  wire [ 4:0] ms_dest_0;
  wire        ms_ld_byte_0;
  wire        ms_ld_half_0;
  wire        ms_ld_sign_ext_0;
  wire [31:0] ms_mem_rdata_0;
  wire        ms_is_csr_0;
  wire [13:0] ms_csr_num_0;
  wire [31:0] ms_csr_wmask_0;
  wire [31:0] ms_csr_wvalue_0;

  assign {ms_pc_0, ms_alu_result_0, ms_res_from_mem_0, ms_gr_we_0, ms_dest_0,
          ms_ld_byte_0, ms_ld_half_0, ms_ld_sign_ext_0,
          ms_mem_rdata_0, ms_is_csr_0, ms_csr_num_0,
          ms_csr_wmask_0, ms_csr_wvalue_0} = ms_to_ws_bus_0;

  wire [31:0] unused_ms_pc_1;
  wire [31:0] ms_alu_result_1;
  wire        ms_res_from_mem_1;
  wire        ms_gr_we_1;
  wire [ 4:0] ms_dest_1;
  wire        ms_ld_byte_1;
  wire        ms_ld_half_1;
  wire        ms_ld_sign_ext_1;
  wire [31:0] ms_mem_rdata_1;
  wire        ms_is_csr_1;
  wire [13:0] ms_csr_num_1;
  wire [31:0] ms_csr_wmask_1;
  wire [31:0] ms_csr_wvalue_1;

  assign {unused_ms_pc_1, ms_alu_result_1, ms_res_from_mem_1, ms_gr_we_1, ms_dest_1,
          ms_ld_byte_1, ms_ld_half_1, ms_ld_sign_ext_1,
          ms_mem_rdata_1, ms_is_csr_1, ms_csr_num_1,
          ms_csr_wmask_1, ms_csr_wvalue_1} = ms_to_ws_bus_1;

  // 加载数据的函数
  function [31:0] load_result;
    input [31:0] alu_result;
    input [31:0] mem_result;
    input        ld_byte;
    input        ld_half;
    input        ld_sign_ext;
    reg [7:0]    load_byte;
    reg [15:0]   load_half;
    begin
      load_byte = alu_result[1] ? (alu_result[0] ? mem_result[31:24] : mem_result[23:16]) :
                (alu_result[0] ? mem_result[15:8]  : mem_result[7:0]);
      load_half = alu_result[1] ? mem_result[31:16] : mem_result[15:0];
      load_result = ld_byte ? (ld_sign_ext ? {{24{load_byte[7]}}, load_byte} :
                               {24'b0, load_byte}) :
                  ld_half ? (ld_sign_ext ? {{16{load_half[15]}}, load_half} :
                             {16'b0, load_half}) :
                  mem_result;
    end
  endfunction

  wire [31:0] ws_load_result_0 = load_result(ws_alu_result_0, ws_mem_result_0,
       ws_ld_byte_0, ws_ld_half_0, ws_ld_sign_ext_0);
  wire [31:0] ws_load_result_1 = load_result(ws_alu_result_1, ws_mem_result_1,
       ws_ld_byte_1, ws_ld_half_1, ws_ld_sign_ext_1);

  wire [31:0] final_result_0 = ws_res_from_mem_0 ? ws_load_result_0 : ws_alu_result_0;
  wire [31:0] final_result_1 = ws_res_from_mem_1 ? ws_load_result_1 : ws_alu_result_1;

  // WB has no functional backpressure after the simulation-only debug FIFO
  // is removed.  Both issue lanes can retire in the same cycle.
  assign ws_allowin = 1'b1;

  assign csr_busy         = ws_valid_0 && ws_is_csr_0;
  assign csr_we           = ws_valid_0 && ws_is_csr_0;
  assign csr_waddr        = ws_csr_num_0;
  assign csr_wmask        = ws_csr_wmask_0;
  assign csr_wdata        = ws_csr_wvalue_0;
  assign csr_flush        = csr_we;
  assign csr_flush_target = ws_pc_0 + 32'd4;

  wire ws_rf_we_0    = ws_valid_0 && ws_gr_we_0;
  wire [ 4:0] ws_rf_waddr_0 = ws_dest_0;
  wire [31:0] ws_rf_wdata_0 = final_result_0;

  wire ws_rf_we_1    = ws_valid_1 && ws_gr_we_1;
  wire [ 4:0] ws_rf_waddr_1 = ws_dest_1;
  wire [31:0] ws_rf_wdata_1 = final_result_1;

  assign ws_to_rf_bus = {ws_rf_we_0, ws_rf_waddr_0, ws_rf_wdata_0,
                         ws_rf_we_1, ws_rf_waddr_1, ws_rf_wdata_1};

  always @(posedge clk)
  begin
    if (reset)
    begin
      ws_valid_0 <= 1'b0;
      ws_valid_1 <= 1'b0;
    end
    else if (ws_allowin)
    begin
      ws_valid_0 <= ms_to_ws_valid_0;
      ws_valid_1 <= ms_to_ws_valid_1;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ws_pc_0           <= 32'b0;
      ws_gr_we_0        <= 1'b0;
      ws_res_from_mem_0 <= 1'b0;
      ws_dest_0         <= 5'b0;
      ws_alu_result_0   <= 32'b0;
      ws_mem_result_0   <= 32'b0;
      ws_ld_byte_0      <= 1'b0;
      ws_ld_half_0      <= 1'b0;
      ws_ld_sign_ext_0  <= 1'b0;
      ws_is_csr_0       <= 1'b0;
      ws_csr_num_0      <= 14'b0;
      ws_csr_wmask_0    <= 32'b0;
      ws_csr_wvalue_0   <= 32'b0;

      ws_gr_we_1        <= 1'b0;
      ws_res_from_mem_1 <= 1'b0;
      ws_dest_1         <= 5'b0;
      ws_alu_result_1   <= 32'b0;
      ws_mem_result_1   <= 32'b0;
      ws_ld_byte_1      <= 1'b0;
      ws_ld_half_1      <= 1'b0;
      ws_ld_sign_ext_1  <= 1'b0;
      ws_is_csr_1       <= 1'b0;
      ws_csr_num_1      <= 14'b0;
      ws_csr_wmask_1    <= 32'b0;
      ws_csr_wvalue_1   <= 32'b0;
    end
    else if (ws_allowin)
    begin
      if (ms_to_ws_valid_0)
      begin
        ws_pc_0           <= ms_pc_0;
        ws_alu_result_0   <= ms_alu_result_0;
        ws_mem_result_0   <= ms_mem_rdata_0;
        ws_res_from_mem_0 <= ms_res_from_mem_0;
        ws_gr_we_0        <= ms_gr_we_0;
        ws_dest_0         <= ms_dest_0;
        ws_ld_byte_0      <= ms_ld_byte_0;
        ws_ld_half_0      <= ms_ld_half_0;
        ws_ld_sign_ext_0  <= ms_ld_sign_ext_0;
        ws_is_csr_0       <= ms_is_csr_0;
        ws_csr_num_0      <= ms_csr_num_0;
        ws_csr_wmask_0    <= ms_csr_wmask_0;
        ws_csr_wvalue_0   <= ms_csr_wvalue_0;
      end
      else
      begin
        ws_gr_we_0        <= 1'b0;
        ws_res_from_mem_0 <= 1'b0;
        ws_is_csr_0       <= 1'b0;
      end

      if (ms_to_ws_valid_1)
      begin
        ws_alu_result_1   <= ms_alu_result_1;
        ws_mem_result_1   <= ms_mem_rdata_1;
        ws_res_from_mem_1 <= ms_res_from_mem_1;
        ws_gr_we_1        <= ms_gr_we_1;
        ws_dest_1         <= ms_dest_1;
        ws_ld_byte_1      <= ms_ld_byte_1;
        ws_ld_half_1      <= ms_ld_half_1;
        ws_ld_sign_ext_1  <= ms_ld_sign_ext_1;
        ws_is_csr_1       <= ms_is_csr_1;
        ws_csr_num_1      <= ms_csr_num_1;
        ws_csr_wmask_1    <= ms_csr_wmask_1;
        ws_csr_wvalue_1   <= ms_csr_wvalue_1;
      end
      else
      begin
        ws_gr_we_1        <= 1'b0;
        ws_res_from_mem_1 <= 1'b0;
        ws_is_csr_1       <= 1'b0;
      end
    end
  end

endmodule
