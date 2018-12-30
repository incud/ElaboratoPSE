#include "xtea.hh"

void xtea::datapath() 
{
    switch(fsmState.read()) {
        case ROUTER: {
            dpValues[0].write(values[0].read());
            dpValues[1].write(values[1].read());

            int comando = command.read().to_int();
            if(comando == Commands::RUN_ENCRYPT) {
                counter.write(0);
                sum.write(INIT_SUM_ENCRYPT);

            } else if (comando == Commands::RUN_DECRYPT) {
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

void xtea::fsm()
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

                if(comando == Commands::CONFIGURE_KEYS_0_1) {
                    keys[0].write(values[0].read());
                    keys[1].write(values[1].read());
                    outputReady.write(1);
                    fsmState.write(WAIT_FOR_INPUT);

                } else if(comando == Commands::CONFIGURE_KEYS_2_3) {
                    keys[2].write(values[0].read());
                    keys[3].write(values[1].read());
                    outputReady.write(1);
                    fsmState.write(WAIT_FOR_INPUT);

                } else if(comando == Commands::RUN_ENCRYPT) {
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
