#include <iostream>
#include "matrix.h"
#include "identityMatrix.h"
#include "rectangularMatrix.h"
#include "test.h"

//------ Вариант #4 ------

int main()
{
	/*
	bool T = test();
	if (T)
		cout << "Test passed...\n" << endl;
	else cout << "Test failed...\n" << endl;
	*/
	cout << "Square matrix:" << endl;
	Matrix squareMatrix(3);
	cout << squareMatrix << endl;

	cout << "Identity matrix:" << endl;
	IdentityMatrix identityMatrix(3);
	cout << identityMatrix << endl;

	cout << "Rectangular matrices:" << endl;
	RectangularMatrix m1(2, 3);
	RectangularMatrix m2(3, 2);
	RectangularMatrix m3(3, 2);
	cout << m1 << "\n" << m2 << endl;

	cout << "squareMatrix = squareMatrix + identityMatrix" << endl;
	squareMatrix = squareMatrix + identityMatrix;
	cout << squareMatrix << endl;

	cout << "m1 = m1 + m2;" << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	m2 = m2 + m3;
	cout << m2 << endl;

	cout << "m1 = m1 - m2;" << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	m2 = m2 - m3;
	cout << m2 << endl;

	cout << "m1 = m1 * m2" << endl;
	m1 = m1 * m2;
	cout << m1 << endl;
	return 0;
};