#ifndef TEST_H
#define TEST_H

#include "matrix.h"

using std::cout;
using std::endl;

int sum(Matrix& cc); // Adds all the values in the matrix and returns the sum.

bool test1() // +
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

	// Special case
	// Creating a matrix with negative sizes.
	Matrix m3(2);
	Matrix m4(-8);

	// Addition and subtraction matrices with negative size.
	m3 = m3 + m4;

	// Addition and subtraction matrices with different sizes.
	m1 = m1 + m3;

	return true;
}

bool test2() // -
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


	// Subtraction of matrices
	m1 = m1 - m2;
	if (sum(m1) != -9) // Target value -9
	{
		cout << "Test #2 failed..." << endl;
		return false;
	}

	// Special case
	// Creating a matrix with negative sizes.
	Matrix m3(2);
	Matrix m4(-8);

	m3 = m3 - m4;
	m1 = m1 - m2;

	return true;
}

bool test3() // =
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

	m1 = m2;

	if (sum(m1) != 45) // Target value 45
		return false;

	m1(0, 0, 0); m1(0, 1, 0); m1(0, 2, 0);
	m1(1, 0, 0); m1(1, 1, 0); m1(1, 2, 0);
	m1(2, 0, 0); m1(2, 1, 0); m1(2, 2, 0);

	m2(0, 0, 1); m2(0, 1, 1); m2(0, 2, 1);
	m2(1, 0, 1); m2(1, 1, 1); m2(1, 2, 1);
	m2(2, 0, 1); m2(2, 1, 1); m2(2, 2, 1);

	// Special case
	// Creating a matrix with negative sizes.
	Matrix m3(2);
	Matrix m4(-8);

	m3 = m4;

	m1 = m2;

	return true;
}

int sum(Matrix& cc)
{
	int s = 0;
	int size = cc.GetSize();

	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
			s += cc(x, y);

	return s;
}

#endif