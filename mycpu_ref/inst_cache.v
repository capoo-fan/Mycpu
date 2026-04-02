`timescale 1ns / 1ps
module inst_cache( 
    input  wire         cpu_clk,
    input  wire         cpu_rstn,
    input  wire         flush,

    input  wire         pred_taken,
    input  wire [31:0]  pred_target,
    input  wire         bj_offset,

    output wire         full,
    input  wire         buffer_is_full,   
    
    input  wire         inst_rreq,
    input  wire [31:0]  inst_addr,
    output reg  [1:0]   inst_valid,
    output reg  [63:0]  inst_out,
    output reg  [31:0]  inst_pc1,
    output reg  [31:0]  inst_pc2,

    input  wire         dev_rrdy,
    output reg  [3:0]   cpu_ren,
    output reg  [31:0]  cpu_raddr,
    input  wire         dev_rvalid,
    input  wire [63:0]  dev_rdata,

    output reg          pred_taken1,
    output reg          pred_taken2,
    output reg [31:0]   pred_target1,
    output reg [31:0]   pred_target2
);

    parameter IDLE          = 2'b00;
    parameter REFILL_WAIT   = 2'b01;
    parameter RECOVERY      = 2'b10; 
    parameter DONE          = 2'b11;

    reg [1:0] state;
    reg [1:0] nstat;
    reg [63:0] refill_data_reg;


    wire        s0_valid = inst_rreq;
    wire [31:0] s0_addr  = inst_addr;
    wire [4:0]  s0_index = s0_addr[7:3];

    reg         s1_valid;
    reg [31:0]  s1_addr;
    reg         s1_bj_offset;
    reg         s1_pred_taken;
    reg [31:0]  s1_pred_target;
    wire [23:0] s1_tag   = s1_addr[31:8];
    wire [4:0]  s1_index = s1_addr[7:3];

    reg         s2_valid;
    reg         s2_hit;
    reg [63:0]  s2_data_from_bram;
    reg [31:0]  s2_addr;
    reg         s2_bj_offset;
    reg         s2_pred_taken;
    reg [31:0]  s2_pred_target;
    wire [23:0] s2_tag    = s2_addr[31:8];
    wire [4:0]  s2_index  = s2_addr[7:3];
    wire        s2_offset = s2_addr[2];


    wire s3_stall = buffer_is_full && |inst_valid; 
    wire s2_stall = s3_stall || (!s2_hit &&s2_valid && state != DONE );
    wire s1_stall = s2_stall;
    assign full = s1_stall;
 

    always @(posedge cpu_clk or negedge cpu_rstn) begin
        if (!cpu_rstn) begin
            s1_valid       <= 1'b0;
            s1_addr        <= 32'b0;
            s1_bj_offset   <= 1'b0;
            s1_pred_taken  <= 1'b0;
            s1_pred_target <= 32'b0;
        end else if (flush) begin
            s1_valid       <= 1'b0;
            s1_addr        <= 32'b0;
            s1_bj_offset   <= 1'b0;
            s1_pred_taken  <= 1'b0;
            s1_pred_target <= 32'b0;
        end else if (!s1_stall) begin
            s1_valid       <= s0_valid;
            s1_addr        <= s0_addr;
            s1_bj_offset   <= bj_offset;
            s1_pred_taken  <= pred_taken;
            s1_pred_target <= pred_target;
        end
    end

    wire [88:0] bmem_dout;
    wire        bmem_valid_bit = bmem_dout[88];
    wire [23:0] bmem_tag       = bmem_dout[87:64];
    wire [63:0] bmem_data_blk  = bmem_dout[63:0];
    wire        s1_hit = s1_valid && bmem_valid_bit && (bmem_tag == s1_tag);

    always @(posedge cpu_clk or negedge cpu_rstn) begin
        if (!cpu_rstn) begin
            s2_valid            <= 1'b0;
            s2_hit              <= 1'b0;
            s2_data_from_bram   <= 64'b0;
            s2_addr             <= 32'b0;
            s2_bj_offset        <= 1'b0;
            s2_pred_taken       <= 1'b0;
            s2_pred_target      <= 32'b0;
        end else if (flush) begin
            s2_valid            <= 1'b0;
            s2_hit              <= 1'b0;
            s2_data_from_bram   <= 64'b0;
            s2_addr             <= 32'b0;
            s2_bj_offset        <= 1'b0;
            s2_pred_taken       <= 1'b0;
            s2_pred_target      <= 32'b0;
        end else if (!s2_stall) begin
            s2_valid            <= s1_valid;
            s2_hit              <= s1_hit;
            s2_data_from_bram   <= bmem_data_blk;
            s2_addr             <= s1_addr;
            s2_bj_offset        <= s1_bj_offset;
            s2_pred_taken       <= s1_pred_taken;
            s2_pred_target      <= s1_pred_target;
        end
    end


    reg [1:0]   s2_inst_valid_nxt;
    reg [63:0]  s2_inst_out_nxt;
    reg [31:0]  s2_inst_pc1_nxt;
    reg [31:0]  s2_inst_pc2_nxt;
    reg         s2_pred_taken1_nxt;
    reg         s2_pred_taken2_nxt;
    reg [31:0]  s2_pred_target1_nxt;
    reg [31:0]  s2_pred_target2_nxt;

    wire [63:0] s2_data_to_process;
    wire [1:0]  s2_temp_valid;
    wire [31:0] s2_base_pc_for_slot0 = {s2_addr[31:3], 3'b000};
    wire [31:0] s2_base_pc_for_slot1 = {s2_addr[31:3], 3'b100};


    assign s2_data_to_process =  s2_hit ? s2_data_from_bram :  refill_data_reg ;
    assign s2_temp_valid = (2'b11 << s2_offset) & (s2_pred_taken ? (2'b11 >> !s2_bj_offset) : 2'b11);


    always @(*) begin
        // Default values
        s2_inst_valid_nxt   = 2'b0;
        s2_inst_out_nxt     = 64'b0;
        s2_inst_pc1_nxt     = 32'b0;
        s2_inst_pc2_nxt     = 32'b0;
        s2_pred_taken1_nxt  = 1'b0;
        s2_pred_target1_nxt = 32'h0;
        s2_pred_taken2_nxt  = 1'b0;
        s2_pred_target2_nxt = 32'h0;
        if( state == DONE || s2_hit  )begin
            case (s2_temp_valid)
                2'b11: begin
                    s2_inst_valid_nxt = 2'b11;
                    s2_inst_out_nxt   = s2_data_to_process;
                    s2_inst_pc1_nxt   = s2_base_pc_for_slot0;
                    s2_inst_pc2_nxt   = s2_base_pc_for_slot1;
                end
                2'b10: begin
                    s2_inst_valid_nxt = 2'b01;
                    s2_inst_out_nxt   = {32'b0, s2_data_to_process[63:32]};
                    s2_inst_pc1_nxt   = s2_base_pc_for_slot1;
                    s2_inst_pc2_nxt   = 32'b0;
                end
                2'b01: begin
                    s2_inst_valid_nxt = 2'b01;
                    s2_inst_out_nxt   = {32'b0, s2_data_to_process[31:0]};
                    s2_inst_pc1_nxt   = s2_base_pc_for_slot0;
                    s2_inst_pc2_nxt   = 32'b0;
                end
                default: begin
                end
            endcase
         
            if (s2_pred_taken) begin
                if (s2_bj_offset == 1'b0) begin
                    {s2_pred_taken1_nxt, s2_pred_target1_nxt} = {s2_pred_taken, s2_pred_target};
                end else begin
                    if (s2_temp_valid == 2'b11) begin
                        {s2_pred_taken2_nxt, s2_pred_target2_nxt} = {s2_pred_taken, s2_pred_target};
                    end else begin
                        {s2_pred_taken1_nxt, s2_pred_target1_nxt} = {s2_pred_taken, s2_pred_target};
                    end
                end
            end
        end
    end

    always @(posedge cpu_clk or negedge cpu_rstn) begin
        if (!cpu_rstn ) begin
            inst_valid   <= 2'b0;
            inst_out     <= 64'b0;
            inst_pc1     <= 32'b0;
            inst_pc2     <= 32'b0;
            pred_taken1  <= 1'b0;
            pred_target1 <= 32'h0;
            pred_taken2  <= 1'b0;
            pred_target2 <= 32'h0;
        end else if (flush) begin
            inst_valid   <= 2'b0;
            inst_out     <= 64'b0;
            inst_pc1     <= 32'b0;
            inst_pc2     <= 32'b0;
            pred_taken1  <= 1'b0;
            pred_target1 <= 32'h0;
            pred_taken2  <= 1'b0;
            pred_target2 <= 32'h0;
        end else if (!s3_stall) begin
            inst_valid   <= s2_inst_valid_nxt;
            inst_out     <= s2_inst_out_nxt;
            inst_pc1     <= s2_inst_pc1_nxt;
            inst_pc2     <= s2_inst_pc2_nxt;
            pred_taken1  <= s2_pred_taken1_nxt;
            pred_target1 <= s2_pred_target1_nxt;
            pred_taken2  <= s2_pred_taken2_nxt;
            pred_target2 <= s2_pred_target2_nxt;
        end
    end

    wire trigger_miss = s2_valid && !s2_hit;

    always @(posedge cpu_clk or negedge cpu_rstn) begin
        if (!cpu_rstn ) begin
            state <= IDLE;
        end else if (flush) begin
            state <= IDLE;
        end else begin
            state <= nstat;
        end
    end

    always @(*) begin
        case(state)
            IDLE:        nstat = trigger_miss ? REFILL_WAIT : IDLE;
            REFILL_WAIT: nstat = dev_rvalid ? RECOVERY : REFILL_WAIT;
            RECOVERY:    nstat = DONE;
            DONE :       nstat = s3_stall? DONE :IDLE;
            default:     nstat = IDLE;
        endcase
    end

    always @(posedge cpu_clk or negedge cpu_rstn) begin
        if (!cpu_rstn) begin
            refill_data_reg <= 64'b0;
        end else if ((state == REFILL_WAIT) && dev_rvalid) begin
            refill_data_reg <= dev_rdata;
        end
    end

    wire cache_we0 = (state == REFILL_WAIT && dev_rvalid);
    wire [88:0] cache_line_w = {1'b1, s2_tag, dev_rdata}; 
    wire [4:0] bmem_addr = cache_we0 ? s2_index : (s1_stall ? s1_index : s0_index);
    
    blk_mem_gen_0 U_isram0 (
        .clka  (cpu_clk),
        .wea   (cache_we0),
        .addra (bmem_addr),
        .dina  (cache_line_w),
        .douta (bmem_dout)
    );

 
    always @(posedge cpu_clk or negedge cpu_rstn) begin
        if(!cpu_rstn ) begin
            cpu_ren   <= 4'h0;
            cpu_raddr <= 32'h0;
        end else if (flush) begin
            cpu_ren   <= 4'h0;
            cpu_raddr <= 32'h0;            
        end else begin
            if (state == IDLE && trigger_miss) begin
                cpu_ren   <= 4'b1111;
                cpu_raddr <= {s2_addr[31:3], 3'b0};
            end else if( state == REFILL_WAIT && dev_rvalid )begin
                cpu_ren   <= 4'b0000;
                cpu_raddr <= 32'b0;
            end 
        end
    end
    
endmodule
