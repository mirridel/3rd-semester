#include "list.h"
#include "matrix.h"
#include "rectangularMatrix.h"
#include <iostream>

using namespace std;

void main()
{
    List L;

    Matrix* p;
    Matrix m1(2), m2(2), m3(2);

    RectangularMatrix M(2, 3);

    p = &m1;
    cout << p->ToString() << endl;
    p = &m2;
    cout << p->ToString() << endl;
    p = &m3;
    cout << p->ToString() << endl;
    p = &M;
    cout << p->ToString() << endl;

    L.AddTail(m1);
    L.AddTail(m2);
    L.AddTail(m3);

    L.Insert(M, 1);

    // Распечатка списка
    std::cout << "List L:\n";
    L.Print();

    // Удаление элемента из списка
    std::cout << "List L:\n";
    L.Del(1);
    L.Print();

    // Печать элемента по логическому номеру
    L.Print(1);
}