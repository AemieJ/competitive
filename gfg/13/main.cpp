#include<bits/stdc++.h>

using namespace std;


void reverseArray(vector<int>& arr, int n, int k) {
    for(int i = 0; i < n; i += k) {
        if ((i + k) < arr.size()) {
            reverse(arr.begin() + i, arr.begin() + i + k);
        } else {
            reverse(arr.begin() + i, arr.end());
        }
    }
    
    for(auto x: arr) {
        cout << x << " ";
    }
}

int main() {
    int t, n, k; 
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        reverseArray(arr, n, k);
        cout << endl;
    }
    return 0;
}