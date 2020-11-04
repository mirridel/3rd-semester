#include <iostream>
#include "matrix.h"
#include "test.h"

using std::cout; using std::endl;

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

	std::cout << "Original Matrix\n" << endl; // Originals Matrices
	cout << mtx1.toString() << "\nDeterminant:\t" << mtx1() << "\n\n";
	cout << mtx2.toString() << "\nDeterminant:\t" << mtx2() << "\n\n";
	cout << mtx3.toString() << "\nDeterminant:\t" << mtx3() << "\n\n";

	std::cout << "Addition Matrix\n" << endl; // Addition Matrices
	mtx1 = mtx1 + mtx2;
	cout << mtx1.toString() << endl;

	std::cout << "Substraction Matrix\n" << endl; //Substraction Matrices
	mtx1 = mtx1 - mtx2;
	cout << mtx1.toString() << endl;

	double subNum = mtx1[1][1];
	mtx1[1][1] = 1024;
	cout << "Change " << subNum << " on " << mtx1[1][1] << endl;
	cout << mtx1.toString() << endl;

	return 0;
};