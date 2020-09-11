#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
	cin >> t;
	while (t--) {
	    cin >> n;
	    vector<int>arr(n);
        stack<int> s;
	    for(int i = 0; i < n; ++i) 
            cin >> arr[i]; 
        
        s.push(arr[0]);
        for(int i = 1; i < n; ++i) {
            if (arr[i] != arr[i-1]) {
                s.push(arr[i]);
            } else {
                s.pop();
            }
        }

        cout << s.top() << endl;
	}
	return 0;
}