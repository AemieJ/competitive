#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;
        if(n<=0) // if n is less than equal to zero then it can't be a power of 2
        {
            cout<<"NO"<<endl; //so we print No
            continue; //continue and check for other values
        }

         long long ans=log2(n); //In above if doesn't work then take log2 of number
        if(pow(2,ans)==n)//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
        {//will definitely produce the original n
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }

    return 0;
}