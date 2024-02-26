#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

class Graph {
private:
    
    struct Kante{
        int nod1;
        int nod2;
        int kost;
        Kante* next;

        Kante(int n1, int n2, int k) : nod1(n1), nod2(n2), kost(k), next(nullptr) {}

    };

    Kante* head;

public:
    Graph(const string& file);
    void shortestPath(int startKnote, int endKnote);

    ~Graph() {
        while (head != nullptr) {
            Kante* temp = head;
            head = head->next;
            delete temp;
        }
    }

};

#endif  // GRAPH_H




