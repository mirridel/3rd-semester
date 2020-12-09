#include <iostream>
#include "matrix.h"
#include "identityMatrix.h"
#include "rectangularMatrix.h"
#include "test.h"

//------ Вариант #4 ------

void test();

int main()
{
	test();

	std::fstream File("text.txt", std::ios_base::out | std::ios_base::in);
	std::fstream BinFile("file.dat", std::ios_base::out | std::ios_base::in | std::ios_base::binary);

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
	cout << m1 << "\n" << m2 << "\n" << m3 << endl;

	File << m1;
	m2.WriteToBinFile(BinFile);

	cout << "squareMatrix = squareMatrix + identityMatrix" << endl;
	squareMatrix = squareMatrix + identityMatrix;
	cout << squareMatrix << endl;

	cout << "m2 = m2 + m3;" << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	m2 = m2 + m3;
	cout << m2 << endl;

	cout << "m2 = m2 - m3;" << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	m2 = m2 - m3;
	cout << m2 << endl;

	cout << "m1 = m1 * m2" << endl;
	m1 = m1 * m2;
	cout << m1 << endl;

	return 0;
};

void test()
{
	if (test1())
		cout << "Test passed #1 (+)" << endl;
	else cout << "Test failed #1 (+)" << endl;

	if (test2())
		cout << "Test passed #2 (-)" << endl;
	else cout << "Test failed #2 (-)" << endl;

	if (test3())
		cout << "Test passed #3 (*)" << endl;
	else cout << "Test failed #3 (*)" << endl;

	if (test4())
		cout << "Test passed #4 (=)" << endl;
	else cout << "Test failed #4 (=)" << endl;
}