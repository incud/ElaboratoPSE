// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "xtea.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic xtea::ap_const_logic_1 = sc_dt::Log_1;
const sc_lv<1> xtea::ap_const_lv1_0 = "0";
const sc_lv<32> xtea::ap_const_lv32_1 = "1";
const sc_lv<1> xtea::ap_const_lv1_1 = "1";
const sc_lv<32> xtea::ap_const_lv32_3 = "11";
const sc_lv<4> xtea::ap_const_lv4_0 = "0000";
const sc_logic xtea::ap_const_logic_0 = sc_dt::Log_0;
const bool xtea::ap_const_boolean_1 = true;

xtea::xtea(sc_module_name name) : sc_module(name), mVcdFile(0) {
    dpValues_U = new xtea_dpValues("dpValues_U");
    dpValues_U->clk(ap_clk);
    dpValues_U->reset(ap_rst);
    dpValues_U->address0(dpValues_address0);
    dpValues_U->ce0(dpValues_ce0);
    dpValues_U->we0(grp_xtea_datapath_fu_154_dpValues_we0);
    dpValues_U->d0(grp_xtea_datapath_fu_154_dpValues_d0);
    dpValues_U->q0(dpValues_q0);
    dpValues_U->address1(dpValues_address1);
    dpValues_U->ce1(dpValues_ce1);
    dpValues_U->we1(grp_xtea_datapath_fu_154_dpValues_we1);
    dpValues_U->d1(grp_xtea_datapath_fu_154_dpValues_d1);
    dpValues_U->q1(dpValues_q1);
    keys_U = new xtea_keys("keys_U");
    keys_U->clk(ap_clk);
    keys_U->reset(ap_rst);
    keys_U->address0(keys_address0);
    keys_U->ce0(keys_ce0);
    keys_U->we0(grp_xtea_fsm_fu_114_keys_we0);
    keys_U->d0(grp_xtea_fsm_fu_114_keys_d0);
    keys_U->q0(keys_q0);
    keys_U->address1(grp_xtea_fsm_fu_114_keys_address1);
    keys_U->ce1(grp_xtea_fsm_fu_114_keys_ce1);
    keys_U->we1(grp_xtea_fsm_fu_114_keys_we1);
    keys_U->d1(grp_xtea_fsm_fu_114_keys_d1);
    values_U = new xtea_dpValues("values_U");
    values_U->clk(ap_clk);
    values_U->reset(ap_rst);
    values_U->address0(values_address0);
    values_U->ce0(values_ce0);
    values_U->we0(grp_xtea_fsm_fu_114_values_we0);
    values_U->d0(grp_xtea_fsm_fu_114_values_d0);
    values_U->q0(values_q0);
    values_U->address1(values_address1);
    values_U->ce1(values_ce1);
    values_U->we1(grp_xtea_fsm_fu_114_values_we1);
    values_U->d1(grp_xtea_fsm_fu_114_values_d1);
    values_U->q1(values_q1);
    grp_xtea_fsm_fu_114 = new xtea_fsm("grp_xtea_fsm_fu_114");
    grp_xtea_fsm_fu_114->ap_clk(clock);
    grp_xtea_fsm_fu_114->ap_rst(ap_rst);
    grp_xtea_fsm_fu_114->counter(counter);
    grp_xtea_fsm_fu_114->dpValues_address0(grp_xtea_fsm_fu_114_dpValues_address0);
    grp_xtea_fsm_fu_114->dpValues_ce0(grp_xtea_fsm_fu_114_dpValues_ce0);
    grp_xtea_fsm_fu_114->dpValues_q0(dpValues_q0);
    grp_xtea_fsm_fu_114->dpValues_address1(grp_xtea_fsm_fu_114_dpValues_address1);
    grp_xtea_fsm_fu_114->dpValues_ce1(grp_xtea_fsm_fu_114_dpValues_ce1);
    grp_xtea_fsm_fu_114->dpValues_q1(dpValues_q1);
    grp_xtea_fsm_fu_114->keys_address0(grp_xtea_fsm_fu_114_keys_address0);
    grp_xtea_fsm_fu_114->keys_ce0(grp_xtea_fsm_fu_114_keys_ce0);
    grp_xtea_fsm_fu_114->keys_we0(grp_xtea_fsm_fu_114_keys_we0);
    grp_xtea_fsm_fu_114->keys_d0(grp_xtea_fsm_fu_114_keys_d0);
    grp_xtea_fsm_fu_114->keys_address1(grp_xtea_fsm_fu_114_keys_address1);
    grp_xtea_fsm_fu_114->keys_ce1(grp_xtea_fsm_fu_114_keys_ce1);
    grp_xtea_fsm_fu_114->keys_we1(grp_xtea_fsm_fu_114_keys_we1);
    grp_xtea_fsm_fu_114->keys_d1(grp_xtea_fsm_fu_114_keys_d1);
    grp_xtea_fsm_fu_114->values_address0(grp_xtea_fsm_fu_114_values_address0);
    grp_xtea_fsm_fu_114->values_ce0(grp_xtea_fsm_fu_114_values_ce0);
    grp_xtea_fsm_fu_114->values_we0(grp_xtea_fsm_fu_114_values_we0);
    grp_xtea_fsm_fu_114->values_d0(grp_xtea_fsm_fu_114_values_d0);
    grp_xtea_fsm_fu_114->values_q0(values_q0);
    grp_xtea_fsm_fu_114->values_address1(grp_xtea_fsm_fu_114_values_address1);
    grp_xtea_fsm_fu_114->values_ce1(grp_xtea_fsm_fu_114_values_ce1);
    grp_xtea_fsm_fu_114->values_we1(grp_xtea_fsm_fu_114_values_we1);
    grp_xtea_fsm_fu_114->values_d1(grp_xtea_fsm_fu_114_values_d1);
    grp_xtea_fsm_fu_114->values_q1(values_q1);
    grp_xtea_fsm_fu_114->memCommand(grp_xtea_fsm_fu_114_memCommand);
    grp_xtea_fsm_fu_114->memCommand_ap_vld(grp_xtea_fsm_fu_114_memCommand_ap_vld);
    grp_xtea_fsm_fu_114->fsmState_i(fsmState);
    grp_xtea_fsm_fu_114->fsmState_o(grp_xtea_fsm_fu_114_fsmState_o);
    grp_xtea_fsm_fu_114->fsmState_o_ap_vld(grp_xtea_fsm_fu_114_fsmState_o_ap_vld);
    grp_xtea_fsm_fu_114->reset(reset);
    grp_xtea_fsm_fu_114->op1(op1);
    grp_xtea_fsm_fu_114->op2(op2);
    grp_xtea_fsm_fu_114->command(command);
    grp_xtea_fsm_fu_114->inputReady(inputReady);
    grp_xtea_fsm_fu_114->result1(grp_xtea_fsm_fu_114_result1);
    grp_xtea_fsm_fu_114->result1_ap_vld(grp_xtea_fsm_fu_114_result1_ap_vld);
    grp_xtea_fsm_fu_114->result2(grp_xtea_fsm_fu_114_result2);
    grp_xtea_fsm_fu_114->result2_ap_vld(grp_xtea_fsm_fu_114_result2_ap_vld);
    grp_xtea_fsm_fu_114->outputReady(grp_xtea_fsm_fu_114_outputReady);
    grp_xtea_fsm_fu_114->outputReady_ap_vld(grp_xtea_fsm_fu_114_outputReady_ap_vld);
    grp_xtea_datapath_fu_154 = new xtea_datapath("grp_xtea_datapath_fu_154");
    grp_xtea_datapath_fu_154->ap_clk(clock);
    grp_xtea_datapath_fu_154->ap_rst(ap_rst);
    grp_xtea_datapath_fu_154->counter_i(counter);
    grp_xtea_datapath_fu_154->counter_o(grp_xtea_datapath_fu_154_counter_o);
    grp_xtea_datapath_fu_154->counter_o_ap_vld(grp_xtea_datapath_fu_154_counter_o_ap_vld);
    grp_xtea_datapath_fu_154->sum_i(sum);
    grp_xtea_datapath_fu_154->sum_o(grp_xtea_datapath_fu_154_sum_o);
    grp_xtea_datapath_fu_154->sum_o_ap_vld(grp_xtea_datapath_fu_154_sum_o_ap_vld);
    grp_xtea_datapath_fu_154->temp_i(temp);
    grp_xtea_datapath_fu_154->temp_o(grp_xtea_datapath_fu_154_temp_o);
    grp_xtea_datapath_fu_154->temp_o_ap_vld(grp_xtea_datapath_fu_154_temp_o_ap_vld);
    grp_xtea_datapath_fu_154->acc_i(acc);
    grp_xtea_datapath_fu_154->acc_o(grp_xtea_datapath_fu_154_acc_o);
    grp_xtea_datapath_fu_154->acc_o_ap_vld(grp_xtea_datapath_fu_154_acc_o_ap_vld);
    grp_xtea_datapath_fu_154->dpValues_address0(grp_xtea_datapath_fu_154_dpValues_address0);
    grp_xtea_datapath_fu_154->dpValues_ce0(grp_xtea_datapath_fu_154_dpValues_ce0);
    grp_xtea_datapath_fu_154->dpValues_we0(grp_xtea_datapath_fu_154_dpValues_we0);
    grp_xtea_datapath_fu_154->dpValues_d0(grp_xtea_datapath_fu_154_dpValues_d0);
    grp_xtea_datapath_fu_154->dpValues_q0(dpValues_q0);
    grp_xtea_datapath_fu_154->dpValues_address1(grp_xtea_datapath_fu_154_dpValues_address1);
    grp_xtea_datapath_fu_154->dpValues_ce1(grp_xtea_datapath_fu_154_dpValues_ce1);
    grp_xtea_datapath_fu_154->dpValues_we1(grp_xtea_datapath_fu_154_dpValues_we1);
    grp_xtea_datapath_fu_154->dpValues_d1(grp_xtea_datapath_fu_154_dpValues_d1);
    grp_xtea_datapath_fu_154->keys_address0(grp_xtea_datapath_fu_154_keys_address0);
    grp_xtea_datapath_fu_154->keys_ce0(grp_xtea_datapath_fu_154_keys_ce0);
    grp_xtea_datapath_fu_154->keys_q0(keys_q0);
    grp_xtea_datapath_fu_154->values_address0(grp_xtea_datapath_fu_154_values_address0);
    grp_xtea_datapath_fu_154->values_ce0(grp_xtea_datapath_fu_154_values_ce0);
    grp_xtea_datapath_fu_154->values_q0(values_q0);
    grp_xtea_datapath_fu_154->values_address1(grp_xtea_datapath_fu_154_values_address1);
    grp_xtea_datapath_fu_154->values_ce1(grp_xtea_datapath_fu_154_values_ce1);
    grp_xtea_datapath_fu_154->values_q1(values_q1);
    grp_xtea_datapath_fu_154->fsmState(fsmState);
    grp_xtea_datapath_fu_154->command(command);

    SC_METHOD(thread_acc);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_counter);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_fsmState);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_outputReady);
    dont_initialize();
    sensitive << ( clock.pos() );

    SC_METHOD(thread_result1);
    dont_initialize();
    sensitive << ( clock.pos() );

    SC_METHOD(thread_result2);
    dont_initialize();
    sensitive << ( clock.pos() );

    SC_METHOD(thread_sum);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_temp);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_CS_fsm);

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state4);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_dpValues_address0);
    sensitive << ( grp_xtea_fsm_fu_114_dpValues_address0 );
    sensitive << ( grp_xtea_fsm_fu_114_dpValues_ce0 );
    sensitive << ( grp_xtea_datapath_fu_154_dpValues_address0 );
    sensitive << ( grp_xtea_datapath_fu_154_dpValues_ce0 );

    SC_METHOD(thread_dpValues_address1);
    sensitive << ( grp_xtea_fsm_fu_114_dpValues_address1 );
    sensitive << ( grp_xtea_fsm_fu_114_dpValues_ce1 );
    sensitive << ( grp_xtea_datapath_fu_154_dpValues_address1 );
    sensitive << ( grp_xtea_datapath_fu_154_dpValues_ce1 );

    SC_METHOD(thread_dpValues_ce0);
    sensitive << ( grp_xtea_fsm_fu_114_dpValues_ce0 );
    sensitive << ( grp_xtea_datapath_fu_154_dpValues_ce0 );

    SC_METHOD(thread_dpValues_ce1);
    sensitive << ( grp_xtea_fsm_fu_114_dpValues_ce1 );
    sensitive << ( grp_xtea_datapath_fu_154_dpValues_ce1 );

    SC_METHOD(thread_keys_address0);
    sensitive << ( grp_xtea_fsm_fu_114_keys_address0 );
    sensitive << ( grp_xtea_fsm_fu_114_keys_ce0 );
    sensitive << ( grp_xtea_datapath_fu_154_keys_address0 );
    sensitive << ( grp_xtea_datapath_fu_154_keys_ce0 );

    SC_METHOD(thread_keys_ce0);
    sensitive << ( grp_xtea_fsm_fu_114_keys_ce0 );
    sensitive << ( grp_xtea_datapath_fu_154_keys_ce0 );

    SC_METHOD(thread_values_address0);
    sensitive << ( grp_xtea_fsm_fu_114_values_address0 );
    sensitive << ( grp_xtea_fsm_fu_114_values_ce0 );
    sensitive << ( grp_xtea_datapath_fu_154_values_address0 );
    sensitive << ( grp_xtea_datapath_fu_154_values_ce0 );

    SC_METHOD(thread_values_address1);
    sensitive << ( grp_xtea_fsm_fu_114_values_address1 );
    sensitive << ( grp_xtea_fsm_fu_114_values_ce1 );
    sensitive << ( grp_xtea_datapath_fu_154_values_address1 );
    sensitive << ( grp_xtea_datapath_fu_154_values_ce1 );

    SC_METHOD(thread_values_ce0);
    sensitive << ( grp_xtea_fsm_fu_114_values_ce0 );
    sensitive << ( grp_xtea_datapath_fu_154_values_ce0 );

    SC_METHOD(thread_values_ce1);
    sensitive << ( grp_xtea_fsm_fu_114_values_ce1 );
    sensitive << ( grp_xtea_datapath_fu_154_values_ce1 );

    SC_METHOD(thread_xtea_ssdm_thread_1_load_fu_198_p1);

    SC_METHOD(thread_xtea_ssdm_thread_s_load_fu_194_p1);

    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "xtea_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, clock, "(port)clock");
    sc_trace(mVcdFile, reset, "(port)reset");
    sc_trace(mVcdFile, op1, "(port)op1");
    sc_trace(mVcdFile, op2, "(port)op2");
    sc_trace(mVcdFile, command, "(port)command");
    sc_trace(mVcdFile, inputReady, "(port)inputReady");
    sc_trace(mVcdFile, result1, "(port)result1");
    sc_trace(mVcdFile, result2, "(port)result2");
    sc_trace(mVcdFile, outputReady, "(port)outputReady");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, dpValues_address0, "dpValues_address0");
    sc_trace(mVcdFile, dpValues_ce0, "dpValues_ce0");
    sc_trace(mVcdFile, dpValues_q0, "dpValues_q0");
    sc_trace(mVcdFile, dpValues_address1, "dpValues_address1");
    sc_trace(mVcdFile, dpValues_ce1, "dpValues_ce1");
    sc_trace(mVcdFile, dpValues_q1, "dpValues_q1");
    sc_trace(mVcdFile, keys_address0, "keys_address0");
    sc_trace(mVcdFile, keys_ce0, "keys_ce0");
    sc_trace(mVcdFile, keys_q0, "keys_q0");
    sc_trace(mVcdFile, values_address0, "values_address0");
    sc_trace(mVcdFile, values_ce0, "values_ce0");
    sc_trace(mVcdFile, values_q0, "values_q0");
    sc_trace(mVcdFile, values_address1, "values_address1");
    sc_trace(mVcdFile, values_ce1, "values_ce1");
    sc_trace(mVcdFile, values_q1, "values_q1");
    sc_trace(mVcdFile, xtea_ssdm_thread_s_load_fu_194_p1, "xtea_ssdm_thread_s_load_fu_194_p1");
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, xtea_ssdm_thread_1_load_fu_198_p1, "xtea_ssdm_thread_1_load_fu_198_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_dpValues_address0, "grp_xtea_fsm_fu_114_dpValues_address0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_dpValues_ce0, "grp_xtea_fsm_fu_114_dpValues_ce0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_dpValues_address1, "grp_xtea_fsm_fu_114_dpValues_address1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_dpValues_ce1, "grp_xtea_fsm_fu_114_dpValues_ce1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_address0, "grp_xtea_fsm_fu_114_keys_address0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_ce0, "grp_xtea_fsm_fu_114_keys_ce0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_we0, "grp_xtea_fsm_fu_114_keys_we0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_d0, "grp_xtea_fsm_fu_114_keys_d0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_address1, "grp_xtea_fsm_fu_114_keys_address1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_ce1, "grp_xtea_fsm_fu_114_keys_ce1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_we1, "grp_xtea_fsm_fu_114_keys_we1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_keys_d1, "grp_xtea_fsm_fu_114_keys_d1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_address0, "grp_xtea_fsm_fu_114_values_address0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_ce0, "grp_xtea_fsm_fu_114_values_ce0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_we0, "grp_xtea_fsm_fu_114_values_we0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_d0, "grp_xtea_fsm_fu_114_values_d0");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_address1, "grp_xtea_fsm_fu_114_values_address1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_ce1, "grp_xtea_fsm_fu_114_values_ce1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_we1, "grp_xtea_fsm_fu_114_values_we1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_values_d1, "grp_xtea_fsm_fu_114_values_d1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_memCommand, "grp_xtea_fsm_fu_114_memCommand");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_memCommand_ap_vld, "grp_xtea_fsm_fu_114_memCommand_ap_vld");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_fsmState_o, "grp_xtea_fsm_fu_114_fsmState_o");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_fsmState_o_ap_vld, "grp_xtea_fsm_fu_114_fsmState_o_ap_vld");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_result1, "grp_xtea_fsm_fu_114_result1");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_result1_ap_vld, "grp_xtea_fsm_fu_114_result1_ap_vld");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_result2, "grp_xtea_fsm_fu_114_result2");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_result2_ap_vld, "grp_xtea_fsm_fu_114_result2_ap_vld");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_outputReady, "grp_xtea_fsm_fu_114_outputReady");
    sc_trace(mVcdFile, grp_xtea_fsm_fu_114_outputReady_ap_vld, "grp_xtea_fsm_fu_114_outputReady_ap_vld");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_counter_o, "grp_xtea_datapath_fu_154_counter_o");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_counter_o_ap_vld, "grp_xtea_datapath_fu_154_counter_o_ap_vld");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_sum_o, "grp_xtea_datapath_fu_154_sum_o");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_sum_o_ap_vld, "grp_xtea_datapath_fu_154_sum_o_ap_vld");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_temp_o, "grp_xtea_datapath_fu_154_temp_o");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_temp_o_ap_vld, "grp_xtea_datapath_fu_154_temp_o_ap_vld");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_acc_o, "grp_xtea_datapath_fu_154_acc_o");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_acc_o_ap_vld, "grp_xtea_datapath_fu_154_acc_o_ap_vld");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_address0, "grp_xtea_datapath_fu_154_dpValues_address0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_ce0, "grp_xtea_datapath_fu_154_dpValues_ce0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_we0, "grp_xtea_datapath_fu_154_dpValues_we0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_d0, "grp_xtea_datapath_fu_154_dpValues_d0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_address1, "grp_xtea_datapath_fu_154_dpValues_address1");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_ce1, "grp_xtea_datapath_fu_154_dpValues_ce1");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_we1, "grp_xtea_datapath_fu_154_dpValues_we1");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_dpValues_d1, "grp_xtea_datapath_fu_154_dpValues_d1");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_keys_address0, "grp_xtea_datapath_fu_154_keys_address0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_keys_ce0, "grp_xtea_datapath_fu_154_keys_ce0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_values_address0, "grp_xtea_datapath_fu_154_values_address0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_values_ce0, "grp_xtea_datapath_fu_154_values_ce0");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_values_address1, "grp_xtea_datapath_fu_154_values_address1");
    sc_trace(mVcdFile, grp_xtea_datapath_fu_154_values_ce1, "grp_xtea_datapath_fu_154_values_ce1");
    sc_trace(mVcdFile, counter, "counter");
    sc_trace(mVcdFile, sum, "sum");
    sc_trace(mVcdFile, temp, "temp");
    sc_trace(mVcdFile, acc, "acc");
    sc_trace(mVcdFile, fsmState, "fsmState");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
