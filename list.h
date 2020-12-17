#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "matrix.h"
#include "squareMatrix.h"
#include "rectangularMatrix.h"

struct Elem
{
    Matrix* data;
    Elem* next, * prev;
};

class List
{
public:
    List();
    List(const List&);
    ~List();

    // �������� ���������� ���������
    int GetCount();
    // �������� ������� ������
    Elem* GetElem(int);
    // �������� ��������, ���� �������� �� �����������,
    // �� ������� ��� �����������
    void Del(int pos = 0);
    // ������� ��������, ���� �������� �� �����������,
    // �� ������� ��� �����������
    void Insert(Matrix& n, int pos = 0);

    void AddTail(Matrix& n);
    void AddHead(Matrix& n);
    // ������ ������
    void Print();
    // ������ ������������� ��������
    void Print(int pos);

private:
    Elem* Head, * Tail;
    int Count;
};

#endif