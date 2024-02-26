#include <vector>
#ifndef GRAPHEN_LAB1_ADJAZENZLISTE_H
#define GRAPHEN_LAB1_ADJAZENZLISTE_H


class Adjazenzliste {
private:
    int n;
    int m;
    std::vector<int> array[100];

public:

    Adjazenzliste();

    void addToArray(int x,int y);

    void displayArray();

    void coloringAlgorithm();
};



#endif //GRAPHEN_LAB1_ADJAZENZLISTE_H
