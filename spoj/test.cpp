#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include "math.h"
#include "util.h"

using namespace std;

int main()
{
    int totalNumber;
    cin >> totalNumber;
    cin.ignore(256,'\n');
    string input;
    getline(cin , input);

    vector< int >array;
    istringstream is(input);
    int number;
    while(is >> number) array.push_back(number);

    int output;
    output = checkOrderPossible(array , totalNumber);

    if(output == 1)
        cout << "yes" << endl;
    if(output == 0)
        cout << "no" << endl;
        
    return 0;
}