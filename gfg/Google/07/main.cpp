/* Dynammic Programming - Important Question */

#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int dpImplementation(string &a, string &b) {
    int row = b.length();
    int col = a.length();

    int dp[row+1][col+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < col + 1; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < row + 1; ++i) {
        for (int j = 1; j < col + 1; ++j) {
            if (b[i-1] == a[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] += dp[i][j-1];
        }
    }

    return dp[row][col];

}

int main() {
    int t;
    cin >> t;
    string a, b;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        cout << dpImplementation(a, b) << endl;
    }
    return 0;
}