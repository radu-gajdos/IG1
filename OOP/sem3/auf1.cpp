#include <iostream>
using namespace std;

enum WochenTag
{
    Montag = 1,
    Dienstag,
    Mittwoch,
    Donnerstag,
    Freitag,
    Samstag,
    Sonntag
};

WochenTag convert(int index)
{

    return WochenTag(index);
}

int main()
{
    int i;
    cin >> i;
    WochenTag temp = convert(i);
    switch (temp)
    {
    case Montag:
        cout << "Montag";
        break;
    case Dienstag:
        cout << "Dienstag";
        break;
    case Mittwoch:
        cout << "Mittwoch";
        break;
    case Donnerstag:
        cout << "Donnerstag";
        break;
    case Freitag:
        cout << "Freitag";
        break;
    case Samstag:
        cout << "Samstag";
        break;
    case Sonntag:
        cout << "Sonntag";
        break;
    }
}