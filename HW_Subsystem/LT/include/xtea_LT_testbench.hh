#ifndef XTEA_LT_TESTBENCH_HH_
#define XTEA_LT_TESTBENCH_HH_

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/tlm_quantumkeeper.h"
#include "define_LT.hh"

#define TESTBENCH_ITERATION 1000

class xtea_LT_testbench : 
    public sc_module,
    public virtual tlm::tlm_bw_transport_if<>
{
public:

    tlm::tlm_initiator_socket<> initiator_socket;

    xtea_LT_testbench(sc_module_name name);

private:

    struct Packet command(sc_uint<32> k0, sc_uint<32> k1, int command, tlm::tlm_generic_payload& payload, sc_time& local_time);

    // Quando il offset temporale locale è maggiore del quanto di tempo prefissato allora
    // il processo dovrebbe cedere il controllo al kernel chiamando il metodo 'sync'. Questo
    // non è obbligatorio o automatico, è il programmatore a doversene occupare. Se però faccio
    // troppe chiamate a sync perdo il vantaggio dato dal temporal decoupling. Si usa allora
    // il metodo need_sync. 
    tlm_utils::tlm_quantumkeeper quantumKeeper;

    SC_HAS_PROCESS(xtea_LT_testbench);

    void run();

    virtual void invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range);

    virtual tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t);
};

#endif