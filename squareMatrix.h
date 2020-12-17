#include "matrix.h"

#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

class SquareMatrix : public Matrix {
public:

	SquareMatrix(const int size) : Matrix(size) { this->size = size; };
	SquareMatrix(const SquareMatrix& cc) : Matrix(cc) { this->size = cc.size; };

	void PrintName() override { cout << "Square Matrix" << endl; };
	char* ToString() override; // Function that returns a matrix as a string
	int GetCountElements() override { return size * size; };
	//Getters and setters
	int GetSize() { return size; };
	void SetSize(const int size)
	{
		Matrix::SetCols(size);
		Matrix::SetRows(size);
		this->size = size;
	};
	
	// Operators
	SquareMatrix& operator=(const SquareMatrix& other);
	friend SquareMatrix& operator+(SquareMatrix& first, const SquareMatrix& second); // Friendly operator for addition
	friend SquareMatrix& operator-(SquareMatrix& first, const SquareMatrix& second); // Friendly operator for subtraction

private:
	int size;
};

#endif