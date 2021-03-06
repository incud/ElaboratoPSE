// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="xtea,hls_ip_2018_2_2,{HLS_INPUT_TYPE=sc,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=7.196000,HLS_SYN_LAT=4,HLS_SYN_TPT=none,HLS_SYN_MEM=6,HLS_SYN_DSP=0,HLS_SYN_FF=300,HLS_SYN_LUT=1083,HLS_VERSION=2018_2_2}" *)

module xtea (
        ap_clk,
        ap_rst,
        clock,
        reset,
        op1,
        op2,
        command,
        inputReady,
        result1,
        result2,
        outputReady
);


input   ap_clk;
input   ap_rst;
input   clock;
input   reset;
input  [31:0] op1;
input  [31:0] op2;
input  [1:0] command;
input   inputReady;
output  [31:0] result1;
output  [31:0] result2;
output   outputReady;

reg[31:0] result1;
reg[31:0] result2;
reg outputReady;

reg   [0:0] dpValues_address0;
reg    dpValues_ce0;
wire   [31:0] dpValues_q0;
reg   [0:0] dpValues_address1;
reg    dpValues_ce1;
wire   [31:0] dpValues_q1;
reg   [1:0] keys_address0;
reg    keys_ce0;
wire   [31:0] keys_q0;
reg   [0:0] values_address0;
reg    values_ce0;
wire   [31:0] values_q0;
reg   [0:0] values_address1;
reg    values_ce1;
wire   [31:0] values_q1;
wire   [0:0] xtea_ssdm_thread_s_load_fu_194_p1;
wire   [3:0] ap_CS_fsm;
wire   [0:0] xtea_ssdm_thread_1_load_fu_198_p1;
wire    ap_CS_fsm_state2;
wire   [0:0] grp_xtea_fsm_fu_114_dpValues_address0;
wire    grp_xtea_fsm_fu_114_dpValues_ce0;
wire   [0:0] grp_xtea_fsm_fu_114_dpValues_address1;
wire    grp_xtea_fsm_fu_114_dpValues_ce1;
wire   [1:0] grp_xtea_fsm_fu_114_keys_address0;
wire    grp_xtea_fsm_fu_114_keys_ce0;
wire    grp_xtea_fsm_fu_114_keys_we0;
wire   [31:0] grp_xtea_fsm_fu_114_keys_d0;
wire   [1:0] grp_xtea_fsm_fu_114_keys_address1;
wire    grp_xtea_fsm_fu_114_keys_ce1;
wire    grp_xtea_fsm_fu_114_keys_we1;
wire   [31:0] grp_xtea_fsm_fu_114_keys_d1;
wire   [0:0] grp_xtea_fsm_fu_114_values_address0;
wire    grp_xtea_fsm_fu_114_values_ce0;
wire    grp_xtea_fsm_fu_114_values_we0;
wire   [31:0] grp_xtea_fsm_fu_114_values_d0;
wire   [0:0] grp_xtea_fsm_fu_114_values_address1;
wire    grp_xtea_fsm_fu_114_values_ce1;
wire    grp_xtea_fsm_fu_114_values_we1;
wire   [31:0] grp_xtea_fsm_fu_114_values_d1;
wire   [1:0] grp_xtea_fsm_fu_114_memCommand;
wire    grp_xtea_fsm_fu_114_memCommand_ap_vld;
wire   [31:0] grp_xtea_fsm_fu_114_fsmState_o;
wire    grp_xtea_fsm_fu_114_fsmState_o_ap_vld;
wire   [31:0] grp_xtea_fsm_fu_114_result1;
wire    grp_xtea_fsm_fu_114_result1_ap_vld;
wire   [31:0] grp_xtea_fsm_fu_114_result2;
wire    grp_xtea_fsm_fu_114_result2_ap_vld;
wire    grp_xtea_fsm_fu_114_outputReady;
wire    grp_xtea_fsm_fu_114_outputReady_ap_vld;
wire   [5:0] grp_xtea_datapath_fu_154_counter_o;
wire    grp_xtea_datapath_fu_154_counter_o_ap_vld;
wire   [63:0] grp_xtea_datapath_fu_154_sum_o;
wire    grp_xtea_datapath_fu_154_sum_o_ap_vld;
wire   [31:0] grp_xtea_datapath_fu_154_temp_o;
wire    grp_xtea_datapath_fu_154_temp_o_ap_vld;
wire   [31:0] grp_xtea_datapath_fu_154_acc_o;
wire    grp_xtea_datapath_fu_154_acc_o_ap_vld;
wire   [0:0] grp_xtea_datapath_fu_154_dpValues_address0;
wire    grp_xtea_datapath_fu_154_dpValues_ce0;
wire    grp_xtea_datapath_fu_154_dpValues_we0;
wire   [31:0] grp_xtea_datapath_fu_154_dpValues_d0;
wire   [0:0] grp_xtea_datapath_fu_154_dpValues_address1;
wire    grp_xtea_datapath_fu_154_dpValues_ce1;
wire    grp_xtea_datapath_fu_154_dpValues_we1;
wire   [31:0] grp_xtea_datapath_fu_154_dpValues_d1;
wire   [1:0] grp_xtea_datapath_fu_154_keys_address0;
wire    grp_xtea_datapath_fu_154_keys_ce0;
wire   [0:0] grp_xtea_datapath_fu_154_values_address0;
wire    grp_xtea_datapath_fu_154_values_ce0;
wire   [0:0] grp_xtea_datapath_fu_154_values_address1;
wire    grp_xtea_datapath_fu_154_values_ce1;
reg   [5:0] counter;
reg   [63:0] sum;
reg   [31:0] temp;
reg   [31:0] acc;
reg   [31:0] fsmState;
wire    ap_CS_fsm_state4;

