#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& start, vector<int>& end, int n) {
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) v[i] = {end[i], start[i]};
    sort(v.begin(), v.end());

    vector<int> index;
    queue<pair<int, int>> q;
    q.push({v[0].first, 0});

    while (!q.empty()) {
        pair<int, int> front = q.front();
        int endVal = front.first;
        int itr = front.second;
        q.pop();
        auto it = find(end.begin(), end.end(), endVal);
        int idx = it - end.begin();
        index.push_back(idx); 

        for(int i = itr + 1; i < n; ++i) {
            if (v[i].second >= endVal) {
                q.push({v[i].first, i});
                break;
            }
        }        
    }  

    for(auto x: index) cout << x + 1 << " ";
    cout << endl;

}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> start(n);
        vector<int> end(n);

        for(int i = 0; i < n; ++i) cin >> start[i];
        for(int i = 0; i < n; ++i) cin >> end[i];
        solve(start, end, n);
    }
    return 0;
}