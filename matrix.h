#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
	int size; 
	double** matrix;

public:

	Matrix(int size);

	Matrix(double** qq = NULL, int n = 0);

	Matrix(const Matrix &other);

	void PushMatrix();

	void PrintMatrix();

	double determinant();

	Matrix Minor(const int p, const  int q);

	double* operator[](int j) { return matrix[j]; }

	double*& operator[](int j) const { return matrix[j]; }

	Matrix GausStep(int p, int q);

	Matrix ReverseMatrix();

	Matrix Tr();

	double operator()();

	double& operator()(int i, int j);

	Matrix& operator=(const Matrix& other);

	Matrix& operator+(const Matrix& other);

	Matrix& operator-(const Matrix& other);

	~Matrix();
};

#endif