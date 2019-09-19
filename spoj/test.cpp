#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include "math.h"
#include "util.h"

using namespace std;

int main()
{
    int test;
    for(int _ = 0; _ < test ; _++)
    {
        long long int term;
        cin >> term; 
        long long int value = getCantorTerm(term);
        long long int numerator = getCantorNumerator(value);
        
    }

    return 0;
}