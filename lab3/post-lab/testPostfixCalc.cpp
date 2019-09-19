// Yu Du, yd2am
// 09/19/2019
// testProfixCalc.cpp

#include <iostream>
#include <stack>
#include <cstdlib>
#include "Stack.h"
#include "postfixCalculator.h"
using namespace std;

int main() {
    string s;
    postfixCalculator p;

    cout << "Please enter postfix expression:" << endl;
    cout << "Don't forget to hit Enter and Control-D in the end!"<< endl;

    while(cin >> s) {
        // convert s to char[]
        const char* cstr = s.c_str();
        // when input is a positive number
        if(isdigit(cstr[0])) {
            int num = atoi(cstr);
            p.addNum(num);
        }
        // when input is a negative number
        else if(cstr[0] == '-' && s.length()>1){
            int num = atoi(cstr);
            p.addNum(num);
        }
        // when input is operand
        else if(s == "+") {
            p.add();
        }
        else if(s == "-") {
            p.subtract();
        }
        else if(s == "*") {
            p.multiply();
        }
        else if(s == "/") {
            p.divide();
        }
        else if(s == "~") {
            p.negation();
        }
        // invalid inputs
        else {
            cout << "Invalid Input!!" << endl;
            exit(-1);
        }
    }

    cout << "result = " << p.getTopValue() << endl;

    return 0;
}