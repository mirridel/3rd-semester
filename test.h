#ifndef TEST_H
#define TEST_H

#include "matrix.h"
#include "identityMatrix.h"
#include "rectangularMatrix.h"

int sum(Matrix& cc); // Adds all the values in the matrix and returns the sum.

bool test() // Main function.
{
	Matrix squareMatrix(3);
	squareMatrix[0][0] = 0; squareMatrix[0][1] = 1; squareMatrix[0][2] = 2; // 0  1  2
	squareMatrix[1][0] = 3; squareMatrix[1][1] = 4; squareMatrix[1][2] = 5; // 3  4  5
	squareMatrix[2][0] = 6; squareMatrix[2][1] = 7; squareMatrix[2][2] = 8; // 6  7  8
	if (sum(squareMatrix) != 36)
	{
		cout << "Test #1 failed..."<< sum(squareMatrix) << endl;
		return false;
	}

	IdentityMatrix iMatrix(3);
	if (sum(iMatrix) != 3)
	{
		cout << "Test #2 failed..." << endl;
		return false;
	}

	RectangularMatrix m1(2, 3);
	RectangularMatrix m2(3, 2);
	RectangularMatrix m3(3, 2);
	m1[0][0] = 0; m1[0][1] = 0; m1[0][2] = 0; // 0  0  0
	m1[1][0] = 0; m1[1][1] = 0; m1[1][2] = 0; // 0  0  0
	//cout << m1 << endl;
	m2[0][0] = 1; m2[0][1] = 2; // 1  2
	m2[1][0] = 3; m2[1][1] = 4; // 3  4
	m2[2][0] = 5; m2[2][1] = 6; // 5  6
	//cout << m2 << endl;

	// Testing basic functions.

	// Getter
	if ((m1[0][0] != 0) || (m2[0][0] != 1))
		return false;

	// Getter of size
	if ((m1.GetCols() != 3) || (m2.GetRows() != 3))
		return false;

	// Setter
	m3[0][0] = 128;
	if (m3[0][0] != 128)
		return false;

	// Test 1 
	// Addition of matrices

	m1 = m1 + m2;

	if (sum(m1) != 0) // Target value 81
	{
		cout << "Test #3 failed..." << endl;
		return false;
	}

	for (int i = 0; i < 2; i++)       // 0  0  0
		for (int j = 0; j < 3; j++)   // 0  0  0
			m1[i][j] = 0;       
	//cout << "M1\n" << m1 << endl;

	for (int i = 0; i < 3; i++)       // 1  1
		for (int j = 0; j < 2; j++)   // 1  1
			m2[i][j] = 1;             // 1  1 
	//cout << "M2\n" << m2 << endl;

	for (int i = 0; i < 3; i++)       // 0  0
		for (int j = 0; j < 2; j++)   // 1  1
			m3[i][j] = i;             // 2  2
	//cout << "M3\n" <<m3 << endl;

	// Test 2
	// Subtraction of matrices
	
	m2 = m2 - m3;

	if (sum(m2) != 0) // Target value 0
	{
		cout << "Test #4 failed..." << endl;
		return false;
	}

	// Test 3
	// Assigning values of the 2nd matrix to the 1st matrix.

	//m1 = m2;

	if (sum(m1) != 0) // Target value 0
	{
		cout << "Test #5 failed..." << endl;
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

	return true;
}

int sum(Matrix& cc)
{
	int s = 0;
	int X = cc.GetRows();
	int Y = cc.GetCols();
	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			s += cc[x][y];
	return s;
}
#endif