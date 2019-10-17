# Yu Du, yd2am
# Makefile
# 2019.10.16

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
CXXFLAGS=-std=c++11

OFILES = AVLNode.o AVLTree.o AVLPathTest.o

.SUFFIXES: .o .cpp

pathTest: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES) -o a.out
	@echo "AVL path test compiled!"
	
clean:
	-rm -f *.o *~ outputfile

AVLNode.o: AVLNode.cpp AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLNode.h AVLTree.h