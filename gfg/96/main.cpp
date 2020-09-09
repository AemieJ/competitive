#include<bits/stdc++.h>

using namespace std;

int LCS(string &a, string &b) {
    int la = a.length();
    int lb = b.length();

    int dp[la+1][lb+1];

    for(int i = 0; i < la; ++i) dp[i][0] = 0;
    for(int i = 0; i < lb; ++i) dp[0][i] = 0;

    for(int i = 1; i <= la; ++i) {
        for(int j = 1; j <= lb; ++j) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    int maxEl = INT_MIN;
    for(int i = 1; i <= la; ++i) {
        for(int j = 1; j <= lb; ++j) {
            if (dp[i][j] > maxEl) maxEl = dp[i][j];
        }
    }
    return maxEl;
}

int main() {
    int t;
    string a, b;
    int n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> a;
        cin >> b;
        cout << LCS(a, b) << endl;
    }
    return 0;
}