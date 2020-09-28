#include <fstream>
#include <iostream>
#include <iomanip>
#include "matrix.h"

	Matrix::Matrix(int size) // Вызов конструктора
	{
		this->size = size;

		matrix = new double* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new double[size];
	}

	Matrix::Matrix(double** qq, int n)
	{
		size = n;

		matrix = new double* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new double[size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = qq[i][j];
	}

	Matrix::Matrix(const Matrix &other) // Конструктор копирования
	{
		this->size = other.size;

		matrix = new double* [this->size];
		for (int i = 0; i < this->size; i++)
			matrix[i] = new double[this->size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = other.matrix[i][j];
	}

	static int position = 0;

	std::ostream& operator <<(std::ostream &os, Matrix &cc)
	{
		for (int i = 0; i < cc.size; i++)
		{
			for (int j = 0; j < cc.size; j++)
				os << cc.matrix[i][j] << " ";
			os << std::endl;
		}
		return os;
	}

	std::ofstream& operator <<(std::ofstream& ofs, Matrix &other)
	{
		for (int i = 0; i < other.size; i++)
		{
			for (int j = 0; j < other.size; j++)
				ofs << other.matrix[i][j] << " ";
			ofs << "\n";
		}
		ofs << "\n";

		return ofs;
	}

	std::istream& operator >> (std::istream& is, Matrix& cc)
	{
		for (int i = 0; i < cc.size; i++)
			delete[] cc.matrix[i];
		delete[] cc.matrix;

		std::cout << "Enter size: " << std::endl;
		is >> cc.size;

		std::cout << "Enter number:" << std::endl;
		cc.matrix = new double* [cc.size];
		for (int i = 0; i < cc.size; i++)
			cc.matrix[i] = new double[cc.size];
		for (int i = 0; i < cc.size; i++)
			for (int j = 0; j < cc.size; j++)
				is >> cc.matrix[i][j];
		return is;
	}

	std::ifstream& operator >> (std::ifstream& ifs, Matrix &cc)
	{
		for (int i = 0; i < cc.size; i++)
			for (int j = 0; j < cc.size; j++)
				ifs >> cc.matrix[i][j];

		return ifs;
	}

	void Matrix::WriteToFile(Matrix &obj)
	{
		std::ofstream f("text.txt", std::ios::app);

		if (!f) {
			std::cout << "File opening error";
		}

		f << obj;
		f.close();
	}

	void Matrix::ReadFromFile(Matrix& obj)
	{
		std::ifstream f1("text.txt", std::ios::app);
		if (!f1)
			std::cout << "File opening error";

		f1.seekg(position, std::ios_base::cur);

		f1 >> obj;

		position = f1.tellg();

		f1.close();
	}

	void Matrix::PushMatrix()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = rand() % 10;
	}

	double& Matrix::operator()(int i, int j)
	{
		return (matrix[i][j]);
	}

	Matrix& Matrix::operator=(const Matrix& other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix& Matrix::operator+(const Matrix &other)
	{
		if (this->size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					this->matrix[i][j] += other.matrix[i][j];
				}
			}
		}
		else std::cout << "Matrixes of different sizes. Addition is not possible." << std::endl;
		return *this;
	}

	Matrix& Matrix::operator-(const Matrix &other)
	{
		if (this->size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					this->matrix[i][j] -= other.matrix[i][j];
				}
			}
		}
		else std::cout << "Matrixes of different sizes. Substraction is not possible." << std::endl;
		return *this;
	}

	Matrix::~Matrix()
	{
		for (int i = 0; i < size; i++)
			delete[] matrix[i];

		delete[] matrix;
	}