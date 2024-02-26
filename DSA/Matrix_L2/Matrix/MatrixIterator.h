#pragma once
#include "Matrix.h"

//DO NOT CHANGE THIS PART
class MatrixIterator
{
    friend class Matrix;
private:
    const Matrix& multime;

    int i;
    int j;

public:

    MatrixIterator(const Matrix& m);
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};

