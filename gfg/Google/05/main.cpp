#include<iostream>
#include<map>
#include<string>
#include<vector>
#include <sstream>

using namespace std;

map<char, int> createFreqCount(string &str) {
    int l = str.length();
    map<char, int> storage;
    for (int i = 0; i < l; ++i) {
       char val = str.at(i);
        if (storage[val]) {
            ++storage[val];
        } else {
            storage[val] = 1;
        }
    }
    return storage;
}

string longest(vector<string> &arr, string &str) {
    int s = arr.size();
    int largestCount = 0, index = -1;
    for (int i = 0; i < s; ++i) {
        map<char, int> storage = createFreqCount(str);
        int count = 0;
        for (auto x: arr[i]) {
            if (storage[x]) {
                --storage[x];
                ++count;
            }
        }
        if (count > largestCount) {
            index = i;
            largestCount = count;
        }
    }
    return arr[index];
}

int main() {
    int t, x;
    cin >> t;
    vector<string> arr;
    string str, st, s;
    for (int i = 0; i < t; ++i) {
        cin >> x;
        cin.ignore(256, '\n');
        getline(cin, st);
        stringstream ss(st);
        while (getline(ss, s, ' ')) {
            arr.push_back(s);
        }
        getline(cin, str);
        cout << longest(arr, str) << endl;
    }
    return 0;
}