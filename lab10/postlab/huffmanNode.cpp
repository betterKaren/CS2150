// Yu Du, yd2am
// huffmanNode.cpp
// 2019.11.24
// This is the file implements huffmanNode class.

#include<iostream>
#include "huffmanNode.h"

using namespace std; 

// default constructor
huffmanNode::huffmanNode() {
	frequency = 0;
	character = 0;
	left = NULL;
	right = NULL;
}

// constructor with given character and it's frequency
huffmanNode::huffmanNode(char c, int freq) {
	character = c;
	frequency = freq;
	left = NULL;
	right = NULL;
}

// destructor
huffmanNode::~huffmanNode() {
	delete left;
	delete right;
}

