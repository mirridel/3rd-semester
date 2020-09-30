#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:

	Matrix(int size); // Конструктор

	Matrix(const Matrix &other); // Конструктор копирования

	~Matrix(); // Деструктор

	bool SetData(int, int, int); // Сеттер, который позволяет установить данные для одной ячейки
	
	int GetData(int, int); // Геттер, который позволяет получить данные из одной ячейки

	bool PushMatrix(); // Заполнение матрицы случайными числами

	void toString(); // Выводим матрицу в типе char

	void toInt(); // Выводим матрицу в типе int

	static bool TransposeMatrix(Matrix &other); // Транспонирование матрицы

	bool AdditionMatrix(Matrix &other); // Сложение матриц

	bool SubstractionMatrix(Matrix &other); // Вычитание матриц

private:

	int size; // Размер матрицы
	int** matrix; // Матрица
	char** str; // Строковое представление матрицы
};

#endif