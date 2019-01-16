#include "xtea_AT4_testbench.hh"

void xtea_AT4_testbench::invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range)
{
}

tlm::tlm_sync_enum xtea_AT4_testbench::nb_transport_bw(tlm::tlm_generic_payload &  trans, tlm::tlm_phase &  phase, sc_time &  t)
{
	// There must be a pending response.
	if (!response_pending) {
		cout << "Unexpected state" << endl;
		trans.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
		return tlm::TLM_COMPLETED;
	}

	// The phase should be BEGIN_RESP.
	if (phase != tlm::BEGIN_RESP) {
		cout << "Unexpected phase" << endl;
		trans.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
		return tlm::TLM_COMPLETED;
	}

	available_response.notify();
	phase = tlm::END_RESP;

	return tlm::TLM_COMPLETED;
}

void xtea_AT4_testbench::run()
{
	struct Packet packet;
	sc_time local_time = SC_ZERO_TIME;
	tlm::tlm_generic_payload payload;
	tlm::tlm_sync_enum result;	
	tlm::tlm_phase phase;
	bool ok = true;

	// Configurazione prima chiave
	phase = tlm::BEGIN_REQ;
	packet.data.range(31, 0) = static_cast<uint32_t>(std::rand());
	packet.data.range(63, 32) = static_cast<uint32_t>(std::rand());
	packet.command = COMMAND_CONFIGURE_KEYS_01;
	payload.set_address(0);
	payload.set_data_ptr((unsigned char*) &packet);
	payload.set_write();
	result = initiator_socket->nb_transport_fw(payload, phase, local_time);

	if (result == tlm::TLM_COMPLETED) {
		cout << "Transaction error. Forcing simulation stop." << endl;
		sc_stop();
	} else if (phase != tlm::END_REQ) {
		cout << "Unexpected protocol phase. Forcing simulation stop." << endl;
		sc_stop();
	}

	response_pending = true;
	wait(available_response);
	response_pending = false;

	// Configurazione seconda chiave
	phase = tlm::BEGIN_REQ;
	packet.data.range(31, 0) = static_cast<uint32_t>(std::rand());
	packet.data.range(63, 32) = static_cast<uint32_t>(std::rand());
	packet.command = COMMAND_CONFIGURE_KEYS_23;
	payload.set_address(0);
	payload.set_data_ptr((unsigned char*) &packet);
	payload.set_write();
	result = initiator_socket->nb_transport_fw(payload, phase, local_time);

	if (result == tlm::TLM_COMPLETED) {
		cout << "Transaction error. Forcing simulation stop." << endl;
		sc_stop();
	} else if (phase != tlm::END_REQ) {
		cout << "Unexpected protocol phase. Forcing simulation stop." << endl;
		sc_stop();
	}

	response_pending = true;
	wait(available_response);
	response_pending = false;

	for (size_t i = 0; i < TESTBENCH_ITERATION; i++){

        // Valori in input ed output dalle transazioni
        uint32_t values[2], enc[2], dec[2];
        values[0] = static_cast<uint32_t>(std::rand());
        values[1] = static_cast<uint32_t>(std::rand());

        // ================= CODIFICA =================
		phase = tlm::BEGIN_REQ;
		packet.data.range(31, 0) = values[0];
		packet.data.range(63, 32) = values[1];
		packet.command = COMMAND_RUN_ENCRYPT;
		payload.set_address(0);
		payload.set_data_ptr((unsigned char*) &packet);
		payload.set_write();
		result = initiator_socket->nb_transport_fw(payload, phase, local_time);

		if (result == tlm::TLM_COMPLETED) {
			cout << "Transaction error. Forcing simulation stop." << endl;
			sc_stop();
		} else if (phase != tlm::END_REQ) {
			cout << "Unexpected protocol phase. Forcing simulation stop." << endl;
			sc_stop();
		}

		response_pending = true;
		wait(available_response);

		enc[0] = packet.data.range(31, 0).to_uint();
        enc[1] = packet.data.range(63, 32).to_uint();
		response_pending = false;

		// ================= DECODIFICA =================
		phase = tlm::BEGIN_REQ;
		packet.data.range(31, 0) = enc[0];
		packet.data.range(63, 32) = enc[1];
		packet.command = COMMAND_RUN_DECRYPT;
		payload.set_address(0);
		payload.set_data_ptr((unsigned char*) &packet);
		payload.set_write();
		result = initiator_socket->nb_transport_fw(payload, phase, local_time);

		if (result == tlm::TLM_COMPLETED) {
			cout << "Transaction error. Forcing simulation stop." << endl;
			sc_stop();
		} else if (phase != tlm::END_REQ) {
			cout << "Unexpected protocol phase. Forcing simulation stop." << endl;
			sc_stop();
		}

		response_pending = true;
		wait(available_response);

		dec[0] = packet.data.range(31, 0).to_uint();
        dec[1] = packet.data.range(63, 32).to_uint();
		response_pending = false;

        // ================= ESITO =================
        if(values[0] != dec[0] || values[1] != dec[1]) {
            cout << "Errore su valori " << values[0] << " " << values[1] << endl;
            ok = false;
        }
    }

	// Stampa finale
    cout << "Test " << (ok ? "passato" : "fallito") << endl;
	sc_stop();
}


xtea_AT4_testbench::xtea_AT4_testbench(sc_module_name name) : sc_module(name) , response_pending(false)
{
	initiator_socket(*this);
	SC_THREAD(run);
}
