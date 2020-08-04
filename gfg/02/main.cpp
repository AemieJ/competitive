#include <iostream>
using namespace std;

long long a[1000000];
long long pre[1000000];
int main() {

	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    
	   
	    long long sum = 0;
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	        sum+=a[i];
	        pre[i] = sum;
	    }
	    
	    long long sum2 = 0, ans = -1;
	    
	    for(long long i = n-1;i>=0;i--){
	        sum2 += a[i];
	        if(sum2 == pre[i]){
	            ans = i+1;
	        }
	    }
	   
	    
	    if(ans == 0){
	        cout << "-1"<< endl;
	    }
	    else cout << ans << endl;
	}
	return 0;
}