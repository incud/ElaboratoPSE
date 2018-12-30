#ifndef CONTROLLER_INITIATOR_HH_
#define CONTROLLER_INITIATOR_HH_

#include <tlm.h>
#include <tlm_utils/tlm_quantumkeeper.h>
#include "common.hh"

class controller_tlm : public sc_module, public virtual tlm::tlm_bw_transport_if<>
{
private:
    // Parte TLM con implementazione default
    virtual void invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range) { }
    virtual tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t) { return tlm::TLM_COMPLETED; }
    
    // Parte TLM realmente usata
    void elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2]);
    struct packet_transactor encrypt(struct packet_transactor p);
    tlm_utils::tlm_quantumkeeper m_qk;

    // Metodi di supporto alla simulazione
    void run();

    // Variabile di appoggio per il calcolo del threshold
    double thresh;
    
public:
    // Comunicazione con il transattore
    tlm::tlm_initiator_socket<> initiator_socket_transactor_cipher;
    // Costruttore
    SC_HAS_PROCESS(controller_tlm);
    controller_tlm(sc_module_name name);
};

#endif