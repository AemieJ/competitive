#include<bits/stdc++.h>

using namespace std;

bool withinBounds(int r, int c, int i, int j) {
    return (i < r && i >= 0 && j < c && j >= 0);
}

void solve(vector<vector<int>>& arr, int r, int c) {
    queue<pair<int, int>> rotten;
    int total = 0;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if (arr[i][j] == 1 || arr[i][j] == 2) {
                ++total;
            }
            if (arr[i][j] == 2) {
                rotten.push({i, j});
            }
        }
    }

    int cnt = 0, time = 0; 
    while(!rotten.empty()) {
        int s = rotten.size();
        cnt += s;
        while (s--) {
            pair<int, int> tmp = rotten.front();
            int i = tmp.first;
            int j = tmp.second;
            rotten.pop();
            if (withinBounds(r, c, i+1, j) && arr[i+1][j] == 1) {
                arr[i+1][j] = 2;
                rotten.push({i+1, j});
            }
            if (withinBounds(r, c, i-1, j) && arr[i-1][j] == 1) {
                arr[i-1][j] = 2;
                rotten.push({i-1, j});
            }
            if (withinBounds(r, c, i, j+1) && arr[i][j+1] == 1) {
                arr[i][j+1] = 2;
                rotten.push({i, j+1});
            }
            if (withinBounds(r, c, i, j-1) && arr[i][j-1] == 1) {
                arr[i][j-1] = 2;
                rotten.push({i, j-1});
            }
        }
        ++time;
    }
    if (cnt == total) cout << time-1 << endl;
    else cout << -1 << endl;
}

int main() {
    int t, r, c;
    cin >> t;
    while (t--) {
        cin >> r >> c;
        vector<vector<int>> arr(r, vector<int>(c, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> arr[i][j];
            }
        }

        solve(arr, r, c);
        
    }
    return 0;
}