#ifndef DEFINE_LT_HH_
#define DEFINE_LT_HH_

#include "systemc.h"

#define COMMAND_CONFIGURE_KEYS_01 0
#define COMMAND_CONFIGURE_KEYS_23 1
#define COMMAND_RUN_ENCRYPT 2
#define COMMAND_RUN_DECRYPT 3

struct Packet {
    // Dato, che può essere la chiave oppure il messaggio a seconda del comando dato
    sc_uint<64> data;
    // Uno dei quattro comandi CONFIGURE_KEYS_01, CONFIGURE_KEYS_23, RUN_ENCRYPT, RUN_DECRYPT
    int command;
};

#endif