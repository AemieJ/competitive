#include<bits/stdc++.h>

using namespace std;

int getK(vector<int>& a, vector<int> &b, int n, int m, int k) {
    vector<int> c;

    int i = 0, j = 0; 
    int la = n, lb = m; 

    while (i < la && j < lb) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            ++i;
        } else {
            c.push_back(b[j]);
            ++j;
        }
    }

    if (i <= la - 1) {
        for(int m = i; m < la; ++m) c.push_back(a[m]);
    }

    if (j <= lb - 1) {
        for(int m = j; m < lb; ++m) c.push_back(b[m]);
    }

    return c[k-1];
}

int main() {
    int t, n, m, k; 
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);

        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < m; ++i) cin >> b[i];
        cout << getK(a, b, n, m, k) << endl;
    }
    return 0;
}