#include "list.h"
#include "matrix.h"
#include "rectangularMatrix.h"
#include "test.hpp"
#include <iostream>

using namespace std;

void test();

void main()
{
    List L;

    Matrix* p;
    Matrix m1(2), m2(2), m3(2), m4(5);

    RectangularMatrix M(2, 3);

    test();

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

void test()
{
    if (test1())
        cout << "Test passed #1 (+)" << endl;
    else cout << "Test failed #1 (+)" << endl;

    if (test2())
        cout << "Test passed #2 (-)" << endl;
    else cout << "Test failed #2 (-)" << endl;

    if (test3())
        cout << "Test passed #3 (*)" << endl;
    else cout << "Test failed #3 (*)" << endl;

    if (test4())
        cout << "Test passed #4 (=)" << endl;
    else cout << "Test failed #4 (=)" << endl;

    if (exceptionTest())
        cout << "Exception test passed #5" << endl;
    else cout << "Exception test passed #5" << endl;
}