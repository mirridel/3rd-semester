#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

Matrix::Matrix(int size)
{
	this->rows = size;
	this->cols = size;
	CreateMatrix(this->rows, this->cols);
	FillMatrix();
};

Matrix::Matrix(const int X, const int Y)
{
	this->rows = X;
	this->cols = Y;
	CreateMatrix(this->rows, this->cols);
	FillMatrix();
};

Matrix::Matrix(const Matrix& cc)
{
	if (cc.rows > 0 && cc.cols > 0)
	{
		this->rows = cc.rows;
		this->cols = cc.cols;
		CreateMatrix(this->rows, this->cols);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = cc.matrix[i][j];
	}
};

std::ostream& operator << (std::ostream& os, Matrix& cc)
{
	for (int i = 0; i < cc.rows; i++)
	{
		for (int j = 0; j < cc.cols; j++)
			os << cc.matrix[i][j] << "\t";
		os << endl;
	}
	return os;
};

std::fstream& operator << (std::fstream& ofs, Matrix& cc) {

	ofs.clear();

	ofs.seekg(0, std::ios_base::beg);

	for (int i = 0; i < cc.rows; i++)
	{
		for (int j = 0; j < cc.cols; j++)
			ofs << cc.matrix[i][j] << "\t";
		ofs << endl;
	}
	ofs << endl;
	return ofs;
};

std::istream& operator >> (std::istream& is, Matrix& cc)
{
	for (int i = 0; i < cc.rows; i++)
		for (int j = 0; j < cc.cols; j++)
			is >> cc.matrix[i][j];
	return is;
}

std::fstream& operator >> (std::fstream& ifs, Matrix& cc)
{
	ifs.seekg(0, std::ios_base::beg);

	for (int i = 0; i < cc.rows; i++)
		for (int j = 0; j < cc.cols; j++)
			ifs >> cc.matrix[i][j];
	return ifs;
}

void Matrix::WriteToBinFile(std::fstream& file) // Write to binary file
{
	if (!file.is_open())
		std::cout << "File opening error\t" << endl;

	file.clear();
	file.seekg(0, std::ios_base::beg);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			file.write((char*)&(matrix[i][j]), sizeof(**matrix));
}

void Matrix::ReadFromBinFile(std::fstream& file) // Read from binary file
{
	if (!file.is_open())
		std::cout << "File opening error\t" << endl;

	file.seekg(0, std::ios_base::beg);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			file.read((char*)&(matrix[i][j]), sizeof(**matrix));
}

void Matrix::CreateMatrix(const int rows, const int cols)
{
	if (rows > 0 && cols > 0)
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[cols];
	}
};

void Matrix::FillMatrix()
{
	if (rows > 0 && cols > 0)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 10;
	}
};

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}