#endif

    }
}

xtea::~xtea() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete dpValues_U;
    delete keys_U;
    delete values_U;
    delete grp_xtea_fsm_fu_114;
    delete grp_xtea_datapath_fu_154;
}

void xtea::thread_acc() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_acc_o_ap_vld.read())) {
        acc = grp_xtea_datapath_fu_154_acc_o.read();
    }
}

void xtea::thread_counter() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_counter_o_ap_vld.read())) {
        counter = grp_xtea_datapath_fu_154_counter_o.read();
    }
}

void xtea::thread_fsmState() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_fsmState_o_ap_vld.read())) {
        fsmState = grp_xtea_fsm_fu_114_fsmState_o.read();
    }
}

void xtea::thread_outputReady() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_outputReady_ap_vld.read())) {
        outputReady = grp_xtea_fsm_fu_114_outputReady.read();
    }
}

void xtea::thread_result1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_result1_ap_vld.read())) {
        result1 = grp_xtea_fsm_fu_114_result1.read();
    }
}

void xtea::thread_result2() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_result2_ap_vld.read())) {
        result2 = grp_xtea_fsm_fu_114_result2.read();
    }
}

void xtea::thread_sum() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_sum_o_ap_vld.read())) {
        sum = grp_xtea_datapath_fu_154_sum_o.read();
    }
}

