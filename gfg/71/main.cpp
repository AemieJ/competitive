#include<bits/stdc++.h>

using namespace std;

void createHashMap(vector<int>& A, map<int, int>& m) {
    for(int x: A) {
        if (m[x]) ++m[x];
        else m[x] = 1;
    }
}

void relativeSort(vector<int>& A, vector<int>& B) {
    map<int, int> m;
    createHashMap(A, m);

    for(int x : B) {
        if (m.find(x) != m.end()) {
            int count = m[x];
            while (count--) {
                cout << x << " ";
            }
            m.erase(x);
        }
    }

    vector<pair<int, int>> res;
    for(auto x: m) res.push_back({x.first, x.second});
    sort(res.begin(), res.end());
    for(auto x: res) {
        while (x.second--) cout << x.first << " ";
    }
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; 
        vector<int> A(n);
        vector<int> B(m);

        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int j = 0; j < m; ++j) cin >> B[j];

        relativeSort(A, B);
        cout << endl;
    }
    return 0;
}