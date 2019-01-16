#ifndef CONTROLLER_CIPHER_TRANSACTOR_HH__
#define CONTROLLER_CIPHER_TRANSACTOR_HH__

#include <tlm.h>
#include "common.hh"
#include "xtea.hh"

class controller_cipher_transactor : 
    public sc_module, 
    public virtual tlm::tlm_bw_transport_if<>, 
    public virtual tlm::tlm_fw_transport_if<>
{
public:
    // Metodi di supporto alla simulazione
    void run();

    // Variabile di appoggio per il calcolo del threshold
    double thresh;
    
public:
    // Parte TLM
    tlm::tlm_target_socket<> target_socket_controller;
    tlm::tlm_initiator_socket<> initiator_socket_transactor;
    virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& t );

    // Parte TLM - implementazione di default
    virtual bool get_direct_mem_ptr( tlm::tlm_generic_payload& trans, tlm::tlm_dmi & dmi_data ) { return false; }
    virtual tlm::tlm_sync_enum nb_transport_fw( tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t) { return tlm::TLM_COMPLETED; }
    virtual unsigned int transport_dbg( tlm::tlm_generic_payload& trans ) { return 0; }
    virtual void invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range) { }
    virtual tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t) { return tlm::TLM_COMPLETED; }
    
    // Parte RTL
    sc_core::sc_in<bool>         clock;
    sc_core::sc_out<sc_uint<32>> op1, op2;
    sc_core::sc_out<sc_uint<2>>  command;
    sc_core::sc_out<bool>        inputReady;
    sc_core::sc_in<sc_uint<32>>  result1, result2;
    sc_core::sc_in<bool>         outputReady;

    // Eventi che servono per la scrittura
    int                      decriptaComando();
    double                   decriptaThreshold();
    void                     WRITEPROCESS();
    sc_core::sc_event        begin_write, end_write;
    struct packet_transactor packet;

    // Implementazione del transattore
    SC_HAS_PROCESS(controller_cipher_transactor);
    controller_cipher_transactor(sc_module_name name);
    ~controller_cipher_transactor();
};


#endif