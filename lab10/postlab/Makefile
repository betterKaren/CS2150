# Yu Du, yd2am
# Makefile
# 2019.11.27

# Defines the C++ compiler we'll be using
CXX	= clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -O2 -g -std=c++11

OFILES	= huffmanNode.o

.SUFFIXES: .o .cpp

main:	encoder decoder
encoder:	heap.o huffmanenc.o $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) huffmanenc.o heap.o -o encoder
decoder:	huffmandec.o $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) huffmandec.o -o decoder

clean:
	/bin/rm -f *.o *~
