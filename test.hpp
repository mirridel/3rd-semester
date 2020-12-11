#ifndef TEST_H
#define TEST_H

#include "matrix.h"
#include "identityMatrix.h"
#include "rectangularMatrix.h"

int sum(Matrix& cc); // Adds all the values in the matrix and returns the sum.

bool test1() // +
{
	Matrix squareM1(3);
	Matrix squareM2(3);

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

	IdentityMatrix identityM1(3);
	
	squareM1 = squareM1 + identityM1;
	//cout << sum(squareM1);
	if (sum(squareM1) != 3)
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

	// Special cases

	try
	{
		squareM1 = squareM1 + rectangueM1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}
	
	try
	{
		squareM1 = squareM1 + rectangueM2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = rectangueM1 + squareM1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = rectangueM1 + squareM2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	return true;
}

bool test2() // -
{
	Matrix squareM1(3);
	Matrix squareM2(3);

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

	IdentityMatrix identityM1(3);

	squareM1 = squareM1 - identityM1;
	//cout << sum(squareM1);
	if (sum(squareM1) != 69)
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

	// Special cases

	try
	{
		squareM1 = squareM1 - rectangueM1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		squareM1 = squareM1 - rectangueM2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = rectangueM1 - squareM1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = rectangueM1 - squareM2;
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
	Matrix squareM1(3);
	Matrix squareM2(3);

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

	IdentityMatrix identityM1(3);

	squareM1 = identityM1;
	//cout << sum(squareM1);
	if (sum(squareM1) != 3)
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

	// Special cases

	try
	{
		squareM1 = rectangueM1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		squareM1 = rectangueM2;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = squareM1;
	}
	catch (const std::exception& ex)
	{
		//cout << ex.what() << endl;
	}

	try
	{
		rectangueM1 = squareM2;
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

	Matrix m1(2), m2(4);

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