#include <iostream>
#include "math.h"

using namespace std;

int main()
{
    long long int number;
    cin >> number;
    if(number != 1 && floor(log2(number)) == ceil(log2(number)))
            cout << "TAK" << endl;

    else 
            cout << "NIE" << endl;
    
    return 0;
}