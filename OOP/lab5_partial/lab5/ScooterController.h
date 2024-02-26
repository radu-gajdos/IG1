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

        void standOrtSuche(string ort, int rol);

        void filterAlter(string date, int rol);

        void filterKilometer(int kilometer);

        void nachAlterSortieren();

        void reservieren(string id);

        void update(string modell, string inbetriebnahmedatum, string lezterStandort, string id, string actuellerZustand, int kilometer);
    };


} // scooterController

#endif //LAB5_SCOOTERCONTROLLER_H
