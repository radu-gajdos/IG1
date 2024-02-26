//
// Created by Paul on 5/10/2023.
//

#include "Elektroscooter.h"
#include <iostream>

namespace Domain {

    bool Elektroscooter::isValidDate(const string &dateStr) {
        // dd/mm/yyyy also len 10
        if (dateStr.length() != 10) {
            return false;
        }

        string dayStr = dateStr.substr(0, 2);
        string monthStr = dateStr.substr(3, 2);
        string yearStr = dateStr.substr(6, 4);

        int day, month, year;

        day = stoi(dayStr);
        month = stoi(monthStr);
        year = stoi(yearStr);

        if (month < 1 || month > 12) {
            return false;
        }

        int daysInMonth = 31;

        if (month == 2) {//februrarie
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {//an bisect
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        }

        return day >= 1 && day <= daysInMonth;
    }

    Elektroscooter::Elektroscooter(const string &id, int km, const string &modell1, const string &inbetribnahmedatum1,
                                   const string &letzterStandort1, const string &aktuellerZustand1) {
        if (id.length() > 3 || typeid(id) != typeid(string)) {
            throw invalid_argument("Invalid id: Empty string");
        }
        if (km < 0 || typeid(km) != typeid(int)) {
            throw invalid_argument("Invalid kilometer: Negative value");
        }
        if (typeid(modell1) != typeid(string)) {
            throw invalid_argument("Invalid modell: Empty string");
        }
        if (typeid(inbetribnahmedatum1) != typeid(string)) {
            throw invalid_argument("Invalid inbetribnahmedatum: Empty string");
        }
        if (typeid(letzterStandort1) != typeid(string)) {
            throw invalid_argument("Invalid letzterStandort: Empty string");
        }
        if (typeid(aktuellerZustand1) != typeid(string)) {
            throw invalid_argument("Invalid aktuellerZustand: Empty string");
        }
        if (!isValidDate(inbetribnahmedatum1)) {
            throw invalid_argument("Invalid datum format (es soll dd/mm/yyyy sein)!");
        }

    }

    Date Elektroscooter::convertDate() {
        Date dateInt{};
        string date = this->inbetriebnahmedatum;
        string dayStr = date.substr(0, 2);
        string monthStr = date.substr(3, 2);
        string yearStr = date.substr(7, 4);

        dateInt.day = stoi(dayStr);
        dateInt.month = stoi(monthStr);
        dateInt.year = stoi(yearStr);

        return dateInt;
    }


} // Domain