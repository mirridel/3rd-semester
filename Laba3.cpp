#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;

//------ Вариант #4 ------

void main()
{
	Matrix mtx1(4), mtx2(2), mtx3(4);
	
	//mtx1.PushMatrix();
	//mtx2.PushMatrix();
	//mtx3.PushMatrix();

	Matrix::ReadFromFile(mtx1);
	Matrix::ReadFromFile(mtx2);
	Matrix::ReadFromFile(mtx3);

	//Matrix::WriteToFile(mtx1);
	//Matrix::WriteToFile(mtx2);
	//Matrix::WriteToFile(mtx3);

	cout << mtx1 << endl;
	cout << mtx2 << endl;
	cout << mtx3 << endl;
};