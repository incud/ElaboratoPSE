#ifndef TRANSACTOR_HH_
#define TRANSACTOR_HH_

#include <tlm.h>
#include "common.hh"

class transactor : public sc_module, public virtual tlm::tlm_fw_transport_if<>
{
public:
    // Parte TLM
    tlm::tlm_target_socket<> target_socket;
    virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& t );
    // Parte TLM - implementazione di default
    virtual bool get_direct_mem_ptr( tlm::tlm_generic_payload& trans, tlm::tlm_dmi & dmi_data ) { return false; }
    virtual tlm::tlm_sync_enum nb_transport_fw( tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t) { return tlm::TLM_COMPLETED; }
    virtual unsigned int transport_dbg( tlm::tlm_generic_payload& trans ) { return 0; }

    // Parte AMS
    sc_out<int> comando;
    sc_out<double> threshold; 
    sc_in<double> livello_acqua;

    // Implementazione del transattore
    SC_HAS_PROCESS(transactor);
    transactor(sc_module_name name);
    ~transactor();
};

#endif