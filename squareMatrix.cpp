#define _CRT_SECURE_NO_WARNINGS
#include "squareMatrix.h"

char* SquareMatrix::ToString()
{
	if (size > 0)
	{
		//cout << "Square Matrix" << endl;
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

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& second)
{
	if (this->cols == second.cols &&
		this->rows == second.rows &&
		this->cols > 0 && this->rows > 0 &&
		second.cols > 0 && second.rows > 0)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = second.matrix[i][j];
	}
	return *this;
}

SquareMatrix& operator+(SquareMatrix& first, const SquareMatrix& second)
{
	if ((first.cols == second.cols) &&
		(first.rows == second.rows) &&
		(first.cols > 0 && first.rows > 0) &&
		(second.cols > 0 && second.rows > 0))
	{
		for (int i = 0; i < first.rows; i++)
			for (int j = 0; j < first.cols; j++)
				first.matrix[i][j] += second.matrix[i][j];
	}
	return *&first;
}

SquareMatrix& operator-(SquareMatrix& first, const SquareMatrix& second)
{
	if ((first.cols == second.cols) &&
		(first.rows == second.rows) &&
		(first.cols > 0 && first.rows > 0) &&
		(second.cols > 0 && second.rows > 0))
	{
		for (int i = 0; i < first.rows; i++)
			for (int j = 0; j < first.cols; j++)
				first.matrix[i][j] -= second.matrix[i][j];
	}
	return *&first;
}