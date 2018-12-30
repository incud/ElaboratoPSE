#include "watertank_if.hh"

void watertank_if::set_attribute() { }

void watertank_if::processing()
{
    livello_acqua_rtl.write(livello_acqua_ams.read());
}