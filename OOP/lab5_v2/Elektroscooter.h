//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_ELEKTROSCOOTER_H
#define LAB5_ELEKTROSCOOTER_H

#include <cstdio>
#include <string>
#include <stdexcept>

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
        string aktuellerZustand;

    public:

        Elektroscooter(const string& id, int km, const string& modell1, const string& inbetribnahmedatum1, const string& letzterStandort1,
                       const string& aktuellerZustand1);

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

//        bool same(Elektroscooter &other){
//            if(id == other.id &&
//                    kilometer == other.kilometer &&
//                    modell == other.modell &&
//                    inbetriebnahmedatum == other.inbetriebnahmedatum &&
//                    letzterStandort == other.letzterStandort &&
//                    aktuellerZustand == other.aktuellerZustand){
//                return true;
//            }else{
//                return false;
//            }
//        }

        bool isValidDate(const string &dateStr);

        Date convertDate();

        string get_id() const {
            return this->id;
        }

        int get_kilometer() const {
            return this->kilometer;
        }

        string get_modell() const {
            return this->modell;
        }

        string get_inbetriebnahmedatum() const {
            return this->inbetriebnahmedatum;
        }

        string get_letzterStandort() const {
            return this->letzterStandort;
        }

        string get_aktuellerZustand() const {
            return this->aktuellerZustand;
        }

        void set_aktuellerZustand(string newZustand) {
            this->aktuellerZustand = newZustand;
        }

    };

}

#endif //LAB5_ELEKTROSCOOTER_H
