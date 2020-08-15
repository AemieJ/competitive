#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;


int findLarge(vector<int> arr, int n) {
    map<int, int, greater<int>> count;
    for (int i = 0; i < n; ++i) {
        if (count[arr[i]]) {
            ++count[arr[i]];
        } else {
            count[arr[i]] = 1;
        }
    }

    auto it = count.begin();
    int largest = it->first;
    int minfreq = it->second;
    for (auto itr : count) {
        if (itr.second < minfreq) {
            largest = itr.first;
            minfreq = itr.second;
        }
    }
    return largest;
}

int main() {
    int t, n, val;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; ++j) {
            cin >> val; 
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end());
        cout << findLarge(arr, n) << endl;
    }
    return 0;
}
