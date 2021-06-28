#include <iostream>
using namespace std;

#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

int main() // The random data generation does not take anything into account when making the data. It just spits out stuff in the format I wanted.
{
    ofstream DataFile;
    DataFile.open("RainOrShine.txt");

    srand (time(NULL));

    int result;

    for (int i = 0; i < 90; i++)
    {
        result = rand() % 3;

        switch(result)
        {
        case 0:
            {
                DataFile << 'R';
                break;
            }
        case 1:
            {
                DataFile << 'C';
                break;
            }
        case 2:
            {
                DataFile << 'S';
                break;
            }
        }
        DataFile << endl;
    }
}
