#include <iostream>
using namespace std;

#include <iomanip>

int main()
{
    const double YEN_PER_DOLLAR = 98.93;
    const double EUROS_PER_DOLLAR = 0.74;

    double dollars;
    double euros, yen;

    cout << "Enter a number of USD to convert to Yen and Euros: ";
    cin >> dollars;

    euros = EUROS_PER_DOLLAR * dollars;
    yen = YEN_PER_DOLLAR * dollars;

    cout << endl << setprecision(2) << fixed <<
    "Yen: " << yen << endl <<
    "Euros: " << euros << endl;
}