void xtea::thread_temp() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_temp_o_ap_vld.read())) {
        temp = grp_xtea_datapath_fu_154_temp_o.read();
    }
}

void xtea::thread_ap_CS_fsm() {
    ap_CS_fsm = ap_const_lv4_0;
}

void xtea::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void xtea::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void xtea::thread_dpValues_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_dpValues_ce0.read())) {
        dpValues_address0 = grp_xtea_datapath_fu_154_dpValues_address0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_dpValues_ce0.read())) {
        dpValues_address0 = grp_xtea_fsm_fu_114_dpValues_address0.read();
    } else {
        dpValues_address0 = "X";
    }
}

void xtea::thread_dpValues_address1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_dpValues_ce1.read())) {
        dpValues_address1 = grp_xtea_datapath_fu_154_dpValues_address1.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_dpValues_ce1.read())) {
        dpValues_address1 = grp_xtea_fsm_fu_114_dpValues_address1.read();
    } else {
        dpValues_address1 = "X";
    }
}

void xtea::thread_dpValues_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_dpValues_ce0.read())) {
        dpValues_ce0 = grp_xtea_datapath_fu_154_dpValues_ce0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_dpValues_ce0.read())) {
        dpValues_ce0 = grp_xtea_fsm_fu_114_dpValues_ce0.read();
    } else {
        dpValues_ce0 = sc_logic('X');
    }
}

