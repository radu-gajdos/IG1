
#include <exception>
#include <stdexcept>
#include "ListIterator.h"
#include "IteratedList.h"

// functie suplimentara
// Theta(n)
//precond: valid iterator
//postcond: lastIndex if element is in list; -1 if element is not in list
int IteratedList::lastIndex(TElem e) const {
    ListIterator it = first();
    int i=0;
    int indexFinal = -1;
    while (it.valid()) {
        if (getElement(it) == e) {
            indexFinal = i;
        }
        i++;
        it.next();
    }
    return indexFinal;
}

/// Complexity: θ(n)
// Constructor
IteratedList::IteratedList() {
    this->elements = new TElem[10];
    this->next = new int[10];
    this->prev = new int[10];

    for (int i = 0; i < 10; i++) {
        this->next[i] = i + 1;
        this->prev[i] = i - 1;
        this->elements[i] = NULL_TELEM;
    }

    this->prev[0] = -1;
    this->next[9] = -1;

    this->head = 0; // Set the head to the index of the first element
    this->tail = -1;
    this->capacity = 10;
    this->firstEmpty = 0;
    this->dimensiune = 0;
}

/// Complexity: θ(1)
// Return the number of elements in the list
int IteratedList::size() const {
	return dimensiune;
}

/// Complexity: θ(1)
// Verify if the list is empty
bool IteratedList::isEmpty() const {
    return dimensiune==0;
}

/// Complexity: θ(1)
// Return the first position from the list
ListIterator& IteratedList::first() const {
    ListIterator* it = new ListIterator(*this);
    it->first(); // Reset the iterator to the first position
    return *it;
}

/// Complexity: θ(1)
// Return the element from the given position
TElem IteratedList::getElement(ListIterator pos) const {
    // throws exception if the position is not valid
    if (!pos.valid()) {
        throw std::invalid_argument("get Element invalid");
    }
    return elements[pos.index];
}

/// Complexity: θ(1)
// Remove the element from position pos
TElem IteratedList::remove(ListIterator& pos) {
    // throws exception if the position is not valid
    if (!pos.valid()) {
        throw std::invalid_argument("remove Element invalid");
    }

    // Save the value of the element to be removed
    TElem removedElement = elements[pos.index];

    // Update the indices of the neighboring nodes
    if (pos.index == head) {
        head = next[head];
        prev[head] = -1;
    }
    else if (pos.index == tail) {
        tail = prev[tail];
        next[tail] = -1;
    }
    else {
        next[prev[pos.index]] = next[pos.index];
        prev[next[pos.index]] = prev[pos.index];
    }

    // Update the empty slots list
    next[pos.index] = firstEmpty;
    firstEmpty = pos.index;

    // Update the size of the list
    dimensiune--;

    // Update the position of the iterator to point to the next element
    pos.next();

    return removedElement;
}

/// Complexity: O(n)
// Search for the first occurrence of an element
ListIterator IteratedList::search(TElem e) const{
    ListIterator it(*this);  // create an iterator pointing to the beginning of the list
    while (it.valid()) {  // loop through the list
        if (it.getCurrent() == e) {  // if the current element matches the given element, return the iterator
            return it;
        }
        it.next();  // move to the next element
    }
    return ListIterator(*this);  // return an invalid iterator if the element was not found
}

/// Complexity: θ(1)
// Change the element from current position to given position
TElem IteratedList::setElement(ListIterator pos, TElem e) {
    // throws exception if the position is not valid
    if (!pos.valid()) {
        throw std::invalid_argument("set Element invalid");
    }
    int current = pos.index;
    TElem old = elements[current];
    elements[current] = e;
    // return the old value from the position
    return old;
}

/// Complexity: θ(1)
// Add a new element after the current element
void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    if (!pos.valid()) {
        throw std::invalid_argument("Invalid position");
    }

    if (firstEmpty == -1) {
        resize();
    }

    int newPosition = firstEmpty;
    firstEmpty = next[firstEmpty];

    elements[newPosition] = e;

    prev[newPosition] = pos.index;
    next[newPosition] = next[pos.index];

    if (next[pos.index] != -1) {
        prev[next[pos.index]] = newPosition;
    } else {
        tail = newPosition;
    }

    next[pos.index] = newPosition;

    pos.index = newPosition;
    dimensiune++;
}

/// Complexity: θ(1)
// Add an element to the end of the list
void IteratedList::addToEnd(TElem e) {
    if (firstEmpty == -1) {
        resize();
    }

    int newPosition = firstEmpty;
    firstEmpty = next[firstEmpty];

    elements[newPosition] = e;

    next[newPosition] = -1;
    prev[newPosition] = tail;

    if (tail != -1) {
        next[tail] = newPosition;
    } else {
        head = newPosition;
    }
    tail = newPosition;
    dimensiune++;
}

/// Complexity: O(n)
// Destructor
IteratedList::~IteratedList() {
    delete[] elements;
    delete[] next;
    delete[] prev;
}

/// Complexity: θ(n)
// Resize
void IteratedList::resize() {
    int newCapacity = capacity * 2;  // Double the capacity

    // Create new dynamic arrays with the new capacity
    TElem* newElements = new TElem[newCapacity];
    int* newNext = new int[newCapacity];
    int* newPrev = new int[newCapacity];

    // Copy the existing elements, next, and prev arrays to the new arrays
    for (int i = 0; i < capacity; i++) {
        newElements[i] = elements[i];
        newNext[i] = next[i];
        newPrev[i] = prev[i];
    }

    // Initialize the remaining positions in the new arrays
    for (int i = capacity; i < newCapacity; i++) {
        newNext[i] = i + 1;  // Set the next pointer to the next position
        newPrev[i] = -1;  // Set the previous pointer to -1
    }
    newNext[newCapacity - 1] = -1;  // Set the last position's next pointer to -1

    // Update the firstEmpty pointer to the first newly created position
    firstEmpty = capacity;

    // Update the tail pointer if it points to an empty position
    if (tail == -1) {
        tail = capacity;
    }

    // Delete the old dynamic arrays
    delete[] elements;
    delete[] next;
    delete[] prev;

    // Update the member variables with the new arrays and capacity
    elements = newElements;
    next = newNext;
    prev = newPrev;
    capacity = newCapacity;
}

/// Complexity: θ(1)
// Add an element to the beginning of the list
void IteratedList::addToBeginning(TElem e) {
    if (firstEmpty == -1) {
        resize();
    }

    int newPosition = firstEmpty;
    firstEmpty = next[firstEmpty];

    elements[newPosition] = e;

    if (isEmpty()) {
        // If the list is empty, update both head and tail pointers
        head = newPosition;
        tail = newPosition;
        prev[newPosition] = -1;
        next[newPosition] = -1;
    } else {
        // If the list is not empty, update the head pointer and previous/next pointers
        next[newPosition] = head;
        prev[newPosition] = -1;
        prev[head] = newPosition;
        head = newPosition;
    }

    dimensiune++;
}




