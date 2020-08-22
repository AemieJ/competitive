#include <bits/stdc++.h>

using namespace std;

bool triplet(int arr[],int n){
    int l,r;
    for(int i=0;i<n;i++)arr[i]=(arr[i]*arr[i]);
     for (int i = n-1; i >= 2; i--) 
    { 
        int l = 0;
        int r = i-1;
        while (l < r) 
        { 
            if (arr[l] + arr[r] == arr[i]) 
                return true; 
            (arr[l] + arr[r] < arr[i])?  l++: r--; 
        } 
    } 
    return false; 
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    sort(a,a+n);
	        if(triplet(a,n))
	        cout<<"Yes";
	        else cout<<"No";
	    cout<<'\n';
	}
}