void xtea::thread_dpValues_ce1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_dpValues_ce1.read())) {
        dpValues_ce1 = grp_xtea_datapath_fu_154_dpValues_ce1.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_dpValues_ce1.read())) {
        dpValues_ce1 = grp_xtea_fsm_fu_114_dpValues_ce1.read();
    } else {
        dpValues_ce1 = sc_logic('X');
    }
}

void xtea::thread_keys_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_keys_ce0.read())) {
        keys_address0 = grp_xtea_datapath_fu_154_keys_address0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_keys_ce0.read())) {
        keys_address0 = grp_xtea_fsm_fu_114_keys_address0.read();
    } else {
        keys_address0 =  (sc_lv<2>) ("XX");
    }
}

void xtea::thread_keys_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_keys_ce0.read())) {
        keys_ce0 = grp_xtea_datapath_fu_154_keys_ce0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_keys_ce0.read())) {
        keys_ce0 = grp_xtea_fsm_fu_114_keys_ce0.read();
    } else {
        keys_ce0 = sc_logic('X');
    }
}

void xtea::thread_values_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_values_ce0.read())) {
        values_address0 = grp_xtea_datapath_fu_154_values_address0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_values_ce0.read())) {
        values_address0 = grp_xtea_fsm_fu_114_values_address0.read();
    } else {
        values_address0 = "X";
    }
}

