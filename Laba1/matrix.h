#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:

	Matrix(int size); // �����������

	Matrix(const Matrix &other); // ����������� �����������

	~Matrix(); // ����������

	bool SetData(int, int, int); // ������, ������� ��������� ���������� ������ ��� ����� ������
	
	int GetData(int, int); // ������, ������� ��������� �������� ������ �� ����� ������

	bool PushMatrix(); // ���������� ������� ���������� �������

	void toString(); // ������� ������� � ���� char

	void toInt(); // ������� ������� � ���� int

	static bool TransposeMatrix(Matrix &other); // ���������������� �������

	bool AdditionMatrix(Matrix &other); // �������� ������

	bool SubstractionMatrix(Matrix &other); // ��������� ������

private:

	int size; // ������ �������
	int** matrix; // �������
	char** str; // ��������� ������������� �������
};

#endif