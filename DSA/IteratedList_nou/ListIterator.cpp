#include "ListIterator.h"
#include "IteratedList.h"

ListIterator::ListIterator(const IteratedList& list) : list(list) {
    first();
}

void ListIterator::first() {
    current = list.head;
}

void ListIterator::next() {
    if (valid()) {
        current = list.next[current];
    }
    else {
        throw std::runtime_error("Invalid iterator position!");
    }
}

bool ListIterator::valid() const {
    return current != -1;
}

TElem ListIterator::getCurrent() const {
    if (valid()) {
        return list.elements[current];
    }
    else {
        return NULL_TELEM;
    }
}
