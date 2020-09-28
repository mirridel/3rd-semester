#include <iostream>
#include "matrix.h"

//------ Вариант #4 ------

void main()
{
	Matrix mtx1(4), mtx2(2), mtx3(4);

	mtx1.PushMatrix();
	mtx2.PushMatrix();
	mtx3.PushMatrix();

	std::cout << "Original Matrix\n\n"; // Оригинальная матрица
	mtx1.PrintMatrix();
	std::cout << "detA= " << mtx1() << "\n\n";
	mtx2.PrintMatrix();
	std::cout << "detB= " << mtx2() << "\n\n";
	mtx3.PrintMatrix();
	std::cout << "detC= " << mtx3() << "\n\n";

	std::cout << "\nAddition Matrix\n\n"; // Сложение матриц
	mtx1 = mtx1 + mtx2;
	mtx1.PrintMatrix();

	std::cout << "\nSubstraction Matrix\n\n"; // Вычитание матриц
	mtx1 = mtx1 - mtx3;
	mtx1.PrintMatrix();

	std::cout << "A(1,1)= " << mtx1(1, 1) << std::endl;
};