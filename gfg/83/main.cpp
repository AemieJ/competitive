#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& wt, int n) {
    vector<vector<int>> visited(n, vector<int>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = wt[0][0];

    while (!pq.empty()) {
        pair<int, int> u = pq.top().second;
        pq.pop();
        while(!visited[u.first][u.second]) {
            visited[u.first][u.second] = true; 
            if (u.first - 1 >= 0 && !visited[u.first-1][u.second] && dist[u.first-1][u.second] > dist[u.first][u.second] + wt[u.first-1][u.second]) {
                dist[u.first - 1][u.second] = dist[u.first][u.second] + wt[u.first-1][u.second];
                pq.push({dist[u.first - 1][u.second], {u.first-1, u.second}});
            }
            if (u.first +1 < n && !visited[u.first + 1][u.second] && dist[u.first + 1][u.second] > dist[u.first][u.second] + wt[u.first+1][u.second]) {
                dist[u.first + 1][u.second] = dist[u.first][u.second] + wt[u.first+1][u.second];
                pq.push({dist[u.first + 1][u.second], {u.first + 1, u.second}});
            }

            if (u.second - 1 >= 0 && !visited[u.first][u.second - 1] && dist[u.first][u.second - 1] > dist[u.first][u.second] + wt[u.first][u.second - 1]) {
                dist[u.first][u.second - 1] = dist[u.first][u.second] + wt[u.first][u.second - 1];
                pq.push({dist[u.first][u.second - 1], {u.first, u.second - 1}});
            }

            if (u.second + 1 < n && !visited[u.first][u.second + 1] && dist[u.first][u.second + 1] > dist[u.first][u.second] + wt[u.first][u.second + 1]) {
                dist[u.first][u.second + 1] = dist[u.first][u.second] + wt[u.first][u.second + 1];
                pq.push({dist[u.first][u.second + 1], {u.first, u.second + 1}});
            }
        }
    }

    return dist[n-1][n-1];

}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> wt(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> wt[i][j];
            }
        }
        cout << solve(wt, n) << endl;
    }
    return 0;
}