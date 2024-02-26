#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r) {
    this->space = 10;
    this->len = 0;
    this->elementen = new TComp[this->space];
    this->r = r;
}

// O(n) toate ca itereaza peste for de fiecare data
void SortedSet::resizeUp(TComp* a) {

    this->space *= 2;

    TComp* newElements = new TComp[this->space];

    for (int i = 0; i < this->len; i++) {
        newElements[i] = this->elementen[i];
    }

    delete[] this->elementen;
    this->elementen = newElements;
}

// O(n) toate ca itereaza peste for de fiecare data
void SortedSet::resizeDown(TComp* a) {

    this->space /= 2;

    TComp* newElements = new TComp[this->space];

    for (int i = 0; i < this->len; i++) {
        newElements[i] = this->elementen[i];
    }

    delete[] this->elementen;
    this->elementen = newElements;
}

// O(1) // O(n) // O(2n)
bool SortedSet::add(TComp elem) {

    int index = 0;

    if(search(elem)){
        return false;
    }
    //cauta index
    while (index < this->len && this->r(this->elementen[index], elem)) {
        index++;
    }
    //deja in array
    if (index < this->len && this->elementen[index] == elem) {
        return false;
    }
    //nu mai este loc
    if (this->len == this->space) {
        resizeUp(this->elementen);
    }
    //shift la dreapta
    for (int i = this->len; i > index; i--) {
        this->elementen[i] = this->elementen[i - 1];
    }
    // pe index = elem
    this->elementen[index] = elem;
    this->len++;
    return true;
}

// O(1) // O(n/2) // O(n)
void SortedSet::view(){

    for(int i=0; i < len; i++){
        std::cout << elementen[i] << " ";
    }

}

// O(1) // O(n) // O(2n)
bool SortedSet::remove(TComp elem) {

    int index = 0;



    // cauta index
    while (index < this->len && this->r(this->elementen[index], elem)) {
        index++;
    }
    index--;

    if (index >= 0 && index < this->len && this->elementen[index] == elem) {

        //shift stanga
        for (int i = index; i < this->len - 1; i++) {
            this->elementen[i] = this->elementen[i + 1];
        }

        //fa mai mic
        this->len--;
        //resize daca e mai mic ca jumatate din spatiul alocat
        if (this->len < this->space / 2) {
            resizeDown(this->elementen);
        }
        return true;
    }

    return false;
}

// O(1) // O(n/2) // O(n)
bool SortedSet::search(TComp elem) const {

    for(int i=0; i < len; i++){
        if(elementen[i] == elem){
            return true;
        }
    }
    return false;
}


int SortedSet::size() const {
    return this->len;
}



bool SortedSet::isEmpty() const {
    return this->len == 0;
}

SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    delete[] elementen;
}


