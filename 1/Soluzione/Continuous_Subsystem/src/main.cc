#include "common.hh"
#include "controller.hh"
#include "valve.hh"
#include "watertank.hh"

int sc_main(int argc, char* argv[])
{
    // Inizio settando la risoluzione della simulazione
    sc_core::sc_set_time_resolution(1.0, sc_core::SC_US);

    // Moduli
    watertank wt("watertank");
    valve v("valve");
    controller c("controller");

    // Segnali di connessione tra i moduli
    sca_tdf::sca_signal<double> sig_livello_acqua, sig_threshold, sig_apertura;
    sca_tdf::sca_signal<int> sig_comando;

    // Connessioni
    c.livello_acqua(sig_livello_acqua); // in
    c.comando(sig_comando);             // out
    v.comando(sig_comando);             // in
    c.threshold(sig_threshold);         // out
    v.threshold(sig_threshold);         // in
    v.apertura(sig_apertura);           // out
    wt.in(sig_apertura);                // in
    wt.out(sig_livello_acqua);          // out

    // File di trace
    sca_util::sca_trace_file* trace = sca_util::sca_create_vcd_trace_file("trace.vcd");
    sca_util::sca_trace(trace, sig_livello_acqua, "livello_acqua");
    sca_util::sca_trace(trace, sig_threshold, "threshold");
    sca_util::sca_trace(trace, sig_apertura, "apertura");
    sca_util::sca_trace(trace, sig_comando, "comando");

    // Partenza simulazione
    sc_core::sc_start(COMMON_TIMESTEP * CONTROLLER_ITERATION_THRESHOLD * 100);
    sca_util::sca_close_vcd_trace_file(trace);

    return 0;
}
