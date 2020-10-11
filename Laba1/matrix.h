#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:

	Matrix(int size); // �����������

	Matrix(const Matrix &other); // ����������� �����������

	~Matrix(); // ����������

	bool SetData(int x, int y, int data); // ������, ������� ��������� ���������� ������ ��� ����� ������
	
	int GetData(int x, int y); // ������, ������� ��������� �������� ������ �� ����� ������

	bool PushMatrix(); // ���������� ������� ���������� �������

	char* toString(); // ������� ������� � char

	static bool TransposeMatrix(Matrix &other); // ���������������� �������

	bool AdditionMatrix(Matrix &other); // �������� ������

	bool SubstractionMatrix(Matrix &other); // ��������� ������

private:

	int size; // ������ �������
	int** matrix; // �������
};

#endif