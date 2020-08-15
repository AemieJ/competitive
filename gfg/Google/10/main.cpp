// DFS IMPLEMENTATION - IMP QUESTION **
#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

void dfs(int adj[100][100], int a, int b, int visited[100][100]) {
    int row[] = {0, 0, -1, 1};
    int col[] = {-1, 1, 0, 0};

    visited[a][b] = 1;
    for(int i = 0; i < 4; ++i) {
        if (adj[a+row[i]][b+col[i]] == 1 && visited[a+row[i]][b+col[i]] == 0) {
            dfs(adj, a+row[i], b+col[i], visited);
        }
    }
}

int main() {
    int t;
    int x, y;
    cin >> t;
    int adj[100][100], visited[100][100];
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));

    while(t--) {
        cin >> x >> y;
        for(int i = 0; i < x; ++i) {
            string str;
            cin >> str;
            for(int j = 0; j < str.length(); ++j) {
                if (str[j] == 'X') {
                    adj[i][j] = 1;
                }
            }
        }

        int groups = 0;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (adj[i][j] == 1 && visited[i][j] == 0) {
                    dfs(adj, i, j, visited);
                    groups++;
                }
            }
        }
        cout << groups << endl;
    }
}