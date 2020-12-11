#include "matrix.h"

#ifndef RECTANGULAR_MATRIX_H
#define RECTANGULAR_MATRIX_H

class RectangularMatrix : public Matrix
{
public:
	RectangularMatrix(const int rows, const int cols);
	RectangularMatrix(const Matrix& cc) : Matrix(cc) {};
	RectangularMatrix(const RectangularMatrix& cc) : Matrix(cc) {};
	~RectangularMatrix() {};

	char* ToString() override;

	RectangularMatrix&
		operator=(const RectangularMatrix& other);

	friend RectangularMatrix&
		operator+(RectangularMatrix& first,
			RectangularMatrix& second);

	friend RectangularMatrix&
		operator-(RectangularMatrix& first,
			RectangularMatrix& second);

	friend RectangularMatrix&
		operator*(RectangularMatrix& first,
			RectangularMatrix& second);
};

#endif