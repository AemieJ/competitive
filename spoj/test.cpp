#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include "math.h"
#include "util.h"

using namespace std;

int main()
{
    long long int total;
    cin >> total;
    vector< int >storeNum;
    for(int _=0 ; _<total ; _++)
    {
        int number;
        cin >> number;
        storeNum.push_back(number);
    }

    int count = totalInversions(storeNum , total);
    cout << count << endl;

    return 0;
}