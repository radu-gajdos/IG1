#include <iostream>
using namespace std;

int ggt(int a, int b)
{
    if (b == 0)
        return a;
    return ggt(b, a % b);
}

void a()
{

    int n;
    cout << "Bitte eine naturliche zahl n geben \n";
    cin >> n;

    cout << "Diese sind alle Zahlen kleiner als n die relativ prim zu n sind: ";
    for (int i = n - 1; i > 0; i--)
    {
        if (ggt(n, i) == 1) // zwei Zahlen sind relativ prim wenn ihre ggt gleich mit 1 ist
            cout << i << " ,";
    }
}

int *input_array(int &laenge)
{
    cout << "Laenge des vectors: ";
    cin >> laenge;

    int *v = new int(laenge);

    cout << "Nummern:\n";
    for (int i = 0; i < laenge; i++)
    {
        cin >> v[i];
    }

    return v;
}

void get_max_folge_poz(int v[], int l, int &max_start, int &end)
{

    int max_sum = v[0], current_sum = v[0];
    int start = 0;

    for (int i = 1; i < l; i++)
    {

        if (current_sum + v[i] < current_sum)
        {
            current_sum = v[i];
            start = i;
        }
        else
        {
            current_sum += v[i];
        }

        if (current_sum >= max_sum)
        {
            end = i;
            max_start = start;
            max_sum = current_sum;
        }
        cout << "\n";
    }
}

void output_array(int v[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << v[i] << ", ";
    }
}

void b()
{

    int start = 0, max_end = 0, max_start = 0;
    int l = 0;
    int *v = input_array(l); // initializierung des arrays

    get_max_folge_poz(v, l, max_start, max_end);
    // im max_start wird dem Anfang(Position) des Seqventz sein und im max-end der Ende

    cout << "Die laengste aufeinanderfolgende Teilfolge mit der maximalen Summe ist: ";
    output_array(v, max_start, max_end);
    // cout<< von elem der array von die 2 Positionen

    delete[] v;
}

int main()
{
    cout << "Ubung 9.a (Alle zahlen relativ prim zu n)\n";
    a();
    cout << "\n";
    cout << "Ubung 9.b (Laengste Teilfolge mit max Summe)\n";
    b();
}