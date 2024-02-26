#include <iostream>
using namespace std;



int main() {

    int l=9;
    int v[l]={1,2,-3,-4,5,6,-7,-8,9};

    int start = 0, end = 0, max_start = 0; 
    int max_s = v[0], s = v[0];

    for (int i = 1; i < l; i++) {

        if (s + v[i] < v[i]) {
            s = v[i];
            start = i;
            cout<<"start: "<<start<<" ";
        }else {
            s += v[i];
            cout<<"s: "<<s<<" ";
        }

        if (s > max_s) {
            end = i;
            max_start = start;
            cout<<"end: "<<end<<" ";
            max_s = s;
            cout<<"max_s: "<<max_s<<" ";
        }

        cout<<"\n";
    }

    cout << "Die laengste aufeinanderfolgende Teilfolge mit der maximalen Summe ist: ";
    for (int i = max_start; i <= end; i++) {
        cout << v[i] << ", ";
    }
    return 0;
}