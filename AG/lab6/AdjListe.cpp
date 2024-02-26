#include "AdjListe.h"
#include <fstream>
#include <iostream>

using namespace std;

Adjazenzliste::Adjazenzliste() {

    ifstream f;
    f.open("data.in");
    f >> this->n;
    f >> this->m;
    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        addToArray(x,y);
    }
}

void Adjazenzliste::addToArray(int x,int y) {
    array[x].push_back(y);
    array[y].push_back(x);
}

void Adjazenzliste::displayArray() {
    for (int i = 0; i<n; i++) {
        cout<<i<<": ";
        for (int j = 0; j<array[i].size(); j++) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Adjazenzliste::maximalGrad() {
    int max = 0;
    for (int i = 0; i<n; i++) {
        if (array[i].size() > max)
            max = int(array[i].size());
    }
    cout<<"Maximalgrad ist: "<<max <<endl;
}

void Adjazenzliste::minimalGrad() {
    int min = 10000;
    for (int i = 0; i<n; i++) {
        if (array[i].size() < min)
            min = int(array[i].size());
    }
    cout<<"Minimalgrad ist: "<<min;
}

