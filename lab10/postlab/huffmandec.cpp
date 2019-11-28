// Yu Du, yd2am
// huffmandec.cpp
// 2019.11.26

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffmanNode.h"
using namespace std;


// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffmanNode *root = new huffmanNode();
    huffmanNode *cur = root;
    while ( true ) {
        string character, prefix;
        cur = root;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        // cout << "character '" << character << "' has prefix code '"
        //      << prefix << "'" << endl;

        // build huffman tree
		for (int i = 0; i < prefix.length(); i++) {
		    if (prefix[i] == '0' && cur->left == NULL)
				cur->left = new huffmanNode();
		    if (prefix[i] == '0')
				cur = cur->left;

		    if (prefix[i] == '1' && cur->right == NULL)
				cur->right = new huffmanNode();
		    if (prefix[i] == '1')
				cur = cur->right;
		  }
		  cur->character = character[0];
    }

    // cout << "huffman tree built!!" << endl;

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // cout << "----------------------------------------" << endl;


    cur = root;
    // now read in compressed file and decode
    for(int i=0; i<allbits.length(); i++) {
    	char c = allbits[i];
    	if((c == '0' && cur->left == NULL) || (c == '1' && cur->right == NULL)) {
    		cout << cur->character;
    		cur = root;
    	}

    	if(c == '0' && cur->left != NULL)
    		cur = cur->left;

    	if(c == '1' && cur->right != NULL)
    		cur = cur->right;
    }
    cout << cur->character << endl;

    // close the file before exiting
    file.close();
    delete root;
    return 0;
}

