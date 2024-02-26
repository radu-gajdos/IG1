#include "Matrix.h"
#include<iostream>
#include<fstream>

using namespace std;

int main(){

    GraphNou g("C:\\Users\\Radu\\Desktop\\AG\\lab4\\file.txt");
    g.afiseazaMatrix();
    g.afiseazaAdjliste();
    g.minimalerSpannbaum();

}