#include <iostream>
using namespace std;

enum ConnectionState
{
    Connecting,
    Established,
    Closing,
    Interrupted
};

int main()
{
    ConnectionState state = Closing;

    switch (state)
    {
    case Established:
        cout << "State is Established";
        break;
    case Connecting:
        cout << "State is Connecting";
        break;
    case Closing:
        cout << "State is Closing";
        break;
    default:
        cout << "State is interrupted";
    }
}