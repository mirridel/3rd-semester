#include <iostream>
#include "matrix.h"

	Matrix::Matrix(int size) // Вызов конструктора
	{
		this->size = size;

		matrix = new double* [size];

		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
	}

	Matrix::Matrix(double** qq, int n)
	{
		size = n;

		matrix = new double* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new double[size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = qq[i][j];
	}

	Matrix::Matrix(const Matrix &other) // Конструктор копирования
	{
		this->size = other.size;

		matrix = new double* [this->size];
		for (int i = 0; i < this->size; i++)
			matrix[i] = new double[this->size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = other.matrix[i][j];
	}

	void Matrix::PushMatrix()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = rand() % 10;
	}

	void Matrix::PrintMatrix()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				std::cout << matrix[i][j] << " ";

			std::cout << "\n";
		}
		std::cout << "\n";
	}

	double Matrix::determinant()
	{
		Matrix A(*this);
		double result = 1;
		if (size == 1) return matrix[0][0];
		if (size == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		else
		{
			int k = 0;
			while (matrix[0][k] == 0) k++;
			if (k == size) return 0;
			else
				return  pow(-1, k) * A.GausStep(0, k).matrix[0][k] * (A.GausStep(0, k).Minor(0, k)).determinant();
		}
	}

	Matrix Matrix::Minor(const int p, const  int q)
	{
		double** minor = new double* [size - 1];
		for (int i = 0; i < size - 1; i++) minor[i] = new double[size - 1];

		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < q; j++)
				minor[i][j] = matrix[i][j];
			for (int j = q; j < size - 1; j++)
				minor[i][j] = matrix[i][j + 1];
		}

		for (int i = p; i < size - 1; i++)
		{
			for (int j = q; j < size - 1; j++)
				minor[i][j] = matrix[i + 1][j + 1];
			for (int j = 0; j < q; j++)
				minor[i][j] = matrix[i + 1][j];
		}

		Matrix result(minor, size - 1);

		for (int i = 0; i < size - 1; i++)
			delete[] minor[i];
		delete[] minor;

		return result;
	}

	Matrix Matrix::GausStep(int p, int q)
	{
		double** result = new double* [size];
		for (int i = 0; i < size; i++) result[i] = new double[size];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				result[i][j] = matrix[i][j];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (i != p)
					result[i][j] = matrix[i][j] - (matrix[p][j] * matrix[i][q] / matrix[p][q]);
			}

		Matrix A(result, size);

		for (int i = 0; i < size; i++)
			delete[] result[i];
		delete[] result;

		return A;
	}

	Matrix Matrix::ReverseMatrix()
	{
		Matrix qq(size);
		if (determinant() != 0)
		{
			double Det = determinant();
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					qq.matrix[i][j] = Minor(i, j).determinant() * pow(-1, i + j) / Det;
		}
		return qq.Tr();
	}

	Matrix Matrix::Tr()
	{
		Matrix qq(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				qq[i][j] = matrix[j][i];
		return qq;
	}

	double Matrix::operator()()
	{
		return determinant();
	}

	double& Matrix::operator()(int i, int j)
	{
		return (matrix[i][j]);
	}

	Matrix& Matrix::operator=(const Matrix& other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix& Matrix::operator+(const Matrix &other)
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
		else std::cout << "Matrixes of different sizes. Addition is not possible." << std::endl;
		return *this;
	}

	Matrix& Matrix::operator-(const Matrix &other)
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
		else std::cout << "Matrixes of different sizes. Substraction is not possible." << std::endl;
		return *this;
	}

	Matrix::~Matrix()
	{
		for (int i = 0; i < size; i++)
			delete[] matrix[i];

		delete[] matrix;
	}