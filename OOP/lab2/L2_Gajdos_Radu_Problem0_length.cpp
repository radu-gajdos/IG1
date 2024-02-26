#include "L2_Gajdos_Radu_Problem0_length.h"
#include <fstream>
#include <iostream>

#include "L2_Gajdos_Radu_Problem0_length_test.cpp"

using namespace std;

double Length::get_value()
{
    return anzahl;
}

string Length::get_unit()
{
    return masseinheit;
}

Length Length::add(Length &l)
{
    if (masseinheit != l.masseinheit)
    {
        throw invalid_argument("Verschiedene Masseinheiten!!!");
    }

    return Length(anzahl + l.anzahl, masseinheit);
}

Length Length::subtract(Length &l)
{
    if (masseinheit != l.masseinheit)
    {
        throw invalid_argument("Verschiedene Masseinheiten!!!");
    }

    return Length(anzahl - l.anzahl, masseinheit);
}

Length Length::scale(double x)
{
    return Length(anzahl * x, masseinheit);
}

Length Length::divide(double x)
{
    return Length(anzahl / x, masseinheit);
}

string Length::text()
{
    return (to_string(anzahl) + masseinheit);
}

int Length::compare(Length l2)
{
    if (masseinheit != l2.masseinheit)
    {
        throw invalid_argument("Verschiedene Masseinheiten!!!");
    }
    // mai mic
    if (anzahl < l2.anzahl)
    {
        return -1;
    }
    // egal
    if (anzahl == l2.anzahl)
    {
        return 0;
    }
    // mai mare
    if (anzahl > l2.anzahl)
    {
        return 1;
    }
}

int main()
{

    // variabeln deklarieren
    double anzahl1, anzahl2, skalar, divizor;
    string masseinheit1, masseinheit2;
    
    // tests
    test_alle();

    // input Laenge1
    cout << "Laenge 1 eingeben: ";
    cin >> anzahl1 >> masseinheit1;

    Length laenge1(anzahl1, masseinheit1);

    // input Laenge2
    cout << "Laenge 2 eingeben:";
    cin >> anzahl2 >> masseinheit2;

    Length laenge2(anzahl2, masseinheit2);

    // input skalar
    cout << "Skalierungsfaktor eingeben: ";
    cin >> skalar;

    // input divizor
    cout << "Divizor eingeben: ";
    cin >> divizor;

    // addieren
    Length laengeadd = laenge1.add(laenge2);
    cout << "Laenge 1 + Laenge 2 = " << (laengeadd.text()) << endl;

    // subtrahieren
    Length laengesub = laenge1.subtract(laenge2);
    cout << "Laenge 1 - Laenge 2 = " << (laengesub.text()) << endl;

    // skalieren
    Length laengeska = laenge1.scale(skalar);
    cout << "Laenge 1 * " << skalar << " = " << (laengeska.text()) << endl;

    // dividieren
    Length laengediv = laenge1.divide(divizor);
    cout << "Laenge 1 / " << skalar << " = " << (laengediv.text()) << endl;

    // vergleichen
    int vergleichzahl = laenge1.compare(laenge2);

    if (vergleichzahl == -1)
        cout << "Laenge 1 ist kleiner als Laenge 2" << endl;
    if (vergleichzahl == 0)
        cout << "Laenge 1 gleich mit Laenge 2" << endl;
    if (vergleichzahl == 1)
        cout << "Laenge 1 ist grosser als Laenge 2" << endl;

    // jezt fuer konversionen
    double anzahla;
    string masseinheita, konversiona;

    // input Laenge A
    cout << "Laenge A eingeben: " << endl;
    cin >> anzahla >> masseinheita;
    cout << "Ihre neue Masseinheit eingeben: " << endl;
    cin >> konversiona;

    Length a(anzahla, masseinheita);

    cout << "Laenge A hat ist initial: " << a.text() << endl;
    a.convert(konversiona);
    cout << "Nach die Konversion zum " << konversiona << " ist es: " << a.text() << endl;
}