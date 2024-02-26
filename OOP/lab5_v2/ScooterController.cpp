//
// Created by Paul on 5/10/2023.
//

#include "ScooterController.h"
#include <iostream>

using namespace scooterRepo;
using namespace Domain;

namespace scooterController {

    vector<Elektroscooter> scooterController::ScooterController::standOrtSuche(string &ort) {
        vector<Elektroscooter> result;
        for (auto scooter: repo->readFromFile()) {
            string objectName = scooter.get_letzterStandort();
            auto checkIfSubstring = objectName.find(ort);
            if (checkIfSubstring != std::string::npos) {
                result.push_back(scooter);
            }
        }
        return result;
    }

    vector<Elektroscooter> scooterController::ScooterController::nachAlterSortieren() {
        // sortam toate produsele dupa daca de expirare
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size(); i++) {
            for (int j = i + 1; j < aux.size(); j++) {
                Date date1 = aux[i].convertDate();
                Date date2 = aux[j].convertDate();
                if (date1.year > date2.year ||
                    (date1.year == date2.year && date1.month > date2.month) ||
                    (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)) {
                    auto aux2 = aux[i];
                    aux[i] = aux[j];
                    aux[j] = aux2;
                }
            }
        }
        return aux;
    }

    vector<Elektroscooter> scooterController::ScooterController::filterAlter(string &date) {
        vector<Elektroscooter> result;
        auto aux = repo->readFromFile();
        for (auto & scooter : aux) {
            Date date1 = scooter.convertDate();
            Date datefin{};
            datefin.day = stoi(date.substr(0, 2));
            datefin.month = stoi(date.substr(3, 2));
            datefin.year = stoi(date.substr(6, 4));
            if (date1.year <= datefin.year || (date1.month <= datefin.month && date1.year == datefin.year) ||
                (date1.day <= datefin.day && date1.year == datefin.year && date1.month == datefin.month))
                result.push_back(scooter);
        }
        return  result;
    }

    vector<Elektroscooter> scooterController::ScooterController::filterKilometer(int kilometer) {
        vector<Elektroscooter> result;
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size(); i++) {
            if (aux[i].get_kilometer() >= kilometer)
                result.push_back(aux[i]);
        }
        return result;
    }

    bool scooterController::ScooterController::reservieren(const string &id) {
        auto aux = repo->readFromFile();
        for (auto &skooter: aux) {
            if (skooter.get_id() == id) {
                if (skooter.get_aktuellerZustand() != "geparkt") {
                    return false;
                } else {
                    skooter.set_aktuellerZustand(" reserviert");
                    repo->writeToFile(aux);
                    return true;
                }
            }
        }
    }

    bool scooterController::ScooterController::update(const string &id, int kilometer, const string &modell,
                                                      const string &inbetriebnahmedatum, const string &lezterStandort,
                                                      const string &actuellerZustand) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
            if (aux[i].get_id() == id) {
                Domain::Elektroscooter snou(id, kilometer, modell, inbetriebnahmedatum, lezterStandort,
                                            actuellerZustand);
                aux[i] = snou;
                repo->writeToFile(aux);
                return true;
            }
        }
        return false;
    }

    void scooterController::ScooterController::add(const string &id, int kilometer, const string &modell,
                                                   const string &inbetriebnahmedatum, const string &lezterStandort,
                                                   const string &actuellerZustand) {
        Elektroscooter aux(id, kilometer, modell, inbetriebnahmedatum, lezterStandort, actuellerZustand);
        repo->add(aux);
    }

    void scooterController::ScooterController::remove(const string &id) {
        auto aux = repo->readFromFile();
        for (auto scooter: aux)
            if (scooter.get_id() == id)
                repo->deleteProd(scooter);
    }

    bool scooterController::ScooterController::checkID(const string& id) {
        auto aux = repo->readFromFile();
        for (auto scooter: aux)
            if (scooter.get_id() == id)
                return true;
        return false;
    }
} // scooterController