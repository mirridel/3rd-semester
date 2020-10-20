#ifndef TEST_H
#define TEST_H

#include "matrix.h"

using std::cout;
using std::endl;

int sum(Matrix& cc); // Adds all the values in the matrix and returns the sum.

bool test() // Main function.
{

	Matrix m1(3);
	m1(0, 0, 0); m1(0, 1, 1); m1(0, 2, 2); // 0  1  2
	m1(1, 0, 3); m1(1, 1, 4); m1(1, 2, 5); // 3  4  5
	m1(2, 0, 6); m1(2, 1, 7); m1(2, 2, 8); // 6  7  8
	//cout << toString(m1) << endl;

	Matrix m2(3);
	m2(0, 0, 9); m2(0, 1, 8); m2(0, 2, 7); // 9  8  7
	m2(1, 0, 6); m2(1, 1, 5); m2(1, 2, 4); // 6  5  4
	m2(2, 0, 3); m2(2, 1, 2); m2(2, 2, 1); // 3  2  1
	//cout << toString(m2) << endl;

	Matrix m3(3);
	m3(0, 0, 0); m3(0, 1, 0); m3(0, 2, 0); // 0  0  0
	m3(1, 0, 0); m3(1, 1, 0); m3(1, 2, 0); // 0  0  0
	m3(2, 0, 0); m3(2, 1, 0); m3(2, 2, 0); // 0  0  0
	//cout << toString(m3) << endl;

	// Testing basic functions.

	// Getter
	if ((m1(0, 0) != 0) || (m2(0, 0) != 9))
		return false;

	// Getter of size
	if ((m1.getSize() != 3) || (m2.getSize() != 3))
		return false;

	// Setter
	m3(0, 0, 128);
	if (m3(0, 0) != 128)
		return false;

	// Test 1 
	// Addition of matrices

	m1 = m1 + m2;

	if (sum(m1) != 81) // Target value 81
	{
		cout << "Test #1 failed..." << endl;
		return false;
	}

	m1(0, 0, 0); m1(0, 1, 0); m1(0, 2, 0);
	m1(1, 0, 0); m1(1, 1, 0); m1(1, 2, 0);
	m1(2, 0, 0); m1(2, 1, 0); m1(2, 2, 0);

	m2(0, 0, 1); m2(0, 1, 1); m2(0, 2, 1);
	m2(1, 0, 1); m2(1, 1, 1); m2(1, 2, 1);
	m2(2, 0, 1); m2(2, 1, 1); m2(2, 2, 1);

	// Test 2
	// Subtraction of matrices

	m1 = m1 - m2;

	if (sum(m1) != -9) // Target value -9
	{
		cout << "Test #2 failed..." << endl;
		return false;
	}

	// Test 3
	// Assigning values of the 2nd matrix to the 1st matrix.

	m1 = m2;

	if (sum(m1) != 9) // Target value 9
	{
		cout << "Test #3 failed..." << endl;
		return false;
	}

	// Test 4
	// Determinant of matrix.

	if (m1() != 0) // Target value 0
	{
		cout << "Test #4 failed..." << endl;
		return false;
	}

	// Special case

	// Test 5
	// Creating a matrix with negative sizes.

	Matrix m4(-1);
	Matrix m5(0);

	// Test 6
	// Addition and subtraction matrices with negative size.

	m4 = m4 + m5;
	m4 = m4 - m5;

	// Test 7
	// Addition and subtraction matrices with different sizes.

	m1 = m1 + m4;
	m1 = m1 - m4;

	// Test 8
	// Decrement for matrices with negative size.

	m4(); m5();    

	// Test 9
	// Checking the getter and setter for incorrect data.
	
	m1(-64, 128);
	m4(-128, -512, 2);

	return true;
}

int sum(Matrix& cc)
{
	int s = 0;
	int size = cc.getSize();

	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
			s += cc(x, y);

	return s;
}

#endif