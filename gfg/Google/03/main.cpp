#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int findFreq(vector<int> arr, int x) {
    map<int, int> count;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == x && count[x]) ++count[x];
        else count[arr[i]] = 1;
    }

    return count[x];
}

int main() {
    int t, n, val, x;
    vector<int> arr;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> val;
            arr.push_back(val);
        }
        cin >> x;
        cout << findFreq(arr, x) << endl;
    }
    return 0;
}