#include "SortedSetIterator.h"
#include <exception>

using namespace std;


SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m), i(0){}

void SortedSetIterator::first() {
    i=0;
}


void SortedSetIterator::next() {
    if (!valid()) {
        throw exception();
    }
    i++;
}


TElem SortedSetIterator::getCurrent()
{
    if (!valid()) {
        throw exception();
    }
    return multime.elementen[i];
}

bool SortedSetIterator::valid() const {
    return i >= 0 && i < multime.size();
}