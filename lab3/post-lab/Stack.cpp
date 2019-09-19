// Yu Du, yd2am
// 09/19/2019
// Stack.cpp

#include <iostream>
#include "Stack.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std; 

// Constructor
Stack :: Stack() {
	// stackList = new List();
}

// Destructor
Stack::~Stack() {
  // delete stackList;
}

void Stack::push(int x) {
	stackList.insertAtTail(x);
}

int Stack::top() {
	if(stackList.isEmpty()){
		cout << "Error! Stack is empty!" << endl;
		exit(-1);
	}
	
	ListItr iter = stackList.last();
	return iter.retrieve();
}

void Stack::pop() {
	if(stackList.isEmpty()){
		cout << "Error! Stack is empty!" << endl;
		exit(-1);
	}
	
	ListItr iter = stackList.last();
	int x = iter.retrieve();
	stackList.remove(x);
}
