#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t, x;
	cin>>t;
	while(t--)
	{
		int n,res=0;
		cin >> n;

		for(int i=1;i<n;i++){
			cin >> x;
			res = res^x;
			res = res^i;
		}
		cout<<(res^n)<<endl;
	}
	return 0;
}

/* Naive approach 

long c[n] = {0};
long idx, num;
for (int i=1; i < n; ++i) {
    cin >> num;
    idx = num - 1;
    c[idx] = num;    
}

for (int j=0; j < n; ++j) {
    if (c[j] == 0) return j+1;
}

*/