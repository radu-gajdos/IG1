#include "GraphKantListe.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;

GraphK::GraphK(){

    ifstream in("data.in");

    int n, m;
    int u, v;
    in >> n >> m;
    kanten.resize(m);

    for (int i = 0; i < m; i++) {
        in >> u >> v;
        kanten[i] = make_pair(u, v);
    }
    in.close();
}

void GraphK::showGraphK() {
    for (int i = 0; i < kanten.size(); i++) {
        cout << kanten[i].first << ' ' << kanten[i].second << endl;
    }
}



