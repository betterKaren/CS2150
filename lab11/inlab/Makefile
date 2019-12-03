# Yu Du, yd2am
# Makefile
# 2019.12.3

# Defines the C++ compiler we'll be using
CXX	= clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -O2 -g -std=c++11

OFILES	= traveling.o middleearth.h middleearth.cpp

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

clean:
	/bin/rm -f *.o *~
