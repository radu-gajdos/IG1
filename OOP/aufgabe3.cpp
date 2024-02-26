#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Bankkonto
{
public:
    Bankkonto()
    {
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

};

int main()
{
    Bankkonto b;
    cout << b.kontostand() << endl;
    b.einzahlen(10);
    cout << b.kontostand() << endl;
}