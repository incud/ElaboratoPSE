#include "xtea_UT_testbench.hh"

xtea_UT_testbench::xtea_UT_testbench(sc_module_name name) : sc_module(name)
{
    initiator_socket(*this);
    SC_THREAD(run);
}

void xtea_UT_testbench::run()
{
    // Dati della computazione
    const sc_uint<32> keys[4] = { 0x6a1d78c8, 0x8c86d67f, 0x2a65bfbe, 0xb4bd6e46 };
    sc_uint<32> values[2], encryptedValues[2], decryptedValues[2]; 

    // Nella versione "untimed" il tempo non viene mai settato. Comunque è un parametro obbligatorio
    // quindi dobbiamo istanziare comunque un oggetto sc_time anche se non viene usato.
    sc_time local_time;

    // Istanzio un oggetto payload che conterrà il pacchetto
    tlm::tlm_generic_payload payload;	

    // Istanza di un pacchetto
    struct Packet packet;

    // Configuro la prima parte della chiave
    packet.data.range(31, 0) = keys[0];
    packet.data.range(63, 32) = keys[1];
    packet.command = COMMAND_CONFIGURE_KEYS_01;
    payload.set_data_ptr((unsigned char*) &packet);
    payload.set_address(0);
    payload.set_write();
    initiator_socket->b_transport(payload, local_time);
    if(payload.get_response_status() == tlm::TLM_OK_RESPONSE) {
        // nada
    } else if(payload.get_response_status() == tlm::TLM_COMMAND_ERROR_RESPONSE) {
        cout << "[Prima parte chiave] Status: TLM_COMMAND_ERROR_RESPONSE" << endl;
    } else {
        cout << "[Prima parte chiave] Status: SCONOSCIUTO (" << payload.get_response_status() << ")" << endl;
    }

    // Configuro la seconda parte della chiave
    packet.data.range(31, 0) = keys[2];
    packet.data.range(63, 32) = keys[3];
    packet.command = COMMAND_CONFIGURE_KEYS_23;
    payload.set_data_ptr((unsigned char*) &packet);
    payload.set_address(0);
    payload.set_write();
    initiator_socket->b_transport(payload, local_time);
    if(payload.get_response_status() == tlm::TLM_OK_RESPONSE) {
        // nada
    } else if(payload.get_response_status() == tlm::TLM_COMMAND_ERROR_RESPONSE) {
        cout << "[Seconda parte chiave] Status: TLM_COMMAND_ERROR_RESPONSE" << endl;
    } else {
        cout << "[Seconda parte chiave] Status: SCONOSCIUTO (" << payload.get_response_status() << ")" << endl;
    }

    bool ok = true;
    for(size_t i = 0; i < TESTBENCH_ITERATION; i++) {

        values[0] = static_cast<uint32_t>(std::rand());
        values[1] = static_cast<uint32_t>(std::rand());

        // Criptazione
        packet.data.range(31, 0) = values[0];
        packet.data.range(63, 32) = values[1];
        packet.command = COMMAND_RUN_ENCRYPT;
        payload.set_data_ptr((unsigned char*) &packet);
        payload.set_address(0);
        payload.set_write();
        initiator_socket->b_transport(payload, local_time);
        if(payload.get_response_status() == tlm::TLM_OK_RESPONSE) {
            // nada
        } else if(payload.get_response_status() == tlm::TLM_COMMAND_ERROR_RESPONSE) {
            cout << "[Criptazione] Status: TLM_COMMAND_ERROR_RESPONSE" << endl;
        } else {
            cout << "[Criptazione] Status: SCONOSCIUTO (" << payload.get_response_status() << ")" << endl;
        }
        encryptedValues[0] = packet.data.range(31, 0).to_uint();
        encryptedValues[1] = packet.data.range(63, 32).to_uint();

        // Decriptazione
        packet.data.range(31, 0) = encryptedValues[0];
        packet.data.range(63, 32) = encryptedValues[1];
        packet.command = COMMAND_RUN_DECRYPT;
        payload.set_data_ptr((unsigned char*) &packet);
        payload.set_address(0);
        payload.set_write();
        initiator_socket->b_transport(payload, local_time);
        if(payload.get_response_status() == tlm::TLM_OK_RESPONSE) {
            // nada
        } else if(payload.get_response_status() == tlm::TLM_COMMAND_ERROR_RESPONSE) {
            cout << "[Decriptazione] Status: TLM_COMMAND_ERROR_RESPONSE" << endl;
        } else {
            cout << "[Decriptazione] Status: SCONOSCIUTO (" << payload.get_response_status() << ")" << endl;
        }
        decryptedValues[0] = packet.data.range(31, 0).to_uint();
        decryptedValues[1] = packet.data.range(63, 32).to_uint();

        if(values[0] != decryptedValues[0] || values[1] != decryptedValues[1]) {
            cout << "Errore su valori " << values[0] << " " << values[1] << endl;
            ok = false;
        }
    }
    
    // Stampa finale
    cout << "Test " << (ok ? "passato" : "fallito") << endl;

    // Fermo la simulazione
    sc_stop();
}

void xtea_UT_testbench::invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range)
{
}

tlm::tlm_sync_enum xtea_UT_testbench::nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t)
{
    return tlm::TLM_COMPLETED;
}
