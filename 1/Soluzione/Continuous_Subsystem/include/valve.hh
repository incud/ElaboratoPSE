#ifndef VALVE_HH_
#define VALVE_HH_

#include "systemc.h"
#include "systemc-ams.h"
#include "common.hh"

SCA_TDF_MODULE(valve) {
public:
    // Il modulo ha due input: il comando OPEN, CLOSE, IDLE ed
    // il valore di threshold. L'output è dato dal valore dell'
    // apertura. Tutti i segnali sono TDF quindi discreti.
    sca_tdf::sca_in<int>     comando;
    sca_tdf::sca_in<double>  threshold;
    sca_tdf::sca_out<double> apertura;
    // Costruttore
    SCA_CTOR(valve) : comando("comando"), threshold("threshold"), apertura("apertura") { }
private:
    // Variabile di appoggio per il calcolo dell'apertura
    double a;
    // Funzione TDF per la quale occorre fare l'override e che conterrà il codice dell'esecuzione del modulo
    void processing();   
    // Funzione TDF per settare il timestep, delay ecc.
    void set_attributes();
};

#endif