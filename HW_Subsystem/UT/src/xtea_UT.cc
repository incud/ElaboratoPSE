#include "xtea_UT.hh"

xtea_UT::xtea_UT(sc_module_name name_) : sc_module(name_), target_socket("target_socket")
{
    target_socket(*this);
}

void xtea_UT::b_transport(tlm::tlm_generic_payload& trans, sc_time& t)
{
    // Ottengo i dati dal pacchetto
    packet = *((struct Packet*) trans.get_data_ptr());

    switch(packet.command) {
        case COMMAND_CONFIGURE_KEYS_01: {

            keys[0] = packet.data.range(31, 0).to_uint();
            keys[1] = packet.data.range(63, 32).to_uint();

            trans.set_response_status(tlm::TLM_OK_RESPONSE);
            break;
        }
        case COMMAND_CONFIGURE_KEYS_23: {

            keys[2] = packet.data.range(31, 0).to_uint();
            keys[3] = packet.data.range(63, 32).to_uint();

            trans.set_response_status(tlm::TLM_OK_RESPONSE);
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

            *((struct Packet*) trans.get_data_ptr()) = packet;
            trans.set_response_status(tlm::TLM_OK_RESPONSE);
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

            *((struct Packet*) trans.get_data_ptr()) = packet;
            trans.set_response_status(tlm::TLM_OK_RESPONSE);
            break;
        }
        default: {
            // Non è stato possibile interpretare il comando dato 
            trans.set_response_status(tlm::TLM_COMMAND_ERROR_RESPONSE);
            break;
        }
    }
}

bool xtea_UT::get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data) 
{
    return false;
}

tlm::tlm_sync_enum xtea_UT::nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t)
{
    return tlm::TLM_COMPLETED;
}

unsigned int xtea_UT::transport_dbg(tlm::tlm_generic_payload& trans)
{
    return 0;
}

void xtea_UT::end_of_elaboration() { }

void xtea_UT::reset() { }

void xtea_UT::elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2]) {

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