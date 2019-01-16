#ifndef XTEA_UT_TESTBENCH_HH_
#define XTEA_UT_TESTBENCH_HH_

#include "systemc.h"
#include "tlm.h"
#include "define_UT.hh"

#define TESTBENCH_ITERATION 1000000

class xtea_UT_testbench : 
    public sc_module,
    public virtual tlm::tlm_bw_transport_if<>
{
public:

    // Socket che si interfaccia con il target, cioè con il modulo xtea_UT
    tlm::tlm_initiator_socket<> initiator_socket;

    // Costruttore
    xtea_UT_testbench(sc_module_name name);

private:

    // Il processo da avviare è il costruttore. Ha tutto al suo interno
    SC_HAS_PROCESS(xtea_UT_testbench);

    // Funzione che esegue tutto il lavoro. Viene usata nel costruttore. 
    void run();

    // Serve per togliere la zona di memoria condivisa col socket, se esiste. Implementa vuota.
    virtual void invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range);

    // Stessa cosa di xtea_UT: ritorna tlm::TLM_COMPLETED
    virtual tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t);
};

#endif