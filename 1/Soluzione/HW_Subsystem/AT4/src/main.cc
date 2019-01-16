#include "xtea_AT4.hh"
#include "xtea_AT4_testbench.hh"

int main(int argc, char* argv[])
{
    xtea_AT4 x("xtea_AT4");
    xtea_AT4_testbench xtb("xtea_AT4_testbench");
    xtb.initiator_socket(x.target_socket);

    sc_start();
    return 0;
}
