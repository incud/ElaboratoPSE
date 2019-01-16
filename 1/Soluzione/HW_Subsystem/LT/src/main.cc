#include "xtea_LT.hh"
#include "xtea_LT_testbench.hh"

class xtea_top : public sc_module {
private:
    xtea_LT target;
    xtea_LT_testbench initiator;
public:
    xtea_top(sc_module_name name) : 
        sc_module(name), 
        target("target", sc_time(10, SC_PS)), 
        initiator("initiator") 
    {
        initiator.initiator_socket(target.target_socket);
    }
};

int main()
{
    xtea_top top("top");
    sc_start();
    return 0;
}
