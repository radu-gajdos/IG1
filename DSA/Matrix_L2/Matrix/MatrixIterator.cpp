#include "MatrixIterator.h"
#include <exception>
#include <iostream>

using namespace std;

MatrixIterator::MatrixIterator(const Matrix& m) : multime(m) {
    this->first();
}

void MatrixIterator::first() {
    i = 0;
    j = 0;
}

void MatrixIterator::next() {

    if (!valid()) {
        throw exception();
    }

    if(i==(multime.nrLines()-1)){
        i = 0;
        j++;
    }else{
        i++;
    }
}

TElem MatrixIterator::getCurrent() {
    if (!valid()) {
        throw exception();
    }
    return multime.element(i, j);
}

bool MatrixIterator::valid() const {
    return i >= 0 && i < multime.nrLines() && j>=0 && j<multime.nrColumns();
}