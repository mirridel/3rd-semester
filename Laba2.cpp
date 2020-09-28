#include <iostream>
#include "matrix.h"

//------ Вариант #4 ------

void main()
{
	Matrix mtx1(4), mtx2(4), mtx3(4);

	mtx1.PushMatrix();
	mtx2.PushMatrix();
	mtx3.PushMatrix();

	std::cout << "Original Matrix\n\n"; // Оригинальная матрица
	mtx1.PrintMatrix();
	std::cout <<"\nTranspose Matrix\n\n"; // Транспонирование
	Matrix::TransposeMatrix(mtx1);
	mtx1.PrintMatrix();
	std::cout << "\nAddition Matrix\n\n"; // Сложение матриц
	mtx1.PrintMatrix();
	std::cout << "\n";
	mtx2.PrintMatrix();
	mtx1.AdditionMatrix(mtx2);
	std::cout << "\n";
	mtx1.PrintMatrix();
	std::cout << "\nSubstraction Matrix\n\n"; // Вычитание матриц
	mtx1.PrintMatrix();
	std::cout << "\n";
	mtx3.PrintMatrix();
	std::cout << "\n";
	mtx1.SubstractionMatrix(mtx3);
	mtx1.PrintMatrix();
};