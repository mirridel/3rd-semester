#include <iostream>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include "matrix.h"
using namespace std;

#ifndef TEST_H
#define TEST_H

bool test1() // Matrix
{
    unsigned start_t, end_t;
    unsigned int n = 1024;

    Matrix* p;
    p = new Matrix[n];
    stack <Matrix> matrixStack;

    start_t = clock();

    for (int i = 0; i < n; i++)
        matrixStack.push(p[i]);

    matrixStack.pop();

    end_t = clock() - start_t;
    //cout << "Время прохождение теста: " << end_t << endl;

	return true;
}

bool test2() // int
{
    unsigned start_t, end_t;
    unsigned int n = 1024;

    stack <int> intStack;

    start_t = clock();

    for (int i = 0; i < n; i++) {
        int random = rand() % 10 + 1;
        intStack.push(random);
    }

    intStack.pop();

    multiset <int> Multiset;
    multiset <int> ::iterator it1;

    for (int i = 0; i < n; i++) {
        int random = rand() % 10 + 1;
        Multiset.insert(random);
    }
    
    Multiset.erase(10);
   
    it1 = Multiset.find(5);

    end_t = clock() - start_t;
    //cout << "Время прохождение теста: " << end_t << endl;

	return true;
}

bool test3() // float
{
    unsigned start_t, end_t;
    unsigned int n = 1024;

    multiset <float> floatMultiset;
    multiset <float> ::iterator it2;

    start_t = clock(); // Начало теста

    for (int i = 0; i < n; i++) {
        int random = rand() % 10 + 1;
        floatMultiset.insert(random);
    }

    floatMultiset.erase(10);

    it2 = floatMultiset.find(5);

    end_t = clock() - start_t;
    //cout << "Время прохождение теста: " << end_t << endl;

	return true;
}

#endif