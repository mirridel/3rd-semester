#ifndef TEST_H
#define TEST_H

#include "pch.h"

bool test1() // Matrix
{
	List <Matrix> L;

	Matrix m1(1), m2(2), m3(3), m4(4);

	for (size_t i = 0; i < 1; i++)
		for (size_t j = 0; j < 1; j++)
			m1[i][j] = 1;

	for (size_t i = 0; i < 2; i++)
		for (size_t j = 0; j < 2; j++)
			m2[i][j] = 2;

	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			m3[i][j] = 3;

	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			m4[i][j] = 4;

	L.AddTail(m2);
	L.AddTail(m1);
	L.AddHead(m3);
	L.AddHead(m4);

	L.Insert(m4, 1);
	L.Insert(m4, 1);

	L.Del(1);
	L.Del(2);
	L.Del(3);

	int count = L.GetCount();
	if (count != 3)
		return false;
	else
		return true;
}

bool test2() // Int
{
	List <int> L;

	int A = 1;
	int B = 2;
	int C = 3;
	int D = -1;

	L.AddTail(A);
	L.AddTail(D);
	L.AddHead(B);
	L.AddHead(C);

	L.Insert(A, 1);
	L.Insert(B, 1);

	L.Del(1);
	L.Del(2);
	L.Del(3);

	int count = L.GetCount();
	if (count != 3)
		return false;
	else
		return true;
}

bool test3() // Double
{
	List <double> L;

	double A = 1.11;
	double B = 2.22;
	double C = 3.33;
	double D = -1.11;

	L.AddTail(A);
	L.AddTail(D);
	L.AddHead(B);
	L.AddHead(C);

	L.Insert(A, 1);
	L.Insert(B, 1);

	L.Del(1);
	L.Del(2);
	L.Del(3);

	int count = L.GetCount();
	if (count != 3)
		return false;
	else
		return true;
}

#endif