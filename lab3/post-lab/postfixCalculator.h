// Yu Du, yd2am
// 09/19/2019
// postfixCalculator.h

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include "Stack.h"
using namespace std;

class postfixCalculator {
public:
	postfixCalculator();	// Constructor
	~postfixCalculator();	// Deconstructor
	void addNum(int x);
	void add();
	void subtract();
	void multiply();
	void divide();
	void negation();
	int getTopValue();


private:
	Stack* myStack;
};