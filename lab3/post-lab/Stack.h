// Yu Du, yd2am
// 09/19/2019
// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std; 

class List;

class Stack {
public:
	Stack();	// Constructor
	~Stack();	// Destructor
	void push(int x);
	int top();
	void pop();
	bool empty();

private:
	List stackList;
};

#endif