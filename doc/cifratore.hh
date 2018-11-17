#ifndef CIFRATORE_HH_
#define CIFRATORE_HH_

#include <iostream>
#include <iomanip>
#include "systemc.h"

#define CIFRATORE_MODE_ENCRYPT false
#define CIFRATORE_MODE_DECRYPT true
#define DELTA 0x9e3779b9
#define N_ITERATIONS 32

SC_MODULE(cifratore) 
{
private:

    // Variabile interna che mantiene il multiplo di un certo numero DELTA usato
    // per generare i valori idx0, idx1
    sc_signal<sc_uint<64>> sum;

    // Contatore delle iterazioni da 0 a 31
    sc_signal<sc_uint<5>> counter;

    void run();

public:

    enum Commands {
        RESET = 0,
        CYPHER = 1,
        OPERATE_ON_V0 = 2,
        OPERATE_ON_V1 = 3,
        NONE = 1 // Pongo il comando NONE = COMMAND poichè è l'unico che non cambia lo stato
    };

    // Clock
    sc_in<bool> clock;

    // Operatori in input
    sc_in<sc_uint<32>> op1, op2;

    // Comando in ingresso, uno di quelli nella struttura Commands
    sc_in<sc_uint<2>> command;

    // Comando di mode, prende i valori CIFRATORE_MODE_ENCRYPT e CIFRATORE_MODE_DECRYPT
    sc_in<bool> mode;

    // Risultato del cifratore in output
    sc_out<sc_uint<32>> result;

    // Contatore in output
    sc_out<sc_uint<6>> iterations;

    // Indici generati dalla variabile 'sum'
    sc_out<sc_uint<2>> idx0, idx1;

    // Costruttore del metodo. Utilizzo un method per semplicità. Non ho un segnale di reset
    // dedicato ma uso uno dei comandi passati in 'commands' per lo scopo
    SC_CTOR(cifratore) {
        SC_METHOD(run);
        sensitive << clock.pos();
    }

};

#endif