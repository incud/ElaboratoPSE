#ifndef COMMON_HH_
#define COMMON_HH_

#include "systemc.h"
#include "systemc-ams.h"

// Timestep in comune a tutti i moduli
#define COMMON_TIMESTEP sc_core::sc_time(1,sc_core::SC_MS)

// Numero di iterazione alla quale si attiverà il controllore
#define CONTROLLER_ITERATION_ACTIVE 10

// Numero di iterazione che attiverà l'aggiornamento del threshold
#define CONTROLLER_ITERATION_THRESHOLD 5000

// Threshold iniziale
#define CONTROLLER_INITIAL_THRESHOLD 0.7

// Valori del cifrario
#define CIPHER_SECOND_WORD_IF_MISSING 0xDEADBEEF
#define CIPHER_KEY0 0xDEADBEEF
#define CIPHER_KEY1 0xDEADBEEF
#define CIPHER_KEY2 0xDEADBEEF
#define CIPHER_KEY3 0xDEADBEEF

// Comandi che il controllore da alla valvola
enum Commands { OPEN = 1, IDLE = 2, CLOSE = 3};

struct packet_transactor
{
    int comando;
    int padding;
    double threshold;
    double livello_acqua;
};

uint64_t double_to_uint(double d);

double uint_to_double(uint64_t u);

double uints_to_double(uint32_t a, uint32_t b);

double sc_uints_to_double(sc_uint<32> a, sc_uint<32> b);


#endif