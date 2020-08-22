# include<bits/stdc++.h>

using namespace std;

int minCOunt(int arr[], int n, int s) {
    vector<int> res;
    for(int i = 0; i < n; ++i) {
        if (i + s - 1 < n) {
            int min = arr[i + s - 1] - arr[i];
            res.push_back(min);
        }
    }
    return *min_element(res.begin(), res.end());
}

int main() {
    int t, n, s;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cin >> s;
        sort(arr, arr + n);
        cout << minCOunt(arr, n, s) << endl;
        
    }
    return 0;
}