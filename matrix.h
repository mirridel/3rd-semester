#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
	// Constructors and destructor
	Matrix() = default;
	Matrix(const int size);
	Matrix(const int X, const int Y);
	Matrix(const Matrix& cc);
	~Matrix();

	friend std::ostream& operator<< (std::ostream& os, Matrix& cc);
	friend std::fstream& operator<< (std::fstream& ofs, Matrix& cc);
	friend std::istream& operator>> (std::istream& is, Matrix& cc);
	friend std::fstream& operator>> (std::fstream& ifs, Matrix& cc);

	void WriteToBinFile(std::fstream& file); // Writing from binary file
	void ReadFromBinFile(std::fstream& file); // Reading from binary file

	virtual void PrintName() = 0;
	virtual int GetCountElements() = 0;
	virtual char* ToString() = 0; // Function that returns a matrix as a string
	
	int GetRows() { return rows; };
	int GetCols() { return cols; };
	void SetRows(const int rows) { this->rows = rows; }
	void SetCols(const int cols) { this->cols = cols; }

	// Overloading the indexing operator
	int* operator[](int i) { return matrix[i]; };
	int*& operator[](int i) const { return matrix[i]; };

protected:
	int** matrix;
	int cols;
	int rows;

private:
	void CreateMatrix(int x, int y);
	void FillMatrix();
};

#endif