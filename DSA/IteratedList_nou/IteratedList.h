#pragma once
#include "ListIterator.h"

#define NULL_TELEM -11111

typedef int TElem;

class IteratedList {
private:
    friend class ListIterator;

    TElem* elements;
    int* next;
    int* previous;
    int head;
    int tail;
    int capacity;
    int size;
    int firstEmpty;

public:
    IteratedList();
    int size() const;
    bool isEmpty() const;
    ListIterator first() const;
    TElem getElement(ListIterator pos) const;
    TElem setElement(ListIterator pos, TElem e);
    void addToEnd(TElem e);
    void addToBeginning(TElem e);
    void addToPosition(ListIterator& pos, TElem e);
    TElem remove(ListIterator& pos);
    ListIterator search(TElem e) const;
    ~IteratedList();

private:
    void resize();
    int allocateNode(TElem e);
    void freeNode(int pos);
};
