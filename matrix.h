#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;

class Matrix
{
public:

	Matrix();
	Matrix(int size); // �����������
	Matrix(const Matrix &other); // ����������� �����������
	~Matrix(); // ����������

	friend std::ostream& operator<< (std::ostream& os, Matrix& cc);
	friend std::fstream& operator<< (std::fstream& ofs, Matrix& cc);
	friend std::istream& operator>> (std::istream& is, Matrix& cc);
	friend std::fstream& operator>> (std::fstream& ifs, Matrix& cc);

	bool SetData(int x, int y, int data); // ������, ������� ��������� ���������� ������ ��� ����� ������
	int GetData(int x, int y); // ������, ������� ��������� �������� ������ �� ����� ������

	char* toString(); // ������� ������� � char

	static bool TransposeMatrix(Matrix &other); // ���������������� �������
	bool AdditionMatrix(Matrix &other); // �������� ������
	bool SubstractionMatrix(Matrix &other); // ��������� ������

private:

	int size; // ������ �������
	int** matrix; // �������
};

#endif