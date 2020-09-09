#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, int n, int sum) {
    int dp[n+1][sum+1];

    for(int i = 0; i <= sum; ++i) dp[0][i] = 0;
    for(int i = 0; i <= n; ++i) dp[i][0] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if (arr[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j - arr[i-1]];
        }
    }

    cout << dp[n][sum] << endl;
}

int main() {
    int t, sum, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cin >> sum;
        solve(arr, n, sum);
    }
    return 0;
}