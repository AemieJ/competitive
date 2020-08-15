#include<bits/stdc++.h> 
#include<iostream>

using namespace std;

int maxTotal(int arr[], int n) {
    // recursive logic (n is always even)
    // solve(i, j) => returns the max total between the i and j range
    // solve(i, i) => arr[i] 
    // solve(i, i + 1) => max(arr[i], arr[i+1])
    // 1. first element, arr[i] + min{solve(i+2, j), solve(i+1, j-1)}
    // 2. last element, arr[j] + min{solve(i+1, j-1), solve(i, j-2)}
    // result will be max of both
    int dp[n][n];
    for(int i = 0; i < n -1; ++i) {
        dp[i][i] = arr[i];
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }
    dp[n-1][n-1] = arr[n-1];

    for(int size = 4; size <= n; ++size) { 
        for(int i = 0; i < n - size + 1; ++i) {
            int j = i + size - 1;
            dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                            arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << maxTotal(arr, n) << endl;
    }
    return 0;
}