#Default architecture (if none specified)
ARCH?=host

# Making for host
# > make ARCH=host
ifeq (${ARCH}, host)
CXX=g++
BUILD_DIR=build/host
BIN_DIR=bin/host
endif 

# Making for target
# > make ARCH=target
ifeq (${ARCH}, target)
CXX=arm-rpizw-g++
BUILD_DIR=build/target
BIN_DIR=bin/target
endif

# Quick and dirty (does not handle changes in h-file)
SRCS=main.cpp SensorReader.cpp CoinIdentifier.cpp FakeReceiver.cpp
OBJS=$(SRCS:.cpp=.o)
BASEPATH=..
# Determine whether this is a debug build or not
ifdef DEBUG
CXXFLAGS=-ggdb -O0
LIBPATH=$(BASEPATH)/lib/host/debug
else
CXXFLAGS=-O2
LIBPATH=$(BASEPATH)/lib/target/debug
endif
# Setup the CFLAGS to ensure that the relevant warnings, includes and defines.
CXXFLAGS+=-Wall -D_REENTRANT -DOS_LINUX -I$(BASEPATH)/inc

#%.o : %cpp
#	g++ $(CXXFLAGS) -c -o $@ $^
# Then again, note how the flags are NOT part of the linking process
main: $(OBJS)
	$(CXX) -o main $(OBJS)  -L$(LIBPATH) -lOSApi -lrt -lpthread

all: main

clean:$(OBJS)
	rm -f *.o main
