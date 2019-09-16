// Yu Du, yd2am
// 09/15/2019
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
	int num1 = myStack->top();
	myStack->pop();
	int num2 = myStack->top();
	myStack->pop();

	myStack->push(num1 + num2);
}

void postfixCalculator::subtract() {
	int num1 = myStack->top();
	myStack->pop();
	int num2 = myStack->top();
	myStack->pop();
	
	// myStack : LIFO
	myStack->push(num2 - num1);
}

void postfixCalculator::multiply() {
	int num1 = myStack->top();
	myStack->pop();
	int num2 = myStack->top();
	myStack->pop();
	
	myStack->push(num1 * num2);
}

void postfixCalculator::divide() {
	int num1 = myStack->top();
	myStack->pop();
	int num2 = myStack->top();
	myStack->pop();

	myStack->push(num2/num1);
}

void postfixCalculator::negation() {
	int num=myStack->top();
	myStack->pop();
	
	myStack->push(-1 * num);
}


int postfixCalculator::getTopValue() {
	return myStack->top();
}




