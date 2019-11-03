// Yu Du, yd2am
// 2019.11.3
// mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int  main () {
    // delcare the local variables
    int x, y, prod, pow;

    cout << "Please enter a positive integer as x : ";
    cin >> x;
    cout << "Please enter a positive integer as y : ";
    cin >> y;

    // call externally defined functions to get the result
    prod = product(x, y);
    cout << "The product of " << x << "and " << y << " is " << prod << endl;
    pow = power(x, y);
    cout << x << " to the power of "<< y << " is " << pow << endl;

    // no need to deallocate
    return 0;
}
