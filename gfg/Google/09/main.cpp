#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>

using namespace std;

void remove(string a) {
    int l = a.length();
    vector<int>index;
    for (int i = 0; i < l; ++i) {
        if (a[i] == 'b') {
            continue;
        } else if(i+1 < l && a[i] == 'a' && a[i+1] == 'c') {
            ++i;
        } else {
            index.push_back(i);
        }
    }

    for (auto x: index) {
        cout << a[x];
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        remove(s);
        cout << endl;
    }
    return 0;
}