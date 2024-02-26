#include <iostream>
using namespace std;

int langste_Teilfolge_Similarwerte() {
    std::vector<int> myVector{};
    int value;
    cout << "Please type in elements for the array. If you wanna exit, type 0.";
    cin >> value;
    while (value != 0) {
        myVector.push_back(value);
        cin >> value;
    }
    int cif = 0, cnt = 0, aux1, aux2, max_size = 0;
    std::vector<int> newVector{};
    std::vector<int> maxVector{};
    newVector.push_back(myVector[0]);
    cnt++;
    for (int idx=0; idx<myVector.size()-1; idx++) {
        aux1 = myVector[idx];
        aux2 = myVector[idx+1];
        while (aux1) {
            if (aux1%10 != aux2%10) {
                aux1 = aux1/10;
            }
            else {
                cif++;
                aux1 = aux1/10;
                aux2 = aux2/10;
            }
        }
        if (cif >= 2) {
            newVector.push_back(myVector[idx+1]);
            cnt++;
        }
        else {
            if (cnt > max_size) {
                maxVector = newVector;
                max_size = cnt;
            }
            newVector.clear();
            newVector.push_back(myVector[idx+1]);
            cnt = 1;
        }
        cif = 0;
    }
    
    for(int idx=0; idx<maxVector.size()-1; idx++) {
        cout << maxVector[idx] << " ";
    }
    cout << endl;
    return 0;
}