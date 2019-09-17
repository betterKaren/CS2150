// Yu Du, yd2am
// 09/15/2019
// testProfixCalc.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;

int main() {
    postfixCalculator p;
    p.addNum(20);
    p.addNum(10);
    p.subtract();
    p.addNum(3);
    p.negation();
    p.addNum(10);
    p.subtract();
    p.subtract();
    p.addNum(2);
    p.subtract();
    cout << "Result is: " << p.getTopValue() << endl;

    return 0;
}