xtea_dpValues #(
    .DataWidth( 32 ),
    .AddressRange( 2 ),
    .AddressWidth( 1 ))
dpValues_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(dpValues_address0),
    .ce0(dpValues_ce0),
    .we0(grp_xtea_datapath_fu_154_dpValues_we0),
    .d0(grp_xtea_datapath_fu_154_dpValues_d0),
    .q0(dpValues_q0),
    .address1(dpValues_address1),
    .ce1(dpValues_ce1),
    .we1(grp_xtea_datapath_fu_154_dpValues_we1),
    .d1(grp_xtea_datapath_fu_154_dpValues_d1),
    .q1(dpValues_q1)
);

xtea_keys #(
    .DataWidth( 32 ),
    .AddressRange( 4 ),
    .AddressWidth( 2 ))
keys_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(keys_address0),
    .ce0(keys_ce0),
    .we0(grp_xtea_fsm_fu_114_keys_we0),
    .d0(grp_xtea_fsm_fu_114_keys_d0),
    .q0(keys_q0),
    .address1(grp_xtea_fsm_fu_114_keys_address1),
    .ce1(grp_xtea_fsm_fu_114_keys_ce1),
    .we1(grp_xtea_fsm_fu_114_keys_we1),
    .d1(grp_xtea_fsm_fu_114_keys_d1)
);

xtea_dpValues #(
    .DataWidth( 32 ),
    .AddressRange( 2 ),
    .AddressWidth( 1 ))
values_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(values_address0),
    .ce0(values_ce0),
    .we0(grp_xtea_fsm_fu_114_values_we0),
    .d0(grp_xtea_fsm_fu_114_values_d0),
    .q0(values_q0),
    .address1(values_address1),
    .ce1(values_ce1),
    .we1(grp_xtea_fsm_fu_114_values_we1),
    .d1(grp_xtea_fsm_fu_114_values_d1),
    .q1(values_q1)
);

xtea_fsm grp_xtea_fsm_fu_114(
    .ap_clk(clock),
    .ap_rst(ap_rst),
    .counter(counter),
    .dpValues_address0(grp_xtea_fsm_fu_114_dpValues_address0),
    .dpValues_ce0(grp_xtea_fsm_fu_114_dpValues_ce0),
    .dpValues_q0(dpValues_q0),
    .dpValues_address1(grp_xtea_fsm_fu_114_dpValues_address1),
    .dpValues_ce1(grp_xtea_fsm_fu_114_dpValues_ce1),
    .dpValues_q1(dpValues_q1),
    .keys_address0(grp_xtea_fsm_fu_114_keys_address0),
    .keys_ce0(grp_xtea_fsm_fu_114_keys_ce0),
    .keys_we0(grp_xtea_fsm_fu_114_keys_we0),
    .keys_d0(grp_xtea_fsm_fu_114_keys_d0),
    .keys_address1(grp_xtea_fsm_fu_114_keys_address1),
    .keys_ce1(grp_xtea_fsm_fu_114_keys_ce1),
    .keys_we1(grp_xtea_fsm_fu_114_keys_we1),
    .keys_d1(grp_xtea_fsm_fu_114_keys_d1),
    .values_address0(grp_xtea_fsm_fu_114_values_address0),
    .values_ce0(grp_xtea_fsm_fu_114_values_ce0),
    .values_we0(grp_xtea_fsm_fu_114_values_we0),
    .values_d0(grp_xtea_fsm_fu_114_values_d0),
    .values_q0(values_q0),
    .values_address1(grp_xtea_fsm_fu_114_values_address1),
    .values_ce1(grp_xtea_fsm_fu_114_values_ce1),
    .values_we1(grp_xtea_fsm_fu_114_values_we1),
    .values_d1(grp_xtea_fsm_fu_114_values_d1),
    .values_q1(values_q1),
    .memCommand(grp_xtea_fsm_fu_114_memCommand),
    .memCommand_ap_vld(grp_xtea_fsm_fu_114_memCommand_ap_vld),
    .fsmState_i(fsmState),
    .fsmState_o(grp_xtea_fsm_fu_114_fsmState_o),
    .fsmState_o_ap_vld(grp_xtea_fsm_fu_114_fsmState_o_ap_vld),
    .reset(reset),
    .op1(op1),
    .op2(op2),
    .command(command),
    .inputReady(inputReady),
    .result1(grp_xtea_fsm_fu_114_result1),
    .result1_ap_vld(grp_xtea_fsm_fu_114_result1_ap_vld),
    .result2(grp_xtea_fsm_fu_114_result2),
    .result2_ap_vld(grp_xtea_fsm_fu_114_result2_ap_vld),
    .outputReady(grp_xtea_fsm_fu_114_outputReady),
    .outputReady_ap_vld(grp_xtea_fsm_fu_114_outputReady_ap_vld)
);

