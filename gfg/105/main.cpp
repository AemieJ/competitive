#include<bits/stdc++.h>

using namespace std;

int sumMiddle(vector<int>& a, vector<int> &b, int n) {
    vector<int> c;

    int i = 0, j = 0; 
    int la = a.size(), lb = b.size(); 

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

    int s = la + lb;
    int m1 = c[s/2 - 1];
    int m2 = c[s/2];

    return m1 + m2;
}

int main() {
    int t, n; 
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        cout << sumMiddle(a, b, n) << endl;
    }
    return 0;
}