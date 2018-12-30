#include "valve_if.hh"

void valve_if::set_attribute() { }

void valve_if::processing() 
{
    comando_ams.write(comando_rtl.read());
    threshold_ams.write(threshold_rtl.read());
}