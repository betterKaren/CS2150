// Yu Du, yd2am
// heap.cpp
// 2019.11.24
// This is the file implements heap (based on vector) and it's functions.

#include <iostream>
#include <vector>
#include <unordered_map>
#include "heap.h"
#include "huffmanNode.h"

using namespace std; 

// default constructor
heap::heap() : heap_size(0) {
	myHeap.push_back(0);	// start with index=1
}

// default deconstructor
heap::~heap() {
}

void heap::insert(huffmanNode *n) {
	myHeap.push_back(n);
	percolateUp(++heap_size);
}

huffmanNode* heap::findMin() {
	if ( heap_size == 0 )
		throw "findMin() called on empty heap";
	return myHeap[1];
}

huffmanNode* heap::deleteMin() {
	if ( heap_size == 0 )
	    throw "findMin() called on empty heap";

	huffmanNode* ret = myHeap[1];
	// move the last inserted position into the root
	myHeap[1] = myHeap[heap_size--];
	myHeap.pop_back();
	percolateDown(1);
	return ret;
}

unsigned int heap::size() {
	return heap_size;
}

void heap::print() {
	cout << "(" << myHeap[1]->frequency << ")";
	for(int i=1; i<=heap_size; i++) {
		cout << myHeap[i]->character << " ";
		bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
		if(isPow2)
			cout << endl << "\t";
	}
	cout << endl;
}

void heap::percolateUp(int hole) {
	// get the node just inserted
	huffmanNode *n = myHeap[hole];
	// while not reaching top and new node's value<parent's value
	// keep move parent node down
	for(; (hole > 1) && (n->frequency < myHeap[hole/2]->frequency); hole /= 2) {
		myHeap[hole] = myHeap[hole/2];
	}
	myHeap[hole] = n;
}

void heap::percolateDown(int hole) {
	// get the node to percolate down
	huffmanNode *n = myHeap[hole];
	// while there is a left child
	while(hole*2 <= heap_size) {
		int child = hole*2;		// left chile
		// check if there is a right child and if it's less
		if((child+1 <= heap_size) && (myHeap[child+1]->frequency < myHeap[child]->frequency))
			child++;

		// if the child is greater than the node
		if(n->frequency > myHeap[child]->frequency) {
			myHeap[hole] = myHeap[child];
			hole = child;
		} else
			break;
	}
	// correct position found
	myHeap[hole] = n;	
}

// this function can to build a huffman tree, and print out the prefix
void heap::buildTree(huffmanNode* n, string s) {
	// when we reach a character (leaf node)
	if(n->left == NULL && n->right == NULL) {
		if(n->character == ' ')
			cout << "space" << s << endl;
		else
			cout << n->character << " " << s << endl;
		// store into map
		map.insert(make_pair(n->character, s));
	}

	// recursion
	if(n->left != NULL)
		buildTree(n->left, s+"0");
	if(n->right != NULL)
		buildTree(n->right, s+"1");
}

string heap::getCode(char c) {
	return map[c];
}

