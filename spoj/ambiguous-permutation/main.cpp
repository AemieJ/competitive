#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

vector< int > getInversePermutation(vector< int >array)
{
    
    vector< int >output = array;
    for(int i=0 ; i < array.size() ; ++i)
    {
        int value = array[i];
        output[value-1] = i+1;
    }
    return output;
}

int main()
{

    int num = -1;
    while(num != 0)
    {
        cin >> num;
        cin.ignore(256,'\n');
        if(num == 0)
            break;

        vector< int >number;
        string expression , temp;
        stringstream ss;
        
        getline(cin , expression);

        ss << expression;
        int found , bits = 1;

        while(!ss.eof())
        {
            ss >> temp;
            if(stringstream(temp) >> found)
                number.push_back(found);
        }    

        vector< int>inverse = getInversePermutation(number);
        bool result = equal(number.begin() , number.end() , inverse.begin());
        if (result)
            cout << "ambiguous" << endl;
        if(!result)
            cout << "not ambiguous" << endl;
    }
    
    return 0;
}