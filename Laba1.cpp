#include <iostream>
#include "matrix.h"

//------ Вариант #4 ------

bool test() // Тесты(?)
{
	bool result = true;

	std::cout << "Test... Start..." << std::endl;

	// Test #1
	// Создание матрицы отрицательного размера

	Matrix matrixT1(-1);

	// Test #2
	// Копирование отрицательной матрицы с помощью конструктора

	Matrix matrixT2(matrixT1);

	// Test #3
	// Сложение матриц с положительными размерами

	Matrix matrixT3n1(3);
	Matrix matrixT3n2(3);
	if (matrixT3n1.AdditionMatrix(matrixT3n2))
		std::cout << "#3_1 passed..." << std::endl;
	else
	{
		std::cout << "#3_1 failed..." << std::endl;
		return false;
	}

	// Сложение матриц с отрицательными размерами

	Matrix matrixT3n3(-1);
	Matrix matrixT3n4(-1);
	if (!matrixT3n3.AdditionMatrix(matrixT3n4))
		std::cout << "#3_2 passed..." << std::endl;
	else
	{
		std::cout << "#3_2 failed..." << std::endl;
		return false;
	}

	// Test #4
	// Вычитание матриц с положительными размерами

	Matrix matrixT4n1(3);
	Matrix matrixT4n2(3);
	if (matrixT4n1.AdditionMatrix(matrixT4n2))
		std::cout << "#4_1 passed..." << std::endl;
	else
	{
		std::cout << "#4_1 failed..." << std::endl;
		return false;
	}

	// Вычитание матриц с отрицательными размерами
	
	Matrix matrixT4n3(-1);
	Matrix matrixT4n4(-1);
	if (!matrixT4n3.AdditionMatrix(matrixT4n4))
		std::cout << "#4_2 passed..." << std::endl;
	else
	{
		std::cout << "#4_2 failed..." << std::endl;
		return false;
	}

	// Test #5
	// Транспонирование матрицы с положительным размером

	Matrix matrixT5n1(3);
	if (Matrix::TransposeMatrix(matrixT5n1))
		std::cout << "#5_1 passed..." << std::endl;
	else
	{
		std::cout << "#5_1 failed..." << std::endl;
		return false;
	}

	// Транспонирование матрицы с отрицательными размером
	
	Matrix matrixT5n2(-1);
	if (!Matrix::TransposeMatrix(matrixT5n2))
		std::cout << "#5_2 passed..." << std::endl;
	else
	{
		std::cout << "#5_2 failed..." << std::endl;
		return false;
	}

	return true;
}

void main()
{
	bool T = test();

	if (T) std::cout << "Test passed..." << std::endl;
	else std::cout << "Test failed..." << std::endl;

	Matrix mtx1(3);
	mtx1.PushMatrix();

	Matrix mtx2(3);
	mtx2.PushMatrix();

	Matrix mtx3(3);
	mtx3.PushMatrix();

	std::cout << "Original Matrix\n\n"; // Оригинальная матрица
	
	mtx1.toString();
	mtx2.toString();
	mtx3.toString();

	std::cout << "Transpose Matrix\n\n"; // Транспонирование
	Matrix::TransposeMatrix(mtx1);
	mtx1.toString();
	Matrix::TransposeMatrix(mtx2);
	mtx2.toString();
	Matrix::TransposeMatrix(mtx3);
	mtx3.toString();

	std::cout << "Addition Matrix\n\n"; // Сложение матриц
	mtx1.toString();
	mtx2.toString();

	mtx1.AdditionMatrix(mtx2);
	mtx1.toString();

	mtx1.SetData(1, 1, 128);

	std::cout << "Substraction Matrix\n\n"; // Вычитание матриц
	
	mtx1.toString();
	mtx3.toString();

	mtx1.SubstractionMatrix(mtx3);
	mtx1.toString();
};