xtea_datapath grp_xtea_datapath_fu_154(
    .ap_clk(clock),
    .ap_rst(ap_rst),
    .counter_i(counter),
    .counter_o(grp_xtea_datapath_fu_154_counter_o),
    .counter_o_ap_vld(grp_xtea_datapath_fu_154_counter_o_ap_vld),
    .sum_i(sum),
    .sum_o(grp_xtea_datapath_fu_154_sum_o),
    .sum_o_ap_vld(grp_xtea_datapath_fu_154_sum_o_ap_vld),
    .temp_i(temp),
    .temp_o(grp_xtea_datapath_fu_154_temp_o),
    .temp_o_ap_vld(grp_xtea_datapath_fu_154_temp_o_ap_vld),
    .acc_i(acc),
    .acc_o(grp_xtea_datapath_fu_154_acc_o),
    .acc_o_ap_vld(grp_xtea_datapath_fu_154_acc_o_ap_vld),
    .dpValues_address0(grp_xtea_datapath_fu_154_dpValues_address0),
    .dpValues_ce0(grp_xtea_datapath_fu_154_dpValues_ce0),
    .dpValues_we0(grp_xtea_datapath_fu_154_dpValues_we0),
    .dpValues_d0(grp_xtea_datapath_fu_154_dpValues_d0),
    .dpValues_q0(dpValues_q0),
    .dpValues_address1(grp_xtea_datapath_fu_154_dpValues_address1),
    .dpValues_ce1(grp_xtea_datapath_fu_154_dpValues_ce1),
    .dpValues_we1(grp_xtea_datapath_fu_154_dpValues_we1),
    .dpValues_d1(grp_xtea_datapath_fu_154_dpValues_d1),
    .keys_address0(grp_xtea_datapath_fu_154_keys_address0),
    .keys_ce0(grp_xtea_datapath_fu_154_keys_ce0),
    .keys_q0(keys_q0),
    .values_address0(grp_xtea_datapath_fu_154_values_address0),
    .values_ce0(grp_xtea_datapath_fu_154_values_ce0),
    .values_q0(values_q0),
    .values_address1(grp_xtea_datapath_fu_154_values_address1),
    .values_ce1(grp_xtea_datapath_fu_154_values_ce1),
    .values_q1(values_q1),
    .fsmState(fsmState),
    .command(command)
);

