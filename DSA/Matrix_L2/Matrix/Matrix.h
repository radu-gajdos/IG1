#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

struct Node {
    int rand;
    int coloana;
    TElem valoare;
    Node* next;

    Node(int r, int c, TElem val) : rand(r), coloana(c), valoare(val), next(nullptr) {}
};

class Matrix {

private:
    int rows;
    int cols;
    Node* head;

public:


	//Konstruktor
	Matrix(int nrLines, int nrCols);

	//Anzahl Linien
	int nrLines() const;

	//Anzahl Coloane
	int nrColumns() const;

	//returniert dem element an die position i,j oder exception wenn das element nicht existiert
	TElem element(int i, int j) const;


    //returniert dem elementu dinainte und modifiziert dem element an der Stelle i,j oder exception wenn die position invalid ist
	TElem modify(int i, int j, TElem e);

    //Matrix transpoze functie suplimentara
    void transpose();

    void print();

	//Destruktor
	~Matrix();

};
