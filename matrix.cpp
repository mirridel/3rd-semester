#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

static int counter = 0;

Matrix::Matrix() {};

Matrix::Matrix(int size)
{
	this->rows = size;
	this->cols = size;
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

std::ofstream& operator << (std::ofstream& ofs, Matrix& cc) {

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

std::ifstream& operator >> (std::ifstream& ifs, Matrix& cc)
{
	for (int i = 0; i < cc.rows; i++)
		for (int j = 0; j < cc.cols; j++)
			ifs >> cc.matrix[i][j];
	return ifs;
}

void Matrix::WriteToFile(char* path, std::fstream& file)
{
	file.open(path, std::ios_base::out);

	if (!file.is_open())
		std::cout << "File opening error\t" << path << endl;

	file.clear();
	file << *this;
	file.close();
}

void Matrix::ReadFromFile(char* path, std::fstream& file)
{
	file.open(path, std::ios_base::in);

	if (!file.is_open())
		std::cout << "File opening error\t" << path << endl;

	file >> *this;
	file.close();
}

void Matrix::WriteToBinFile(char* path, std::fstream& file) // Write to binary file
{
	file.open(path, std::ios_base::out | std::ios_base::binary);

	if (!file.is_open())
		std::cout << "File opening error\t" << path << endl;

	file.clear();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			file.write((char*)&(matrix[i][j]), sizeof(**matrix));
	file.close();
}

void Matrix::ReadFromBinFile(char* path, std::fstream& file) // Read from binary file
{
	file.open(path, std::ios_base::in | std::ios_base::binary);

	if (!file.is_open())
		std::cout << "File opening error\t" << path << endl;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			file.read((char*)&(matrix[i][j]), sizeof(**matrix));
	file.close();
}



char* Matrix::ToString(Matrix& cc)
{
	if (rows != 0 && cols != 0)
	{
		char* buff = new char[128];

		buff[0] = '\0';

		for (int i = 0; i < cc.rows; i++)
		{
			for (int j = 0; j < cc.cols; j++)
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

Matrix& Matrix::operator=(const Matrix& second)
{
	if (this->cols == second.cols &&
		this->rows == second.rows &&
		this->cols > 0 && this->rows > 0 &&
		second.cols > 0 && second.rows > 0)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = second.matrix[i][j];
	}
	return *this;
}

Matrix& operator+(Matrix& first, const Matrix& second)
{
	if ((first.cols == second.cols) &&
		(first.rows == second.rows) &&
		(first.cols > 0 && first.rows > 0) &&
		(second.cols > 0 && second.rows > 0))
	{
		for (int i = 0; i < first.rows; i++)
			for (int j = 0; j < first.cols; j++)
				first.matrix[i][j] += second.matrix[i][j];
	}
	return *&first;
}

Matrix& operator-(Matrix& first, const Matrix& second)
{
	if ((first.cols == second.cols) &&
		(first.rows == second.rows) &&
		(first.cols > 0 && first.rows > 0) &&
		(second.cols > 0 && second.rows > 0))
	{
		for (int i = 0; i < first.rows; i++)
			for (int j = 0; j < first.cols; j++)
				first.matrix[i][j] -= second.matrix[i][j];
	}
	return *&first;
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