#pragma once
#include "IteratedList.h"

class IteratedList;  // Forward declaration
typedef int TElem;

class ListIterator {
    friend class IteratedList;
private:
    const IteratedList& list;
    int current;

public:
    // Constructor
    ListIterator(const IteratedList& list);

    // Moves the iterator to the first position in the list
    void first();

    // Moves the iterator to the next position in the list
    void next();

    // Checks if the iterator is at a valid position
    bool valid() const;

    // Returns the element at the current position
    TElem getCurrent() const;
};
