#ifndef LENGTH
#define LENGTH
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Length
{
private:
    double anzahl;
    string masseinheit;

    map<string, double> map_fuer_conversion = {
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000.0},
        {"in", 0.0254},
        {"ft", 0.3048},
        {"yd", 0.9144},
        {"mi", 1609.344}};

public:
    // Konstruktor
    Length(double v, const string &u)
        : anzahl(v), masseinheit(u) {}

    double get_value();

    string get_unit();

    Length add(Length &l);

    Length subtract(Length &l);

    Length scale(double x);

    Length divide(double x);

    string text();

    int compare(Length laenge2);

    // Bonus 1

    void convert(string neue_masseinheit)
    {
        anzahl *= map_fuer_conversion[masseinheit] / map_fuer_conversion[neue_masseinheit];
        masseinheit = neue_masseinheit;
    }

    // Bonus 2

    //+
    Length operator+(Length laenge2)
    {
        return add(laenge2);
    }

    //-
    Length operator-(Length laenge2)
    {
        return subtract(laenge2);
    }

    //*
    Length operator*(double skalar)
    {
        return scale(skalar);
    }

    // /
    Length operator/(double divisor)
    {
        return divide(divisor);
    }
};
#endif