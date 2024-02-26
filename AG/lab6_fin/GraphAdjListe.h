#include <vector>
#ifndef GRAPHEN_LAB1_ADJAZENZLISTE_H
#define GRAPHEN_LAB1_ADJAZENZLISTE_H

using namespace std;

class GraphAdjListe {
private:
    int nrNoduri;
    int nrMuchii;
    vector<int> v[50];

public:

    GraphAdjListe();

    void show();

    void farbungsAlgorithmus();
};



#endif //GRAPHEN_LAB1_ADJAZENZLISTE_H
