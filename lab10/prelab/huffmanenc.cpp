// Yu Du, yd2am
// huffmanenc.cpp
// 2019.11.24

// included so we can use cout
#include <iostream>
// stdlib.h is where exit() lives
#include <stdlib.h>
// include the standard I/O library
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include "heap.h"
#include "huffmanNode.h"

using namespace std; 

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // cout << "before open file "<< endl;
    // attempt to open the supplied file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    unordered_map<char, int> freqMap;
    char g;
    // read in each character, one by one
    while ( (g = fgetc(fp)) != EOF ) {
        if(g == '\n')
        	continue;
        // if g is a new character to frequency map
        if(freqMap.find(g) == freqMap.end())
        	freqMap.insert(make_pair(g, 1));
        else
        	// if g is not new, freq += 1
        	freqMap.find(g)->second = freqMap.find(g)->second+1;
    }

    // cout << "map created! "<< endl;
    // rewinds the file pointer, starts reading the file again from the beginning
    rewind(fp);

    heap myHeap = heap();
    unordered_map<char, int>:: iterator iter;
    // scan through the frequency map, and put everything into heap
    for(iter = freqMap.begin(); iter != freqMap.end(); iter++) {
    	huffmanNode* node = new huffmanNode(iter->first, iter->second);
    	myHeap.insert(node);
    }

    // cout << "heap created! "<< endl;
    // now build huffman tree
    while(myHeap.size() > 1) {
    	huffmanNode* left = myHeap.deleteMin();
    	huffmanNode* right = myHeap.deleteMin();
    	huffmanNode* node = new huffmanNode();
    	// update frequence of the new node
    	node->frequency = left->frequency + right->frequency;
    	node->left = left;
    	node->right = right;
    	myHeap.insert(node);
    }

    // the root of huffman tree stores in myHeap[1]
    myHeap.buildTree(myHeap.findMin(), "");
    cout << "----------------------------------------" << endl;

    string encoded = "";
    int count = 0;
    // read the file again, and print the encoded version to the screen
    while ( (g = fgetc(fp)) != EOF ) {
    	if(g != '\n') {
    		encoded += myHeap.getCode(g);
    		encoded += " ";
    		count += 1;
    	}
    }
	cout << encoded << endl;
    // close the file
    fclose(fp);

    cout <<"----------------------------------------" << endl;

    // count the length of encoded string (except for spaces)
    int encodeLength = 0;
    for(int i=0; i<encoded.length(); i++) {
    	if(encoded[i] != ' ')
    		encodeLength += 1;
    }
	double ratio = double (count*8)/encodeLength;
	double cost = double (encodeLength)/count;

	cout <<"There are a total of " << count << " symbols that are encoded." << endl;
	cout <<"There are " << freqMap.size() << " distinct symbols used." << endl;
	cout <<"There were " << count * 8 << " bits in the original file." << endl;
	cout <<"There were " << encodeLength << " in the compressed file." << endl;
	cout <<"This gives a compression ratio of " << ratio << "." << endl;
	cout <<"The cost of the Huffman tree is " <<  cost << " bits per character." << endl;

	return 0;
}