always @ (posedge ap_clk) begin
    if ((grp_xtea_datapath_fu_154_acc_o_ap_vld == 1'b1)) begin
        acc <= grp_xtea_datapath_fu_154_acc_o;
    end
end

always @ (posedge ap_clk) begin
    if ((grp_xtea_datapath_fu_154_counter_o_ap_vld == 1'b1)) begin
        counter <= grp_xtea_datapath_fu_154_counter_o;
    end
end

always @ (posedge ap_clk) begin
    if ((grp_xtea_fsm_fu_114_fsmState_o_ap_vld == 1'b1)) begin
        fsmState <= grp_xtea_fsm_fu_114_fsmState_o;
    end
end

always @ (posedge clock) begin
    if ((grp_xtea_fsm_fu_114_outputReady_ap_vld == 1'b1)) begin
        outputReady <= grp_xtea_fsm_fu_114_outputReady;
    end
end

always @ (posedge clock) begin
    if ((grp_xtea_fsm_fu_114_result1_ap_vld == 1'b1)) begin
        result1 <= grp_xtea_fsm_fu_114_result1;
    end
end

always @ (posedge clock) begin
    if ((grp_xtea_fsm_fu_114_result2_ap_vld == 1'b1)) begin
        result2 <= grp_xtea_fsm_fu_114_result2;
    end
end

always @ (posedge ap_clk) begin
    if ((grp_xtea_datapath_fu_154_sum_o_ap_vld == 1'b1)) begin
        sum <= grp_xtea_datapath_fu_154_sum_o;
    end
end

always @ (posedge ap_clk) begin
    if ((grp_xtea_datapath_fu_154_temp_o_ap_vld == 1'b1)) begin
        temp <= grp_xtea_datapath_fu_154_temp_o;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_dpValues_ce0 == 1'b1)) begin
        dpValues_address0 = grp_xtea_datapath_fu_154_dpValues_address0;
    end else if ((grp_xtea_fsm_fu_114_dpValues_ce0 == 1'b1)) begin
        dpValues_address0 = grp_xtea_fsm_fu_114_dpValues_address0;
    end else begin
        dpValues_address0 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_dpValues_ce1 == 1'b1)) begin
        dpValues_address1 = grp_xtea_datapath_fu_154_dpValues_address1;
    end else if ((grp_xtea_fsm_fu_114_dpValues_ce1 == 1'b1)) begin
        dpValues_address1 = grp_xtea_fsm_fu_114_dpValues_address1;
    end else begin
        dpValues_address1 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_dpValues_ce0 == 1'b1)) begin
        dpValues_ce0 = grp_xtea_datapath_fu_154_dpValues_ce0;
    end else if ((grp_xtea_fsm_fu_114_dpValues_ce0 == 1'b1)) begin
        dpValues_ce0 = grp_xtea_fsm_fu_114_dpValues_ce0;
    end else begin
        dpValues_ce0 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_dpValues_ce1 == 1'b1)) begin
        dpValues_ce1 = grp_xtea_datapath_fu_154_dpValues_ce1;
    end else if ((grp_xtea_fsm_fu_114_dpValues_ce1 == 1'b1)) begin
        dpValues_ce1 = grp_xtea_fsm_fu_114_dpValues_ce1;
    end else begin
        dpValues_ce1 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_keys_ce0 == 1'b1)) begin
        keys_address0 = grp_xtea_datapath_fu_154_keys_address0;
    end else if ((grp_xtea_fsm_fu_114_keys_ce0 == 1'b1)) begin
        keys_address0 = grp_xtea_fsm_fu_114_keys_address0;
    end else begin
        keys_address0 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_keys_ce0 == 1'b1)) begin
        keys_ce0 = grp_xtea_datapath_fu_154_keys_ce0;
    end else if ((grp_xtea_fsm_fu_114_keys_ce0 == 1'b1)) begin
        keys_ce0 = grp_xtea_fsm_fu_114_keys_ce0;
    end else begin
        keys_ce0 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_values_ce0 == 1'b1)) begin
        values_address0 = grp_xtea_datapath_fu_154_values_address0;
    end else if ((grp_xtea_fsm_fu_114_values_ce0 == 1'b1)) begin
        values_address0 = grp_xtea_fsm_fu_114_values_address0;
    end else begin
        values_address0 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_values_ce1 == 1'b1)) begin
        values_address1 = grp_xtea_datapath_fu_154_values_address1;
    end else if ((grp_xtea_fsm_fu_114_values_ce1 == 1'b1)) begin
        values_address1 = grp_xtea_fsm_fu_114_values_address1;
    end else begin
        values_address1 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_values_ce0 == 1'b1)) begin
        values_ce0 = grp_xtea_datapath_fu_154_values_ce0;
    end else if ((grp_xtea_fsm_fu_114_values_ce0 == 1'b1)) begin
        values_ce0 = grp_xtea_fsm_fu_114_values_ce0;
    end else begin
        values_ce0 = 'bx;
    end
end

always @ (*) begin
    if ((grp_xtea_datapath_fu_154_values_ce1 == 1'b1)) begin
        values_ce1 = grp_xtea_datapath_fu_154_values_ce1;
    end else if ((grp_xtea_fsm_fu_114_values_ce1 == 1'b1)) begin
        values_ce1 = grp_xtea_fsm_fu_114_values_ce1;
    end else begin
        values_ce1 = 'bx;
    end
end

assign ap_CS_fsm = 4'd0;

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign xtea_ssdm_thread_1_load_fu_198_p1 = 1'd0;

assign xtea_ssdm_thread_s_load_fu_194_p1 = 1'd0;

endmodule //xtea
