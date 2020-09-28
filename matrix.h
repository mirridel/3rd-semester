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

	double det(int N);

	Matrix& operator()();

	int& operator()(int i, int j);

	Matrix& operator=(const Matrix& other);

	Matrix& operator+(const Matrix& other);

	Matrix& operator-(const Matrix& other);

	~Matrix();
};

#endif