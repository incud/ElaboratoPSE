DESIGN_NAME=xtea
ABSTRACTION_LEVEL=RTL

EXECUTABLE=bin/$(DESIGN_NAME)_$(ABSTRACTION_LEVEL).x

SYSTEMC=$$SYSTEMC_HOME

INCDIR = -I./include/ -I. -I$(SYSTEMC)/include/
LIBDIR = $(SYSTEMC)/lib-linux64

CXX=g++
CFLAGS= -c
LD=g++

all: $(EXECUTABLE)

$(EXECUTABLE): obj/main.o obj/xtea.o obj/xtea_testbench.o
	@echo Building $@
	@$(CXX) -g $(INCDIR) -o $@ $^ $(LIBDIR)/libsystemc.a -lpthread

obj/main.o: src/main.cc
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea.o: src/xtea.cc include/xtea.hh
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_testbench.o: src/xtea_testbench.cc include/xtea_testbench.hh
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

clean:
	@echo Cleaning
	@rm -f obj/*.o *~
	@rm -f $(EXECUTABLE)

.PHONY: all clean

# Comandi per la compilazione con GCC
# -g produce informazioni di debug generiche. Se sai già che userai gdb allora metti -ggdb
# -c è il comando di compile

# Comandi del makefile
# Presa come esempio la riga "nomeoutput: input1 input2"
# $@ corrisponde a 'nomeoutput'
# $< corrisponde a 'input1'
# @<comando> previene che il comando venga stampato