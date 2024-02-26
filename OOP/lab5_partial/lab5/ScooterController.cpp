//
// Created by Paul on 5/10/2023.
//

#include "ScooterController.h"

using namespace scooterRepo;

namespace scooterController {

    void scooterController::ScooterController::standOrtSuche(string ort, int rol) {
        for (auto scooter: repo->readFromFile()) {
            string objectName = scooter.get_letzterStandort();
            auto checkIfSubstring = objectName.find(ort);
            if (checkIfSubstring != std::string::npos) {
                if (rol == 0)
                    scooter.printForCustomer();
                else
                    scooter.printForManager();
            }
        }
    }

    void scooterController::ScooterController::nachAlterSortieren() {
        // sortam toate produsele dupa daca de expirare
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
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
    }

    void scooterController::ScooterController::filterAlter(string date, int rol) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
            Date date1 = aux[i].convertDate();
            Date datefin;
            datefin.day = stoi(date.substr(0, 2));
            datefin.month = stoi(date.substr(3, 2));
            datefin.year = stoi(date.substr(5, 4));
            if (date1.year <= datefin.year || (date1.month <= datefin.month && date1.year == datefin.year) ||
                (date1.day <= datefin.day && date1.year == datefin.year && date1.month == datefin.month))
                aux[i].printForManager();

        }
    }

    void scooterController::ScooterController::filterKilometer(int kilometer) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
            if (aux[i].get_kilometer() < kilometer)
                aux[i].printForManager();
        }
    }

    void scooterController::ScooterController::reservieren(string id) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
            if (aux[i].get_id() == id)
                aux[i].set_aktuellerZustand("reserviert");
        }
    }

    void scooterController::ScooterController::update(string modell, string inbetriebnahmedatum, string lezterStandort,
                                                      string id, string actuellerZustand, int kilometer) {
        auto aux = repo->readFromFile();
        for (int i = 0; i < aux.size() - 1; i++) {
            if (aux[i].get_id()==id){
                Domain::Elektroscooter snou(id,kilometer,modell, inbetriebnahmedatum, lezterStandort, actuellerZustand);
                aux[i]=snou;
                repo->writeToFile(aux);
            }
        }
    }
} // scooterController