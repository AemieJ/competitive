#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        n == 0 ? cout << 0 << endl : cout << log2(n&-n)+1 << endl;
    }
    return 0;
}