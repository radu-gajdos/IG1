//
// Created by Paul on 5/10/2023.
//

#ifndef LAB5_SCOOTERCONTROLLER_H
#define LAB5_SCOOTERCONTROLLER_H

#include "ScooterRepo.h"
#include "memory"

using namespace scooterRepo;

namespace scooterController {

    class ScooterController {
    private:
        shared_ptr<scooterRepo::ScooterRepo> repo;

    public:
        ScooterController(shared_ptr<ScooterRepo> otherRepo) {
            repo = otherRepo;
        }

        vector<Elektroscooter> standOrtSuche(string &ort);

        vector<Elektroscooter> filterAlter(string &date);

        vector<Elektroscooter> filterKilometer(int kilometer);

        vector<Elektroscooter> nachAlterSortieren();

        bool reservieren(const string& id);

        bool update(const string &id, int kilometer, const string& modell,
                    const string &inbetriebnahmedatum, const string &lezterStandort,
                    const string &actuellerZustand);

        void add(const string &id, int kilometer, const string& modell, const string &inbetriebnahmedatum,
                 const string &lezterStandort, const string &actuellerZustand);

        void remove(const string &id);

        bool checkID(const string& id);
    };


} // scooterController

#endif //LAB5_SCOOTERCONTROLLER_H
