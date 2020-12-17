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

    // Получить количество элементов
    int GetCount();
    // Получить элемент списка
    Elem* GetElem(int);
    // Удаление элемента, если параметр не указывается,
    // то функция его запрашивает
    void Del(int pos = 0);
    // Вставка элемента, если параметр не указывается,
    // то функция его запрашивает
    void Insert(Matrix& n, int pos = 0);

    void AddTail(Matrix& n);
    void AddHead(Matrix& n);
    // Печать списка
    void Print();
    // Печать определенного элемента
    void Print(int pos);

private:
    Elem* Head, * Tail;
    int Count;
};

#endif