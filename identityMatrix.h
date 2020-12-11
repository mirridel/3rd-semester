#include "matrix.h"

#ifndef IDENTITY_MATRIX_H
#define IDENTITY_MATRIX_H

class IdentityMatrix : public Matrix
{
public:
	IdentityMatrix(const int size);
	~IdentityMatrix() {};
};

#endif