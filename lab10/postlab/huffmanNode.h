// Yu Du, yd2am
// huffmanNode.h
// 2019.11.24
// This is the file defines huffmanNode class.

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
#include <string>
using namespace std; 

class huffmanNode {
	public:
		huffmanNode();
		huffmanNode(char c, int freq);
		~huffmanNode();

		int frequency;
		char character;
		huffmanNode* left;
		huffmanNode* right;
};

#endif