void xtea::thread_values_address1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_values_ce1.read())) {
        values_address1 = grp_xtea_datapath_fu_154_values_address1.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_values_ce1.read())) {
        values_address1 = grp_xtea_fsm_fu_114_values_address1.read();
    } else {
        values_address1 = "X";
    }
}

void xtea::thread_values_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_values_ce0.read())) {
        values_ce0 = grp_xtea_datapath_fu_154_values_ce0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_values_ce0.read())) {
        values_ce0 = grp_xtea_fsm_fu_114_values_ce0.read();
    } else {
        values_ce0 = sc_logic('X');
    }
}

void xtea::thread_values_ce1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_datapath_fu_154_values_ce1.read())) {
        values_ce1 = grp_xtea_datapath_fu_154_values_ce1.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_xtea_fsm_fu_114_values_ce1.read())) {
        values_ce1 = grp_xtea_fsm_fu_114_values_ce1.read();
    } else {
        values_ce1 = sc_logic('X');
    }
}

void xtea::thread_xtea_ssdm_thread_1_load_fu_198_p1() {
    xtea_ssdm_thread_1_load_fu_198_p1 = ap_const_lv1_0;
}

void xtea::thread_xtea_ssdm_thread_s_load_fu_194_p1() {
    xtea_ssdm_thread_s_load_fu_194_p1 = ap_const_lv1_0;
}

}

