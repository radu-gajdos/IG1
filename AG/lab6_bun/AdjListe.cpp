#include "AdjListe.h"
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

Adjazenzliste::Adjazenzliste() {

    ifstream f;
    f.open("data.in");
    f >> this->n;
    f >> this->m;
    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        addToArray(x,y);
    }
}

void Adjazenzliste::addToArray(int x,int y) {
    array[x].push_back(y);
    array[y].push_back(x);
}

void Adjazenzliste::displayArray() {
    for (int i = 0; i<n; i++) {
        cout<<i<<": ";
        for (int j = 0; j<array[i].size(); j++) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Adjazenzliste::coloringAlgorithm() {
    std::vector<int> colors(n, -1);  // Setze c(vn) =1.in cazul meu -1
    std::vector<bool> visited(n, false);  // pt BFS
    std::queue<int> queue;  // pt BFS

    int startVertex = 0;
    queue.push(startVertex);
    visited[startVertex] = true;

    // Step 1: Perform BFS or DFS starting from vertex s and number the vertices
    int vertexNumber = 1;
    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        // Number the current vertex
        colors[currentVertex] = vertexNumber;
        vertexNumber++;

        // Explore the adjacent vertices
        for (int adjVertex : array[currentVertex]) {
            if (!visited[adjVertex]) {
                queue.push(adjVertex);
                visited[adjVertex] = true;
            }
        }
    }

    // Step 2: Assign colors to the vertices in reverse order
    for (int i = n - 1; i >= 0; i--) {
        int currentVertex = i;

        // c(vi) = min{q∈N:∀j>imit{vj,vi}∈Egiltc(vj)6=q}.
        std::unordered_set<int> usedColors;
        for (int adjVertex : array[currentVertex]) {
            if (colors[adjVertex] != -1) {
                usedColors.insert(colors[adjVertex]);
            }
        }

        int smallestColor = 1;
        while (usedColors.find(smallestColor) != usedColors.end()) {
            smallestColor++;
        }

        // Assign the smallest color to the current vertex
        colors[currentVertex] = smallestColor;
    }

    // Output: Display the assigned colors for each vertex
    std::cout << "Vertex Colors:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Vertex " << i << ": Color " << colors[i] << "\n";
    }
}


