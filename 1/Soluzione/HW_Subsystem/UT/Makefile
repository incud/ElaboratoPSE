DESIGN_NAME=xtea
ABSTRACTION_LEVEL=UT

EXECUTABLE=bin/$(DESIGN_NAME)_$(ABSTRACTION_LEVEL).x

SYSTEMC=$$SYSTEMC_HOME

INCDIR = -I./include/ -I. -I$(SYSTEMC)/include/
LIBDIR = $(SYSTEMC)/lib-linux64

CXX=g++
CFLAGS= -c
LD=g++

all: $(EXECUTABLE)

$(EXECUTABLE): obj/main.o obj/xtea_UT.o obj/xtea_UT_testbench.o
	@echo Building $@
	@$(CXX) -g $(INCDIR) -o $@ $^ $(LIBDIR)/libsystemc.a -lpthread

obj/main.o: src/main.cc
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_UT.o: src/xtea_UT.cc include/xtea_UT.hh
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

obj/xtea_UT_testbench.o: src/xtea_UT_testbench.cc include/xtea_UT_testbench.hh
	@echo Building $@
	@$(CXX) -g $(CFLAGS) $(INCDIR) -o $@ $< 

clean:
	@echo Cleaning
	@rm -f obj/*.o *~
	@rm -f $(EXECUTABLE)

.PHONY: all clean
