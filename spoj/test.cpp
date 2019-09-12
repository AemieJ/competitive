#include <iostream>
#include "util.h"
#include <string>
#include <sstream>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
    /*
     PROBLEMS DEALING WITH LARGE NUMBERS ARE BEST TO BE HANDLED WITH STRINGS
    */  

    long long int totalNumber , candy;

    long long int sum=0;

    cin >> totalNumber;

    for(long long int _=0 ; _ < totalNumber ; _++)
    {
        cin >> candy;
        sum += (candy%totalNumber);
    }

    if( sum%totalNumber == 0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
    cout << endl;

    return 0;
}