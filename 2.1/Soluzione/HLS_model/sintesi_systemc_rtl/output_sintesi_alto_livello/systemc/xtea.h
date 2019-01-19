// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _xtea_HH_
#define _xtea_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "xtea_fsm.h"
#include "xtea_datapath.h"
#include "xtea_dpValues.h"
#include "xtea_keys.h"

namespace ap_rtl {

struct xtea : public sc_module {
    // Port declarations 11
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in_clk clock;
    sc_in< sc_logic > reset;
    sc_in< sc_lv<32> > op1;
    sc_in< sc_lv<32> > op2;
    sc_in< sc_lv<2> > command;
    sc_in< sc_logic > inputReady;
    sc_out< sc_lv<32> > result1;
    sc_out< sc_lv<32> > result2;
    sc_out< sc_logic > outputReady;


    // Module declarations
    xtea(sc_module_name name);
    SC_HAS_PROCESS(xtea);

    ~xtea();

    sc_trace_file* mVcdFile;

    xtea_dpValues* dpValues_U;
    xtea_keys* keys_U;
    xtea_dpValues* values_U;
    xtea_fsm* grp_xtea_fsm_fu_114;
    xtea_datapath* grp_xtea_datapath_fu_154;
    sc_signal< sc_lv<1> > dpValues_address0;
    sc_signal< sc_logic > dpValues_ce0;
    sc_signal< sc_lv<32> > dpValues_q0;
    sc_signal< sc_lv<1> > dpValues_address1;
    sc_signal< sc_logic > dpValues_ce1;
    sc_signal< sc_lv<32> > dpValues_q1;
    sc_signal< sc_lv<2> > keys_address0;
    sc_signal< sc_logic > keys_ce0;
    sc_signal< sc_lv<32> > keys_q0;
    sc_signal< sc_lv<1> > values_address0;
    sc_signal< sc_logic > values_ce0;
    sc_signal< sc_lv<32> > values_q0;
    sc_signal< sc_lv<1> > values_address1;
    sc_signal< sc_logic > values_ce1;
    sc_signal< sc_lv<32> > values_q1;
    sc_signal< sc_lv<1> > xtea_ssdm_thread_s_load_fu_194_p1;
    sc_signal< sc_lv<4> > ap_CS_fsm;
    sc_signal< sc_lv<1> > xtea_ssdm_thread_1_load_fu_198_p1;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<1> > grp_xtea_fsm_fu_114_dpValues_address0;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_dpValues_ce0;
    sc_signal< sc_lv<1> > grp_xtea_fsm_fu_114_dpValues_address1;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_dpValues_ce1;
    sc_signal< sc_lv<2> > grp_xtea_fsm_fu_114_keys_address0;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_keys_ce0;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_keys_we0;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_keys_d0;
    sc_signal< sc_lv<2> > grp_xtea_fsm_fu_114_keys_address1;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_keys_ce1;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_keys_we1;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_keys_d1;
    sc_signal< sc_lv<1> > grp_xtea_fsm_fu_114_values_address0;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_values_ce0;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_values_we0;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_values_d0;
    sc_signal< sc_lv<1> > grp_xtea_fsm_fu_114_values_address1;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_values_ce1;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_values_we1;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_values_d1;
    sc_signal< sc_lv<2> > grp_xtea_fsm_fu_114_memCommand;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_memCommand_ap_vld;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_fsmState_o;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_fsmState_o_ap_vld;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_result1;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_result1_ap_vld;
    sc_signal< sc_lv<32> > grp_xtea_fsm_fu_114_result2;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_result2_ap_vld;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_outputReady;
    sc_signal< sc_logic > grp_xtea_fsm_fu_114_outputReady_ap_vld;
    sc_signal< sc_lv<6> > grp_xtea_datapath_fu_154_counter_o;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_counter_o_ap_vld;
    sc_signal< sc_lv<64> > grp_xtea_datapath_fu_154_sum_o;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_sum_o_ap_vld;
    sc_signal< sc_lv<32> > grp_xtea_datapath_fu_154_temp_o;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_temp_o_ap_vld;
    sc_signal< sc_lv<32> > grp_xtea_datapath_fu_154_acc_o;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_acc_o_ap_vld;
    sc_signal< sc_lv<1> > grp_xtea_datapath_fu_154_dpValues_address0;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_dpValues_ce0;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_dpValues_we0;
    sc_signal< sc_lv<32> > grp_xtea_datapath_fu_154_dpValues_d0;
    sc_signal< sc_lv<1> > grp_xtea_datapath_fu_154_dpValues_address1;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_dpValues_ce1;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_dpValues_we1;
    sc_signal< sc_lv<32> > grp_xtea_datapath_fu_154_dpValues_d1;
    sc_signal< sc_lv<2> > grp_xtea_datapath_fu_154_keys_address0;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_keys_ce0;
    sc_signal< sc_lv<1> > grp_xtea_datapath_fu_154_values_address0;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_values_ce0;
    sc_signal< sc_lv<1> > grp_xtea_datapath_fu_154_values_address1;
    sc_signal< sc_logic > grp_xtea_datapath_fu_154_values_ce1;
    sc_signal< sc_lv<6> > counter;
    sc_signal< sc_lv<64> > sum;
    sc_signal< sc_lv<32> > temp;
    sc_signal< sc_lv<32> > acc;
    sc_signal< sc_lv<32> > fsmState;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    static const sc_logic ap_const_logic_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_logic ap_const_logic_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_acc();
    void thread_counter();
    void thread_fsmState();
    void thread_outputReady();
    void thread_result1();
    void thread_result2();
    void thread_sum();
    void thread_temp();
    void thread_ap_CS_fsm();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state4();
    void thread_dpValues_address0();
    void thread_dpValues_address1();
    void thread_dpValues_ce0();
    void thread_dpValues_ce1();
    void thread_keys_address0();
    void thread_keys_ce0();
    void thread_values_address0();
    void thread_values_address1();
    void thread_values_ce0();
    void thread_values_ce1();
    void thread_xtea_ssdm_thread_1_load_fu_198_p1();
    void thread_xtea_ssdm_thread_s_load_fu_194_p1();
};

}

using namespace ap_rtl;

#endif