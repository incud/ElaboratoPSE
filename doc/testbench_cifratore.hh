#ifndef TESTBENCH_CIFRATORE_HH_
#define TESTBENCH_CIFRATORE_HH_

#include "systemc.h"
#include "cifratore.hh"

void testbench_cifratore_main();

SC_MODULE(testbench_cifratore) 
{
    sc_trace_file *trace;

    void run();

    void run_encrypt();

    void run_decrypt();

    void print(std::string msg);

    void printExpected(int result, int counter);

public:

    // Clock
    sc_in<bool> clock;

    // Operatori in input
    sc_out<sc_uint<32>> op1, op2;

    // Comando in ingresso, uno di quelli nella struttura Commands
    sc_out<sc_uint<2>> command;

    // Comando di mode, prende i valori CIFRATORE_MODE_ENCRYPT e CIFRATORE_MODE_DECRYPT
    sc_out<bool> mode;

    // Risultato del cifratore in output
    sc_in<sc_uint<32>> result;

    // Contatore in output
    sc_in<sc_uint<6>> iterations;

    // Indici generati dalla variabile 'sum'
    sc_in<sc_uint<2>> idx0, idx1;

    // Costruttore del metodo. Utilizzo un method per semplicità. Non ho un segnale di reset
    // dedicato ma uso uno dei comandi passati in 'commands' per lo scopo
    SC_CTOR(testbench_cifratore) {
        SC_THREAD(run);
        sensitive << clock.pos();
    }

};

#endif