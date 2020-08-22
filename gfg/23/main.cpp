/* IMPORTANT QUES */
#include<bits/stdc++.h>

using namespace std;

int largestCommon(string a, string b, int la, int lb) {
    int dp[la+1][lb+1]; 

    for(int i = 0; i < la; ++i) {
        dp[i][0] = 0;
    }

    for(int i = 0; i < lb; ++i) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= la; ++i) {
        for(int j = 1; j <= lb; ++j) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int max = 0;
    for(int i = 1; i <= la; ++i) {
        for(int j = 1; j <= lb; ++j) {
            if (max < dp[i][j]) {
                max = dp[i][j];
            }
        }
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    string a, b;
    int la, lb;
    while (t--) {
        cin >> la >> lb;
        cin >> a;
        cin >> b;
        cout << largestCommon(a, b, a.length(), b.length()) << endl;
    }
    return 0;
}