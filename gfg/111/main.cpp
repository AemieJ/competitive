#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = n^m;
        ans==0 ? cout << 0 << endl : cout <<log2(ans&~(ans-1)) << endl;
    }
    return 0;
}