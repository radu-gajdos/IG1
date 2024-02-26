#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    fstream in;
    in.open(argv[1], ios::in);

    fstream out;
    out.open(argv[2], ios::out);


    string line;
    for (int i = 0; i < 5; i++)
    {
        getline(in, line);
        cout << line << endl;
        out << line << endl;
    }

    in.close();
    out.close();

    return 0;
}
