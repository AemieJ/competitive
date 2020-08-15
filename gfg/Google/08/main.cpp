#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void rotate2D(vector<vector<int>> arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >= 0; --j) {
            cout << arr[i][j] << " ";
        }
    }
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> arr[j][k];
            }
        }
        rotate2D(arr, n);
        cout << endl;
    }
    return 0;
}