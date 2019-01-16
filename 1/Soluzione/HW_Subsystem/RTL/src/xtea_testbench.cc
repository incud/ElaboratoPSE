#include "xtea_testbench.hh"

void xtea_testbench::configureKeysFirstHalf(sc_uint<32> a, sc_uint<32> b)
{
    op1.write(a);
    op2.write(b);
    command.write(xtea::CONFIGURE_KEYS_0_1);
    inputReady.write(1);
    wait();
    inputReady.write(0);

    while(!outputReady.read()) {
        wait();
    }
}

void xtea_testbench::configureKeysSecondHalf(sc_uint<32> a, sc_uint<32> b)
{
    op1.write(a);
    op2.write(b);
    command.write(xtea::CONFIGURE_KEYS_2_3);
    inputReady.write(1);
    wait();

    inputReady.write(0);
    while(!outputReady.read()) {
        wait();
    }
}

void xtea_testbench::encrypt(sc_uint<32> a, sc_uint<32> b)
{
    op1.write(a);
    op2.write(b);
    command.write(xtea::RUN_ENCRYPT);
    inputReady.write(1);
    wait();

    inputReady.write(0);
    while(!outputReady.read()) {
        wait();
    }
}

void xtea_testbench::decrypt(sc_uint<32> a, sc_uint<32> b)
{
    op1.write(a);
    op2.write(b);
    command.write(xtea::RUN_DECRYPT);
    inputReady.write(1);
    wait();

    inputReady.write(0);
    while(!outputReady.read()) {
        wait();
    }
}

void xtea_testbench::run()
{
    sc_uint<32> values[2], encryptedValues[2], decryptedValues[2]; 
    sc_uint<32> keys[4] = { 0x6a1d78c8, 0x8c86d67f, 0x2a65bfbe, 0xb4bd6e46 };

    // Comando il reset del modulo
    reset.write(1);
    wait();
    reset.write(0);

    // Avvio l'esecuzione
    cout << "Configuro la prima parte delle chiavi" << endl;
    configureKeysFirstHalf(keys[0], keys[1]);
    cout << "Configuro la seconda parte delle chiavi" << endl;
    configureKeysSecondHalf(keys[2], keys[3]);

    bool ok = true;
    for(size_t i = 0; i < TESTBENCH_ITERATION; i++) {

        values[0] = static_cast<uint32_t>(std::rand());
        values[1] = static_cast<uint32_t>(std::rand());

        encrypt(values[0], values[1]);
        encryptedValues[0] = result1.read();
        encryptedValues[1] = result2.read();

        decrypt(encryptedValues[0], encryptedValues[1]);
        decryptedValues[0] = result1.read();
        decryptedValues[1] = result2.read();

        if(values[0] != decryptedValues[0] || values[1] != decryptedValues[1]) {
            cout << "Errore su valori " << values[0] << " " << values[1] << endl;
            ok = false;
        }
    }

    cout << "Test " << (ok ? "passato" : "fallito") << endl;

    close_trace_files();
    sc_stop();
}