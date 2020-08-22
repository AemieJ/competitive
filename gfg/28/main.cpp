#include<bits/stdc++.h>

using namespace std;


void longestPrefix(vector<string> v, int n) {
    int maxIndex = 0;
    while (true) {
        for (string s : v) {
            if (maxIndex >= s.length() || s[maxIndex] != v[0][maxIndex]) {
                if (maxIndex == 0) {
                    cout << -1 << endl;
                } else {
                    cout << v[0].substr(0, maxIndex) << endl;
                }
                return;
            }
        }
        ++maxIndex;
    }

}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        longestPrefix(arr, n);
    }
    return 0;
}