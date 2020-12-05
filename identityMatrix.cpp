#define _CRT_SECURE_NO_WARNINGS

#include "identityMatrix.h"

IdentityMatrix::
IdentityMatrix(int size): Matrix(size)
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = 0;

		for (int i = 0; i < size; i++)
			matrix[i][i] = 1;
	}
}