#include <iostream>
#include "util.h"
#include <string>

#include <bits/stdc++.h> 

using namespace std;

int main()
{
    
    int base , power;
    cin >> base >> power;
    int sequenceStorage[4];
    if(power != 0)
    {
        for (int i = 0; i < 4; i++)
        {
            sequenceStorage[i] = powerCalculation(base, i + 1);
            int modulus = (power - (i + 1)) % 4;
            if (modulus == 0)
            {
                cout << sequenceStorage[i] % 10 << endl;
                break;
            }
        }
    }
    else 
        cout << 1 << endl;

    return 0;
}