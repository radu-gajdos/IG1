#include "Graph.h"
#include <iostream>

int main() {
    
    Graph g("input.txt");

    int startNode, endNode;
    std::cout << " Start Knote: ";
    std::cin >> startNode;
    std::cout << "End Knote: ";
    std::cin >> endNode;

    g.shortestPath(startNode, endNode);

    return 0;
}