#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
	// Constructors and destructor
	Matrix(int size);
	Matrix(double** qq = NULL, int n = 0);
	Matrix(const Matrix& other);
	~Matrix();

	void pushMatrix(); // Function that fills a matrix with random numbers
	char* toString(); // Function that returns a matrix as a string

	// Determinant
	double determinant(); // Finding determinant
	Matrix minor(const int p, const  int q); // Finding minor for a determinant
	Matrix gausStep(int p, int q); // Subfunction for determinant
	Matrix reverseMatrix(); // Subfunction for determinant
	Matrix tr(); // Subfunction for determinant
	double operator()() { return determinant(); } // Overloading operator for finding determinant

	// Overloading the indexing operator
	double* operator[](int j) { return matrix[j]; }
	double*& operator[](int j) const { return matrix[j]; }

	double& operator()(int x, int y); // Getter of data
	int getSize() { return this->size; } // Getter of size
	void operator()(int x, int y, int data); // Setter of data

	Matrix& operator=(const Matrix& other); // Operator for assigning
	friend Matrix& operator+(Matrix& first, const Matrix& second); // Operator for addition
	friend Matrix& operator-(Matrix& first, const Matrix& second); // Operator for subtraction

private:
	int size;
	double** matrix;
};

#endif