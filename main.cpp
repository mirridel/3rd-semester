#include <iostream>
#include "matrix.h"
#include "test.h"

using std::cout;
using std::endl;

//------ Variant #4 ------

int main()
{
	bool T = test();
	if (T)
		cout << "Test passed..." << endl;
	else cout << "Test failed..." << endl;

	Matrix mtx1(3), mtx2(3), mtx3(3);

	mtx1.pushMatrix();
	mtx2.pushMatrix();
	mtx3.pushMatrix();

	std::cout << "Original Matrix\n\n"; // Original matrices
	cout << mtx1.toString() << endl;
	cout << "Determinant:\t" << mtx1() << "\n\n";
	cout << mtx2.toString() << endl;
	cout << "Determinant:\t" << mtx2() << "\n\n";
	cout << mtx3.toString() << endl;
	cout << "Determinant:\t" << mtx3() << "\n\n";

	std::cout << "Addition Matrix\n\n"; // Addition of matrices
	mtx1 = mtx1 + mtx2;
	cout << mtx1.toString() << endl;

	std::cout << "Substraction Matrix\n\n"; // Subtraction of matrices
	mtx1 = mtx1 - mtx3;
	cout << mtx1.toString() << endl;

	std::cout << "A(1, 1)\t " << mtx1(1, 1) << std::endl;

	return 0;
};