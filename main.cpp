#include "pch.h"
#include <iostream>

void main()
{
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