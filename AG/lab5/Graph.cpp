#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

Graph::Graph(const std::string& fileName) : head(nullptr) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    int node1, node2, weight;
    while (inputFile >> node1 >> node2 >> weight) {
        Edge* newEdge = new Edge(node1, node2, weight);
        newEdge->next = head;
        head = newEdge;
    }

    inputFile.close();
}

void Graph::shortestPath(int startNode, int endNode) {
    // Count the number of nodes in the graph
    int numNodes = 0;
    Edge* currentNode = head;
    while (currentNode != nullptr) {
        numNodes = max(numNodes, max(currentNode->node1, currentNode->node2));
        currentNode = currentNode->next;
    }
    numNodes++; // Add 1 to include the highest node index

    // Initialize the distance array
    vector<int> distance(numNodes, INT_MAX);
    distance[startNode] = 0;

    // Initialize the predecessor array to track the path
    vector<int> predecessor(numNodes, -1);

    // Relax edges repeatedly
    for (int i = 0; i < numNodes - 1; ++i) {
        currentNode = head;
        while (currentNode != nullptr) {
            int source = currentNode->node1;
            int destination = currentNode->node2;
            int weight = currentNode->weight;

            if (distance[source] != INT_MAX && distance[source] + weight < distance[destination]) {
                distance[destination] = distance[source] + weight;
                predecessor[destination] = source;
            }

            currentNode = currentNode->next;
        }
    }

    // Check for negative cycles
    currentNode = head;
    while (currentNode != nullptr) {
        int source = currentNode->node1;
        int destination = currentNode->node2;
        int weight = currentNode->weight;

        if (distance[source] != INT_MAX && distance[source] + weight < distance[destination]) {
            cerr << "Negative cycle detected!" << endl;
            return;
        }

        currentNode = currentNode->next;
    }

    // Reconstruct the shortest path
    vector<int> path;
    int current = endNode;
    while (current != -1) {
        path.push_back(current);
        current = predecessor[current];
    }

    // Display the shortest path and its associated cost
    cout << "Shortest path from " << startNode << " to " << endNode << ":" << endl;
    cout << "Cost: " << distance[endNode] << endl;
    cout << "Path: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i != 0) {
            cout << " -> ";
        }
    }
    cout << endl;
}
