#include<bits/stdc++.h>

using namespace std;

int memo[76];
int SpecialKeyboard(int n)
{
    if(n>75)
     return -1;
    if(n<7)
     return n;
     
    if(memo[n]!=-1)
     return memo[n];
    
    int maxi=0;
    for(int i=n-3,j=2;i>0;i--,j++)
     maxi=max(maxi,SpecialKeyboard(i)*j);

    memo[n]=maxi;
    return maxi;
}

int main()
{
    for(int i=0;i<76;i++)
     memo[i]=-1;
     
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n; 
        cout<<SpecialKeyboard(n)<<endl;
    }

  
  return 0;
  
}