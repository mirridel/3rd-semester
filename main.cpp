#include "pch.h"
#include "test.hpp"
#include <iostream>

void test();

void main()
{
    test();

    int a = 1;
    int b = 2;
    int c = 3;

    std::cout << "Integer List:" << std::endl;
    List<int> intL;
    intL.AddTail(a);
    intL.AddTail(b);
    intL.AddTail(c);
    intL.Print();

    double A = 1.1;
    double B = 2.2;
    double C = 3.3;

    std::cout << "Double List:" << std::endl;
    List<double> doubleL;
    doubleL.AddTail(A);
    doubleL.AddTail(B);
    doubleL.AddTail(C);
    doubleL.Print();
    
    Matrix m1(3);
    Matrix m2(3);
    Matrix m3(3);
    Matrix m4(5);

    std::cout << "Matrices List:" << std::endl;
    List<Matrix> mL;
    mL.AddTail(m1);
    mL.AddTail(m2);
    mL.AddTail(m3);
    mL.AddTail(m4);
    mL.Print();
}

void test()
{
    // matrix
    if (test1())
        cout << "Test #1 passed..." << endl;
    else
        cout << "Test #1 failed..." << endl;
    // int
    if (test2())
        cout << "Test #2 passed..." << endl;
    else
        cout << "Test #2 failed..." << endl;
    // double
    if (test3())
        cout << "Test #3 passed..." << endl;
    else
        cout << "Test #3 failed..." << endl;
}