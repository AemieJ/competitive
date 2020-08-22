#include<bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& matrix, int m, int n) {
    int sr = 0;
    int sc = 0;
    int er = m;
    int ec = n;

    while (sr < er && sc < ec) {
        for(int i = sc; i < ec; ++i) {
            cout << matrix[sr][i] << " ";
        }
        ++sr;
        for(int j = sr; j < er; ++j) {
            cout << matrix[j][ec - 1] << " ";
        }
        --ec;
        if (sr < er) {
            for(int i = ec - 1; i >= sc; --i) {
                cout << matrix[er-1][i] << " ";
            }
            --er;
        }
        if (sc < ec) {
            for(int j = er - 1; j >= sr; --j) {
                cout << matrix[j][sc] << " ";
            }
            ++sc;
        }
    }
}
int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        solve(matrix, m, n);
        cout << endl;
    }
    return 0;
}