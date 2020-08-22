/* IMPORTANT DP Prob */
#include<bits/stdc++.h>

using namespace std; 

int numInsertions(string a, string b) {
    int la = a.length();
    int lb = b.length();

    int dp[la+1][lb+1];

    for(int i = 0; i <= lb; ++i) {
        dp[0][i] = 0;
    }

    for(int i = 0; i <= la; ++i) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= la; ++i) {
        for(int j = 1; j <= lb; ++j) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return la - dp[la][lb];
}

int main() {
    int t;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> a;
        b = a;
        reverse(b.begin(), b.end());
        cout << numInsertions(a, b) << endl;
    }
    return 0;
}