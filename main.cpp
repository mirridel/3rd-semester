#include <iostream>
#include "matrix.h"
#include "test.h"

using std::cout;
using std::endl;

//------ ������� #4 ------

int main()
{
	bool T = test();
	if (T)
		cout << "Test passed..." << endl;
	else cout << "Test failed..." << endl;

	Matrix mtx1(3), mtx2(3), mtx3(3);

	mtx1.PushMatrix();
	mtx2.PushMatrix();
	mtx3.PushMatrix();

	std::cout << "Original Matrix\n\n"; // ������������ �������
	cout << mtx1.ToString() << endl;
	cout << "Determinant:\t" << mtx1() << "\n\n";
	cout << mtx2.ToString() << endl;
	cout << "Determinant:\t" << mtx2() << "\n\n";
	cout << mtx3.ToString() << endl;
	cout << "Determinant:\t" << mtx3() << "\n\n";

	std::cout << "Addition Matrix\n\n"; // �������� ������
	mtx1 = mtx1 + mtx2;
	cout << mtx1.ToString() << endl;

	std::cout << "Substraction Matrix\n\n"; // ��������� ������
	mtx1 = mtx1 - mtx3;
	cout << mtx1.ToString() << endl;

	std::cout << "A(1, 1)\t " << mtx1(1, 1) << std::endl;

	return 0;
};