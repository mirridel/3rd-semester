#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "matrix.h"

	Matrix::Matrix(int size)
	{
		if (size > 0)
		{
			this->size = size;

			matrix = new int* [size];
			for (int i = 0; i < size; i++)
				matrix[i] = new int[size];
		}
	}

	Matrix::Matrix(const Matrix &other)
	{
		if ( other.size > 0 )
		{
			this->size = other.size;

			this->matrix = new int* [size];
			for (int i = 0; i < size; i++)
				matrix[i] = new int[size];

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					matrix[i][j] = other.matrix[i][j];
		}
	}

	bool Matrix::PushMatrix()
	{
		if (this->size != 0)
		{
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					matrix[i][j] = rand() % 10;

		}
		else std::cout << "Matrix doesn't exist" << std::endl;

		return true;
	}

	char* Matrix::toString()
	{
		if (this->size != 0)
		{
			char* buff = new char [128];

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

	bool Matrix::SetData(int x, int y, int data)
	{
		std::cout << "A["<< x <<","<< y <<"] = "<< data << std::endl;

		if (( x > 0 && x < size) && ( y > 0 && y < size ))
			this->matrix[x][y] = data;

		return true;
	}

	int Matrix::GetData(int x, int y)
	{
		int data = 0;
		if ((x > 0 && x < size) && (y > 0 && y < size))
			data = this->matrix[x][y];

		return data;
	}

	bool Matrix::TransposeMatrix(Matrix &other)
	{
		if (other.size > 0)
		{
			int size = other.size;

			int** subMatrix = new int* [size];
			for (int i = 0; i < size; i++)
				subMatrix[i] = new int[size];

			for (int j = 0; j < size; j++)
				for (int i = 0; i < size; i++)
					subMatrix[i][j] = other.matrix[j][i];

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					other.matrix[i][j] = subMatrix[i][j];

			for (int i = 0; i < size; i++)
				delete[] subMatrix[i];
			delete[] subMatrix;

			return true;
		}
		else return false;
	}

	bool Matrix::AdditionMatrix(Matrix &other)
	{
		if (this->size == other.size && (other.size > 0 && this->size > 0))
		{
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					this->matrix[i][j] += other.matrix[i][j];

			return true;
		}
		else return false;
	}

	bool Matrix::SubstractionMatrix(Matrix &other)
	{
		if (this->size == other.size && (other.size > 0 && this->size > 0))
		{
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					this->matrix[i][j] -= other.matrix[i][j];

			return true;
		}
		else return false;
	}

	Matrix::~Matrix()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] this->matrix[i];
		}
		delete[] this->matrix;
	}