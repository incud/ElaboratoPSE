#ifndef WATERTANK_HH_
#define WATERTANK_HH_

#include "systemc.h"
#include "systemc-ams.h"

SC_MODULE(watertank) {
public:
    // L'ingresso e le uscite sono di tipo TDF Timed DataFlow
    // quindi l'interfaccia verso l'esterno è discreta mentre 
    // il funzionamento interno è LSF Linear Signal Flow quindi 
    // continuo
    sca_tdf::sca_in<double>in;
    sca_tdf::sca_out<double> out;
    // Costruttore e distruttore
    watertank(sc_core::sc_module_name);
    ~watertank();
private:
    // Convertitore in input, permette di lavorare in LSF
    sca_lsf::sca_tdf::sca_source tdf_to_lsf_converter;
    // Convertitore in output, ritorno a valori discreti
    sca_lsf::sca_tdf::sca_sink lsf_to_tdf_converter;
    // Guadagno in ingresso sull'apertura
    sca_lsf::sca_gain guadagno_apertura;
    // Sommatore del valore dell'apertura con il feedback
    sca_lsf::sca_add sommatore_apertura_feedback;
    // Integratore come operazione inversa della derivata nella formula \dot{x} = 0.6a - 0.03x
    sca_lsf::sca_integ integratore;
    // Guadagno del feedback
    sca_lsf::sca_gain guadagno_feedback;
    // Collegamento tra i componenti
    sca_lsf::sca_signal sig_in, sig_in_sommatore, sig_feedback_sommatore, sig_sommatore_integratore, sig_out;
};

#endif