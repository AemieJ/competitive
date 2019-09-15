#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <string>

using namespace std;


int checkOrderPossible(vector< int >input , int size)
{
        vector< int >stack;
        int requiredValue = 1 , answer = 1;
        for(int i=0 ; i< input.size() ; i++)
        {
            while(!stack.empty() && stack.back() == requiredValue)
            {
                requiredValue++;
                stack.pop_back();
            }

            if (input[i] == requiredValue)
                requiredValue++;
            else if(!stack.empty() && stack.back() < input[i])
            {
                answer = 0;
                break;
            }
            else 
                stack.push_back(input[i]);
        }

        return answer;
        
}


int main()
{
    int totalNumber = -1;
    while(totalNumber != 0)
    {
        cin >> totalNumber;
        if(totalNumber == 0)
            break;
        cin.ignore(256, '\n');
        string input;
        getline(cin, input);

        vector<int> array;
        istringstream is(input);
        int number;
        while (is >> number)
            array.push_back(number);

        int output;
        output = checkOrderPossible(array, totalNumber);

        if (output == 1)
            cout << "yes" << endl;
        if (output == 0)
            cout << "no" << endl;
    }
}