DESIGN_NAME=xtea
ABSTRACTION_LEVEL=AT4

EXECUTABLE=bin/$(DESIGN_NAME)_$(ABSTRACTION_LEVEL).x

SYSTEMC=$$SYSTEMC_HOME

INCDIR = -I./include/ -I. -I$(SYSTEMC)/include/
LIBDIR = $(SYSTEMC)/lib-linux64

CXX=g++
CFLAGS= -c -ggdb
LD=g++

all: $(EXECUTABLE)

$(EXECUTABLE): obj/main.o obj/xtea_AT4.o obj/xtea_AT4_testbench.o
	@echo Building $@
	@$(CXX) -g $(INCDIR) -o $@ $^ $(LIBDIR)/libsystemc.a -lpthread

obj/main.o: src/main.cc
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_AT4.o: src/xtea_AT4.cc
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_AT4_testbench.o: src/xtea_AT4_testbench.cc
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

clean:
	@echo Cleaning
	@rm -f obj/*.o *~
	@rm -f $(EXECUTABLE)

.PHONY: all clean
