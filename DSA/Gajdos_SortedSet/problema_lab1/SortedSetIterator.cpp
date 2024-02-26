#include "SortedSetIterator.h"
#include <exception>

using namespace std;


//pre: m ist einem SortedSet
//post: man initializiert einem iterator mit dem anfang index von dem initialIndex gegeben
SortedSetIterator::SortedSetIterator(const SortedSet& m, int initialIndex): multime(m), i(initialIndex){}
void SortedSetIterator::first() {
    i=0;
}

//pre: dem iterator ist gultig
//post: dem iterator wird jezt auf dem nachsten stelle sitzen (nicht wenn der element nicht valid ist)
void SortedSetIterator::next() {
    if (!valid()) {
        throw exception();
    }
    i++;
}
//pre: dem iterator ist gultig
//post: dem iterator wird jezt auf dem initialer Stelle + dem angegebenen n (nicht wenn der element nicht valid ist)
void SortedSetIterator::nextn(int n)
{
    if (!valid()) {
        throw exception();
    }
    i+=n;
}


//pre: dem iterator ist gultig
//post: dem iterator wird jezt auf dem initialer Stelle - dem angegebenen n (nicht wenn der element nicht valid ist)
void SortedSetIterator::previousn(int n) {
    if (!valid()) {
        throw exception();
    }
    i-=n;
}

//pre: dem iterator ist gultig
//post: man returniert der element aus dem Set der auf dem jetzigen index steht
TElem SortedSetIterator::getCurrent()
{
    if (!valid()) {
        throw exception();
    }
    return multime.elementen[i];
}

//pre:dem iterator ist gultig
//post: returniert true wenn dem element auf dem dem index zeigt gultig ist und false ansonsten
bool SortedSetIterator::valid() const {
    return i >= 0 && i < multime.size();
}