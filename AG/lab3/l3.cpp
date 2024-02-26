#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int n = 0, m = 0;
    ifstream file(R"(C:\Users\Radu\Desktop\AG\lab3\labyrinth2.txt)");
    file >> n >> m;
    vector<vector<int>> vectorAdj(n * m);

    vector<vector<char>> matrice(n, vector<char>(m));
    //treci peste n,m
    for (int i = 0; i < n; i++) {
        file.ignore();
        for (int j = 0; j < m; j++) {
            matrice[i][j] = file.get();
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<endl;
        for (int j = 0; j < m; j++) {
            cout<<matrice[i][j];
        }
    }

    int nodStart=0;
    int nodFin=0;
    int nod=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nod++;
            if (matrice[i][j] != 'X') {
                if(matrice[i][j] == 'S'){//daca ii nodu de start
                    nodStart=nod;
                }
                if(matrice[i][j] == 'F'){//daca ii nodu de finish
                    nodFin=nod;
                }
                if (i < n - 1 && matrice[i + 1][j] != 'X') {//vecin sus
                    vectorAdj[nod].push_back(nod + m);
                }
                if (i > 0 && matrice[i - 1][j] != 'X') {//vecin jos
                    vectorAdj[nod].push_back(nod - m);
                }
                if (j > 0 && matrice[i][j - 1] != 'X') {//vecin stange
                    vectorAdj[nod].push_back(nod - 1);
                }
                if (j < m - 1 && matrice[i][j + 1] != 'X') {//vecin dreapta
                    vectorAdj[nod].push_back(nod + 1);
                }
            }
        }
    }

    //afiseaza lista de adiacenta
    for (int i = 0; i < n * m; i++) {
        cout << "Nod " << i << ": ";
        for (int nod : vectorAdj[i]) {
            cout << nod << " ";
        }
        cout << endl;
    }

    //BFS
    queue<int> q;
    vector<int> vizitat(n * m, -1);
    vector<int> drum;
    q.push(nodStart);
    while (!q.empty()) {
        int nodActual = q.front();
        q.pop();
        for(int nod : vectorAdj[nodActual]){
            if(vizitat[nod]==-1){
                cout<<nod<<endl;
                vizitat[nod]=nodActual;
                q.push(nod);
                if(nod==nodFin){//merge dar afiseaza nr nodurilor pe care merge

                    vector<int> drum;
                    int nodDrum = nod;
                    while (nodDrum != nodStart) {
                        drum.push_back(nodDrum);
                        nodDrum = vizitat[nodDrum];
                    }
                    drum.push_back(nodStart);

                    for(int i=drum.size()-1;i>=0;i--){
                        cout<<drum[i]<<"-";
                    }
                    cout<<nodFin<<"(Finish)";
                }
            }
        }
    }

    return 0;
}