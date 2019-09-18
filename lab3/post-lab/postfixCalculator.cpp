// Yu Du, yd2am
// 09/17/2019
// postfixCalculator.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std; 

// Constructor
postfixCalculator::postfixCalculator() {
	myStack = new stack<int>;
}

// Deconstructor
postfixCalculator::~postfixCalculator() {
	delete myStack;
}

void postfixCalculator::addNum(int x) {
	myStack->push(x);
}

void postfixCalculator::add() {
	int num1 = getTopValue();
	myStack->pop();
	int num2 = getTopValue();
	myStack->pop();

	myStack->push(num1 + num2);
}

void postfixCalculator::subtract() {
	int num1 = getTopValue();
	myStack->pop();
	int num2 = getTopValue();
	myStack->pop();
	
	// myStack : LIFO
	cout << num2 - num1 << endl;
	myStack->push(num2 - num1);
}

void postfixCalculator::multiply() {
	int num1 = getTopValue();
	myStack->pop();
	int num2 = getTopValue();
	myStack->pop();
	
	myStack->push(num1 * num2);
}

void postfixCalculator::divide() {
	int num1 = getTopValue();
	myStack->pop();
	int num2 = getTopValue();
	myStack->pop();

	myStack->push(num2/num1);
}

void postfixCalculator::negation() {
	int num = getTopValue();
	myStack->pop();
	
	myStack->push(-1 * num);
}

int postfixCalculator::getTopValue() {
	if(myStack->size() == 0)
		exit(-1);
	return myStack->top();
}




