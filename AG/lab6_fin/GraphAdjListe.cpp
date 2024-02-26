    #include "GraphAdjListe.h"
    #include <fstream>
    #include <iostream>
    #include <queue>
    #include <set>

    using namespace std;


    GraphAdjListe::GraphAdjListe() {

        ifstream f("input.txt");
        f >> nrNoduri;
        f >> nrMuchii;
        int x, y;
        for (int i = 0; i < nrMuchii; i++) {
            f >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        f.close();
    }

    void GraphAdjListe::show() {
        for (int i = 0; i < nrNoduri; i++,cout<<"\n") {
            cout<<"Knoten: "<<i<<" - Adiacente Knoten: ";
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
        }
    }

    void GraphAdjListe::farbungsAlgorithmus(){
        vector<int> culori(nrNoduri, -1);// Setze c(vn) =1.in cazul meu -1
        vector<bool> vizitat(nrNoduri, false);// pt BFS
        queue<int> queue;// pt BFS

        //inceput de BFS
        int startKnoten = 0;
        queue.push(startKnoten);
        vizitat[startKnoten] = true;

        //Fuhre Breiten- oder Tiefensuche mit Startknotensdurchund nummeriere die Knotenv1,...,vnvonGin derReihenfolge ihres Auftretens.
        int nrNod = 1;
        while (!queue.empty()) {//BFS
            int NodCurent = queue.front();
            queue.pop();

            culori[NodCurent] = nrNod;
            nrNod++;//nummeriere dem actuellen Knoten

            for (int adjVertex : v[NodCurent]) {
                if (!vizitat[adjVertex]) {
                    queue.push(adjVertex);
                    vizitat[adjVertex] = true;
                }
            }
        }

        for (int i = nrNoduri - 1; i >= 0; i--) {//for i=nrNoduri−1,...,1do

            int NodCurent = i;

            // c(vi) = min{q∈N:∀j>imit{vj,vi}∈Egiltc(vj)6=q}.
            set<int> culoriFolosite;
            for (int NodAdj : v[NodCurent]) {
                if (culori[NodAdj] != -1) {
                    culoriFolosite.insert(culori[NodAdj]);
                }
            }

            int culoareMinima = 1;
            while (culoriFolosite.find(culoareMinima) != culoriFolosite.end()) {
                culoareMinima++;
            }

            culori[NodCurent] = culoareMinima;
        }

        //afisare
        for (int i = 0; i < nrNoduri; i++) {
            cout << "Knoten: " << i << " - Farbe: " << culori[i] << "\n";
        }
    }