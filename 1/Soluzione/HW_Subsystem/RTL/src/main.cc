#include "xtea.hh"
#include "xtea_testbench.hh"

#include <cstdlib>
#include <iostream>
#include <ctime>

static sc_trace_file *trace;

void close_trace_files()
{
    sc_close_vcd_trace_file(trace);
}

int main()
{
    std::srand(12345678);
    
    xtea module_xtea("xtea");
    xtea_testbench module_xtea_testbench("xtea_tb");

    sc_clock clock("clock", 2, SC_PS);
    sc_signal<bool> reset;
    sc_signal<sc_uint<32>> op1, op2;
    sc_signal<sc_uint<2>> command;
    sc_signal<bool> inputReady;
    sc_signal<sc_uint<32>> result1, result2;
    sc_signal<bool> outputReady;
    
    module_xtea.clock(clock);
    module_xtea.reset(reset);
    module_xtea.command(command);
    module_xtea.op1(op1);
    module_xtea.op2(op2);
    module_xtea.inputReady(inputReady);
    module_xtea.result1(result1);
    module_xtea.result2(result2);
    module_xtea.outputReady(outputReady);

    module_xtea_testbench.clock(clock);
    module_xtea_testbench.reset(reset);
    module_xtea_testbench.command(command);
    module_xtea_testbench.op1(op1);
    module_xtea_testbench.op2(op2);
    module_xtea_testbench.inputReady(inputReady);
    module_xtea_testbench.result1(result1);
    module_xtea_testbench.result2(result2);
    module_xtea_testbench.outputReady(outputReady);

    /*
    trace = sc_create_vcd_trace_file("xtea_trace");
    sc_trace(trace, clock, "clock");
    sc_trace(trace, reset, "reset");
    sc_trace(trace, command, "command");
    sc_trace(trace, op1, "op1");
    sc_trace(trace, op2, "op2");
    sc_trace(trace, inputReady, "inputReady");
    sc_trace(trace, result1, "result1");
    sc_trace(trace, result2, "result2");
    sc_trace(trace, outputReady, "outputReady"); */

    sc_start();
    return 0;
}
