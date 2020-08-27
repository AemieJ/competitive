#include<bits/stdc++.h>

using namespace std;
// works but TLE
void solve(vector<long> v, int n) {
    stack<long> s;
    vector<long> res(n, -1);
    s.push(v[0]);
    for(long i = 1; i < n; ++i) {
        int next = v[i]; 
        int val = i;
        while (!s.empty() && next > s.top()) {
            auto it = find(v.begin(), v.end(), s.top());
            int val = it - v.begin();
            if (res[val] == -1) res[val] = next;
            s.pop();
        }
        s.push(next);
    }

    for(auto x: res) {
        cout << x << " ";
    }
}

int main() {
    int t;
    long n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long> arr(n);
        for(long i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve(arr, n);
        cout << endl;

    }
    return 0;
} 