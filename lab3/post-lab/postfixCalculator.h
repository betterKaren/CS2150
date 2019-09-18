// Yu Du, yd2am
// 09/17/2019
// postfixCalculator.h

#include <iostream>
#include <stack>
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
	stack<int>* myStack;
};