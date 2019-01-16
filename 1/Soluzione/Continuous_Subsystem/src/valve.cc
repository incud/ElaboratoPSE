#include "valve.hh"

void valve::set_attributes(){
    set_timestep(COMMON_TIMESTEP);
    a = 0;
}

void valve::processing()
{
    if(comando.read() == OPEN) {
        a = (a + 0.25 <= threshold.read()) ? a + 0.25 : threshold.read();
    } else if(comando.read() == CLOSE) {
        a = (a - 0.25 >= 0) ? a - 0.25 : 0;
    }
    apertura.write(a);
}