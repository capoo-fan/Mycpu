`timescale 1ns / 1ps
`default_nettype none

module dmem_prefetch(
    input  wire        clk,
    input  wire        resetn,
    input  wire        invalidate_all,
    input  wire        lookup_cancel,

    input  wire        cpu_req,
    input  wire        cpu_wr,
    input  wire [ 1:0] cpu_size,
    input  wire [ 3:0] cpu_wstrb,
    input  wire [31:0] cpu_addr,
    input  wire [31:0] cpu_wdata,
    input  wire [31:0] cpu_pc,
    input  wire        cpu_store_is_ext,
    input  wire        cpu_lookup_valid,
    input  wire [31:0] cpu_lookup_addr,
    output wire        cpu_addr_ok,
    output wire        cpu_data_ok,
    output wire [31:0] cpu_rdata,
    output wire        cpu_fast_ready,
    output wire        cpu_fast_data_ok,
    output wire [31:0] cpu_fast_rdata,
    output wire        cpu_store_ready,

    output wire        mem_req,
    output wire        mem_wr,
    output wire [ 1:0] mem_size,
    output wire [ 3:0] mem_wstrb,
    output wire [31:0] mem_addr,
    output wire [31:0] mem_wdata,
    output wire        mem_store_is_ext,
    input  wire        mem_addr_ok,
    input  wire        mem_data_ok,
    input  wire [31:0] mem_rdata,
    input  wire        mem_fast_ready,
    input  wire        mem_fast_data_ok,
    input  wire [31:0] mem_fast_rdata,
    input  wire        mem_store_ready
  );

  localparam [1:0] OWNER_IDLE     = 2'd0;
  localparam [1:0] OWNER_DEMAND   = 2'd1;
  localparam [1:0] OWNER_PREFETCH = 2'd2;

  reg [1:0] lower_owner;
  reg [31:0] active_prefetch_addr;
  reg        prefetch_promoted;
  reg        prefetch_poisoned;
  reg        concurrent_store_pending;
  reg        prefer_prefetch;

  function is_sram_addr;
    input [31:0] address;
    begin
      is_sram_addr = ((address & 32'hff80_0000) == 32'h1c00_0000);
    end
  endfunction

  function [4:0] buffer_index;
    input [31:0] address;
    begin
      buffer_index = address[6:2] ^ address[11:7] ^
                     address[16:12] ^ address[21:17];
    end
  endfunction

  reg         buffer_valid [0:31];
  (* ram_style = "distributed" *) reg [24:0] buffer_tag [0:31];
  (* ram_style = "distributed" *) reg [31:0] buffer_data [0:31];

  wire        cpu_addr_is_sram = is_sram_addr(cpu_addr);
  wire [4:0]  cpu_buffer_index = buffer_index(cpu_addr);
  wire [4:0]  lookup_buffer_index = buffer_index(cpu_lookup_addr);
  wire        lookup_buffer_hit = cpu_lookup_valid &&
       is_sram_addr(cpu_lookup_addr) &&
       buffer_valid[lookup_buffer_index] &&
       (buffer_tag[lookup_buffer_index] == cpu_lookup_addr[31:7]);
  wire [31:0] lookup_buffer_data = buffer_data[lookup_buffer_index];

  reg         lookup_valid_q;
  reg         lookup_hit_q;
  reg [31:0]  lookup_data_q;
  reg [31:0]  lookup_addr_q;

  wire        cpu_buffer_hit = cpu_req && !cpu_wr &&
       lookup_valid_q && lookup_hit_q &&
       (cpu_addr[31:2] == lookup_addr_q[31:2]);
  wire [31:0] cpu_buffer_data = lookup_data_q;

  reg         hit_response_valid;
  reg [31:0]  hit_response_data;

  reg         predictor_valid  [0:15];
  (* ram_style = "distributed" *) reg [25:0] predictor_tag [0:15];
  (* ram_style = "distributed" *) reg [29:0] predictor_last [0:15];
  (* ram_style = "distributed" *) reg signed [29:0]
       predictor_stride [0:15];
  (* ram_style = "distributed" *) reg [1:0] predictor_conf [0:15];

  (* ram_style = "distributed" *) reg [31:0] prefetch_queue_addr [0:7];
  reg [2:0]  prefetch_queue_head;
  reg [2:0]  prefetch_queue_tail;
  reg [3:0]  prefetch_queue_count;

  wire [31:0] queued_prefetch_addr =
       prefetch_queue_addr[prefetch_queue_head];
  wire cpu_posted_store = cpu_req && cpu_wr && cpu_addr_is_sram;
  wire prefetch_launch = (lower_owner == OWNER_IDLE) &&
       (!cpu_req || (cpu_posted_store && prefer_prefetch)) &&
       (prefetch_queue_count != 4'd0);
  wire demand_forward = (lower_owner == OWNER_IDLE) && cpu_req &&
       !cpu_buffer_hit && !prefetch_launch;
  wire concurrent_store_forward = (lower_owner == OWNER_PREFETCH) &&
       !concurrent_store_pending && cpu_posted_store;
  wire lower_cpu_forward = demand_forward || concurrent_store_forward;

  wire promoted_match = (lower_owner == OWNER_PREFETCH) &&
       !prefetch_promoted && !concurrent_store_pending && cpu_req &&
       !cpu_wr && cpu_addr_is_sram &&
       (cpu_addr[31:2] == active_prefetch_addr[31:2]) &&
       !mem_data_ok && !mem_fast_ready;

  wire hit_accept = cpu_req && !cpu_wr && cpu_buffer_hit &&
       !hit_response_valid && !concurrent_store_pending;
  wire demand_lower_accept = demand_forward && mem_addr_ok;
  wire concurrent_store_accept = concurrent_store_forward && mem_addr_ok;
  wire store_lower_accept = lower_cpu_forward && cpu_wr && mem_addr_ok;
  wire prefetch_lower_accept = prefetch_launch && mem_addr_ok;
  wire promote_accept = promoted_match && !hit_response_valid;
  wire cpu_accept = hit_accept || demand_lower_accept ||
       concurrent_store_accept || promote_accept;
  wire train_accept = cpu_accept && !cpu_wr && cpu_addr_is_sram;

  assign cpu_addr_ok = hit_accept || promote_accept ||
       ((demand_forward || concurrent_store_forward) && mem_addr_ok);
  assign cpu_data_ok = hit_response_valid ||
       ((lower_owner == OWNER_DEMAND) && mem_data_ok) ||
       ((lower_owner == OWNER_PREFETCH) && prefetch_promoted &&
        mem_fast_data_ok) ||
       (concurrent_store_pending && mem_data_ok);
  assign cpu_rdata = hit_response_valid ? hit_response_data :
       ((lower_owner == OWNER_PREFETCH) ? mem_fast_rdata : mem_rdata);
  assign cpu_fast_ready = hit_response_valid ||
       ((lower_owner == OWNER_DEMAND) && mem_fast_ready) ||
       ((lower_owner == OWNER_PREFETCH) && prefetch_promoted && mem_fast_ready);
  assign cpu_fast_data_ok = hit_response_valid ||
       ((lower_owner == OWNER_DEMAND) && mem_fast_data_ok) ||
       ((lower_owner == OWNER_PREFETCH) && prefetch_promoted &&
        mem_fast_data_ok);
  assign cpu_fast_rdata = hit_response_valid ? hit_response_data :
       mem_fast_rdata;
  assign cpu_store_ready = ((lower_owner == OWNER_IDLE) &&
       !prefer_prefetch && cpu_req && cpu_wr && mem_store_ready) ||
       (concurrent_store_forward && mem_store_ready);

  assign mem_req = lower_cpu_forward || prefetch_launch;
  assign mem_wr = lower_cpu_forward ? cpu_wr : 1'b0;
  assign mem_size = lower_cpu_forward ? cpu_size : 2'b10;
  assign mem_wstrb = lower_cpu_forward ? cpu_wstrb : 4'b0;
  assign mem_addr = lower_cpu_forward ? cpu_addr : queued_prefetch_addr;
  assign mem_wdata = lower_cpu_forward ? cpu_wdata : 32'b0;
  assign mem_store_is_ext = cpu_posted_store ? cpu_store_is_ext :
       (lower_cpu_forward ? cpu_store_is_ext : queued_prefetch_addr[22]);

  wire [3:0] predictor_index = cpu_pc[5:2];
  wire predictor_match = predictor_valid[predictor_index] &&
       (predictor_tag[predictor_index] == cpu_pc[31:6]);
  wire signed [31:0] current_word = $signed({2'b0, cpu_addr[31:2]});
  wire signed [31:0] previous_word =
       $signed({2'b0, predictor_last[predictor_index]});
  wire signed [31:0] observed_stride = current_word - previous_word;
  wire signed [31:0] learned_stride =
       $signed({{2{predictor_stride[predictor_index][29]}},
                predictor_stride[predictor_index]});
  wire stride_match = predictor_match && (observed_stride != 32'sd0) &&
       (observed_stride == learned_stride);
  wire signed [31:0] predicted_word = current_word +
       (observed_stride <<< 1);
  wire predicted_word_in_range = (predicted_word[31:30] == 2'b00);
  wire [31:0] predicted_addr = {predicted_word[29:0], 2'b00};
  wire predicted_active = (lower_owner == OWNER_PREFETCH) &&
       (active_prefetch_addr[31:2] == predicted_addr[31:2]);
  wire candidate_valid = train_accept && stride_match &&
       (predictor_conf[predictor_index] >= 2'd2) &&
       predicted_word_in_range && is_sram_addr(predicted_addr) &&
       !predicted_active && !invalidate_all;

  wire prefetch_dequeue = prefetch_lower_accept;
  wire prefetch_enqueue = candidate_valid &&
       ((prefetch_queue_count != 4'd8) || prefetch_dequeue);

  wire prefetch_response = (lower_owner == OWNER_PREFETCH) &&
       mem_fast_data_ok;
  wire [4:0] active_buffer_index = buffer_index(active_prefetch_addr);
  wire install_prefetch = prefetch_response && !prefetch_poisoned;
  wire lookup_install_hit = install_prefetch && cpu_lookup_valid &&
       (cpu_lookup_addr[31:2] == active_prefetch_addr[31:2]);

  integer entry;
  always @(posedge clk)
  begin
    if (!resetn)
    begin
      lower_owner         <= OWNER_IDLE;
      active_prefetch_addr <= 32'b0;
      prefetch_promoted   <= 1'b0;
      prefetch_poisoned   <= 1'b0;
      concurrent_store_pending <= 1'b0;
      prefer_prefetch     <= 1'b0;
    end
    else
    begin
      if (prefetch_lower_accept || (prefetch_queue_count == 4'd0))
        prefer_prefetch <= 1'b0;
      else if (prefetch_queue_count != 4'd0)
        prefer_prefetch <= 1'b1;

      if (invalidate_all && (lower_owner == OWNER_PREFETCH))
        prefetch_poisoned <= 1'b1;
      if (concurrent_store_accept)
      begin
        concurrent_store_pending <= 1'b1;
        if (cpu_addr[31:2] == active_prefetch_addr[31:2])
          prefetch_poisoned <= 1'b1;
      end
      else if (concurrent_store_pending && mem_data_ok)
        concurrent_store_pending <= 1'b0;

      case (lower_owner)
        OWNER_IDLE:
        begin
          prefetch_promoted <= 1'b0;
          prefetch_poisoned <= 1'b0;
          if (demand_lower_accept)
            lower_owner <= OWNER_DEMAND;
          else if (prefetch_lower_accept)
          begin
            lower_owner          <= OWNER_PREFETCH;
            active_prefetch_addr <= queued_prefetch_addr;
          end
        end
        OWNER_DEMAND:
        begin
          if (mem_data_ok)
            lower_owner <= OWNER_IDLE;
        end
        OWNER_PREFETCH:
        begin
          if (promote_accept)
            prefetch_promoted <= 1'b1;
          if (mem_fast_data_ok)
          begin
            lower_owner       <= OWNER_IDLE;
            prefetch_promoted <= 1'b0;
            prefetch_poisoned <= 1'b0;
          end
        end
        default:
          lower_owner <= OWNER_IDLE;
      endcase
    end
  end

  always @(posedge clk)
  begin
    if (!resetn || invalidate_all || lookup_cancel)
    begin
      lookup_valid_q <= 1'b0;
      lookup_hit_q   <= 1'b0;
      lookup_data_q  <= 32'b0;
      lookup_addr_q  <= 32'b0;
    end
    else if (cpu_lookup_valid)
    begin
      lookup_valid_q <= 1'b1;
      lookup_hit_q   <= (lookup_buffer_hit || lookup_install_hit) &&
           !(cpu_req && cpu_wr);
      lookup_data_q  <= lookup_install_hit ? mem_fast_rdata :
           lookup_buffer_data;
      lookup_addr_q  <= cpu_lookup_addr;
    end
    else if (cpu_accept && !cpu_wr)
    begin
      lookup_valid_q <= 1'b0;
      lookup_hit_q   <= 1'b0;
    end
  end

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      hit_response_valid <= 1'b0;
      hit_response_data  <= 32'b0;
    end
    else
    begin
      hit_response_valid <= hit_accept;
      if (hit_accept)
        hit_response_data <= cpu_buffer_data;
    end
  end

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      for (entry = 0; entry < 32; entry = entry + 1)
        buffer_valid[entry] <= 1'b0;
    end
    else
    begin
      if (invalidate_all)
      begin
        for (entry = 0; entry < 32; entry = entry + 1)
          buffer_valid[entry] <= 1'b0;
      end
      else
      begin
        if (install_prefetch)
        begin
          buffer_valid[active_buffer_index] <= 1'b1;
          buffer_tag[active_buffer_index]   <= active_prefetch_addr[31:7];
          buffer_data[active_buffer_index]  <= mem_fast_rdata;
        end
        if (store_lower_accept &&
            buffer_valid[cpu_buffer_index] &&
            (buffer_tag[cpu_buffer_index] == cpu_addr[31:7]))
          buffer_valid[cpu_buffer_index] <= 1'b0;
      end
    end
  end

  always @(posedge clk)
  begin
    if (!resetn || invalidate_all)
    begin
      for (entry = 0; entry < 16; entry = entry + 1)
        predictor_valid[entry]  <= 1'b0;
    end
    else if (train_accept)
    begin
      if (!predictor_match)
      begin
        predictor_valid[predictor_index]  <= 1'b1;
        predictor_tag[predictor_index]    <= cpu_pc[31:6];
        predictor_last[predictor_index]   <= cpu_addr[31:2];
        predictor_stride[predictor_index] <= 30'sd0;
        predictor_conf[predictor_index]   <= 2'b0;
      end
      else
      begin
        predictor_last[predictor_index] <= cpu_addr[31:2];
        if (stride_match)
        begin
          if (predictor_conf[predictor_index] != 2'b11)
            predictor_conf[predictor_index] <=
                 predictor_conf[predictor_index] + 2'd1;
        end
        else
        begin
          predictor_stride[predictor_index] <= observed_stride[29:0];
          predictor_conf[predictor_index]   <= 2'b0;
        end
      end
    end
  end

  always @(posedge clk)
  begin
    if (!resetn || invalidate_all)
    begin
      prefetch_queue_head  <= 3'b0;
      prefetch_queue_tail  <= 3'b0;
      prefetch_queue_count <= 4'b0;
    end
    else
    begin
      case ({prefetch_enqueue, prefetch_dequeue})
        2'b10:
        begin
          prefetch_queue_addr[prefetch_queue_tail] <= predicted_addr;
          prefetch_queue_tail  <= prefetch_queue_tail + 3'd1;
          prefetch_queue_count <= prefetch_queue_count + 4'd1;
        end
        2'b01:
        begin
          prefetch_queue_head  <= prefetch_queue_head + 3'd1;
          prefetch_queue_count <= prefetch_queue_count - 4'd1;
        end
        2'b11:
        begin
          prefetch_queue_addr[prefetch_queue_tail] <= predicted_addr;
          prefetch_queue_tail <= prefetch_queue_tail + 3'd1;
          prefetch_queue_head <= prefetch_queue_head + 3'd1;
        end
        default:
        begin
        end
      endcase
    end
  end

`ifndef SYNTHESIS
  reg [63:0] pf_candidate_count;
  reg [63:0] pf_issue_count;
  reg [63:0] pf_hit_count;
  reg [63:0] pf_late_count;
  reg [63:0] pf_drop_count;

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      pf_candidate_count <= 64'b0;
      pf_issue_count     <= 64'b0;
      pf_hit_count       <= 64'b0;
      pf_late_count      <= 64'b0;
      pf_drop_count      <= 64'b0;
    end
    else
    begin
      if (candidate_valid)
        pf_candidate_count <= pf_candidate_count + 64'd1;
      if (prefetch_lower_accept)
        pf_issue_count <= pf_issue_count + 64'd1;
      if (hit_accept)
        pf_hit_count <= pf_hit_count + 64'd1;
      if (promote_accept)
        pf_late_count <= pf_late_count + 64'd1;
      if (candidate_valid && !prefetch_enqueue)
        pf_drop_count <= pf_drop_count + 64'd1;
    end
  end

  always @(posedge clk)
  begin
    if (resetn)
    begin
      if (mem_req && (lower_owner != OWNER_IDLE) &&
          !concurrent_store_forward)
        $fatal(1, "prefetch lower request overlapped an owned transaction");
      if (prefetch_launch && cpu_req && !cpu_posted_store)
        $fatal(1, "prefetch request overrode an architectural demand");
      if (prefetch_lower_accept && !is_sram_addr(queued_prefetch_addr))
        $fatal(1, "prefetch accessed a non-SRAM address");
    end
  end
`endif

endmodule

`default_nettype wire
