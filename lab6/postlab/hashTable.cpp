// Yu Du, yd2am
// hashTable.cpp
// 2019.10.21

#include "hashTable.h"
using namespace std;

hashTable::hashTable(int size) {
	myBucket = new vector<list <string> >();
	// double the size in case 
	tableSize = 2*size;

	// inorder to rehash, we need to copy the previous tableSize elements
	for(int i=0; i<tableSize; i++) {
		list<string> list;
		myBucket->push_back(list);
	}
}

hashTable::~hashTable() {
	delete myBucket;
}

unsigned int hashTable::hash(string &key) {
	unsigned int hash = 7;			// 0, 5, 7, 11
	// for(int i=0; i<key.length(); i++) {
	// 	hash *= 11;		// 3, 5, 7, 11, 13, 29
	// 	hash += key[i];
	// }

	char *ch = (char*)key.c_str();
	for(int i=0; i<key.length(); i++) {
		int n = ch[i]-'0';
		n++;			// a->1, b->2, ... z->26
		hash *= 5;		// 3, 5, 7, 11, 13, 17, i, n
		hash += n;		// n, i
	}

	hash %= tableSize;
	return hash;
}

void hashTable::insert(string &s) {
	myBucket->at(hash(s)).push_back(s);
}

bool hashTable::contains(string &s) {
	list<string> &chain = myBucket->at(hash(s));
	for(list<string>::iterator i=chain.begin(); i!=chain.end(); i++) {
		if(s == *i)
			return true;
	}

	return false;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
