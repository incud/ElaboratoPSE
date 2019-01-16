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

// Comandi che il controllore da alla valvola
enum Commands { OPEN = 1, IDLE = 2, CLOSE = 3};

#endif