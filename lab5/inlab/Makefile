# Yu Du, yd2am
# Makefile
# 2019.10.15

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
CXXFLAGS=-std=c++11

OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o

.SUFFIXES: .o .cpp

pathTest: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES) -o a.out
	@echo "BST path test compiled!"
	
clean:
	-rm -f *.o *~ outputfile

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
BSTPathTest.o: BSTPathTest.cpp BinaryNode.h BinarySearchTree.h