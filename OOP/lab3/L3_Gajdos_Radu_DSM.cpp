#include <iostream>
#include <fstream>
#include "L3_Gajdos_Radu_DSM.h"
using namespace std;

void DSM::printDSM(){
    for(int i=0;i<anzahlElementen;i++){
        cout<<endl;
        for(int j=0;j<anzahlElementen;j++){
            cout<<matrix[i][j]<<" ";
        }
    }
};

int DSM::size(){
    return anzahlElementen;
}


string DSM::getName(int index){
    return namen[index];
}

int DSM::getNameIndex(string name){
    for(int i=0;i<anzahlElementen;i++){
        if(namen[i]==name){
            return i;
        }
    }
    return -1;
}

void DSM::setElementName(int index, string elementName){
    namen[index]=elementName;
}

void DSM::addLink(string fromElement, string toElement, int weight) {

    int fromIdx = getNameIndex(fromElement);
    int toIdx = getNameIndex(toElement);

    if (fromIdx == -1 || toIdx == -1) {
        if (fromIdx == -1) {

            string neuNamenFromElement[anzahlElementen + 1];
            for (int i = 0; i < anzahlElementen; i++) {
                neuNamenFromElement[i] = namen[i];
            }

            neuNamenFromElement[anzahlElementen] = fromElement;
            fromIdx = anzahlElementen;
            anzahlElementen++;

            DSM DSMneu(neuNamenFromElement, anzahlElementen);

            for (int i = 0; i < anzahlElementen - 1; i++) {
                for (int j = 0; j < anzahlElementen - 1; j++) {
                    DSMneu.matrix[i][j] = matrix[i][j];
                }
            }

            DSMneu.matrix[fromIdx][toIdx] = weight;

            *this = DSMneu;
        }
        if (toIdx == -1) {
            string neuNamenToElement[anzahlElementen + 1];
            for (int i = 0; i < anzahlElementen; i++) {
                neuNamenToElement[i] = namen[i];
            }
            neuNamenToElement[anzahlElementen] = toElement;
            toIdx = anzahlElementen;
            anzahlElementen++;

            DSM DSMneu(neuNamenToElement, anzahlElementen);

            for (int i = 0; i < anzahlElementen - 1; i++) {
                for (int j = 0; j < anzahlElementen - 1; j++) {
                    DSMneu.matrix[i][j] = matrix[i][j];
                }
            }

            DSMneu.matrix[fromIdx][toIdx] = weight;

            *this = DSMneu;
        }

    } else {
        matrix[fromIdx][toIdx] = weight;
    }
}



void DSM::deleteLink(string fromElement,  string  toElement){
    if(matrix[getNameIndex(fromElement)][getNameIndex(toElement)]==0){
        throw exception();
    }
    matrix[getNameIndex(fromElement)][getNameIndex(toElement)]=0;
}


bool DSM::hasLink(string fromElement, string toElement){
    return matrix[getNameIndex(fromElement)][getNameIndex(toElement)]!=0;
}


int DSM::linkWeight(string fromElement, string toElement){
    if(getNameIndex(fromElement)==-1 || getNameIndex(toElement)==-1){
        throw invalid_argument("Einer der Elementen existiert nicht!");
    }
    return matrix[getNameIndex(fromElement)][getNameIndex(toElement)];
}

int DSM::countToLinks(string elementName){
    int ct=0;
    for (int i=0;i<anzahlElementen;i++){
        if (matrix[getNameIndex(elementName)][i] != 0){
            ct+=1;
        }
    }
    return ct;
}


int DSM::countFromLinks(string elementName){
    int ct=0;
    for (int i=0;i<anzahlElementen;i++){
        if (matrix[i][getNameIndex(elementName)] != 0){
            ct+=1;
        }
    }
    return ct;
}

int DSM::countAllLinks(){
    int ct=0;
    for (int i=0;i<anzahlElementen;i++){
        for (int j=0; j<anzahlElementen;j++){
            if (matrix[i][j]!=0){
                ct+=1;
            }
        }
    }
    return ct;
}

void DSM::readFromFile(const string file) {
    ifstream in(file);
    string fromElem, toElem;
    int gewicht;

    if (anzahlElementen != 0)
        throw exception();

    if (in.is_open()) {
        while (in>>fromElem>>gewicht>>toElem) {
            this->addLink(fromElem, toElem, gewicht);
        }
        in.close();
    } else {
        throw exception();
    }
    
}

void DSM::writeToFile(const string file) {
    ofstream out(file);
    for (int i = 0; i < anzahlElementen; i++) {
        if (i != 0)
            out << endl;
        for (int j = 0; j < anzahlElementen; j++)
            out << getName(i) << " " << matrix[i][j] << " " << getName(j) << endl;

    }
    out.close();
}


