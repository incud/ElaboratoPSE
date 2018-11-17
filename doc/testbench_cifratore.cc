#include "testbench_cifratore.hh"

void testbench_cifratore::print(std::string msg)
{
    cout << std::setw(33) << msg << 
        " R " << std::hex << result.read() <<
        " I " << std::hex << iterations.read() << 
        " IDX " << idx0.read() << " " << idx1.read() << endl;
}

void testbench_cifratore::run() 
{
    trace = sc_create_vcd_trace_file("testbench_cifratore_trace");
	sc_trace(trace, clock,   "clock");
    sc_trace(trace, op1,     "op1");
	sc_trace(trace, op2,     "op2");
	sc_trace(trace, command, "command");
	sc_trace(trace, mode,    "mode");
	sc_trace(trace, result,  "result");
	sc_trace(trace, iterations, "iterations");
	sc_trace(trace, idx0,    "idx0");
	sc_trace(trace, idx1,    "idx1");

    cout << "\n\nEncrypt" << endl;
    run_encrypt();
    cout << "\n\nDecrypt" << endl;
    run_decrypt();

    sc_close_vcd_trace_file(trace);
    sc_stop();
}

void testbench_cifratore::run_decrypt() 
{
    sc_uint<32> v0 = 0x12345678, v1 = 0x9abcdeff;
    sc_uint<32> acc;

    command.write(cifratore::RESET);
    mode.write(CIFRATORE_MODE_DECRYPT);
    print("Comandato RESET (DEC): ");
    wait();

    op1.write(v0);
    op2.write(0xb4bd6e46);
    command.write(cifratore::CYPHER);
    print("Comandato CYPHER (DEC): ");
    wait();
    
    acc = result.read();
    op1.write(v1);
    op2.write(acc);
    command.write(cifratore::OPERATE_ON_V1);
    print("Comandato OPERATE_ON_V1 (DEC): ");
    wait();

    command.write(cifratore::NONE);
    print("Comandato NONE: ");
    wait();

    v1 = result.read();
    op1.write(v1);
    op2.write(0x12345);
    command.write(cifratore::CYPHER);
    print("Comandato CYPHER (DEC): ");
    wait();

    acc = result.read();
    op1.write(v1);
    op2.write(acc);
    command.write(cifratore::OPERATE_ON_V1);
    print("Comandato OPERATE_ON_V1 (ENC): ");
    wait();

    command.write(cifratore::NONE);
    print("Comandato NONE: ");
    wait();

    command.write(cifratore::NONE);
    print("Comandato NONE: ");
    wait();
}

void testbench_cifratore::run_encrypt() 
{
    sc_uint<32> v0 = 0x12345678, v1 = 0x9abcdeff;

    command.write(cifratore::RESET);
    mode.write(CIFRATORE_MODE_ENCRYPT);
    print("Comandato RESET (ENC): ");
    wait();

    op1.write(v1);
    op2.write(0xb4bd6e46);
    command.write(cifratore::CYPHER);
    print("Comandato CYPHER (ENC): ");
    wait();

    sc_uint<32> acc = result.read();
    op1.write(v0);
    op2.write(acc);
    command.write(cifratore::OPERATE_ON_V0);
    print("Comandato OPERATE_ON_V0 (ENC): ");
    wait();

    command.write(cifratore::NONE);
    print("Comandato NONE: ");
    wait();

    v0 = result.read();
    op1.write(v0);
    op2.write(0x12345);
    command.write(cifratore::CYPHER);
    print("Comandato CYPHER (ENC): ");
    wait();

    acc = result.read();
    op1.write(v1);
    op2.write(acc);
    command.write(cifratore::OPERATE_ON_V1);
    print("Comandato OPERATE_ON_V1 (ENC): ");
    wait();

    command.write(cifratore::NONE);
    print("Comandato NONE: ");
    wait();

    command.write(cifratore::NONE);
    print("Comandato NONE: ");
    wait();
}

void testbench_cifratore_main()
{
    sc_clock clock("clock", 2, SC_PS);

    sc_signal<sc_uint<32>> op1, op2, result;
    sc_signal<sc_uint<6>> iterations;
    sc_signal<sc_uint<2>> command, idx0, idx1;
    sc_signal<bool> mode;
    
    cifratore modulo_cifratore("cifratore");
    testbench_cifratore tb_cifratore("tb_cifratore");

    modulo_cifratore.clock(clock);
    modulo_cifratore.op1(op1);
    modulo_cifratore.op2(op2);
    modulo_cifratore.command(command);
    modulo_cifratore.idx0(idx0);
    modulo_cifratore.idx1(idx1);
    modulo_cifratore.result(result);
    modulo_cifratore.mode(mode);
    modulo_cifratore.iterations(iterations);

    tb_cifratore.clock(clock);
    tb_cifratore.op1(op1);
    tb_cifratore.op2(op2);
    tb_cifratore.command(command);
    tb_cifratore.idx0(idx0);
    tb_cifratore.idx1(idx1);
    tb_cifratore.result(result);
    tb_cifratore.mode(mode);
    tb_cifratore.iterations(iterations);

    sc_start();
}