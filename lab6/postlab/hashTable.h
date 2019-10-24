// Yu Du, yd2am
// hashTable.h
// 2019.10.21

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
// #include <cstdlib>
// #include <algorithm>
using namespace std;

class hashTable {
private:
	vector< list <string> > *myBucket;
	int tableSize;

public:
	hashTable(int size);		// constructor
	~hashTable();
	unsigned int hash(string &key);
	void insert(string &s);
	bool contains(string &s);
};

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);

#endif
