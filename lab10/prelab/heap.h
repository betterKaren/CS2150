// Yu Du, yd2am
// heap.h
// 2019.11.24
// This is the file defines heap class (implemented by vector).

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "huffmanNode.h"

using namespace std; 

class heap {
	public:
		heap();
		~heap();

		void insert(huffmanNode *n);
		huffmanNode* findMin();
		huffmanNode* deleteMin();
		unsigned int size();
		void print();

		// this map is used to store character and its Huffman code
		unordered_map<char, string> map;
		void buildTree(huffmanNode *n, string s);
		string getCode(char c);

	private:
		vector<huffmanNode *> myHeap;
		unsigned int heap_size;
		void percolateUp(int hole);
		void percolateDown(int hole);
};

#endif