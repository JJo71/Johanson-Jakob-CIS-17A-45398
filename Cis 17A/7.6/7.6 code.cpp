#include <iostream>
using namespace std;

#include <iomanip>
#include <fstream>
#include <string>

int main()
{
    ifstream DataFile;
    DataFile.open("RainOrShine.txt"); // For this program I made the data file myself and assumed its format.

    char weather_data [3][30];
    int total_stats [3][3] = { };
    char current;

    for (int i = 0; i < 90; i++)
    {
        DataFile >> current;
        weather_data[i % 3][(i - i % 3)/3] = current;

        if (current == 'R')
            total_stats[i % 3][0] += 1;
        if (current == 'C')
            total_stats[i % 3][1] += 1;
        if (current == 'S')
            total_stats[i % 3][2] += 1;
    }

    int highest_rain = total_stats[0][0];
    string month = "June";
    if (highest_rain < total_stats[1][0])
        month = "July";
    if (highest_rain < total_stats[2][0])
        month = "August";

    cout <<
    "June:\n" <<
    "Rain: " << total_stats[0][0] << endl <<
    "Cloudy: " << total_stats[0][1] << endl <<
    "Sunny: " << total_stats[0][2] << endl << endl <<
    "July:\n" <<
    "Rain: " << total_stats[1][0] << endl <<
    "Cloudy: " << total_stats[1][1] << endl <<
    "Sunny: " << total_stats[1][2] << endl << endl <<
    "August:\n" <<
    "Rain: " << total_stats[2][0] << endl <<
    "Cloudy: " << total_stats[2][1] << endl <<
    "Sunny: " << total_stats[2][2] << endl << endl;

    cout <<
    "Total Rain: " << total_stats[0][0] + total_stats[1][0] + total_stats[2][0] << endl <<
    "Total Cloudy: " << total_stats[0][1] + total_stats[1][1] + total_stats[2][1] << endl <<
    "Total Sunny: " << total_stats[0][2] + total_stats[1][2] + total_stats[2][2] << endl << endl;

    cout << "Most Rainy Month: " << month << endl;
}
