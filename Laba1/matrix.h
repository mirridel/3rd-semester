#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:

	Matrix(int size); // Конструктор

	Matrix(const Matrix &other); // Конструктор копирования

	~Matrix(); // Деструктор

	bool SetData(int x, int y, int data); // Сеттер, который позволяет установить данные для одной ячейки
	
	int GetData(int x, int y); // Геттер, который позволяет получить данные из одной ячейки

	bool PushMatrix(); // Заполнение матрицы случайными числами

	char* toString(); // Выводим матрицу в char

	static bool TransposeMatrix(Matrix &other); // Транспонирование матрицы

	bool AdditionMatrix(Matrix &other); // Сложение матриц

	bool SubstractionMatrix(Matrix &other); // Вычитание матриц

private:

	int size; // Размер матрицы
	int** matrix; // Матрица
};

#endif