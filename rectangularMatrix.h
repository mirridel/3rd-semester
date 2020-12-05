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

	RectangularMatrix&
		operator=(const RectangularMatrix& other);

	// Friendly operator for addition
	friend RectangularMatrix&
		operator+(RectangularMatrix& first,
			RectangularMatrix& second);

	// Friendly operator for subtraction
	friend RectangularMatrix&
		operator-(RectangularMatrix& first,
			RectangularMatrix& second);

	friend RectangularMatrix&
		operator*(RectangularMatrix& first,
			RectangularMatrix& second);
};

#endif