#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
	// Constructors and destructor
	Matrix();
	Matrix(const int size);
	Matrix(const Matrix& cc);
	~Matrix();

	friend std::ostream& operator<< (std::ostream& os, Matrix& cc);
	friend std::ofstream& operator<< (std::ofstream& ofs, Matrix& cc);
	friend std::istream& operator>> (std::istream& is, Matrix& cc);
	friend std::ifstream& operator>> (std::ifstream& ifs, Matrix& cc);

	friend void WriteToFile(Matrix& obj); // Writing from file
	friend void ReadFromFile(Matrix& obj,const int objPosition); // Reading from file
	friend void WriteToBinFile(Matrix& obj); // Writing from binary file
	friend void ReadFromBinFile(Matrix& obj, const int objPosition); // Reading from binary file

	char* ToString(Matrix& cc); // Function that returns a matrix as a string
	
	//Getters and setters
	int GetRows() { return rows; };
	int GetCols() { return cols; };
	void SetRows(const int rows) { this->rows = rows; }
	void SetCols(const int cols) { this->cols = cols; }
	
	// Operators
	Matrix& operator=(const Matrix& other);
	friend Matrix& operator+(Matrix& first, const Matrix& second); // Friendly operator for addition
	friend Matrix& operator-(Matrix& first, const Matrix& second); // Friendly operator for subtraction

	// Overloading the indexing operator
	int* operator[](int i) { return matrix[i]; };
	int*& operator[](int i) const { return matrix[i]; };

protected:
	void CreateMatrix(const int rows, const int cols);
	void FillMatrix();

	int ID;
	int** matrix;
	int cols;
	int rows;
};

#endif