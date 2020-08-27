#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,long long>mp;
stack<long long>s;
long long arr[10000000];
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        
        s.push(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]<s.top())
            s.push(arr[i]);
            else
            {
               
                while(!s.empty()&&s.top()<arr[i])
                {
                    mp[s.top()]=arr[i];
                    s.pop();
                    
                }
                
                s.push(arr[i]);
            }
            
        }
        while(!s.empty())
         {
             mp[s.top()]=-1;
             s.pop();
         }
         
         for(int i=0;i<n;i++)
         cout<<mp[arr[i]]<<" ";
         cout<<endl;
         
         mp.clear();
         while(!s.empty())
         s.pop();
         
         
    }
	return 0;
}