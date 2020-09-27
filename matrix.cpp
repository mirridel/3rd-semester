#include <iostream>
#include "matrix.h"

	Matrix::Matrix(int size) // Вызов конструктора
	{
		this->size = size;

		matrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
	}

	Matrix::Matrix(const Matrix &other) // Вызов конструктора копирования
	{
		this->matrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
	}

	void Matrix::PushMatrix()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = rand() % 10;
			}
		}
	}

	void Matrix::PrintMatrix()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	void Matrix::TransposeMatrix(Matrix &other)
	{
		int size = other.size;

		int** subMatrix;

		subMatrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			subMatrix[i] = new int[size];
		}

		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size; i++)
			{
				subMatrix[i][j] = other.matrix[j][i];
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				other.matrix[i][j] = subMatrix[i][j];
			}
		}

		for (int i = 0; i < size; i++)
		{
			delete[] subMatrix[i];
		}
		delete[] subMatrix;
	}

	void Matrix::AdditionMatrix(Matrix &other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] += other.matrix[i][j];
			}
		}
	}

	void Matrix::SubstractionMatrix(Matrix &other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] -= other.matrix[i][j];
			}
		}
	}

	Matrix::~Matrix()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] this->matrix[i];
		}
		delete[] this->matrix;
	}