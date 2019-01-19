// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "main.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_lv<32> main::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_logic main::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic main::ap_const_logic_0 = sc_dt::Log_0;

main::main(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_return);

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_sc_inter_clock.posedge_event() );

    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "main_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, module_dpValues_Val_s_q0, "module_dpValues_Val_s_q0");
    sc_trace(mVcdFile, module_dpValues_Val_s_q1, "module_dpValues_Val_s_q1");
    sc_trace(mVcdFile, module_keys_Val_V_q0, "module_keys_Val_V_q0");
    sc_trace(mVcdFile, module_values_Val_V_q0, "module_values_Val_V_q0");
    sc_trace(mVcdFile, module_values_Val_V_q1, "module_values_Val_V_q1");
    sc_trace(mVcdFile, grp_xtea_fu_88_result1, "grp_xtea_fu_88_result1");
    sc_trace(mVcdFile, grp_xtea_fu_88_result2, "grp_xtea_fu_88_result2");
    sc_trace(mVcdFile, grp_xtea_fu_88_outputReady, "grp_xtea_fu_88_outputReady");
#endif

    }
    mHdltvinHandle.open("main.hdltvin.dat");
    mHdltvoutHandle.open("main.hdltvout.dat");
}

main::~main() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
}

void main::thread_ap_return() {
    ap_return = ap_const_lv32_0;
}

void main::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_return\" :  \"" << ap_return.read() << "\" ";
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}
