#ifndef XTEA_HH_
#define XTEA_HH_

#include "systemc.h"
#include "common.hh"
#include <iomanip>

#define DELTA 0x9e3779b9
#define N_ITERATIONS 32
#define INIT_SUM_ENCRYPT 0
#define INIT_SUM_DECRYPT (DELTA*N_ITERATIONS)

SC_MODULE(xtea) {
private:

    enum State {
        WAIT_FOR_INPUT,
        ROUTER,
        CONFIGURE,
        CALCULATE_ENCRYPT, 
        CALCULATE_DECRYPT,
        ENCRYPT_1, 
        ENCRYPT_2, 
        ENCRYPT_3,
        ENCRYPT_4, 
        ENCRYPT_5,
        DECRYPT_1, 
        DECRYPT_2, 
        DECRYPT_3,
        DECRYPT_4, 
        DECRYPT_5
    };

    void fsm();

    void datapath();

    // =========================================================
    // Questi segnali sono comandati esclusivamente dal datapath
    sc_signal<sc_uint<6>> counter;

    sc_signal<sc_uint<64>> sum;

    sc_signal<sc_uint<32>> temp, acc, dpValues[2];

    // =========================================================
    // Questi segnali sono comandati esclusivamente dalla fsm

    sc_signal<sc_uint<32>> keys[4];

    sc_signal<sc_uint<32>> values[2];

    sc_signal<sc_uint<2>> memCommand;

    sc_signal<int> fsmState;

public:

    enum Commands {
        CONFIGURE_KEYS_0_1,
        CONFIGURE_KEYS_2_3,
        RUN_ENCRYPT,
        RUN_DECRYPT
    };

    // Segnali di clock e di reset
    sc_in<bool> clock, reset;

    // Due operatori a 32bit in ingresso
    sc_in<sc_uint<32>> op1, op2;

    // Comando in input
    sc_in<sc_uint<2>> command;

    // Flags di input ready
    sc_in<bool> inputReady;

    // Risultato in output
    sc_out<sc_uint<32>> result1, result2;

    // Valore di output ready
    sc_out<bool> outputReady;

    // Costruttore
    SC_CTOR(xtea) {
        SC_METHOD(fsm);
        sensitive << clock.pos();
        SC_METHOD(datapath);
        sensitive << clock.pos();
        keys[0] = CIPHER_KEY0;
        keys[1] = CIPHER_KEY1;
        keys[2] = CIPHER_KEY2;
        keys[3] = CIPHER_KEY3;
    }

};

#endif