#include <iostream> 
#include<bits/stdc++.h> 

using namespace std;

/* 
 PICK UP ANY 2 ENERGY BAR AND SHE CAN EAT THOSE UNTIL THE CONDITION IS SATISFIED. 
 DIDNT GET THIS.
*/

int compare(string input1 , string input2) 
{
    if (input1 == input2) 
            return 0;
    if (input1 > input2) 
            return 1;
    return -1;
}

int main()
{
    long long int totalNumber;
    int compareInitial = -1 , compareFinal = -1 , totalBars = 0;
    cin >> totalNumber;
    string initial[totalNumber] , final[totalNumber];

    for(int i= 0 ; i<totalNumber ; i++)
    {
        cin >> initial[i] >> final[i];
    }
    for(long long int j=0; j<totalNumber; j++)
    {
        if( compare(initial[j],initial[k]) == -1 || compare(initial[j],initial[k]) == 0)
        {
                    if (compare(final[j],final[k]) == -1)
                        totalBars += 2;
        }
        
    }

    cout << totalBars << endl;
    return 0;
}