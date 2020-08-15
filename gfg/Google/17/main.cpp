#include<bits/stdc++.h>

using namespace std;

int unboundedKnapsace(int val[], int wt[], int n, int w) {
    int dp[n+1][w+1];

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= w; ++j) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (j >= wt[i-1]) {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int t;
    int n, W;
    cin >> t;
    while(t--) {
        cin >> n >> W;
        int val[n], wt[n];
        for(int i = 0; i < n; ++i) {
            cin >> val[i];
        }
        for(int j = 0; j < n; ++j) {
            cin >> wt[j];
        }
        cout << unboundedKnapsace(val, wt, n, W) << endl;
    }
    return 0;
}