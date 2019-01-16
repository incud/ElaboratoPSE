#include "watertank.hh"

// Costruttore
watertank::watertank(sc_core::sc_module_name n) :
    sc_core::sc_module(n), // La classe istanziata è sempre di SystemC
    in("watertank_in"), // Porta in input di tipo TDF
    out("watertank_out"), // Porta in output di tipo TDF
    tdf_to_lsf_converter("convertitore_input_TDF_to_LSF"),
    lsf_to_tdf_converter("convertitore_output_LSF_to_TDF"),
    guadagno_apertura("guadagno_apertura", 0.6),
    sommatore_apertura_feedback("sommatore_apertura_feedback"),
    integratore("integratore"),
    guadagno_feedback("guadagno_feedback", -0.03),
    sig_in("sig_in"), 
    sig_in_sommatore("sig_in_sommatore"), 
    sig_feedback_sommatore("sig_feedback_sommatore"), 
    sig_sommatore_integratore("sig_sommatore_integratore"), 
    sig_out("sig_out")
{
    tdf_to_lsf_converter.inp(in);
    tdf_to_lsf_converter.y(sig_in);

    guadagno_apertura.x(sig_in);
    guadagno_apertura.y(sig_in_sommatore);

    sommatore_apertura_feedback.x1(sig_in_sommatore);
    sommatore_apertura_feedback.x2(sig_feedback_sommatore);
    sommatore_apertura_feedback.y(sig_sommatore_integratore);

    integratore.x(sig_sommatore_integratore);
    integratore.y(sig_out);

    guadagno_feedback.x(sig_out);
    guadagno_feedback.y(sig_feedback_sommatore);

    lsf_to_tdf_converter.x(sig_out);
    lsf_to_tdf_converter.outp(out);
}

watertank::~watertank(){ }