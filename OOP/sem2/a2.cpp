#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
class Bankkonto
{
public:
    Bankkonto()
    {
        incarca();
        total = 0.0;
    }

    void einzahlen(double n)
    {
        total += n;
        l_tranzactii.push_back("IN " + to_string(n) + " " + to_string(total));
        scrie();
    }

    void auszahlen(double n)
    {
        total -= n;
        l_tranzactii.push_back("OUT " + to_string(n) + " " + to_string(total));
        scrie();
    }

    double kontostand() const
    {
        return total;
    }

private:
    double total;
    vector<string> l_tranzactii;

    void scrie() const
    {
        ofstream out("tranzactii.txt");
        for (const auto &tranzactie : l_tranzactii)
        {
            out << tranzactie << endl;
        }
        out.close();
    }
    void incarca()
    {
        ifstream in("tranzactii.txt");
        while (!in.eof())
        {
            string typ, betrag, temp;
            in >> typ >> betrag >> temp;
            cout << typ << " " << betrag << endl;
            if (strcmp(typ.c_str(),"IN")==0)
            {
                einzahlen(stod(betrag)); // stod ii string to double
            }
            if (strcmp(typ.c_str(),"OUT")==0)
            {
                auszahlen(stod(betrag)); // stod ii string to double
            }
        }
        in.close();
    }
};

int main()
{
    Bankkonto b;f
    b.einzahlen(10);
    b.einzahlen(10);
    b.auszahlen(10);
    b.auszahlen(10);
    cout << b.kontostand() << endl;
}