#ifndef M
#define M
#include <string>
#include <vector>

using namespace std;

class Graph{

protected:
    int noduri; 
    int muchii;
    vector< vector<int> > adjliste;

public:
    Graph();

};

class GraphNou: public Graph{

private:
    vector <vector<int>> matrix;

public:
    GraphNou(string filename);
    void minimalerSpannbaum();
    void afiseazaMatrix();
    void afiseazaAdjliste();
};


#endif
