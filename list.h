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

    // Получить количество элементов
    int GetCount();

    // Удаление элемента, если параметр не указывается,
    // то функция его запрашивает
    void Del(int pos);

    // Вставка элемента, если параметр не указывается,
    // то функция его запрашивает
    void Insert(DataT& n, int pos = 0);

    // Добавление хвоста
    void AddTail(DataT& n);
   
    // Добавление головы
    void AddHead(DataT& n);
    
    // Печать списка
    void Print(int pos);
    void Print();

private:

    Elem<DataT> *Head, *Tail;
    int Count;
};

#endif