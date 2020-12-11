#ifndef LIST_H
#define LIST_H

#include "matrix.h"
#include <iostream>

template <class DataT> class Elem
{
public:
    DataT* data;
    Elem* next;
    Elem *prev;
};

template <class DataT> class List
{
public:
    List();
    List(const List& cc);
    ~List();

    // �������� ���������� ���������
    int GetCount();

    // �������� ��������, ���� �������� �� �����������,
    // �� ������� ��� �����������
    void Del(int pos);

    // ������� ��������, ���� �������� �� �����������,
    // �� ������� ��� �����������
    void Insert(DataT& n, int pos = 0);

    // ���������� ������
    void AddTail(DataT& n);
   
    // ���������� ������
    void AddHead(DataT& n);
    
    // ������ ������
    void Print(int pos);
    void Print();

private:

    Elem<DataT> *Head, *Tail;
    int Count;
};

#endif