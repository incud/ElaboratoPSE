#include "systemc.h"
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

    void fsm()
    {
        if(reset.read()) {
            fsmState.write(WAIT_FOR_INPUT);

        } else {

            switch(fsmState.read()) {

                case WAIT_FOR_INPUT: {
                    // Eventualmente segno che l'output precedente non è più valido: è iniziata una nuova computazione
                    outputReady.write(0);
                    // Se è pronto l'input
                    if(inputReady.read()) {
                        // Salvo tutti i valori
                        values[0].write(op1.read());
                        values[1].write(op2.read());
                        memCommand.write(command.read());
                        // Vado alla sezione di router
                        fsmState.write(ROUTER);
                    }
                    break;
                }
                case ROUTER: {

                    int comando = command.read().to_int();

                    if(comando == CONFIGURE_KEYS_0_1) {
                        keys[0].write(values[0].read());
                        keys[1].write(values[1].read());
                        outputReady.write(1);
                        fsmState.write(WAIT_FOR_INPUT);

                    } else if(comando == CONFIGURE_KEYS_2_3) {
                        keys[2].write(values[0].read());
                        keys[3].write(values[1].read());
                        outputReady.write(1);
                        fsmState.write(WAIT_FOR_INPUT);

                    } else if(comando == RUN_ENCRYPT) {
                        fsmState.write(CALCULATE_ENCRYPT);

                    } else {
                        fsmState.write(CALCULATE_DECRYPT);
                    }
                    break;
                }
                case CALCULATE_ENCRYPT: {

                    if(counter.read() >= N_ITERATIONS) {
                        result1.write(dpValues[0].read());
                        result2.write(dpValues[1].read());
                        outputReady.write(1);
                        fsmState.write(WAIT_FOR_INPUT);

                    } else {
                        fsmState.write(ENCRYPT_1);
                    }
                    break;
                }
                case CALCULATE_DECRYPT: {

                    if(counter.read() >= N_ITERATIONS) {
                        result1.write(dpValues[0].read());
                        result2.write(dpValues[1].read());
                        outputReady.write(1);
                        fsmState.write(WAIT_FOR_INPUT);

                    } else {
                        fsmState.write(DECRYPT_1);
                    }
                    break;
                }
                case ENCRYPT_1: { fsmState.write(ENCRYPT_2);         break; }
                case ENCRYPT_2: { fsmState.write(ENCRYPT_3);         break; }
                case ENCRYPT_3: { fsmState.write(ENCRYPT_4);         break; }
                case ENCRYPT_4: { fsmState.write(ENCRYPT_5);         break; }
                case ENCRYPT_5: { fsmState.write(CALCULATE_ENCRYPT); break; }
                case DECRYPT_1: { fsmState.write(DECRYPT_2);         break; }
                case DECRYPT_2: { fsmState.write(DECRYPT_3);         break; }
                case DECRYPT_3: { fsmState.write(DECRYPT_4);         break; }
                case DECRYPT_4: { fsmState.write(DECRYPT_5);         break; }
                case DECRYPT_5: { fsmState.write(CALCULATE_DECRYPT); break; }
            }
        }
    }


    void datapath()
    {
        switch(fsmState.read()) {
            case ROUTER: {
                dpValues[0].write(values[0].read());
                dpValues[1].write(values[1].read());

                int comando = command.read().to_int();
                if(comando == RUN_ENCRYPT) {
                    counter.write(0);
                    sum.write(INIT_SUM_ENCRYPT);

                } else if (comando == RUN_DECRYPT) {
                    counter.write(0);
                    sum.write(INIT_SUM_DECRYPT);
                }
                break;
            }
            case DECRYPT_3:
            case CALCULATE_ENCRYPT: {
                int index = sum.read().range(1,0);
                temp.write(keys[index].read());
                break;
            }
            case DECRYPT_4:
            case ENCRYPT_1: {
                sc_uint<32> v1 = dpValues[1].read();
                acc.write((((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum.read() + temp.read()));
                break;
            }
            case ENCRYPT_2: {
                dpValues[0].write(dpValues[0].read() + acc.read());
                sum.write(sum.read() + DELTA);
                break;
            }
            case CALCULATE_DECRYPT:
            case ENCRYPT_3: {
                int index = sum.read().range(12,11);
                temp.write(keys[index].read());
                break;
            }
            case DECRYPT_1:
            case ENCRYPT_4: {
                sc_uint<32> v0 = dpValues[0].read();
                acc.write((((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum.read() + temp.read()));
                break;
            }
            case ENCRYPT_5: {
                dpValues[1].write(dpValues[1].read() + acc.read());
                counter.write(counter.read() + 1);
                break;
            }
            case DECRYPT_2: {
                dpValues[1].write(dpValues[1].read() - acc.read());
                sum.write(sum.read() - DELTA);
                break;
            }
            case DECRYPT_5: {
                dpValues[0].write(dpValues[0].read() - acc.read());
                counter.write(counter.read() + 1);
                break;
            }
        }
    }

    // =========================================================
    // Questi segnali sono comandati esclusivamente dal datapath
    sc_signal<sc_uint<6> > counter;

    sc_signal<sc_uint<64> > sum;

    sc_signal<sc_uint<32> > temp, acc, dpValues[2];

    // =========================================================
    // Questi segnali sono comandati esclusivamente dalla fsm

    sc_signal<sc_uint<32> > keys[4];

    sc_signal<sc_uint<32> > values[2];

    sc_signal<sc_uint<2> > memCommand;

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
    sc_in<sc_uint<32> > op1, op2;

    // Comando in input
    sc_in<sc_uint<2> > command;

    // Flags di input ready
    sc_in<bool> inputReady;

    // Risultato in output
    sc_out<sc_uint<32> > result1, result2;

    // Valore di output ready
    sc_out<bool> outputReady;

    // Costruttore
    SC_CTOR(xtea) {
    	SC_METHOD(fsm);
		sensitive << clock.pos();
		SC_METHOD(datapath);
		sensitive << clock.pos();
    }

};

int main()
{
	xtea module("xtea");
	return 0;
}
