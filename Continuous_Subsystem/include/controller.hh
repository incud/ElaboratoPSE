#ifndef CONTROLLER_HH_
#define CONTROLLER_HH_

#include "systemc.h"
#include "systemc-ams.h"
#include "common.hh"

SCA_TDF_MODULE(controller) {
public:
    // Il modulo ha un input: il livello dell'acqua. Tale porta 
    // di input ha un ritardo per permettere lo scheduling. Il
    // modulo ha come output il comando da dare alla valvola e il
    // threshold. 
    sca_tdf::sca_in<double>  livello_acqua;
    sca_tdf::sca_out<int>    comando;
    sca_tdf::sca_out<double> threshold;
    // Costruttore
    SCA_CTOR(controller) : livello_acqua("livello_acqua"), comando("comando"), threshold("threshold") { }
private:
    // Variabile di appoggio per il calcolo del threshold
    double thresh;
    // Contatore delle iterazioni
    int counter;
    // Funzione TDF per la quale occorre fare l'override e che conterrà il codice dell'esecuzione del modulo
    void processing();   
    // Funzione TDF per settare il timestep, delay ecc.
    void set_attributes();
};

#endif