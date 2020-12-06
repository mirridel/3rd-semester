#include "rectangularMatrix.h"

RectangularMatrix::
RectangularMatrix(const int rows, const int cols) {
	this->rows = rows;
	this->cols = cols;
	CreateMatrix(rows, cols);
	FillMatrix();
};

RectangularMatrix& RectangularMatrix::
operator=(const RectangularMatrix& second)
{
	if (this->cols == second.cols &&
		this->rows == second.rows &&
		this->cols > 0 && this->rows > 0 &&
		second.cols > 0 && second.rows > 0)
	{
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->cols; j++)
				this->matrix[i][j] = second.matrix[i][j];
	}
	return *this;
}

RectangularMatrix& operator+(RectangularMatrix& first, RectangularMatrix& second)
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
};

RectangularMatrix& operator-(RectangularMatrix& first, RectangularMatrix& second)
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
};

RectangularMatrix& operator*(RectangularMatrix& first, RectangularMatrix& second)
{
	if ((first.cols == second.rows) &&
		(first.cols > 0 && first.rows > 0) &&
		(second.cols > 0 && second.rows > 0))
	{
		int X = first.rows;
		int Y = second.cols;

		RectangularMatrix buffer(X, Y);
		for (int i = 0; i < X; i++)
			for (int j = 0; j < Y; j++)
				buffer.matrix[i][j] = 0;

		for (int a = 0; a < X; a++) {
			for (int b = 0; b < Y; b++) {
				int buff = 0;
				for (int i = 0; i < first.cols; i++)
					buff += first.matrix[a][i] * second.matrix[i][b];
				buffer.matrix[a][b] = buff;
			}
		}

		for (int i = 0; i < first.rows; i++)
			delete[] first.matrix[i];
		delete[] first.matrix;
		
		first.SetRows(X); first.SetCols(Y);
		first.matrix = new int* [first.rows];
		for (int i = 0; i < first.rows; i++)
			first.matrix[i] = new int[first.cols];

		for (int i = 0; i < first.rows; i++)
			for (int j = 0; j < first.cols; j++)
				first.matrix[i][j] = buffer.matrix[i][j];
	}

	return *&first;
};