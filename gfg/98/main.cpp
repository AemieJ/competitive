#include<bits/stdc++.h>

using namespace std;

int knapSack(int n, int w, vector<int> &val, vector<int> &wt) {
    // recursive basics
    // k(n, w) => n items provided and w capacity of bag find max n that can be used
    // k(0, w) => 0
    // k(n, 0) => 0 
    // 1. excluding the nth term: k(n-1, w)
    // 2. Including the nth term and excluding from wt: v[n-1] + k(n-1, w - wt[n-1])
    // max(1, 2) will give k(n, w)

    int dp[n+1][w+1];

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= w; ++j) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (j >= wt[i-1]) {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int t, n, w;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> w;
        vector<int> val(n, 0);
        vector<int> wt(n, 0);

        for(int i = 0; i < n; ++i) cin >> val[i];
        for(int i = 0; i < n; ++i) cin >> wt[i];

        cout << knapSack(n, w, val, wt) << endl;
    }
    return 0;
}