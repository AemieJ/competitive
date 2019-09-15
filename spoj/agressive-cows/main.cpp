#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

int isFeasible(long long int  array[] , long long int mid , long long int total , long long int expected)
{
    int taken=1;
    long long int  last = array[0] , difference;
    for(int i=1 ; i<total;i++)
    {
        if(array[i]-last >= mid)
        {
            taken++;
            last = array[i];
            if(taken==expected) 
                return 1;
        }
    }
    return 0;
}

long long int minDistance(long long int array[] , long long int total , long long int expected)
{
    long long int  low = array[0] , high = array[total-1];
    long long int  mid , res = -1;
    while(low < high)
    {
        mid = (low+high)/2;
        if (isFeasible(array , mid , total , expected))
        {
            res = max(res,mid);
            low = mid+1;
        }

        else   
            high = mid;
    }
    return res;

}

int main() 
{
    int test;
    cin >> test;

    for(int _=0 ; _<test ; _++)
    {
        long long int totalNumber, noOfPoints;
        cin >> totalNumber >> noOfPoints;
        long long int integerStall[totalNumber], largestMinDist;
        cin.ignore(256, '\n');

        for (int i = 0; i < totalNumber; i++)
            cin >> integerStall[i];

        sort(integerStall, integerStall + totalNumber);
        largestMinDist = minDistance(integerStall, totalNumber, noOfPoints);

        cout << largestMinDist << endl;
    }
    return 0;
}