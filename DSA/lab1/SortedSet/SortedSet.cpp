#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r) {
	space=3;
	nrElems = 0;
	a = new TComp [nrElems];
	this->r=r;
}


bool SortedSet::add(TComp elem) {
	if(space<nrElems) space+=1;
	int poz=-1;
	for(int i=1; i<nrElems-1;i++){
		if(a[i]==elem){
			return false;
		}
		if(r(a[i],a[i-1])){
			poz=i;
		}
	}
	nrElems++;
	for(int i=nrElems; i>poz; i--){
		a[i]=a[i-1];
	}
	a[poz]=elem;
	return true;
}


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	return false;
}


bool SortedSet::search(TComp elem) const {
	//O(n)
	for(int i=0;i<nrElems; i++){
		if (a[i]==elem) return true;
	}
	return false;
}


int SortedSet::size() const {
	return nrElems;
}



bool SortedSet::isEmpty() const {
	//O(1)
	if (a[0]) return true;
	return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {

	delete[] a;
}


