echo "Apertura file stimuli.do"

# fai ripartire la simulazione (se non lo fai, 
# continua dal punto nel quale si era fermato)
restart -f 

# tolgo e ri-aggiungo i segnali del modulo alla schermata
delete wave *
add wave *

# RESET DEL MODULO
# il clock parte con 0, resta basso 1ns, viene alzato, 
# resta alto 1ns, e ripeto il processo ogni 2ns
force clock 0 0 ns, 1 1 ns -repeat 2
force reset 1 0 ns, 0 2 ns
force input_ready 0 0 ns
run 6ns

# CONFIGURAZIONE PRIMA PARTE DELLE CHIAVI
# i segnali che dico partire da 0ns non ripartono davvero
# dell'inizio ma dal punto in cui si era fermata la sim.
force op1 16#AAAABBBB 0 ns
force op2 16#CCCCDDDD 0 ns
force command 2#00    0 ns
force input_ready 1   0 ns
run 4 ns
force input_ready 0   
run 6 ns

# CONFIGURAZIONE SECONDA PARTE DELLE CHIAVI
# i segnali che dico partire da 0ns non ripartono davvero
# dell'inizio ma dal punto in cui si era fermata la sim.
force op1 16#EEEEFFFF 0 ns
force op2 16#A000111B 0 ns
force command 2#01    0 ns
force input_ready 1   0 ns
run 4 ns
force input_ready 0   
run 6 ns

# CRIPTAZIONE DEL MESSAGGIO
# i segnali che dico partire da 0ns non ripartono davvero
# dell'inizio ma dal punto in cui si era fermata la sim.
force op1 16#DEADBEEF 0 ns
force op2 16#DEFEC8ED 0 ns
force command 2#10    0 ns
force input_ready 1   0 ns
run 4 ns
force input_ready 0   
run 500 ns

# DECRIPTAZIONE DEL MESSAGGIO
# i segnali che dico partire da 0ns non ripartono davvero
# dell'inizio ma dal punto in cui si era fermata la sim.
force op1 16#D44F3DE7 0 ns
force op2 16#17041ADC 0 ns
force command 2#11    0 ns
force input_ready 1   0 ns
run 4 ns
force input_ready 0   
run 500 ns
