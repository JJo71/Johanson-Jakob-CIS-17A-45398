#include <iostream>
using namespace std;

#include <iomanip>

int main()
{
    unsigned int month, year, days = 30;

    cout << "Enter a month: ";
    cin >> month;
    cout << endl << "Enter a year: ";
    cin >> year;

    if (month > 7)
    {
        if (month % 2 == 0)
            days++;
    }
    else if (month != 2)
    {
        if (month % 2 == 1)
            days++;
    }
    else
    {
        days = 28;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            days++;
    }

    cout << endl << days << " days";
}
