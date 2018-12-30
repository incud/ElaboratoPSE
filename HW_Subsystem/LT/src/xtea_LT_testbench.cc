#include "xtea_LT_testbench.hh"

xtea_LT_testbench::xtea_LT_testbench(sc_module_name name) : sc_module(name)
{
    initiator_socket(*this);
    SC_THREAD(run);

    const sc_time INTERVALLO_TEMPO_MASSIMO = sc_time(1000, SC_NS);
    quantumKeeper.set_global_quantum(INTERVALLO_TEMPO_MASSIMO);
    quantumKeeper.reset();
}

struct Packet xtea_LT_testbench::command(sc_uint<32> k0, sc_uint<32> k1, int command, tlm::tlm_generic_payload& payload, sc_time& local_time)
{
    struct Packet packet;

    // Configuro la prima parte della chiave
    packet.data.range(31, 0) = k0;
    packet.data.range(63, 32) = k1;
    packet.command = command;
    payload.set_data_ptr((unsigned char*) &packet);
    payload.set_address(0);
    payload.set_write();
    initiator_socket->b_transport(payload, local_time);

    if(payload.get_response_status() != tlm::TLM_OK_RESPONSE) {
        cout << "Response non OK: " << payload.get_response_status() << endl;
    }

    return packet;
}

void xtea_LT_testbench::run()
{
    // Dati della computazione
    const sc_uint<32> keys[4] = { 0x6a1d78c8, 0x8c86d67f, 0x2a65bfbe, 0xb4bd6e46 };

    // Nella versione "untimed" il tempo non viene mai settato. Comunque è un parametro obbligatorio
    // quindi dobbiamo istanziare comunque un oggetto sc_time anche se non viene usato.
    sc_time local_time;

    // Istanzio un oggetto payload che conterrà il pacchetto
    tlm::tlm_generic_payload payload;	

    // Istanza di un pacchetto
    struct Packet packet;

    // Configuro la prima parte della chiave
    command(keys[0], keys[1], COMMAND_CONFIGURE_KEYS_01, payload, local_time);

    // Configuro la seconda parte della chiave
    command(keys[2], keys[3], COMMAND_CONFIGURE_KEYS_23, payload, local_time);

    // Criptazione e decriptazione
    bool ok = true;
    for(size_t i = 0; i < TESTBENCH_ITERATION; i++) {

        sc_uint<32> values[2], enc[2], dec[2];

        values[0] = static_cast<uint32_t>(std::rand());
        values[1] = static_cast<uint32_t>(std::rand());

        packet = command(values[0], values[1], COMMAND_RUN_ENCRYPT, payload, local_time);
        enc[0] = packet.data.range(31, 0).to_uint();
        enc[1] = packet.data.range(63, 32).to_uint();

        packet = command(enc[0], enc[1], COMMAND_RUN_DECRYPT, payload, local_time);
        dec[0] = packet.data.range(31, 0).to_uint();
        dec[1] = packet.data.range(63, 32).to_uint();

        if(values[0] != dec[0] || values[1] != dec[1]) {
            cout << "Errore su valori " << values[0] << " " << values[1] << endl;
            ok = false;
        }

        quantumKeeper.set(local_time);
        if (quantumKeeper.need_sync()) {
            cout << "SYNCHRONIZING" << endl;
            quantumKeeper.sync();
        }
    }
    
    cout << "Test " << (ok ? "passato" : "fallito") << endl;
    
    sc_stop();
}

void xtea_LT_testbench::invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range)
{
}

tlm::tlm_sync_enum xtea_LT_testbench::nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t)
{
    return tlm::TLM_COMPLETED;
}
