#include "GraphAdjListe.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

GraphL::GraphL(){

    ifstream f;
    f.open("data.in");
    f>>m;
    f>>n;
    for(int i = 0; i < n; i++)
    {
        vector<int> row;
        l.push_back(row);
    }
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdge(x, y);
    }

}

void GraphL::addEdge(int u, int v)
{
    l[u].push_back(v);
    l[v].push_back(u);
}

void GraphL::printGraph() {
    cout<<"\n";
        for (int i = 0; i < l.size(); i++) {
            cout << "Nod principal " << i << ": ";
            for (int j = 0; j < l[i].size(); j++) {
                cout << l[i][j] << ", ";
            }
            cout << endl;
        }
    }