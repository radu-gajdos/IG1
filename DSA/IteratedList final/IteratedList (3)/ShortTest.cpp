#include "ShortTest.h"

#include <assert.h>
#include <exception>
#include <iostream>

#include "IteratedList.h"
#include "ListIterator.h"



using namespace std;

void testlastIndex(){
    IteratedList list = IteratedList();
    list.addToEnd(1);
    list.addToEnd(2);
    list.addToEnd(2);
    list.addToEnd(2);
    assert(list.lastIndex(2)==3);
    assert(list.lastIndex(1)==0);
    assert(list.lastIndex(10)==-1);
}

void testAll() {
	IteratedList list = IteratedList();
	assert(list.size() == 0);
	assert(list.isEmpty());

	list.addToEnd(1);
	assert(list.size() == 1);
	assert(!list.isEmpty());

	ListIterator it = list.search(1);
	assert(it.valid());
	assert(it.getCurrent() == 1);
	it.next();
	assert(!it.valid());
	it.first();
	assert(it.valid());
	assert(it.getCurrent() == 1);

	assert(list.remove(it) == 1);
	assert(list.size() == 0);
	assert(list.isEmpty());

    IteratedList list2 = IteratedList();
	list2.addToEnd(1);
	list2.addToEnd(3);
	list2.addToEnd(7);
    ListIterator it3 = list2.first();
    list2.addToPosition(it3, 77);
	list2.addToPosition(it3, 44);
	assert(list2.size() == 5);
	ListIterator it2 = list2.first();
	assert(it2.getCurrent() == 1);
	it2.next();
	assert(it2.getCurrent() == 77);
	it2.next();
	assert(it2.getCurrent() == 44);
	it2.next();
	assert(it2.getCurrent() == 3);
	it2.next();
	assert(it2.getCurrent() == 7);
	it2.next();
	assert(it2.valid() == false);

	IteratedList list3 = IteratedList();
	list3.addToBeginning(4);
	list3.addToEnd(5);
	list3.addToBeginning(3);
	list3.addToEnd(6);
	list3.addToBeginning(2);
	list3.addToEnd(7);
	int i = 2;
	ListIterator it4 = list3.first();
	while (it4.valid()) {
        //cout << it4.getCurrent() << " ";
		assert(it4.getCurrent() == i);
		i++;
		it4.next();
	}
    cout << "END OF SHORT TESTS";
}

