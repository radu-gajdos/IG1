#ifndef GRAPH_H
#define GRAPH_H

#include <string>

class Graph {
private:
    struct Edge {
        int node1;
        int node2;
        int weight;
        Edge* next;

        Edge(int n1, int n2, int w) : node1(n1), node2(n2), weight(w), next(nullptr) {}
    };

    Edge* head; // Pointer to the head of the linked list

public:
    Graph(const std::string& fileName); // Constructor with file name parameter
    void shortestPath(int startNode, int endNode); // Method to find the shortest path

    // Destructor to release memory
    ~Graph() {
        while (head != nullptr) {
            Edge* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif  // GRAPH_H




