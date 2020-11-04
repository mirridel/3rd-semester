#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;

Matrix::Matrix(int size)
{
	this->size = size;
	//cout << "C\t" << this << endl;
	if (this->size > 0)
	{
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
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

Matrix::Matrix(const Matrix& other)
{
	if (other.size > 0)
	{
		this->size = other.size;

		this->matrix = new double* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new double[size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = other.matrix[i][j];
	}
}

void Matrix::pushMatrix()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 10;
}

char* Matrix::toString()
{
	if (size != 0)
	{
		char* buff = new char[128];

		buff[0] = '\0';

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				char subBuff[16] = "";
				_itoa(matrix[i][j], subBuff, 10);
				strcat(subBuff, "\t");
				strcat(buff, subBuff);
			}
			strcat(buff, "\n");
		}
		return buff;
	}
}

double Matrix::determinant()
{
	if (this->size > 0)
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
				return  pow(-1, k) * A.gausStep(0, k).matrix[0][k] * (A.gausStep(0, k).minor(0, k)).determinant();
		}
	}
}

Matrix Matrix::minor(const int p, const  int q)
{
	double** m = new double* [size - 1];
	for (int i = 0; i < size - 1; i++) m[i] = new double[size - 1];

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
			m[i][j] = matrix[i][j];
		for (int j = q; j < size - 1; j++)
			m[i][j] = matrix[i][j + 1];
	}

	for (int i = p; i < size - 1; i++)
	{
		for (int j = q; j < size - 1; j++)
			m[i][j] = matrix[i + 1][j + 1];
		for (int j = 0; j < q; j++)
			m[i][j] = matrix[i + 1][j];
	}

	Matrix result(m, size - 1);

	for (int i = 0; i < size - 1; i++)
		delete[] m[i];
	delete[] m;

	return result;
}

Matrix Matrix::gausStep(int p, int q)
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

Matrix Matrix::reverseMatrix()
{
	Matrix qq(size);
	if (determinant() != 0)
	{
		double Det = determinant();
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				qq.matrix[i][j] = minor(i, j).determinant() * pow(-1, i + j) / Det;
	}
	return qq.tr();
}

Matrix Matrix::tr()
{
	Matrix qq(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			qq[i][j] = matrix[j][i];
	return qq;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this->size == other.size && this->size > 0 && other.size > 0)
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
	return *this;
}

Matrix& operator+(Matrix& first, const Matrix& second)
{
	if (first.size == second.size && first.size > 0 && second.size > 0)
	{
		for (int i = 0; i < first.size; i++)
			for (int j = 0; j < first.size; j++)
				first.matrix[i][j] += second.matrix[i][j];

		return *&first;
	}
}

Matrix& operator-(Matrix& first, const Matrix& second)
{
	if (first.size == second.size && first.size > 0 && second.size > 0)
	{
		for (int i = 0; i < first.size; i++)
			for (int j = 0; j < first.size; j++)
				first.matrix[i][j] -= second.matrix[i][j];

		return *&first;
	}
}

Matrix::~Matrix()
{
	//cout << "D\t" << this << endl;
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}