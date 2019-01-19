// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="main,hls_ip_2018_2_2,{HLS_INPUT_TYPE=sc,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=7.196000,HLS_SYN_LAT=5,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=0,HLS_SYN_LUT=0,HLS_VERSION=2018_2_2}" *)

module main (
        ap_return,
        ap_clk,
        ap_rst
);


output  [31:0] ap_return;
input   ap_clk;
input   ap_rst;

wire   [31:0] module_dpValues_Val_s_q0;
wire   [31:0] module_dpValues_Val_s_q1;
wire   [31:0] module_keys_Val_V_q0;
wire   [31:0] module_values_Val_V_q0;
wire   [31:0] module_values_Val_V_q1;
wire   [31:0] grp_xtea_fu_88_result1;
wire   [31:0] grp_xtea_fu_88_result2;
wire    grp_xtea_fu_88_outputReady;

assign ap_return = 32'd0;

endmodule //main
