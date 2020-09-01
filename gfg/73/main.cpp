#include<bits/stdc++.h>

using namespace std;

int maxLen(int a[], int n) {
    int sum=0;
    map<int,int>mp;
    int ans=0,j=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        if(sum==0)
            ans=i+1;
        else {
            if(mp.find(sum)==mp.end()) {
                mp[sum]=i;
                
            } else {
                j=mp[sum];
                ans=max(ans,i-j);
            }
        }     
    }
    return ans;
}

int main() {
    return 0;
}