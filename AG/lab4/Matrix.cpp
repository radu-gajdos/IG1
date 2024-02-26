#include "C:\Users\Radu\Desktop\AG\lab4\Matrix.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Graph::Graph(){}

GraphNou::GraphNou(string filename) {
    noduri=0;
    muchii=0;
    int nod1, nod2, cost;
    ifstream f(filename);
    f>>noduri;
    f>>muchii;

    for(int i=0;i<noduri;i++)
    {
        vector<int>r;
        adjliste.push_back(r);
        
        for(int j=0;j<noduri;j++)
            r.push_back(0);
            
        matrix.push_back(r);
    }

    for(int i=0;i<muchii;i++)
    {
        f>>nod1>>nod2>>cost;
        adjliste[nod1].push_back(nod2);
        adjliste[nod2].push_back(nod1);
        matrix[nod1][nod2] = cost;
    }

    
}

void GraphNou::afiseazaMatrix(){
    cout<<std::endl;
    for(int i=0;i<noduri;i++){
            cout<<std::endl;
            for(int j=0;j<noduri;j++){
                cout<<matrix[i][j]<<" ";
            }
        }
    }

void GraphNou::afiseazaAdjliste(){
    cout<<std::endl;
    for(int i = 0; i < noduri; i++) {
        cout << i << ": ";
        for(int j = 0; j < adjliste[i].size(); j++) {
            cout << adjliste[i][j] << " ";
        }
        cout << endl;
    }
}

void GraphNou::minimalerSpannbaum() {

    vector<bool> vizitat(noduri, false);
    vector<int> costMin(noduri, 999);

    costMin[0] = 0;

    for (int i = 0; i < noduri - 1; i++) {
        int minimalu = -1;
        for (int j = 0; j < noduri; j++) {
            if (!vizitat[j] && (minimalu == -1 || costMin[j] < costMin[minimalu])) {
                minimalu = j;
            }
        }

        vizitat[minimalu] = true;

    }
}