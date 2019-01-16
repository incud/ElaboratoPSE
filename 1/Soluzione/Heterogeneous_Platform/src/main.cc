#include "common.hh"
#include "controller_tlm.hh"
#include "controller_cipher_transactor.hh"
#include "transactor.hh"
#include "valve.hh"
#include "valve_if.hh"
#include "watertank.hh"
#include "watertank_if.hh"

int sc_main(int argc, char* argv[])
{
    sc_core::sc_clock clock("clock", 1, SC_US);

    sca_tdf::sca_signal<double> sig_livello_acqua, sig_threshold, sig_apertura;
    sca_tdf::sca_signal<int> sig_comando;

    sc_core::sc_signal<int> sig_rtl_comando;
    sc_core::sc_signal<double> sig_rtl_threshold, sig_rtl_livello_acqua;

    sc_core::sc_signal<bool>        sig_xtea_reset;
    sc_core::sc_signal<sc_uint<32>> sig_xtea_op1, sig_xtea_op2;
    sc_core::sc_signal<sc_uint<2>>  sig_xtea_command;
    sc_core::sc_signal<bool>        sig_xtea_inputReady;
    sc_core::sc_signal<sc_uint<32>> sig_xtea_result1, sig_xtea_result2;
    sc_core::sc_signal<bool>        sig_xtea_outputReady;

    controller_tlm c("controller_tlm");
    controller_cipher_transactor cct("controller_cipher_transactor");
    xtea x("xtea");
    transactor t("transactor");
    valve_if vif("valve_if");
    valve v("valve");
    watertank wt("watertank");
    watertank_if wtif("watertank_if");

    sca_util::sca_trace_file* trace;

    // Connessione tra controllore e transattore cifrario
    c.initiator_socket_transactor_cipher(cct.target_socket_controller);

    // Connessione tra transattore cifrario ed transattore valvola
    cct.initiator_socket_transactor(t.target_socket);

    // Connessione moduli AMS
    vif.comando_ams(sig_comando);       // out
    vif.threshold_ams(sig_threshold);   // out
    v.comando(sig_comando);             // in
    v.threshold(sig_threshold);         // in
    v.apertura(sig_apertura);           // out
    wt.in(sig_apertura);                // in
    wt.out(sig_livello_acqua);          // out
    wtif.livello_acqua_ams(sig_livello_acqua);

    // Connessione dell'interfaccia della valvola + interfaccia serbatoio col transattore
    t.comando(sig_rtl_comando);
    t.threshold(sig_rtl_threshold);
    t.livello_acqua(sig_rtl_livello_acqua);
    vif.comando_rtl(sig_rtl_comando);
    vif.threshold_rtl(sig_rtl_threshold);
    wtif.livello_acqua_rtl(sig_rtl_livello_acqua);

    // Connessione tra transattore cifrario e cifrario
    cct.clock(clock);
    cct.op1(sig_xtea_op1);
    cct.op2(sig_xtea_op2);
    cct.command(sig_xtea_command);
    cct.inputReady(sig_xtea_inputReady);
    cct.result1(sig_xtea_result1), 
    cct.result2(sig_xtea_result2);
    cct.outputReady(sig_xtea_outputReady);
    x.clock(clock);
    x.op1(sig_xtea_op1);
    x.op2(sig_xtea_op2);
    x.command(sig_xtea_command);
    x.inputReady(sig_xtea_inputReady);
    x.result1(sig_xtea_result1), 
    x.result2(sig_xtea_result2);
    x.outputReady(sig_xtea_outputReady);
    x.reset(sig_xtea_reset);
    
    // File di trace
    trace = sca_util::sca_create_vcd_trace_file("trace.vcd");
    sca_util::sca_trace(trace, sig_livello_acqua, "livello_acqua");
    sca_util::sca_trace(trace, sig_threshold, "threshold");
    sca_util::sca_trace(trace, sig_apertura, "apertura");
    sca_util::sca_trace(trace, sig_comando, "comando");

    // Partenza simulazione
    sc_core::sc_start(COMMON_TIMESTEP * CONTROLLER_ITERATION_THRESHOLD * 100);
    sca_util::sca_close_vcd_trace_file(trace);

    return 0;
}