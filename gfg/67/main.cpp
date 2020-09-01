#include<bits/stdc++.h>

using namespace std;

int numberPaths(int m, int n) {
    if (m == 1 || n == 1) return 1;
    return numberPaths(m - 1, n) + numberPaths(m, n - 1);
}

int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cout << numberPaths(m, n) << endl;
    }
    return 0;
}