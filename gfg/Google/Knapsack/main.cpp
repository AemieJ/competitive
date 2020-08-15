#include<iostream>
#include<bits/stdc++.h> 
#include<algorithm>

using namespace std;

int knapsack(int val[], int wt[], int n, int w) {
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
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = 3;
    cout << knapsack(val, wt, n, W) << endl;
    return 0;
}
