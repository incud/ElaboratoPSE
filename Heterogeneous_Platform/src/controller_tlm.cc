#include "controller_tlm.hh"
#include "common.hh"

controller_tlm::controller_tlm(sc_module_name name) : sc_module(name)
{
    initiator_socket_transactor_cipher(*this);
    SC_THREAD(run);

    m_qk.set_global_quantum(sc_time(500, SC_NS));
    m_qk.reset();
}

void controller_tlm::run()
{
    // Inizializzazione tempo locale
    sc_time local_time = m_qk.get_local_time();

    // Dati per scambio transazioni
    struct packet_transactor packet_data;
    tlm::tlm_generic_payload packet_payload;

    // Inizializzazione threshold
    thresh = CONTROLLER_INITIAL_THRESHOLD;

    while(true) {

        // Prima leggo livello acqua
        packet_payload.set_read();
        packet_payload.set_data_ptr((unsigned char*) &packet_data);
        initiator_socket_transactor_cipher->b_transport(packet_payload, local_time);
        double acqua = packet_data.livello_acqua;

        // Aspetto
        wait(120, sc_core::SC_MS);

        // Applico il calcolo al pacchetto
        if(acqua < 5.0) {
            thresh *= 1.1;
            packet_data.threshold = thresh;
            packet_data.comando = OPEN;

        } else if(acqua > 8.8) {
            thresh *= 0.7;
            packet_data.threshold = thresh;
            packet_data.comando = CLOSE;

        } else {
            packet_data.threshold = thresh;
            packet_data.comando = IDLE;
        }        

        // Poi applico il controllo alla valvola
        packet_payload.set_write();
        struct packet_transactor packet_data_enc = encrypt(packet_data);
        packet_payload.set_data_ptr((unsigned char*) &packet_data_enc);
        initiator_socket_transactor_cipher->b_transport(packet_payload, local_time);

        // Infine aggiorno QK
        m_qk.set(local_time);
        if (m_qk.need_sync()) {
            m_qk.sync();
        }
    }
}

struct packet_transactor controller_tlm::encrypt(struct packet_transactor p)
{
    uint32_t msg[2];
    uint32_t keys[4] = { CIPHER_KEY0, CIPHER_KEY1, CIPHER_KEY2, CIPHER_KEY3 };
    uint32_t result[2];

    // Cripto il comando
    msg[0] = p.comando;
    msg[1] = CIPHER_SECOND_WORD_IF_MISSING;
    elaborate(msg, keys, 0, result);
    p.comando = result[0];
    p.padding = result[1];

    // Cripto il threshold
    uint64_t temp = double_to_uint(p.threshold);
    msg[0] = static_cast<uint32_t>(temp);
    msg[1] = static_cast<uint32_t>(temp >> 32);
    elaborate(msg, keys, 0, result);
    p.threshold = uints_to_double(result[0], result[1]);

    return p;
}

void controller_tlm::elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2])
{
    // Sbobino i parametri in input
    uint32_t word0 = msg[0];
    uint32_t word1 = msg[1];
    uint32_t key0 = keys[0];
    uint32_t key1 = keys[1];
    uint32_t key2 = keys[2];
    uint32_t key3 = keys[3];

    // Elaborazione
    uint64_t sum; 
    uint32_t i, delta, v0, v1, temp; 
    v0 = word0; 
    v1 = word1;
    result[0] = 0; 
    result[1] = 0;

    cout << std::hex;

    if(mode == 0) { // encipher

        delta=0x9e3779b9; 
        sum = 0; 
            
        // cout << v0 << " " << v1 << endl;
        
        for (i=0; i < 32; i++) {

            temp = keys[sum & 3];
            v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + temp);
            sum += delta;
            temp = keys[(sum >> 11) & 3];
            v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + temp);

            // cout << v0 << " " << v1 << endl;
        } 
    } 
    else if (mode == 1) { // decipher

        delta = 0x9e3779b9; 
        sum = delta*32;     

        // cout << v0 << " " << v1 << endl;

        for (i=0; i<32; i++) {

            temp = keys[(sum >> 11) & 3];
            v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + temp);
            sum -= delta;                         
            temp = keys[sum & 3];
            v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + temp);
            
            // cout << v0 << " " << v1 << endl;
        }                                           
    }

    result[0] = v0; 
    result[1] = v1;
}



