#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <iomanip>
#include "matrix.h"

using std::cout;
using std::endl;

static int counter = 0;

Matrix::Matrix(int size)
{
	this->size = size;

	if (this->size > 0)
	{
		matrix = new int* [size];

		for (int i = 0; i < size; i++)
			matrix[i] = new int[size];
	}
}

Matrix::Matrix(const Matrix& other)
{
	if (other.size > 0)
	{
		this->size = other.size;

		this->matrix = new int* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new int[size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = other.matrix[i][j];
	}
}

std::ostream& operator << (std::ostream& os, Matrix& cc)
{
	for (int i = 0; i < cc.size; i++)
	{
		for (int j = 0; j < cc.size; j++)
			os << cc.matrix[i][j] << "\t";
		os << endl;
	}
	return os;
}

std::fstream& operator << (std::fstream& ofs, Matrix& other)
{
	ofs.clear();

	ofs.seekg(0, std::ios_base::beg);

	for (int i = 0; i < other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
			ofs << other.matrix[i][j] << "\t";
		ofs << endl;
	}
	ofs << endl;
	return ofs;
}

std::istream& operator >> (std::istream& is, Matrix& cc)
{
	for (int i = 0; i < cc.size; i++)
		delete[] cc.matrix[i];
	delete[] cc.matrix;

	cc.matrix = new int* [cc.size];
	for (int i = 0; i < cc.size; i++)
		cc.matrix[i] = new int[cc.size];

	for (int i = 0; i < cc.size; i++)
		for (int j = 0; j < cc.size; j++)
			is >> cc.matrix[i][j];

	return is;
}

std::fstream& operator >> (std::fstream& ifs, Matrix& cc)
{
	ifs.seekg(0, std::ios_base::beg);

	for (int i = 0; i < cc.size; i++)
		for (int j = 0; j < cc.size; j++)
			ifs >> cc.matrix[i][j];
	return ifs;
}

void Matrix::WriteToBinFile(std::fstream& file) // Write to binary file
{
	if (!file.is_open())
		std::cout << "File opening error\t" << endl;

	file.clear();

	file.seekg(0, std::ios_base::beg);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			file.write((char*)&(matrix[i][j]), sizeof(**matrix));
}

void Matrix::ReadFromBinFile(std::fstream& file) // Read from binary file
{
	if (!file.is_open())
		std::cout << "File opening error\t" << endl;
	
	file.seekg(0, std::ios_base::beg);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			file.read((char*)&(matrix[i][j]), sizeof(**matrix));
		}
}

void Matrix::PushMatrix()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 10;
}

char* Matrix::ToString()
{
	if (size != 0)
	{
		char* buff = new char[128];

		buff[0] = '\0';

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				char subBuff[16] = "";
				_itoa(matrix[i][j], subBuff, 10);
				strcat(subBuff, "\t");
				strcat(buff, subBuff);
			}
			strcat(buff, "\n");
		}
		return buff;
	}
}

void Matrix::operator()(int x, int y, int data) // Setter
{
	if ((x >= 0 && x < size) && (y >= 0 && y < size))
		matrix[x][y] = data;
}

int Matrix::GetSize() // Getter of size
{
	return this->size;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this->size == other.size && this->size > 0 && other.size > 0)
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				this->matrix[i][j] = other.matrix[i][j];
	return *this;
}

Matrix& operator+(Matrix& first, const Matrix& second)
{
	if (first.size == second.size && first.size > 0 && second.size > 0)
		for (int i = 0; i < first.size; i++)
			for (int j = 0; j < first.size; j++)
				first.matrix[i][j] += second.matrix[i][j];
	return *&first;
}

Matrix& operator-(Matrix& first, const Matrix& second)
{
	if (first.size == second.size && first.size > 0 && second.size > 0)
		for (int i = 0; i < first.size; i++)
			for (int j = 0; j < first.size; j++)
				first.matrix[i][j] -= second.matrix[i][j];
	return *&first;
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}