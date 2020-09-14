#include<bits/stdc++.h>

using namespace std;

#define MAX 5
int visited[MAX][MAX];
vector<string> res;

void path(int m[MAX][MAX], int x, int y, string dir, int n) {
    if (x == n-1 && y == n-1) {
        res.push_back(dir);
        return;
    }

    if (m[x][y] == 0 or visited[x][y] == 1) return;

    // DFS
    visited[x][y] = 1;
    if (x > 0) path(m, x - 1, y, dir + 'U', n);
    if (y > 0) path(m, x, y - 1, dir + 'L', n);
    if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
    if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
    visited[x][y] = 0;
}


vector<string> printPath(int m[MAX][MAX], int n) {
    memset(visited, 0, sizeof visited);
    res.clear();
    if (m[0][0] == 0 || m[n-1][n-1] == 0) return res;
    path(m, 0, 0, "", n);
    
    sort(res.begin(), res.end());
    return res;
}   
