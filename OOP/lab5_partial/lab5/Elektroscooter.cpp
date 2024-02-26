//
// Created by Paul on 5/10/2023.
//

#include "Elektroscooter.h"
#include <iostream>

namespace Domain {

    Date Elektroscooter::convertDate() {
        Date dateInt{};
        string date = this->inbetriebnahmedatum;
        string dayStr = date.substr(0, 2);
        string monthStr = date.substr(3, 2);
        string yearStr = date.substr(6, 4);

        dateInt.day = stoi(dayStr);
        dateInt.month = stoi(monthStr);
        dateInt.year = stoi(yearStr);

        return dateInt;
    }

    void Elektroscooter::printForCustomer() {
        std::cout << "Scooters ID: " << id << "Kilometers: " << kilometer << " Modell: " << modell
                  <<  " Status: " << aktuellerZustand << endl;
    };

    void Elektroscooter::printForManager() {
        std::cout << "Scooters ID: " << id << "Kilometers: " << kilometer << " Modell: " << modell
                  << " letzter Standort: " <<
                  letzterStandort << " Status: " << aktuellerZustand << " Inbetriebnahmedatum: " << inbetriebnahmedatum
                  << endl;
    }

} // Domain