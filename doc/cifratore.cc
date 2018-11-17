#include "cifratore.hh"

void cifratore::run() 
{
    sc_uint<32> value1 = op1.read(), value2 = op2.read();
    sc_uint<2> cmd = command.read();
    sc_uint<64> tempSum;
    sc_uint<32> tempCounter;
    bool _mode = mode.read();

    switch(cmd) {
        case Commands::RESET: {
            // Resetta counter
            counter.write(0);
            iterations.write(0);

            // Resetta sum
            if(_mode == CIFRATORE_MODE_ENCRYPT) {
                tempSum = 0;
                sum.write(tempSum);
                idx0.write(tempSum.range(1,0));
                idx1.write(tempSum.range(12,11));
            }
            else {
                tempSum = DELTA * N_ITERATIONS;
                sum.write(tempSum);
                idx0.write(tempSum.range(1,0));
                idx1.write(tempSum.range(12,11));
            }
            break;
        }
        case Commands::CYPHER: {
            result.write((((value1 << 4) ^ (value1 >> 5)) + value1) ^ (sum.read() + value2));
            break;
        }
        case Commands::OPERATE_ON_V0: {
            if(_mode == CIFRATORE_MODE_ENCRYPT) {
                result.write(value1 + value2);
                tempSum = sum.read() + DELTA;
                sum.write(tempSum);
                idx0.write(tempSum.range(1,0));
                idx1.write(tempSum.range(12,11));
            }
            else {
                result.write(value1 - value2);
                tempCounter = counter.read() + 1;
                counter.write(tempCounter);
                iterations.write(tempCounter);
            }
            break;
        }
        case Commands::OPERATE_ON_V1: {
            if(_mode == CIFRATORE_MODE_ENCRYPT) {
                result.write(value1 + value2);
                tempCounter = counter.read() + 1;
                counter.write(tempCounter);
                iterations.write(tempCounter);
            }
            else {
                result.write(value1 - value2);
                tempSum = sum.read() - DELTA;
                sum.write(tempSum);
                idx0.write(tempSum.range(1,0));
                idx1.write(tempSum.range(12,11));
            }
            break;
        }
    }
}
