#ifndef XTEA_TESTBENCH_HH_
#define XTEA_TESTBENCH_HH_

#include <iomanip>
#include "systemc.h"
#include "xtea.hh"

extern void close_trace_files();

#define TESTBENCH_ITERATION 1000000

SC_MODULE(xtea_testbench) {

private:

    void configureKeysFirstHalf(sc_uint<32> a, sc_uint<32> b);

    void configureKeysSecondHalf(sc_uint<32> a, sc_uint<32> b);

    void encrypt(sc_uint<32> a, sc_uint<32> b);

    void decrypt(sc_uint<32> a, sc_uint<32> b);

    void run();

public:

    sc_in<bool> clock;
    
    sc_out<bool> reset;

    sc_out<sc_uint<32>> op1, op2;

    sc_out<sc_uint<2>> command;

    sc_out<bool> inputReady;

    sc_in<sc_uint<32>> result1, result2;

    sc_in<bool> outputReady;

    // Costruttore
    SC_CTOR(xtea_testbench) {
        SC_THREAD(run);
        sensitive << clock.pos();
    }
};

#endif