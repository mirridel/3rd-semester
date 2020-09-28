#include <iostream>
#include "matrix.h"

using namespace std;

	Matrix::Matrix(int size) // ����� ������������
	{
		std::cout << "COSTRUCT\t" << this << std::endl;

		this->size = size;

		matrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
	}

	Matrix::Matrix(const Matrix &other) // ����� ������������ �����������
	{
		std::cout << "CPY_COSTRUCT\t" << this << std::endl;

		this->size = other.size;

		matrix = new int* [this->size];

		for (int i = 0; i < this->size; i++)
		{
			matrix[i] = new int[this->size];
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

	double Matrix::det(int rows)
	{

		int **arr = new int* [rows];

		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[rows];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = matrix[i][j];
			}
		}

		double opr1, sum;
		//-------------------------------------------------------------------------------------//
		//�������� ������� � ������� ������� 

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				arr[i][j + rows] = arr[i][j];
			}
		}
		//-----------------------------------------------------------------------------------------//   
		// ������� ������������ �������� ������� �+�+�-�-�-�  
		opr1 = 0;

		// ����� ������� ��� 1 ����� ��������� ��� ����� ���� ��������� n ��� �� k=n
		for (int k = 0; k < rows; k++) {
			sum = 1;
			for (int i = 0; i < rows; i++) {
				sum *= arr[i][i + k];
			}
			opr1 += sum;
		}
		// ����� ������� ��� 2 ����� �������� ��������� ��� ������ ��������� n-1 ��� �� k=n-1
		for (int k = 0; k < rows; k++) {
			sum = 1;
			for (int i = 0; i < rows; i++) {
				sum *= arr[i][rows - i - 1 + k];
			}
			opr1 -= sum;
		}

		return opr1;
	};

	Matrix& Matrix::operator()()
	{

		return *this;
	}

	int& Matrix::operator()(int i, int j)
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
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] += other.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix& Matrix::operator-(const Matrix &other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] -= other.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix::~Matrix()
	{
		//std::cout << "DECOSTRUCT\t" << this << std::endl;

		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i];
		}
		delete[] this->matrix;
	}