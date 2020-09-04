#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& v, int n, int k) {
    int removedSoFar = 0, temp = 0, count = INT_MAX;

    for (int i = 0; i < n; ++i) {
        temp = removedSoFar;
        removedSoFar += v[i];
        for (int j = n - 1; j > i; --j) {
        temp += max(v[j] - v[i] - k, 0);
        }

        count = min(count, temp);
    }

    cout << count << endl;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> coins(n);
        for(int i = 0; i < n; ++i) cin >> coins[i];
        sort(coins.begin(), coins.end());
        solve(coins, n, k);

    }
    return 0;
}