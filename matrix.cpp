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
		std::cout << "\n";
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

	int Matrix::AdditionMatrix(Matrix &other)
	{
		if (this->size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					this->matrix[i][j] += other.matrix[i][j];
				}
			}
		}
		else
		{
			std::cout << "Matrixes of different sizes. Addition is not possible." << std::endl;
			return 1;
		}
	}

	int Matrix::SubstractionMatrix(Matrix &other)
	{
		if (this->size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					this->matrix[i][j] -= other.matrix[i][j];
				}
			}
		}
		else
		{
			std::cout << "Matrixes of different sizes. Substraction is not possible." << std::endl;
			return 1;
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