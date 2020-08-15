/* MATHEMATICAL SOLUTION*/ 

#include<bits/stdc++.h>

using namespace std;
#define ull unsigned long long int

int modulo(ull a, ull b, ull c)
{
    if(a == 1 || b == 0)
        return 1;
    return (a % c * modulo(a,b-1,c)) % c;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    ull a,b,c;
	    cin >> a >> b >> c;
	    cout << modulo(a, b, c) << endl;	    
	}
	return 0;
}
