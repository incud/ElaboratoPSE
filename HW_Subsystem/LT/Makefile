DESIGN_NAME=xtea
ABSTRACTION_LEVEL=LT

EXECLTABLE=bin/$(DESIGN_NAME)_$(ABSTRACTION_LEVEL).x

SYSTEMC=$$SYSTEMC_HOME

INCDIR = -I./include/ -I. -I$(SYSTEMC)/include/
LIBDIR = $(SYSTEMC)/lib-linux64

CXX=g++
CFLAGS= -c
LD=g++

all: $(EXECLTABLE)

$(EXECLTABLE): obj/main.o obj/xtea_LT.o obj/xtea_LT_testbench.o
	@echo Building $@
	@$(CXX) -g $(INCDIR) -o $@ $^ $(LIBDIR)/libsystemc.a -lpthread

obj/main.o: src/main.cc
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_LT.o: src/xtea_LT.cc include/xtea_LT.hh
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_LT_testbench.o: src/xtea_LT_testbench.cc include/xtea_LT_testbench.hh
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

clean:
	@echo Cleaning
	@rm -f obj/*.o *~
	@rm -f bin/*.x

.PHONY: all clean
