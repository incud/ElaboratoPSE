#ifndef WATERTANK_IF_HH
#define WATERTANK_IF_HH

// Poichè non è possibile interfacciare direttamente TLM con 
// la parte AMS neanche tramite transattori, ci inventiamo un
// modulo RTL da porre in mezzo tra il transattore e il serbatoio

#include <systemc-ams.h>

SCA_TDF_MODULE(watertank_if)
{
public:
    // Parte che si interfaccia col transattore
    sca_tdf::sca_in<double> livello_acqua_ams;
    sca_tdf::sca_de::sca_out<double> livello_acqua_rtl;

    // Costruttore e metodi del modulo
    SCA_CTOR(watertank_if) : livello_acqua_ams("comando_rtl"), livello_acqua_rtl("threshold_rtl") { }
    void set_attribute();
    void processing();
};

#endif