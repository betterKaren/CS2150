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
    int x, y, product, power;

    cout << "Please enter a positive integer as x : ";
    cin >> x;
    cout << "Please enter a positive integer as y : ";
    cint >> y;

    // call externally defined functions to get the result
    product = product(x, y);
    cout << "The product of " << x << "and " << y << " is " << product << endl;
    power = power(x, y);
    cout << x << " to the power of "<< y << " is " << power << endl;

    // no need to deallocate
    return 0;
}
