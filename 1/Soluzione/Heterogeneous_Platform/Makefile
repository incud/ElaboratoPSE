SYSTEMC_AMS=$$SCAMS_HOME
SYSTEMC=$$SYSTEMC_HOME

PLATFORM= $(shell uname -s)
ARCH=$(shell getconf LONG_BIT)

ifeq ($(PLATFORM),Darwin)
SYSC_LIBDIR := $(SYSTEMC)/lib-macosx
SCAMS_LIBDIR := $(SYSTEMC_AMS)/lib-macosx
endif
ifeq ($(PLATFORM),Linux)
SYSC_LIBDIR := $(SYSTEMC)/lib-linux
SCAMS_LIBDIR := $(SYSTEMC_AMS)/lib-linux
endif

ifeq ($(ARCH),64)
SYSC_LIBDIR := $(SYSC_LIBDIR)64
SCAMS_LIBDIR := $(SCAMS_LIBDIR)64
endif

LIBS = $(SCAMS_LIBDIR)/libsystemc-ams.a \
	   $(SYSC_LIBDIR)/libsystemc.a \
	   -lpthread

INCDIR = -I./include/ -I. -I$(SYSTEMC)/include/ -I$(SYSTEMC_AMS)/include

CXX=g++
CFLAGS= -c
LD=g++

EXECUTABLE=./bin/main.x

all: $(EXECUTABLE)

clean:
	@echo Cleaning
	@rm -f obj/*.o *~
	@rm -f $(EXECUTABLE)

$(EXECUTABLE): obj/main.o obj/common.o obj/controller_tlm.o obj/controller_cipher_transactor.o obj/xtea.o obj/transactor.o obj/valve.o obj/valve_if.o obj/watertank.o obj/watertank_if.o
	@ $(LD) -o $@ $(INCDIR) $^ $(LIBS)

obj/main.o: src/main.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/common.o: src/common.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/controller_tlm.o: src/controller_tlm.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/controller_cipher_transactor.o: src/controller_cipher_transactor.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/transactor.o: src/transactor.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/xtea.o: src/xtea.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/valve.o: src/valve.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/valve_if.o: src/valve_if.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/watertank.o: src/watertank.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

obj/watertank_if.o: src/watertank_if.cc
	@echo Building $@
	@ $(CXX) $(CFLAGS) -o $@ $(INCDIR) $<

.PHONY: all clean
