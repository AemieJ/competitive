#include <iostream>
#include "util.h"
#include <string>

#include <bits/stdc++.h> 

using namespace std;

int main()
{
    
    string input , temp;
    getline(cin , input);
    int check = presenceofZero(input);  
    vector <string> alphaCodes;

    if(check==0)
    {
        alphaCodes.push_back(input);
        for(int i=0 ; i<input.length() ; i++)
        {
            if (i != input.length()-1)  
                temp = ((input[i]-'0')*10 + (input[i+1]-'0')) + '0';
                if(inRangeofAlpha(temp))    
                    
        }
    }
        

    return 0;
}