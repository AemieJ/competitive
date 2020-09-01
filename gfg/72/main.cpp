#include<bits/stdc++.h>

using namespace std;

void createFreq(map<int, int>& m, vector<int>& arr) {
    for(int x: arr) {
        if (m[x]) ++m[x];
        else m[x] = 1;
    }
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

void sortFreq(vector<int>& arr) {
    map<int, int> m;
    createFreq(m, arr);

    vector<pair<int, int>> res;
    for(auto x: m) res.push_back({x.first, x.second});
    sort(res.begin(), res.end(), cmp);

    for(auto x: res) {
        while (x.second--) cout << x.first << " ";
    }

} 

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sortFreq(arr);
        cout << endl;
    }
    return 0;
}