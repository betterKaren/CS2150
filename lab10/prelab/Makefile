# Yu Du, yd2am
# Makefile
# 2019.11.24

# Defines the C++ compiler we'll be using
CXX	= clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -O2 -g -std=c++11

# All of the .o files for our program
OFILES	= heap.o huffmanNode.o huffmanenc.o

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
