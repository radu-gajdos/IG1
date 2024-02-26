#include "ListIterator.h"
#include "IteratedList.h"
#include <stdexcept>

/// Complexity: θ(1)
// Initialise index with the list's head
ListIterator::ListIterator(const IteratedList& list) : list(list) {
    this->index = list.head;
}

/// Complexity: θ(1)
// Iinitialise the first element as the list's head
void ListIterator::first() {
    if (list.isEmpty()) {
        this->index = -1;  // Set the index to an invalid position
    } else {
        this->index = list.head;  // Set the index to the head of the list
    }
}

/// Complexity: θ(1)
void ListIterator::next() {
    if (!this->valid()) {
        throw std::out_of_range("Invalid iterator");
    }

    this->index = list.next[this->index];
}

/// Complexity: θ(1)
bool ListIterator::valid() const {
    return this->index != -1;
}

/// Complexity: θ(1)
TElem ListIterator::getCurrent() const {
    if (!this->valid()) {
        throw std::out_of_range("Invalid iterator");
    }
    //cout << list.elements[this->index] << " ";
    return list.elements[this->index];
}
