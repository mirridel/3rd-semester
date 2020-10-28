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
	counter++;
	ID = counter;
	
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
		counter++;
		ID = counter;

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
	os << "Matrix #" << cc.ID << endl;

	for (int i = 0; i < cc.size; i++)
	{
		for (int j = 0; j < cc.size; j++)
			os << cc.matrix[i][j] << "\t";
		os << endl;
	}
	return os;
}

std::ofstream& operator << (std::ofstream& ofs, Matrix& other)
{
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
		{
			cout << "[" << i << "|" << j << "]\t";
			is >> cc.matrix[i][j];
		}
	return is;
}

std::ifstream& operator >> (std::ifstream& ifs, Matrix& cc)
{
	for (int i = 0; i < cc.size; i++)
		for (int j = 0; j < cc.size; j++)
			ifs >> cc.matrix[i][j];
	return ifs;
}

void WriteToFile(Matrix& obj)
{
	std::ofstream out("text.txt", std::ios::app);

	if (!out)
		std::cout << "File opening error...";

	out << obj;
	out.close();
}

void ReadFromFile(Matrix& obj, const int objPosition)
{
	std::ifstream in("text.txt", std::ios::in);
	if (!in)
		std::cout << "File opening error...";
	cout << "Position in file:\t" << objPosition << endl;
	for (int i = 0; i < objPosition; i++)
	{
		if (!(in.eof()))
			in >> obj;
		else
			break;
	}
	in.close();
}

void WriteToBinFile(Matrix& obj) // Write to binary file
{
	std::ofstream out("file.dat", std::ios::app);

	if (!out)
		std::cout << "File opening error...";

	for (int i = 0; i < obj.size; i++)
		for (int j = 0; j < obj.size; j++)
			out.write((char*)&(obj.matrix[i][j]), sizeof(**(obj.matrix)));
	out.close();
}

void ReadFromBinFile(Matrix& obj, const int objPosition) // Read from binary file
{
	std::ifstream in("file.dat", std::ios::in);

	if (!in)
		std::cout << "File opening error...";
	cout << "Position in file:\t" << objPosition << endl;
	for (int i = 0; i < objPosition; i++)
	{
		if (!(in.eof()))
			for (int i = 0; i < obj.size; i++)
				for (int j = 0; j < obj.size; j++)
					in.read((char*)&(obj.matrix[i][j]), sizeof(**(obj.matrix)));
		else
			break;
	}
	in.close();
}

void Matrix::PushMatrix()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 10;
}

char* Matrix::ToString(Matrix& cc)
{
	if (cc.size != 0)
	{
		char* buff = new char[128];

		buff[0] = '\0';

		for (int i = 0; i < cc.size; i++)
		{
			for (int j = 0; j < cc.size; j++)
			{
				char subBuff[16] = "";
				_itoa(cc.matrix[i][j], subBuff, 10);
				strcat(subBuff, "\t");
				strcat(buff, subBuff);
			}
			strcat(buff, "\n");
		}
		return buff;
	}
}

int& Matrix::operator()(int x, int y) // Getter
{
	if ((x >= 0 && x < size) && (y >= 0 && y < size))
		return (matrix[x][y]);
}

int Matrix::GetSize() // Getter of size
{
	return this->size;
}

void Matrix::operator()(int x, int y, int data) // Setter
{
	if ((x >= 0 && x < size) && (y >= 0 && y < size))
		matrix[x][y] = data;
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