#include<bits/stdc++.h>

using namespace std;

void callDFS(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') return;
    grid[i][j] = '0';

    callDFS(grid, i - 1, j);
    callDFS(grid, i + 1, j);
    callDFS(grid, i, j + 1);
    callDFS(grid, i, j - 1);
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '1', '0'},
        {'0', '0', '0', '0', '1'}
    };

    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                ++count;
                callDFS(grid, i, j);
            }
        }
    }

    cout << count << endl;
    return 0;
}