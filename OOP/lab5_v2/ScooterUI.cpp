//
// Created by Paul on 5/16/2023.
//

#include "ScooterUI.h"
#include "ScooterController.h"
#include <iostream>
#include <limits>

using namespace std;
using namespace scooterController;
using namespace ScooterUINamespace;

void ScooterUI::printScooters(vector<Elektroscooter> scooters){
    for(auto scooter : scooters){
        std::cout << "\nScooters ID: " << scooter.get_id() << " Kilometers: " << scooter.get_kilometer() << " Modell:" << scooter.get_modell()
                  << "\nletzter Standort: " <<
                  scooter.get_letzterStandort() << " Status:" << scooter.get_aktuellerZustand() << "\nInbetriebnahmedatum:" << scooter.get_inbetriebnahmedatum()
                  << endl;
    }
}

void ScooterUI::start() {
    const int CUSTOMER_ROLE = 1;
    const int MANAGER_ROLE = 2;
    const int SEARCH_BY_PLACE = 1;
    const int KILOMETER_FILTER = 2;
    const int AGE_FILTER = 3;
    const int SCOOTER_RESERVATION = 4;
    const int REMOVE_SCOOTER = 5;
    const int EDIT_SCOOTER = 6;
    const int ALL_SORTED_BY_AGE = 7;

    int userRole, selectedOption, kilometers;
    string finalDate, id, location, modell, inbetrebnahmendatum, letzterStandOrt, actuellerZustand;

    cout << "\t Welcome to the app" << endl << "Choose your role:\t1. Customer \t2. Manager" << endl;
    cin >> userRole;

    if (userRole == CUSTOMER_ROLE) {
        cout << "What would you like to do? \nChoose from the actions below:\n";
        cout
                << "1. Search for a scooter \n2. View scooters based on kilometer \n3. View scooters based on age \n4. Book a scooter \n";
        cin >> selectedOption;

        if (selectedOption == SEARCH_BY_PLACE) {
            cout << "Enter a location: ";
            cin >> location;
            printScooters(controller->standOrtSuche(location));
        } else if (selectedOption == KILOMETER_FILTER) {
            cout << "Enter how many kilometers you need: ";
            cin >> kilometers;
            printScooters(controller->filterKilometer(kilometers));
        } else if (selectedOption == AGE_FILTER) {
            cout << "Enter a date: ";
            cin >> finalDate;
            printScooters(controller->filterAlter(finalDate));
        } else if (selectedOption == SCOOTER_RESERVATION) {
            cout << "Enter the ID of the scooter you want to book: ";
            cin >> id;
            if(controller->reservieren(id)){
                cout<<"The scooter was sucsefully reserved!";
            }else{
                cout<<"The scooter already in use!";
            }
        } else {
            cout << "Invalid option" << endl;
        }

    } else if (userRole == MANAGER_ROLE) {
        cout << "What would you like to do? \nChoose from the actions below: \n";
        cout
                << "1. Search for a scooter \n2. View scooters based on kilometer \n3. View scooters based on age \n4. Add a scooter \n5. Remove a scooter \n6. Edit a scooter \n7. Sort by age\n";
        cin >> selectedOption;

        switch (selectedOption) {
            case SEARCH_BY_PLACE:
                cout << "Enter a location: ";
                cin >> location;
                controller->standOrtSuche(location);
                break;
            case KILOMETER_FILTER:
                cout << "Enter how many kilometers you need: ";
                cin >> kilometers;
                controller->filterKilometer(kilometers);
                break;
            case AGE_FILTER:
                cout << "Enter a date: ";
                cin >> finalDate;
                controller->filterAlter(finalDate);
                break;
            case SCOOTER_RESERVATION:
                cout << "Give an ID: ";
                cin >> id;
                cout << "\nGive the number of kilometers available: ";
                cin >> kilometers;
                cout << "\nGive the model: ";
                cin >> modell;

                cout << "\nGive the actual status: ";
                cin >> actuellerZustand;
                cout << "\nGive the last location: ";
                cin >> location;
                cout << "\nGive the date it was created: ";
                cin >> inbetrebnahmendatum;

                controller->add(id, kilometers, modell, inbetrebnahmendatum, location, actuellerZustand);
                break;
            case REMOVE_SCOOTER:
                cout << "Give an ID: ";
                cin >> id;
                if (!controller->checkID(id))
                    throw invalid_argument("The scooter does not exist");
                controller->remove(id);
                break;
            case EDIT_SCOOTER:
                cout << "Give the ID of the scooter: ";
                cin >> id;
                if (!controller->checkID(id))
                    throw invalid_argument("The scooter does not exist");
                cout << "\tNow you are editing it\n";
                cout << "\nGive the number of kilometers available: ";
                cin >> kilometers;
                cout << "\nGive the model: ";
                cin >> modell;
                cout << "\nGive the date it was created: ";
                cin >> inbetrebnahmendatum;
                cout << "\nGive the last location: ";
                cin >> location;
                cout << "\nGive the actual status: ";
                cin >> actuellerZustand;
                if(controller->update(id, kilometers, modell, inbetrebnahmendatum, location, actuellerZustand)){
                    cout<<"Scooter succsefully updateted!";
                }else{
                    cout<<"Scooter does not exist!";
                }
                break;
            case ALL_SORTED_BY_AGE:
                printScooters(controller->nachAlterSortieren());
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }

    } else {
        cout << "Invalid role" << endl;
    }

    int exitOption;
    cout << "Enter 0 to exit or any other number to continue: ";

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cin >> exitOption;

    if (exitOption != 0) {
        start();
    }
}