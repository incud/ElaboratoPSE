#ifndef XTEA_AT4_HH_
#define XTEA_AT4_HH_

#include <systemc.h>
#include <tlm.h>
#include "define_AT4.hh"

class xtea_AT4 : 
    public sc_module, 
    public virtual tlm::tlm_fw_transport_if<> 
{
public:
    tlm::tlm_target_socket<> target_socket;

    SC_HAS_PROCESS(xtea_AT4);
    xtea_AT4(sc_module_name name_);

private:
    // Nella modalità AT4 implemento solo la funzione che segue. Devo però utilizzare
    // la pending transaction perchè se sto già facendo una transazione non posso farne 
    // un'altra. Inoltre un evento sblocca il lavoro fatto dal cifratore, racchiuso in IOPROCESS
    virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t);

    tlm::tlm_generic_payload* pending_transaction;

    sc_core::sc_event io_event;

    void IOPROCESS();

    void IOPROCESS_INTERNAL();

    // I dati vengono passati dalla nb_transport_fw all'IOPROCESS attraverso 'packet'
    struct Packet packet;

    sc_uint<32> keys[4];

    sc_uint<32> msg[2];

    // Metodi con implementazione di default
    virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& t);
    virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data);
    virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans);

    // Segue il metodo che compie la cifratura e la decifratura
    void elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2]);
};

#endif