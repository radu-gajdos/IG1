#include "ShortTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <assert.h>
#include <iostream>

bool r2(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    }
    else {
        return false;
    }
}


void testAll() {
    TComp e;

    SortedSet s1(r2);
    assert(s1.add(5) == true);
    assert(s1.add(1) == true);
    assert(s1.add(10) == true);
    SortedSetIterator it1(s1,0);
    it1.nextn(2);
    assert(it1.getCurrent()==10);
//    try {
//        it1.nextn(2);
//        assert(false);
//    }
//    catch (std::exception&) {
//        assert (true);
//    }

    SortedSet s2(r2);
    assert(s2.add(0) == true);
    assert(s2.add(1) == true);
    assert(s2.add(2) == true);
    assert(s2.add(3) == true);
    assert(s2.add(4) == true);
    assert(s2.add(5) == true);
    assert(s2.add(6) == true);
    SortedSetIterator it2(s2,4);
    it2.previousn(2);
    assert(it2.getCurrent()==2);



}

