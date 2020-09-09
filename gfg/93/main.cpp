#include<bits/stdc++.h>

using namespace std;

void solve(int &n, int &count) {
    if (n == 0) return;
    else {
        if (n % 2) {
            int newVal = n - 1;
            solve(newVal, ++count);
        } else {
            int newVal = n/2;
            solve(newVal, ++count);
        }
    }
}

int main() {
    int t, n, count;
    cin >> t;
    while (t--) {
        cin >> n;
        count = 0;
        solve(n, count);
        cout << count << endl;
    }
    return 0;
}