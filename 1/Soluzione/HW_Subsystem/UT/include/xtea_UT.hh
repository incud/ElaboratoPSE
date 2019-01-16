#ifndef XTEA_HH_
#define XTEA_HH_

#include "systemc.h"
#include "tlm.h"
#include "define_UT.hh"

class xtea_UT : 
    public sc_module, 
    public virtual tlm::tlm_fw_transport_if<> 
{
public:

    // Porta attraverso la quale il nostro modulo comunica con l'esterno. Poichè
    // questa classe funziona come 'slave', che risponde alle richieste invece che 
    // farne, il tipo di socket è detto TARGET (si contrappone alla socket del testbench
    // che viene detta INITIATOR SOCKET poichè la tb inizia le connessioni)
    tlm::tlm_target_socket<> target_socket;

    // Costruttore
    xtea_UT(sc_module_name name_);

private:

    // Dichiaro che il processo SystemC del modulo è il suo costruttore. A fare i calcoli ci penserà
    // l'interfaccia bloccante B_TRANSPORT. 
    SC_HAS_PROCESS(xtea_UT);

    // Callback standard di SystemC, occorre definire i metodi vuoti. 
    void end_of_elaboration();
    void reset();

    // Il metodo B_TRANSPORT riceve in input il payload dall'initiator (nel nostro caso 
    // contiene un'istanza di struct Packet) e l'istante corrente dell'esecuzione. Il suo scopo
    // è salvare i dati che arrivano dal payload all'interno della classe, e fa partire l'
    // esecuzione. La B_TRANSPORT fa parte dell'interfaccia "bloccante". L'annotazione del tempo
    // viene utilizzata sia all'inizio della transazione per sapere a che tempo sono, sia alla fine il 
    // suo valore viene sovrascritto. Poichè la B_TRANSPORT potrebbe chiamare wait, non va usata con SC_METHOD
    virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& t);

    // La DMI (Direct Memory Interface) serve all'initiator per poter leggere i dati dall'area di
    // memoria del target, senza passare quindi dalle transazioni. Poichè non forniamo questa
    // funzionalità nel nostro progetto, il metodo ignora i parametri e ritorna false. Se utilizzato
    // occorre anche definire invalidate_direct_mem_ptr.
    virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data);

    // Usata solamente nelle chiamate non bloccanti (quindi non qui). Occorre ritornare sempre
    // il valore TLM_COMPLETED che segna la fine della transazione. Comunque questa funzione non 
    // è chiamata. 
    virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t);

    // Interfaccia di debug. Stessa cosa della chiamata bloccante ma senza delay. Per questo
    // non viene passato il tempo. Occorre che la funzione ritorni 0. 
    virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans);

    // Dato passato all'inizio della transazione
    struct Packet packet;

    // Funzione di criptazione / decriptazione
    void elaborate (const uint32_t msg[2], const uint32_t keys[4], bool mode, uint32_t result[2]);

    // Dati da memorizzare all'interno del modulo. Il primo è la chiave, il secondo è il messaggio. 
    sc_uint<32> keys[4];
    sc_uint<32> msg[2];
};

#endif