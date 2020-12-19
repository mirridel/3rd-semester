#ifndef TEST_H
#define TEST_H

#include "matrix.h"
#include "squareMatrix.h"
#include "rectangularMatrix.h"

int sum(Matrix& cc); // Adds all the values in the matrix and returns the sum.

bool test1() // +
{
	SquareMatrix m1(3);
	SquareMatrix m2(3);
	SquareMatrix m3(6);

	for (int i = 0, val = 0; i < 3; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			m1[i][j] = val;					// 6  7  8
	//cout << m1 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			m2[i][j] = val;					//-6 -7 -8
	//cout << m2 << endl;

	m1 = m1 + m2;
	//cout << sum(squareM1);
	if (sum(m1) != 0)
		return false;

	RectangularMatrix M1(2, 3);
	RectangularMatrix M2(2, 3);
	RectangularMatrix M3(3, 4);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			M1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			M2[i][j] = val;
	//cout << M2 << endl;

	try
	{
		m1 = m1 + m3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}
	
	try
	{
		m3 = m3 + m1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		M1 = M1 + M3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		M3 = M3 + M1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	return true;
}

bool test2() // -
{
	SquareMatrix m1(3);
	SquareMatrix m2(3);
	SquareMatrix m3(6);

	for (int i = 0, val = 0; i < 3; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			m1[i][j] = val;           // 6  7  8
	//cout << squareM1 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			m2[i][j] = val;           //-6 -7 -8
	//cout << squareM2 << endl;

	m1 = m1 - m2;
	//cout << sum(squareM1);
	if (sum(m1) != 72)
		return false;

	RectangularMatrix M1(2, 3);
	RectangularMatrix M2(2, 3);
	RectangularMatrix M3(4, 6);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			M1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			M2[i][j] = val;
	//cout << rectangueM2 << endl;

	M1 = M1 - M2;
	//cout << sum(rectangueM1);
	if (sum(M1) != 30)
		return false;

	// Special cases

	try
	{
		m1 = m1 - m3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		m3 = m3 - m1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		M1 = M1 - M3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		M3 = M3 - M1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	return true;
}

bool test3() // *
{
	RectangularMatrix rectangueM1(2, 3);
	RectangularMatrix rectangueM2(2, 3);
	RectangularMatrix rectangueM3(3, 2);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			rectangueM1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			rectangueM2[i][j] = val;
	//cout << rectangueM2 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0  1
		for (int j = 0; j < 2; j++, val++)  // 2  3
			rectangueM3[i][j] = val;        // 4  5
	//cout << rectangueM3 << endl;

	try
	{
		rectangueM1 = rectangueM1 * rectangueM2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = rectangueM1 * rectangueM3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	return true;
}

bool test4() // =
{
	SquareMatrix m1(3);
	SquareMatrix m2(3);
	SquareMatrix m3(6);

	for (int i = 0, val = 0; i < 3; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			m1[i][j] = val;				    // 6  7  8
	//cout << squareM1 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			m2[i][j] = val;					//-6 -7 -8
	//cout << squareM2 << endl;

	m1 = m1 - m2;
	//cout << sum(squareM1);
	if (sum(m1) != 72)
		return false;

	m1 = m2;
	//cout << sum(squareM1);
	if (sum(m1) != -36)
		return false;

	RectangularMatrix M1(2, 3);
	RectangularMatrix M2(2, 3);
	RectangularMatrix M3(4, 6);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			M1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			M2[i][j] = val;
	//cout << rectangueM2 << endl;

	M1 = M1 - M2;
	//cout << sum(rectangueM1);
	if (sum(M1) != 30)
		return false;

	// Special cases

	try
	{
		m1 = m3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		m3 = m1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		M1 = M3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		M3 = M1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	return true;
}

bool exceptionTest()
{
	int counter = 0;

	SquareMatrix m1(2), m2(4);

	RectangularMatrix M1(2, 4), M2(4, 2), M3(2, 4);

	try
	{
		m1 = m1 + m1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
		counter++;
	}

	try
	{
		m1 = m1 - m1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
		counter++;
	}

	try
	{
		M1 = M1 + M2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
		counter++;
	}

	try
	{
		M1 = M1 - M2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
		counter++;
	}

	try
	{
		M1 = M1 * M3;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
		counter++;
	}

	if (counter != 5)
		return false;
	else
		return true;
}

int sum(Matrix& cc)
{
	int s = 0;
	int X = cc.GetRows();
	int Y = cc.GetCols();
	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			s += cc[x][y];
	return s;
}
#endif