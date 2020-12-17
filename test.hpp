#ifndef TEST_H
#define TEST_H

#include "matrix.h"
#include "squareMatrix.h"
#include "rectangularMatrix.h"

int sum(Matrix& cc); // Adds all the values in the matrix and returns the sum.

bool test1() // +
{
	SquareMatrix squareM1(3);
	SquareMatrix squareM2(3);

	for (int i = 0, val = 0; i < 3; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			squareM1[i][j] = val;           // 6  7  8
	//cout << squareM1 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			squareM2[i][j] = val;           //-6 -7 -8
	//cout << squareM2 << endl;

	squareM1 = squareM1 + squareM2;
	//cout << sum(squareM1);
	if (sum(squareM1) != 0)
		return false;

	RectangularMatrix rectangueM1(2, 3);
	RectangularMatrix rectangueM2(2, 3);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			rectangueM1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			rectangueM2[i][j] = val;
	//cout << rectangueM2 << endl;

	rectangueM1 = rectangueM1 + rectangueM2;
	//cout << sum(rectangueM1);
	if (sum(rectangueM1) != 0)
		return false;

	return true;
}

bool test2() // -
{
	SquareMatrix squareM1(3);
	SquareMatrix squareM2(3);

	for (int i = 0, val = 0; i < 3; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			squareM1[i][j] = val;           // 6  7  8
	//cout << squareM1 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			squareM2[i][j] = val;           //-6 -7 -8
	//cout << squareM2 << endl;

	squareM1 = squareM1 - squareM2;
	//cout << sum(squareM1);
	if (sum(squareM1) != 72)
		return false;

	RectangularMatrix rectangueM1(2, 3);
	RectangularMatrix rectangueM2(2, 3);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			rectangueM1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			rectangueM2[i][j] = val;
	//cout << rectangueM2 << endl;

	rectangueM1 = rectangueM1 - rectangueM2;
	//cout << sum(rectangueM1);
	if (sum(rectangueM1) != 30)
		return false;

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

	rectangueM1 = rectangueM1 * rectangueM2;
	if (sum(rectangueM1) != 15)
		return false;

	rectangueM1 = rectangueM1 * rectangueM3;
	if (sum(rectangueM1) != 91)
		return false;

	return true;
}

bool test4() // =
{
	SquareMatrix squareM1(3);
	SquareMatrix squareM2(3);

	for (int i = 0, val = 0; i < 3; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			squareM1[i][j] = val;           // 6  7  8
	//cout << squareM1 << endl;

	for (int i = 0, val = 0; i < 3; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			squareM2[i][j] = val;           //-6 -7 -8
	//cout << squareM2 << endl;

	squareM1 = squareM2;
	//cout << sum(squareM1);
	if (sum(squareM1) != -36)
		return false;

	RectangularMatrix rectangueM1(2, 3);
	RectangularMatrix rectangueM2(2, 3);

	for (int i = 0, val = 0; i < 2; i++)    // 0  1  2
		for (int j = 0; j < 3; j++, val++)  // 3  4  5
			rectangueM1[i][j] = val;
	//cout << rectangueM1 << endl;

	for (int i = 0, val = 0; i < 2; i++)    // 0 -1 -2
		for (int j = 0; j < 3; j++, val--)  //-3 -4 -5
			rectangueM2[i][j] = val;
	//cout << rectangueM2 << endl;

	rectangueM1 = rectangueM2;
	//cout << sum(rectangueM1);
	if (sum(rectangueM1) != -15)
		return false;

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