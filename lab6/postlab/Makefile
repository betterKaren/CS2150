# Yu Du, yd2am
# Makefile
# 2019.10.22

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -O2
CXXFLAGS=-std=c++11

OFILES = hashTable.o wordPuzzle.o timer.o

.SUFFIXES: .o .cpp

pathTest: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES)
	@echo "compiled!"
	
clean:
	-rm -f *.o *~ outputfile

hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h
timer.o: timer.cpp timer.h