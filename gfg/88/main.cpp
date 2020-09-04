#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, int n, int k) {
    sort(arr.begin(), arr.end());
    int sum = 0;
    int index = 0;
    for(int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum > k) {
            index = i;
            break;
        }
    }
    cout << index << endl;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        solve(arr, n, k);
    }
    return 0;
}