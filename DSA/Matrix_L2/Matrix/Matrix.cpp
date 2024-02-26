#include "Matrix.h"
#include <exception>
#include <iostream>
using namespace std;

//Theta(1)
Matrix::Matrix(int nrLines, int nrCols)  : rows(nrLines), cols(nrCols), head(nullptr) {}

//Theta(1)
int Matrix::nrLines() const {
    return rows;
}

//Theta(1)
int Matrix::nrColumns() const {
    return cols;
}

//Theta(1), O(n/2), O(n)
TElem Matrix::element(int i, int j) const {

    //nu se afla in limitele matricii => exceptie
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw exception();
    }

    Node* curent = head;//initializezi cu primu element(head-ul)

    while (curent != nullptr) { //pana cand nu iese din limitele matricii
        if (curent->rand == i && curent->coloana == j) {//daca elementul curent are indexii i si j
            return curent->valoare;//returneaza val element
        }
        curent = curent->next;//incearca urmatorul
    }
	return NULL_TELEM;
}

//Theta(1), O(n/2), O(2n)
TElem Matrix::modify(int i, int j, TElem e)
{
    //incerci sa pui elem nou in afara limitelor matricii => exceptie
    if (i < 0 || i >= nrLines() || j < 0 || j >= nrColumns()) {
        throw exception();
    }

    Node* prev = nullptr;//prev initializat
    Node* curent = head;//current initializat cu primul element al matricii
    while (curent != nullptr && curent->rand < i) {//parcurgi matricia pentru a ajunge pe linia corecta
        prev = curent;//ti minte prev
        curent = curent->next;//si ti minte curent
    }

    while (curent != nullptr && curent->rand == i && curent->coloana < j) {//parcurgi matricia pana ajungi la coloana corecta
        prev = curent;//ti minte prev
        curent = curent->next;//si ti minte curent
    }

    if (curent != nullptr &&     curent->rand == i && curent->coloana == j) { //daca elementul se afla in matricie
        TElem valoareVeche = curent->valoare;
        if (e == NULL_TELEM) {//cazul in care exista dar trebuie transformat in NULL_TELEM => se sterge
            if (prev == nullptr) {//este primul
                head = curent->next;
            } else {//nu este primul
                prev->next = curent->next;
            }
            delete curent;//stergel
        } else {//cazul in care elementul exista si trebuie modificat
            curent->valoare = e;
        }
        return valoareVeche;//dupa cerinta
    }else {//daca elementul nu exista in matrice
        if (e == NULL_TELEM) {//daca este NULL_TELEM
            return NULL_TELEM;//nu faci nimic si returnezi valoare veche adica nimic(NULL_TELEM)
        }
        Node* NodNou = new Node(i, j, e);//cream nodul nou
        if (prev == nullptr) {//daca trebuie sa fie primul
            head = NodNou;
        } else {//daca nu este primul
            prev->next = NodNou;
        }
        NodNou->next = curent;//creezi legatura
        return NULL_TELEM;//valoare veche nu exista(NULL_TELEM)
    }
}


//O(1)//O((rows^cols)/2)//O(rows^cols)
//pre:
//      die matrix war gut gebildet und enthaelt valide elemente.
//      die matrix ist eine valide sparse matrix mit dem anzahl von rows and columns initializiert.


//post:
//      die transposition des matrix war gebildet.
//      die originale matrix war mit die neue ersetzt.
//      dem Anzahl von rows and columns von dem originalen matrix waren vertauscht.
//      die transposition des matrix ist eine valide sparse matrix.
void Matrix::transpose() {

    Matrix t(cols, rows);

    //parcurgi toata matricia si dai modify de j,i in loc de poz i,j
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            TElem elem = element(x, y);
            if (elem != NULL_TELEM) {
                t.modify(y, x, elem);
            }
        }
    }

    //copiezi headul in NodTemp
    Node* NodTemp = head;
    head = t.head;
    t.head = NodTemp;

    //si in caz ca rows si cols sunt de nr diferit le schimbi (matricea nu este patratica)
    swap(rows,cols);
}

//asta ii pt debug-ingul meu
void Matrix::print() {
    for(int i=0;i<rows;i++, cout<<std::endl)
        for(int j=0;j<rows;j++)
            cout<<element(i,j)<<" ";
}

//Theta(n)
Matrix::~Matrix() {
    Node* current = head; //incepi de la primul nod
    while (current != nullptr) {//le parcurgi pe toate
        Node* next = current->next;//memorezi "i++-ul"
        delete current;//delete
        current = next;//next (adica un fel de i++ numai ca trebuie sa ocolim delete-ul)
    }
}