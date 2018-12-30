#include "xtea_AT4.hh"

xtea_AT4::xtea_AT4(sc_module_name name_) :
    sc_module(name_), 
    target_socket("target_socket"), 
    pending_transaction(NULL)
{
    target_socket(*this);
    SC_THREAD(IOPROCESS);
}

// Unico metodo TLM che serve per AT4

tlm::tlm_sync_enum xtea_AT4::nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t)
{
    // Gestione errori
    if (pending_transaction != NULL) {
        // Se c'è una transazione in corso non posso completare la seguente
        cout << "[XE] Transazione in corso..." << endl;
        trans.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
        return tlm::TLM_COMPLETED;
    } else if (phase != tlm::BEGIN_REQ) {
        // Se pending transaction è null allora la prima fase deve essere
        // BEGIN_REQ altrimenti genero errore
        cout << "[XE] Fase != BEGIN_REQ ..." << endl;
        trans.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
        return tlm::TLM_COMPLETED;
    }

    // Salvo i dati ed aggiorno la fase
    pending_transaction = &trans;
    packet = *((struct Packet*) trans.get_data_ptr());
    phase = tlm::END_REQ;

    // Avvio la fase di codifica/decodifica e chiudo la transazione
    io_event.notify();
    return tlm::TLM_UPDATED;
}

// Implementazione del loop delle risposte

void xtea_AT4::IOPROCESS()
{
    while(true) {

        // Aspetto il verificarsi di una richiesta
        wait(io_event);

        // Aspetto un tempo canonico per processare la richiesta,
        // metto 100NS come nell'esempio 'root'
        wait(100, SC_NS);

        // Processo la richesta che mi è stata fatta - calcoli veri e propri
        IOPROCESS_INTERNAL();

        // Aggiorno i campi della transazione corrente
        pending_transaction->set_response_status(tlm::TLM_OK_RESPONSE);
        *((struct Packet*) pending_transaction->get_data_ptr()) = packet;

        // Mando la risposta (inizializzo variabili che servono per la backward)
        tlm::tlm_phase phase = tlm::BEGIN_RESP;
        sc_time timing_annotation;
        target_socket->nb_transport_bw(*pending_transaction, phase, timing_annotation);

        // Pulisco la pending transaction per poter accettare una nuova transazione
        pending_transaction = NULL;
    }
}

void xtea_AT4::IOPROCESS_INTERNAL() 
{
    switch(packet.command) {
        case COMMAND_CONFIGURE_KEYS_01: {

            keys[0] = packet.data.range(31, 0).to_uint();
            keys[1] = packet.data.range(63, 32).to_uint();
            break;
        }
        case COMMAND_CONFIGURE_KEYS_23: {
            
            keys[2] = packet.data.range(31, 0).to_uint();
            keys[3] = packet.data.range(63, 32).to_uint();
            break;
        }
        case COMMAND_RUN_ENCRYPT: {
            
            msg[0] = packet.data.range(31, 0).to_uint();
            msg[1] = packet.data.range(63, 32).to_uint();

            const bool MODE_ENCRYPT = false;
            uint32_t kk[4] = { keys[0].to_uint(), keys[1].to_uint(), keys[2].to_uint(), keys[3].to_uint() };
            uint32_t mm[2] = { msg[0].to_uint(), msg[1].to_uint() };
            uint32_t result[2];
            elaborate(mm, kk, MODE_ENCRYPT, result);
            packet.data.range(31, 0) = result[0];
            packet.data.range(63, 32) = result[1];
            break;
        }
        case COMMAND_RUN_DECRYPT: {

            msg[0] = packet.data.range(31, 0).to_uint();
            msg[1] = packet.data.range(63, 32).to_uint();

            const bool MODE_DECRYPT = true;
            uint32_t kk[4] = { keys[0].to_uint(), keys[1].to_uint(), keys[2].to_uint(), keys[3].to_uint() };
            uint32_t mm[2] = { msg[0].to_uint(), msg[1].to_uint() };
            uint32_t result[2];
            elaborate(mm, kk, MODE_DECRYPT, result);
            packet.data.range(31, 0) = result[0];
            packet.data.range(63, 32) = result[1];
            break;
        }
        default: {
            break;
        }
    }
}

// Metodi TLM con implementazione di default 

void xtea_AT4::b_transport(tlm::tlm_generic_payload& trans, sc_time& t) { }

bool xtea_AT4::get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data) { return false; }

unsigned int xtea_AT4::transport_dbg(tlm::tlm_generic_payload& trans) { return 0; }

// Elaborazione xtea

void xtea_AT4::elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2])
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