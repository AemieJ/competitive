#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> k;
        (n >> k & 1) == 0 ? cout << "No" << endl : cout << "Yes" << endl;
    }
    return 0;
}