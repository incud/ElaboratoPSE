#include "controller_cipher_transactor.hh"

controller_cipher_transactor::controller_cipher_transactor(sc_module_name name) : 
    sc_module(name),
    target_socket_controller("target_socket_controller"),
    initiator_socket_transactor("initiator_socket_transactor"),
    op1("op1"),
    op2("op2"),
    command("command"),
    inputReady("inputReady"),
    result1("result1"), 
    result2("result2"),
    outputReady("outputReady")
{
    target_socket_controller(*this);
    initiator_socket_transactor(*this);

    SC_THREAD(WRITEPROCESS);
    sensitive << clock.pos();
}

controller_cipher_transactor::~controller_cipher_transactor()
{
}

void controller_cipher_transactor::b_transport( tlm::tlm_generic_payload& trans, sc_time& t )
{
    if(trans.is_read()) {

        // passo avanti il pacchetto al transattore che legge i valori del serbatoio
        tlm::tlm_generic_payload packet_payload;
        packet_payload.set_read();
        packet_payload.set_data_ptr((unsigned char*) &packet);
        initiator_socket_transactor->b_transport(packet_payload, t);

        // transazione finita, ritorno esito OK 
        *((struct packet_transactor*) trans.get_data_ptr()) = packet;
        trans.set_response_status(tlm::TLM_OK_RESPONSE);

    } else {
        packet = *((struct packet_transactor*) trans.get_data_ptr());

        // notifico l'avvio della scrittura ed aspetto che finisca (metodo WRITEPROCESS)
        begin_write.notify();
        wait(end_write);

        // passo avanti il pacchetto al transattore che porta i valori alla valvola
        tlm::tlm_generic_payload packet_payload;
        packet_payload.set_write();
        packet_payload.set_data_ptr((unsigned char*) &packet);
        initiator_socket_transactor->b_transport(packet_payload, t);

        // transazione finita, ritorno esito OK 
        trans.set_response_status(tlm::TLM_OK_RESPONSE);
    }
}

void controller_cipher_transactor::WRITEPROCESS() 
{
    while(true) {

        // aspetto una nuova richiesta
        wait(begin_write);

        // decripto
        packet.comando = decriptaComando();
        packet.threshold = decriptaThreshold();

        // fine della richiesta
        end_write.notify();
    }

}

int controller_cipher_transactor::decriptaComando()
{
    // spacchetto i valori
    sc_uint<32> a = static_cast<uint32_t>(packet.comando);
    sc_uint<32> b = static_cast<uint32_t>(packet.padding);

    // avvio decriptazione
    op1.write(a);
    op2.write(b);
    command.write(xtea::RUN_DECRYPT);
    inputReady.write(1);
    wait();

    // aspetto che finisca
    inputReady.write(0);
    while(!outputReady.read()) {
        wait();
    }

    // leggo i risultati e li metto nel packet
    return result1.read();
}

double controller_cipher_transactor::decriptaThreshold()
{
    uint64_t thresh = double_to_uint(packet.threshold);
    
    // spacchetto i valori
    sc_uint<32> a = static_cast<uint32_t>(thresh);
    sc_uint<32> b = static_cast<uint32_t>(thresh >> 32);

    // avvio decriptazione
    op1.write(a);
    op2.write(b);
    command.write(xtea::RUN_DECRYPT);
    inputReady.write(1);
    wait();

    // aspetto che finisca
    inputReady.write(0);
    while(!outputReady.read()) {
        wait();
    }

    // impacchetto e ritorno il valore
    return sc_uints_to_double(result1.read(), result2.read());
}