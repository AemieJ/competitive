#include<bits/stdc++.h>

using namespace std;

int dp[11][51];
int minEggs(int n, int k) {
    if (n == 1) return k; 
    if (k == 0) return 0; 

    if (dp[n][k] != -1) return dp[n][k]; 

    int ans = INT_MAX;
    for(int i = 1; i <= k; ++i) {
        ans = min(ans, 1 + max(minEggs(n, k - i), minEggs(n-1, i - 1)));
    }
    dp[n][k] = ans;
    return dp[n][k];

}
void solve(int n, int k) {
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j]=-1;
            
    cout << minEggs(n, k) << endl;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}