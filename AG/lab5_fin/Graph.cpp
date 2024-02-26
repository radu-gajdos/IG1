#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

Graph::Graph(const string &file) : head(nullptr)
{
    ifstream in(file);
    if (!in)
    {
        throw invalid_argument("Nume fisier invalid!");
        return;
    }

    int knote1, knote2, kost;
    while (in >> knote1 >> knote2 >> kost)
    {
        Kante *newEdge = new Kante(knote1, knote2, kost);
        newEdge->next = head;
        head = newEdge;
    }

    in.close();
}

void Graph::shortestPath(int startNode, int endNode)
{
    // Anzahl der knoten bestimmen
    int numNodes = 0;
    Kante *currentNode = head;
    while (currentNode != nullptr)
    { // parcurgi toate
        numNodes = max(numNodes, max(currentNode->nod1, currentNode->nod2));
        currentNode = currentNode->next;
    }
    numNodes++; // adaugi si nodul cu

    // algo propriuzis ca in curs

    // Distanz(v) :=∞
    vector<int> distanz(numNodes, numeric_limits<int>::max());

    // Distanz(s) := 0
    distanz[startNode] = 0;

    // Vorganger(v) := keiner
    vector<int> vorganger(numNodes, -1);

    for (int i = 0; i < numNodes - 1; ++i)
    { // wiederhole|V|−1 mal
        currentNode = head;
        while (currentNode != nullptr)
        { // fur jedes(u,v)aus E
            int u = currentNode->nod1;
            int v = currentNode->nod2;
            int kost = currentNode->kost;

            if (distanz[u] != numeric_limits<int>::max() && distanz[u] + kost < distanz[v])
            {                                   // wenn(Distanz(u) + Gewicht(u,v))<Distanz(v)dann
                distanz[v] = distanz[u] + kost; // Distanz(v) := Distanz(u) + Gewicht(u,v)
                vorganger[v] = u;               // Vorganger(v) :=u
            }

            currentNode = currentNode->next; // continua loop-ul
        }
    }

    currentNode = head;
    while (currentNode != nullptr)
    { // fur jedes(u,v)ausE
        int u = currentNode->nod1;
        int v = currentNode->nod2;
        int kost = currentNode->kost;

        if (distanz[u] != numeric_limits<int>::max() && distanz[u] + kost < distanz[v])
        { // wenn(Distanz(u) + Gewicht(u,v))<Distanz(v) dann
            throw invalid_argument("STOPP mit Ausgabe: Es gibt Kreis negativen Gewichtes.");
            return;
        }

        currentNode = currentNode->next; // continua loop-ul
    }

    // creeaza path-ul prin a parcurge vorgangeri invers ->
    vector<int> path;
    int current = endNode;
    while (current != -1)
    {
        path.push_back(current);
        current = vorganger[current];
    }

    // Afisarea (de la primu la ultimul deci dupa cum am create path-ul invers o iau de la capatul vectorului la inceput)
    cout << "Kost: " << distanz[endNode] << endl;
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i];
        if (i != 0)
            cout << " --- ";
    }
}
