#include<bits/stdc++.h>

using namespace std;

int maxActivity(vector<int>& start, vector<int>& end, int n) {
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) v[i] = {end[i], start[i]};
    sort(v.begin(), v.end()); 

    int count = 0; 
    queue<pair<int, int>> q;
    q.push({v[0].first, 0});

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        ++count;

        int endVal = front.first;
        int index = front.second;

        for(int i = index + 1; i < n; ++i) {
            int startVal = v[i].second; 
            if (startVal >= endVal) {
                q.push({v[i].first, i});
                break;
            }
        }
    }
    return count;
}

int  main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> start(n);
        vector<int> end(n);
        for(int i = 0; i < n; ++i) cin >> start[i];
        for(int i = 0; i < n; ++i) cin >> end[i];
        cout << maxActivity(start, end, n) << endl;
    }
    return 0;
}