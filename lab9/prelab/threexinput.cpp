// Yu Du, yd2am
// threexinput.cpp
// 2019.11.16

#include <iostream>
#include <cstdlib>
#include "time.h"
using namespace std;

extern "C" int threexplusone(int);

int  main () {
    // delcare the local variables
    int x, n, count;
    double time;

    cout << "Please enter a possitive integer as x:";
    cin >> x;
    cout << "Please enter a positive integer as n:";
    cin >> n;

    // call externally defined functions to get the result
    // start timer
    timer t;
    t.start();
    while(n-- > 0) {
	    count = threexplusone(x);
    }
    t.stop();
    time = t.getTime()*1000;

	cout << x << " took " << count << " steps to reach the value 1 " << endl;
	cout << "Average time = " << time/n << "ms" << endl;
    // no need to deallocate
    return 0;
}
