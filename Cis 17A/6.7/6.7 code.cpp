#include <iostream>
using namespace std;

#include <iomanip>

double celsius(double);

int main()
{
    cout <<
    "Fahrenheit | Celsius\n" <<
    "--------------------\n";
    for (int i = 0; i <= 20; i++)
    {
        cout << setprecision(2) << setw(10) << fixed << left <<
        i << " | " << celsius(i) << endl;
    }
}

double celsius(double fahrenheit)
{
    return ((5 / 9.0) * (fahrenheit - 32));
}
