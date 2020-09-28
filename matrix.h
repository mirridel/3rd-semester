#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
	int size; 
	int** matrix;

public:

	Matrix(int size);

	Matrix(const Matrix &other);

	void PushMatrix();

	void PrintMatrix();

	static void TransposeMatrix(Matrix &other);

	int AdditionMatrix(Matrix &other);

	int SubstractionMatrix(Matrix &other);

	~Matrix();
};

#endif