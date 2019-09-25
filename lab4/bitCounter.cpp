// Yu Du, yd2am
// 09/25/2019
// bitCounter.cpp

#include<iostream>

using namespace std;

// recursive function counts the number of '1's in binary representation of n
int helper(int n) {
	// the initial case
	if(n == 0)
		return 0;

	// when n is even
	if(n%2 == 0) {
		return helper(n/2);
	}
	// when n is odd
	else {
		return helper((n-1)/2) + 1;
	}
}

int main(int argc, char **argv) {
	// exit w/out command-line parameter
	if(argc == 1) {
		cout << "Please check your input. It should be a non-negative integer :)" << endl;
		exit(-1);
	}

	int n = atoi(argv[1]);
	int res = helper(n);
	cout << "The number of 1s in binary representation of " << n << "is: " << res << endl;  
}
