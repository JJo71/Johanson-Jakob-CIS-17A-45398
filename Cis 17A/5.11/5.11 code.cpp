#include <iostream>
using namespace std;

#include <iomanip>

int main()
{
    double start_pop, days, growth_rate;
    bool valid = false;

    do
    {
        cout << "Enter a population count: ";
        cin >> start_pop;

        if (start_pop >= 2)
        {
            valid = true;
        }
        else
            cout << endl << "Invalid value. Try again.\n";

    } while (!valid);

    valid = false;
    do
    {
        cout << "Enter the growth rate as a percentage: ";
        cin >> growth_rate;

        if (growth_rate >= 0)
        {
            valid = true;
        }
        else
            cout << endl << "Invalid value. Try again.\n";

    } while (!valid);

    valid = false;
    do
    {
        cout << "Enter the number of days: ";
        cin >> days;

        if (days >= 1)
        {
            valid = true;
        }
        else
            cout << endl << "Invalid value. Try again.\n";

    } while (!valid);

    cout << setprecision(4) << fixed << endl << "Start: " << start_pop << endl;

    for (int i = 1; i <= days; i++)
    {
        start_pop *= 1 + growth_rate/100.0;
        cout << setprecision(4) << fixed << "Day " << i << ": " << start_pop << endl;
    }
}
