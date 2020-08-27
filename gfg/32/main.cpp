#include<bits/stdc++.h>

using namespace std;

bool custom(pair<string, char> &a, pair<string, char> &b) {
    vector<string> order = {"5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM"};
    auto ita = find(order.begin(), order.end(), a.first);
    auto itb = find(order.begin(), order.end(), b.first);
    if (a.first == b.first) return a.second < b.second;
    int idxA = ita - order.begin();
    int idxB = itb - order.begin();
    return idxA < idxB;
}

void solve(vector<string> arr, int n) {
    vector<string> a;
    vector<string> d;

    for(auto x: arr) {
        string s;
        stringstream ss(x);
        vector<string> temp;
        while (getline(ss, s, '#')) {
            temp.push_back(s);
        }
        a.push_back(temp[0]);
        d.push_back(temp[1]);
    }

    vector<pair<string, char>> mapping;
    for(int i = 0; i < n; ++i) {
        mapping.push_back({a[i], 'a'});
        mapping.push_back({d[i], 'd'});
    }

    sort(mapping.begin(), mapping.end(), custom);

    vector< pair<string,char>>::iterator it = mapping.begin();
    int res = 0;
    int requirement = 0;
    for(; it != mapping.end(); ++it) {
        if ((*it).second == 'a') ++requirement;
        if ((*it).second == 'd') --requirement;
        if (res < requirement) res = requirement;
    }
    cout << res * 500 << endl;
}

int main() {
    int n;
    string s;
    cin >> n;
    vector<string> arr;
    while (n--) {
        cin >> s;
        arr.push_back(s);
    }
    solve(arr, arr.size());
    return 0;
}