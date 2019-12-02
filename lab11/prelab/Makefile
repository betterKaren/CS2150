# Yu Du, yd2am
# Makefile
# 2019.11.30

# Defines the C++ compiler we'll be using
CXX	= clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -O2 -g -std=c++11

OFILES	= topological.o

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

clean:
	/bin/rm -f *.o *~
