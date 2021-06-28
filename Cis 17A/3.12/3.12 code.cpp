#include <iostream>
using namespace std;

#include <iomanip>

int main()
{
    double input, output;

    cout << "Enter a temperature in celsius: ";
    cin >> input;

    output = 9.0 * (input / 5.0) + 32;

    cout << setprecision(2) << fixed << endl << output << " degrees fahrenheit";
}
