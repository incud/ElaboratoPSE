#include "controller.hh"

void controller::set_attributes()
{
    // Per prima cosa setto il timestep comune
    set_timestep(COMMON_TIMESTEP);

    // Il segnale 'livello_acqua' avrà delay = 1 per permettere
    // uno scheduling (loop non ammessi altrimenti)
    livello_acqua.set_delay(1);

    // Inizializzazione threshold
    thresh = CONTROLLER_INITIAL_THRESHOLD;
}

void controller::processing()
{
    double acqua = livello_acqua.read();

    if(counter % CONTROLLER_ITERATION_THRESHOLD == 0) {
        // Il controller è attivo e svolge le proprie funzioni di monitoraggio 
        // del livello dell'acqua e di cambio threshold
        if(acqua < 5.0) {
            thresh *= 1.1;
            threshold.write(thresh);
            comando.write(OPEN);

        } else if(acqua > 8.8) {
            thresh *= 0.7;
            threshold.write(thresh);
            comando.write(CLOSE);

        } else {
            comando.write(IDLE);
        }        
    } 

    counter++;
}