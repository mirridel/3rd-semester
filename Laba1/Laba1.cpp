#include <iostream>
#include "matrix.h"

using std::cout; 
using std::endl;

//------ Вариант #4 ------

bool test() // Тесты(?)
{
	bool result = true;

	cout << "Test... Start..." << endl;

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
		cout << "#3_1 passed..." << endl;
	else
	{
		cout << "#3_1 failed..." << endl;
		return false;
	}

	// Сложение матриц с отрицательными размерами

	Matrix matrixT3n3(-1);
	Matrix matrixT3n4(-1);
	if (!matrixT3n3.AdditionMatrix(matrixT3n4))
		cout << "#3_2 passed..." << endl;
	else
	{
		cout << "#3_2 failed..." << endl;
		return false;
	}

	// Test #4
	// Вычитание матриц с положительными размерами

	Matrix matrixT4n1(3);
	Matrix matrixT4n2(3);
	if (matrixT4n1.AdditionMatrix(matrixT4n2))
		cout << "#4_1 passed..." << endl;
	else
	{
		cout << "#4_1 failed..." << endl;
		return false;
	}

	// Вычитание матриц с отрицательными размерами
	
	Matrix matrixT4n3(-1);
	Matrix matrixT4n4(-1);
	if (!matrixT4n3.AdditionMatrix(matrixT4n4))
		cout << "#4_2 passed..." << endl;
	else
	{
		cout << "#4_2 failed..." << endl;
		return false;
	}

	// Test #5
	// Транспонирование матрицы с положительным размером

	Matrix matrixT5n1(3);
	if (Matrix::TransposeMatrix(matrixT5n1))
		cout << "#5_1 passed..." << endl;
	else
	{
		cout << "#5_1 failed..." << endl;
		return false;
	}

	// Транспонирование матрицы с отрицательными размером
	
	Matrix matrixT5n2(-1);
	if (!Matrix::TransposeMatrix(matrixT5n2))
		cout << "#5_2 passed..." << endl;
	else
	{
		cout << "#5_2 failed..." << endl;
		return false;
	}

	return true;
}

void main()
{
	bool T = test();

	if (T) cout << "Test passed..." << endl;
	else cout << "Test failed..." << endl;

	const int size = 3;

	char** str;

	// Заполняем матрицы случайными числами

	Matrix mtx1(size);
	mtx1.PushMatrix();

	Matrix mtx2(size);
	mtx2.PushMatrix();

	Matrix mtx3(size);
	mtx3.PushMatrix();

	cout << "Original Matrix\n\n"; // Оригинальные матрицы

	str = mtx1.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	str = mtx2.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	str = mtx3.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	cout << "Transpose Matrix\n\n"; // Транспонирование
	Matrix::TransposeMatrix(mtx1);
	str = mtx1.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	Matrix::TransposeMatrix(mtx2);
	str = mtx2.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	Matrix::TransposeMatrix(mtx3);
	str = mtx3.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	std::cout << "Addition Matrix\n\n"; // Сложение матриц
	
	str = mtx1.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	str = mtx2.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	mtx1.AdditionMatrix(mtx2);
	str = mtx1.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	cout << mtx1.GetData(1, 1) << endl;

	mtx1.SetData(1, 1, 128);

	std::cout << "Substraction Matrix\n\n"; // Вычитание матриц

	str = mtx1.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	str = mtx3.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";

	mtx1.SubstractionMatrix(mtx3);
	str = mtx1.toString();
	for (size_t i = 0; i < size; i++)
		cout << str[i] << "\n";
	cout << "\n";
};