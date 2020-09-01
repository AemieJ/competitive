#include<bits/stdc++.h>

using namespace std;

void longestSubSequence(vector<int>& a, int n) {
    map<int, vector<int>> m;
    sort(a.begin(), a.end());

    int j = 0;
    for(int i = 1; i < n; ++i) {
        if (a[i] - a[i-1] == 1) {
            m[j].push_back(a[i]);
        } else if(a[i] - a[i-1] > 1) {
            ++j;
        }
    }

    int maxSize = 1;
    for(auto x: m) {
        int size = x.second.size();
        if ((size+1) > maxSize) maxSize = size + 1;
    }   

    cout << maxSize << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        longestSubSequence(a, n);
    }
    return 0;
}