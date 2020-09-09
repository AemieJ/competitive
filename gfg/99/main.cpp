#include<bits/stdc++.h>

using namespace std;

int maxSumSubsequence(vector<int>& arr, int n) {
    vector<int> dp = arr;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
              dp[i] = dp[j] + arr[i];
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cout << maxSumSubsequence(arr, n) << endl;
    }
    return 0;
}