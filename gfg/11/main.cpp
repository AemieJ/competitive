#include<bits/stdc++.h>

using namespace std;

void leaders(vector<int> arr, int n) {
    vector<int> res;
    int max = INT_MIN;
    for(int i = n -1; i >= 0; --i) {
        if (arr[i] >= max) {
            res.push_back(max);
            max = arr[i];
        }
    }
    res.push_back(max);
    for(int i = res.size() - 1; i > 0; --i) {
        cout << res[i] << " ";
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        leaders(arr, n);
        cout << endl;
    }
    return 0;
}