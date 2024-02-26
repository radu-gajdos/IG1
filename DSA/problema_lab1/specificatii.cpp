#include <iostream>
using namespace std;

//functiile de next n si previous n sunt schimbate pentru a functiona try si catchul

void SortedSetIterator::nextn(int n)
{
    int temp=i+n;
    if (temp<multime.len) {
        throw exception();
    }
    i+=n;
}   

void SortedSetIterator::previousn(int n) {
    int temp=i+n;
    if (temp<0) {
        throw exception();
    }
    i-=n;
}

//searchul din SortedSet facut binar

bool SortedSet::search(TComp elem) const {

    st=0;
    dr=this->len;
    

    while(st<dr){
        mid=(st+dr)/2;
        if (elementen[mid]==elem){
            return true;
        }else{
            if(elem<elementen[mid]){
                dr=mid;
            }else{
                st=mid;
            }
        }
    }

}