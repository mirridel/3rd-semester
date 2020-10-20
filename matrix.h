#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:

	// Constructors and destructor

	Matrix(int size);

	Matrix(double** qq = NULL, int n = 0);

	Matrix(const Matrix& other);

	~Matrix();

	void PushMatrix(); // Function that fills a matrix with random numbers

	friend char* toString(Matrix& cc); // Friendly function that returns a matrix as a string

	double determinant(); // Finding determinant

	Matrix Minor(const int p, const  int q); // Finding minor for a determinant

	double* operator[](int j) { return matrix[j]; } // Operator for determinant

	double*& operator[](int j) const { return matrix[j]; } // Operator for determinant

	Matrix GausStep(int p, int q); // Subfunction for determinant

	Matrix ReverseMatrix(); // Subfunction for determinant

	Matrix Tr(); // Subfunction for determinant

	double operator()(); // Determinant

	double& operator()(int x, int y); // Getter

	int getSize(); // Getter of size

	void operator()(int x, int y, int data); // Setter

	Matrix& operator=(const Matrix& other); // Operator for assigning

	Matrix& operator+(const Matrix& other); // Operator for addition

	Matrix& operator-(const Matrix& other); // Operator for subtraction

private:
	int size;
	double** matrix;
};

#endif