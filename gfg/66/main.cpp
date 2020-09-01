#include<bits/stdc++.h>

using namespace std;

void floodFill(vector<vector<int>>& mat,int i, int j, int k, int val) {
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[i].size() || mat[i][j] != val) return; 

    mat[i][j] = k; 
    floodFill(mat, i + 1, j, k, val);
    floodFill(mat, i - 1, j, k, val);
    floodFill(mat, i, j + 1, k, val);
    floodFill(mat, i, j - 1, k, val);
}

int main() {
    int t, n, m;
    int x, y, k;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        cin >> x >> y >> k;
        floodFill(mat, x, y, k, mat[x][y]);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}