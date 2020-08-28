#include<bits/stdc++.h>

using namespace std;

bool withinBounds(int i, int n) {
    return (i <= n);
}

void solve(vector<int>& arr, int n, int k) {
    vector<int> res;
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if (withinBounds(i + k, n)) { 
            res.push_back(*max_element(arr.begin() + i, arr.begin() + i + k)); 
        }
    }

    for(auto x: res) {
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
        solve(arr, n, k);
        cout << endl;
    }
    return 0;
}