#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
private:
	int size; 
	double** matrix;

public:

	Matrix(int size);

	Matrix(double** qq = NULL, int n = 0);

	Matrix(const Matrix &other);

	friend std::ostream& operator << (std::ostream& os, Matrix &cc);

	friend std::ofstream& operator << (std::ofstream& ofs, Matrix &cc);

	friend std::istream& operator >> (std::istream& is, Matrix &cc);

	friend std::ifstream& operator >> (std::ifstream& ifs, Matrix &cc);

	static void WriteToFile(Matrix& obj); // Записать в файл

	static void ReadFromFile(Matrix& obj); // Прочитать из файла

	void PushMatrix();

	double& operator()(int i, int j);

	Matrix& operator=(const Matrix& other);

	Matrix& operator+(const Matrix& other);

	Matrix& operator-(const Matrix& other);

	~Matrix();
};

#endif