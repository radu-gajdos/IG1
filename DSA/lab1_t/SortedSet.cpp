#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	//TODO - Implementation
}


bool SortedSet::add(TComp elem) {

    if (this->search(elem)) {
        return false;
    }
    if (this->nrElems == this->capacity) {
        this->resize();
    }
    int i = this->nrElems;
    while (i > 0 && this->r(elem, this->elems[i-1])) {
        this->elems[i] = this->elems[i-1];
        i--;
    }
    this->elems[i] = elem;
    this->nrElems++;
    return true;
}


bool SortedSet::remove(TComp elem) {
    int i = 0;
    while (i < this->nrElems && this->elems[i] != elem) {
        i++;
    }
    if (i == this->nrElems) {
        return false;
    }
    for (int j = i; j < this->nrElems - 1; j++) {
        this->elems[j] = this->elems[j+1];
    }
    this->nrElems--;
    return true;
}


bool SortedSet::search(TComp elem) const {
    int left = 0;
    int right = this->nrElems - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (this->elems[middle] == elem) {
            return true;
        }
        if (this->r(elem, this->elems[middle])) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return false;
}


int SortedSet::size() const {
    return this->nrElems;
}

bool SortedSet::isEmpty() const {
    return this->nrElems == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    delete[] this->elems;
}

void SortedSet::resize() {
    this->capacity *= 2;
    TComp* newElems = new TComp[this->capacity];
    for (int i = 0; i < this->nrElems; i++) {
        newElems[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = newElems;
}


