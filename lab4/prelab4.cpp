// Yu Du, yd2am
// 09/21/2019
// prelab4.cpp


#include <iostream>

using namespace std;

void sizeOfTest() {
	cout <<  "Size of int: " << sizeof(int) << endl;
	cout <<  "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout <<  "Size of float: " << sizeof(float) << endl;
	cout <<  "Size of double: " << sizeof(double) << endl;
	cout <<  "Size of char: " << sizeof(char) << endl;
	cout <<  "Size of bool: " << sizeof(bool) << endl;
	cout <<  "Size of int*: " << sizeof(int*) << endl;
	cout <<  "Size of char*: " << sizeof(char*) << endl;
	cout <<  "Size of double*: " << sizeof(double*) << endl;
}

// print out 32-bit binary big Endian representation of the unsigned int
void outputBinary(unsigned int x) {
	int rep[32] = {};
	// convert unsigned int x to binary
	for(int i=0; i<32; i++) {
		int remainder = x%2;
		rep[i] = remainder;
		x = (x>>1);
	}

	// revert to big Endian representation
	for(int i=31; i>=0; i--) {
		if((i+1) != 32 && (i+1)%4 == 0)
			cout << " ";
		cout << rep[i];
	}
	cout << endl;
}

// add one to an unsigned maximum value
void overflow() {
	unsigned int x = 4294967295;
	cout << "Maximum unsigned int = " << x << endl;
	cout << "The result of adding one to the maximum unsigned integer is : " << x+1 << endl;
	cout << "Because the binary representation of the maximum integer is :" << endl;
	outputBinary(x);
	cout << "When we add 1 to it, all the bits become 0 and causes overflow." << endl;
}

int main() {
	cout << "---------sizeof() test results---------" << endl;
	sizeOfTest();

	cout << "---------Integer to binary representation---------" << endl;
	cout << "Please enter a unsigned integer: ";
	unsigned int x;
	cin >> x;
	outputBinary(x);

	cout << "---------Calling overflow()---------" << endl;
	overflow();
	return 0;
}