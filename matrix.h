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

	void AdditionMatrix(Matrix &other);

	void SubstractionMatrix(Matrix &other);

	~Matrix();
};

#endif