#include <iostream>
#include "matrix.h"

//------ Вариант #4 ------

bool test() // Тесты(?)
{
	Matrix mtx1(4), mtx2(4), mtx3(4);

	mtx1.PushMatrix();
	mtx2.PushMatrix();
	mtx3.PushMatrix();

	Matrix::TransposeMatrix(mtx1);
	
	mtx1.AdditionMatrix(mtx2);
	
	mtx1.SubstractionMatrix(mtx3);
	
	return true;
}

void main()
{
	bool T = test();

	if (T != true) std::cout << "Test failed..." << std::endl;
	else std::cout << "Test passed..." << std::endl;

	Matrix mtx1(3), mtx2(3), mtx3(4);

	mtx1.PushMatrix();
	mtx2.PushMatrix();
	mtx3.PushMatrix();

	std::cout << "Original Matrix\n\n"; // Оригинальная матрица
	mtx1.PrintMatrix();
	mtx2.PrintMatrix();
	mtx3.PrintMatrix();

	std::cout << "Transpose Matrix\n\n"; // Транспонирование
	Matrix::TransposeMatrix(mtx1);
	mtx1.PrintMatrix();
	Matrix::TransposeMatrix(mtx2);
	mtx2.PrintMatrix();

	std::cout << "Addition Matrix\n\n"; // Сложение матриц
	mtx1.PrintMatrix();
	mtx2.PrintMatrix();

	mtx1.AdditionMatrix(mtx2);
	mtx1.PrintMatrix();

	std::cout << "Substraction Matrix\n\n"; // Вычитание матриц
	
	mtx1.PrintMatrix();
	mtx3.PrintMatrix();

	mtx1.SubstractionMatrix(mtx3);
	mtx1.PrintMatrix();
};