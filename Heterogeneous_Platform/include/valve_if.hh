#ifndef VALVE_IF_HH
#define VALVE_IF_HH

// Poichè non è possibile interfacciare direttamente TLM con 
// la parte AMS neanche tramite transattori, ci inventiamo un
// modulo RTL da porre in mezzo tra il transattore e la valvola

#include <systemc-ams.h>

SCA_TDF_MODULE(valve_if)
{
public:
    // Parte che si interfaccia col transattore
    sca_tdf::sca_de::sca_in<int> comando_rtl;
    sca_tdf::sca_de::sca_in<double> threshold_rtl;

    // Parte che si interfaccia con AMS
    sca_tdf::sca_out<int> comando_ams;
    sca_tdf::sca_out<double> threshold_ams;

    // Costruttore e metodi del modulo
    SCA_CTOR(valve_if) : comando_rtl("comando_rtl"), threshold_rtl("threshold_rtl"), comando_ams("comando_ams"), threshold_ams("threshold_ams") { }
    void set_attribute();
    void processing();
};

#endif