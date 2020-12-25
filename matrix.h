#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;

class Matrix
{
public:

	Matrix();
	Matrix(int size); // Конструктор
	Matrix(const Matrix &other); // Конструктор копирования
	~Matrix(); // Деструктор

	friend std::ostream& operator<< (std::ostream& os, Matrix& cc);
	friend std::fstream& operator<< (std::fstream& ofs, Matrix& cc);
	friend std::istream& operator>> (std::istream& is, Matrix& cc);
	friend std::fstream& operator>> (std::fstream& ifs, Matrix& cc);

	bool SetData(int x, int y, int data); // Сеттер, который позволяет установить данные для одной ячейки
	int GetData(int x, int y); // Геттер, который позволяет получить данные из одной ячейки

	char* toString(); // Выводим матрицу в char

	static bool TransposeMatrix(Matrix &other); // Транспонирование матрицы
	bool AdditionMatrix(Matrix &other); // Сложение матриц
	bool SubstractionMatrix(Matrix &other); // Вычитание матриц

private:

	int size; // Размер матрицы
	int** matrix; // Матрица
};

#endif