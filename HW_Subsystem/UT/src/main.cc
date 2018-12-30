#include <cstdlib>
#include <iostream>
#include <ctime>

#include "xtea_UT.hh"
#include "xtea_UT_testbench.hh"

class xtea_top : public sc_module {
private:
    xtea_UT target;
    xtea_UT_testbench initiator;
public:
    xtea_top(sc_module_name name): sc_module(name), target("target"), initiator("initiator") {
        initiator.initiator_socket(target.target_socket);
    }
};

int main()
{
    std::srand(12345678);

    xtea_top top("top");
    sc_start();
    return 0;
}
