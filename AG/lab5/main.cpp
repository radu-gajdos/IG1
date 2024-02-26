#include "Graph.h"
#include <iostream>

int main() {
    // Create a Graph object with the input file name
    Graph graph("input.txt");

    // Call the shortestPath method
    int startNode, endNode;
    std::cout << "Enter the start node: ";
    std::cin >> startNode;
    std::cout << "Enter the end node: ";
    std::cin >> endNode;

    graph.shortestPath(startNode, endNode);

    return 0;
}