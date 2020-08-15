/*
Input: arr[] = {“1.1.2”, “0.9.1”, “1.1.0”}
Output: “0.9.1” “1.1.0” “1.1.2”

Input: arr[] = {“1.2”, “0.8.1”, “1.0”}
Output: “0.8.1” “1.0” “1.2” 
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int check(const string& a,const string& b) {
    int al = a.length();
    int bl = b.length();

    int i = 0, j = 0;
    while ( i < al && j < al) {
        if (a[i] == b[i]) { 
            ++i;
            ++j; 
        }
        if (a[i] > b[j]) return 1;
        if (a[i] < b[j]) return -1;
    }
    if (i == al && j == bl) {
        return 0;
    }
    if (i == al) return -1;
    return 1;

}

vector<string> getTokens(const string& a) {
    vector<string> v;
    string s;
    stringstream ss(a);
    while (getline(ss, s, '.')) {
        v.push_back(s);
    }
    return v;
}

bool comp(const string& a,const string& b) {
    vector<string> va;
    vector<string> vb;

    va = getTokens(a);
    vb = getTokens(b);

    for (int i = 0; i < min(va.size(), vb.size()); ++i) {
        int countCheck = check(va[i], vb[i]);
        if (countCheck == 1) return false;
        else if (countCheck == -1) return true;
    }
    if (va.size() < vb.size()) return true;
    return false;
}

int main() {
    vector<string> arr;
    arr.push_back("1.1.2");
    arr.push_back("0.9.1");
    arr.push_back("1.1.0");

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}