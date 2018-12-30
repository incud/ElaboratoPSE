#ifndef XTEA_LT_HH_
#define XTEA_LT_HH_

#include "systemc.h"
#include "tlm.h"
#include "define_LT.hh"

#define TESTBENCH_ITERATION 1000

class xtea_LT : 
    public sc_module, 
    public virtual tlm::tlm_fw_transport_if<> 
{
public:

    tlm::tlm_target_socket<> target_socket;

    xtea_LT(sc_module_name name_, sc_time clockPeriod);

private:

    struct Packet packet;

    sc_uint<32> keys[4];

    sc_uint<32> msg[2];

    // Gestione delle annotazioni temporali.

    const sc_time CLOCK_PERIOD;

    const sc_time TIME_FOR_ENCRYPTION = 80 * CLOCK_PERIOD;

    const sc_time TIME_FOR_DECRYPTION = 80 * CLOCK_PERIOD;

    const sc_time TIME_FOR_CONFIGURATION = 80 * CLOCK_PERIOD;

    // Metodi necessari per implementare l'interfaccia TLM. La modalità loosely timed utilizza
    // ancora B_TRANSPORT, si arricchisce però della notazione del tempo, che per farla breve consiste
    // del sommare al parametro sc_time di B_TRANSPORT un valore pari al tempo passato per completare
    // la computazione.

    SC_HAS_PROCESS(xtea_LT);

    void end_of_elaboration();

    void reset();

    virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& t);

    virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data);

    virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t);

    virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans);

    // Segue il metodo che compie la cifratura e la decifratura

    void elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2]);
};

#endif