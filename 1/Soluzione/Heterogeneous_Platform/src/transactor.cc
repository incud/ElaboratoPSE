#include "transactor.hh"

void transactor::b_transport( tlm::tlm_generic_payload& trans, sc_time& t )
{
    struct packet_transactor packet = *((struct packet_transactor*) trans.get_data_ptr());

    if(trans.is_write()) {
        // Se la richiesta è di scrittura, mando i dati alla valvola
        comando.write(packet.comando);
        threshold.write(packet.threshold);
        trans.set_response_status(tlm::TLM_OK_RESPONSE);  

    } else {
        // Se la richiesta è di lettura, leggo il livello di acqua dal serbatoio
        packet.livello_acqua = livello_acqua.read();
        *((struct packet_transactor*) trans.get_data_ptr()) = packet;
        trans.set_response_status(tlm::TLM_OK_RESPONSE); 
    }
}

transactor::transactor(sc_module_name name) : 
    sc_module(name), target_socket("target_socket"),
    comando("comando"), threshold("threshold"), livello_acqua("livello_acqua")
{
    target_socket(*this);
}

transactor::~transactor()
{
}
