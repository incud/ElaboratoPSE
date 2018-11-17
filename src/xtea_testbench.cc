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
    sc_uint<32> values[2] = { 0xc1a0c1a0, 0xdeadbeff }, encryptedValues[2], decryptedValues[2]; 
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

    cout << "Avvio la criptazione" << endl;
    encrypt(values[0], values[1]);
    encryptedValues[0] = result1.read();
    encryptedValues[1] = result2.read();

    cout << "Avvio la decriptazione" << endl;
    decrypt(encryptedValues[0], encryptedValues[1]);
    decryptedValues[0] = result1.read();
    decryptedValues[1] = result2.read();

    cout << std::setw(15) << "Ingresso: " << std::hex << values[0] << " " << values[1] << endl;
    cout << std::setw(15) << "Criptato: " << std::hex << encryptedValues[0] << " " << encryptedValues[1] << endl;
    cout << std::setw(15) << "Decriptato: " << std::hex << decryptedValues[0] << " " << decryptedValues[1] << endl;

    close_trace_files();
    sc_stop();
}