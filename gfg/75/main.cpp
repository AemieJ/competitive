#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, int n, int k) {
    sort(a.begin(), a.end());
    vector<bool> foundPair(n, false);

    map<int, deque<int>> m;
    for(int i = 0; i < n; ++i) {
        int key = a[i]%k;
        m[key].push_back(i);
    }

    for(int i = 0; i < n; ++i) {
        if (!foundPair[i]) {
            int rem = a[i]%k;
            m[rem].pop_front();
            int compliment = (k-rem)%k;
            if (m[compliment].empty()) {
                cout << "False" << endl;
                return;
            } 
            int complimentIndex = m[compliment].front();
            m[compliment].pop_front();
            foundPair[i] = true;
            foundPair[complimentIndex] = true;
        }
    }

    cout << "True" << endl;

}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        cin >> k;
        solve(a, n, k);
    }
    return 0;
}