#include<iostream>
#include<vector>

using namespace std;

void floodFill(vector<vector<int>>& matrix, int i, int j, int from, int to) {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size() || from != matrix[i][j]) return;
    matrix[i][j] = to;
    floodFill(matrix, i+1, j, from, to);
    floodFill(matrix, i-1, j, from, to);
    floodFill(matrix, i, j+1, from, to);
    floodFill(matrix, i, j-1, from, to);
}

int main() {
    int t;
    int n, m;
    cin >> t;
    int x, y, k;
    while(t--) {
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        cin >> x >> y >> k;
        floodFill(matrix, x, y, matrix[x][y], k);

        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;

    }
    return 0;
}