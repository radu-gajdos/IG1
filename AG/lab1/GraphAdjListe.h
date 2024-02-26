#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class GraphL {
private:
    int m;
    int n;
    vector<vector<int>> l;

public:

    GraphL();

    void addEdge(int u, int v);

    bool isEdge(int x, int y);

    void printGraph();

};