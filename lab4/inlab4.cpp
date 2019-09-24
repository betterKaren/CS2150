// Yu Du, yd2am
// 09/24/2019
// inlab4.cpp

#include <iostream>
#include <climits>
#include <limits>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	// max values base 10
	cout << "int max : " << INT_MAX << endl;
	cout << "unsigned int max : " << UINT_MAX << endl;
	cout << "char max : " << CHAR_MAX << endl;

	std::cout << "float max : " << std::numeric_limits<float>::max() << '\n';
	std::cout << "double max : " << std::numeric_limits<double>::max() << '\n';
	std::cout << "boolean max : " << std::numeric_limits<bool>::max() << '\n';
	cout << "------ End of checking max value ------" << endl;

	// 0
	int i = 0;
	float f = 0;
	double d = 0;
	char c = '0';
	bool b = false;
	// 1
	int i_1 = 1;
	float f_1 = 1;
	double d_1 = 1;
	char c_1 = '1';
	bool b_1 = true;
	cout << endl;
	cout << "------ End of checking hex for 0/1 ------" << endl;


	// Representation in Memory
	cout << "------ Start of Representation in memory ------" << endl;
	bool b_2 = true;
	char c_2 = 'a';
	int i_2 = 10;
	double d_2 = 10.25;
	int* i_pointer = &i_2;
	cout << b_2 << endl;
	cout << c_2 << endl;
	cout << i_2 << endl;
	cout << d_2 << endl;
	cout << i_pointer << endl;
	cout << "------ End of Representation in memory ------" << endl;

	// Primitive Arrays in C++
	cout << "------ Start of Primitive arrays in C++ ------" << endl;
	int IntArray[10];
	char CharArray[10];
	int IntArray2D[6][5];
	char CharArray2D[6][5];
	char array[10] = {'a','b','c','d','e','f','i','g','k','l'};
	for(int i=0; i<10; i++) {
		IntArray[i] = i;
		CharArray[i] = array[i];
	}

	for(int i=0; i<6; i++) {
		for(int j=0; j<5; j++) {
			IntArray2D[i][j] = i + pow(10, j);
			CharArray2D[i][j] = array[i+j];
		}
	}
	cout << "------ End of Primitive arrays in C++ ------" << endl;

	return 0;
}