//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_ELEKTROSCOOTER_H
#define LAB5_ELEKTROSCOOTER_H

#include <cstdio>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

namespace Domain {

    class Elektroscooter {
    private:
        int kilometer;
        string modell, inbetriebnahmedatum, letzterStandort, id;
        string aktuellerZustand; // cu case geparkt, reserviert, in Verwendung, inWartung, außer Betrieb

    public:

        Elektroscooter(string id, int km, string modell1, string inbetribnahmedatum1, string letzterStandort1,
                       string aktuellerZustand1) {
            this->id = id;
            this->kilometer = km;
            this->modell = modell1;
            this->inbetriebnahmedatum = inbetribnahmedatum1;
            this->letzterStandort = letzterStandort1;
            this->aktuellerZustand = aktuellerZustand1;
        };

        Elektroscooter &operator=(const Elektroscooter &other) {
            if (this != &other) {
                id = other.id;
                kilometer = other.kilometer;
                modell = other.modell;
                inbetriebnahmedatum = other.inbetriebnahmedatum;
                letzterStandort = other.letzterStandort;
                aktuellerZustand = other.aktuellerZustand;
            }
            return *this;
        }

        Date convertDate();

        string get_id() {
            return this->id;
        }

        int get_kilometer() {
            return this->kilometer;
        }

        string get_modell() {
            return this->modell;
        }

        string get_inbetriebnahmedatum() {
            return this->inbetriebnahmedatum;
        }

        string get_letzterStandort() {
            return this->letzterStandort;
        }

        string get_aktuellerZustand() {
            return this->aktuellerZustand;
        }

        void set_aktuellerZustand(string newZustand) {
            this->aktuellerZustand = newZustand;
        }

        void printForCustomer();

        void printForManager();

    };

}

#endif //LAB5_ELEKTROSCOOTER_H
