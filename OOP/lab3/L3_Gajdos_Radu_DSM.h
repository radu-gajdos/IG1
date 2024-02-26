#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
class DSM {
private:
    string *namen;
    int anzahlElementen;
    int **matrix;

public:
    // ersten Konstruktor

    DSM(int anzahlElementen) {

        this->anzahlElementen = anzahlElementen;
        namen = new string[anzahlElementen];
        matrix = new int*[anzahlElementen];

        for (int i = 0; i < anzahlElementen; i++) {

            matrix[i] = new int[anzahlElementen];

            for (int j = 0; j < anzahlElementen; j++) matrix[i][j] = 0;
        }
    }

    // zweiten Konstruktor

    DSM(string namen[], int anzalElementen) : DSM(anzalElementen){

        for (int i = 0; i < anzahlElementen; i++) {
            this->namen[i] = namen[i];
        }

    }

    // copy Konstruktor
    DSM(const DSM& other) {

        this->anzahlElementen = other.anzahlElementen;

        this->namen = new string[anzahlElementen];

        for (int i = 0; i < anzahlElementen; i++) {
            this->namen[i] = other.namen[i];
        }

        this->matrix = new int*[anzahlElementen];

        for (int i = 0; i < anzahlElementen; i++) {

            this->matrix[i] = new int[anzahlElementen];

            for (int j = 0; j < anzahlElementen; j++) {
                this->matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // Destruktor
    ~DSM() {

       // delete[] namen;

      //  for (int i = 0; i < anzahlElementen; i++) {
      //      delete[] matrix[i];
    //    }

    //    delete[] matrix;
    }


    void printDSM();

    int size();

    string getName(int index);

    int getNameIndex(string name);

    void setElementName(int index, string elementName);

    void addLink(string fromElement,  string  toElement, int weight);

    void deleteLink(string fromElement,  string  toElement);

    bool hasLink(string fromElement, string toElement);

    int linkWeight(string fromElement, string toElement);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();

    void readFromFile(string file);

    void writeToFile(string file);

};