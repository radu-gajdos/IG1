#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
    int i;

public:
    SortedSetIterator(const SortedSet& m, int index=0);

    void first();
    void next();
    void nextn(int n);
    void previousn(int n);
	TElem getCurrent();
	bool valid() const;
};

