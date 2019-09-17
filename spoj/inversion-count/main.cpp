#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

long long int totalInversions(vector< int >array , long long int size)
{
}

int main()
{
    /* USE OF BIT : BINARY INDEXED TREE*/
    int test;
    cin >> test;
    for(int _=0 ; _<test ; _++)
    {
        cout << endl;
        long long int total;
        cin >> total;
        vector<int> storeNum;
        for (int _ = 0; _ < total; _++)
        {
            long long int number;
            cin >> number;
            storeNum.push_back(number);
        }

        long long int count = totalInversions(storeNum, total);
        cout << count << endl;
    }
    return 0;
}