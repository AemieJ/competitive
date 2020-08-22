#include<bits/stdc++.h>

using namespace std;

vector<int> createFreq(string a) {
    int l = a.length();
    vector<int> arr(26, 0);
    int first = 'a';
    for(int i = 0; i < l; ++i) {
        int val = a[i] - first;
        ++arr[val];
    }

    return arr;
}

bool anagram(string a, string b) {
    int la = a.length();
    int lb = b.length();

    vector<int> arrA = createFreq(a);


    if (la != lb) {
        return false;
    }
    for(int i = 0; i < lb; ++i) {
        int val = b[i] - 'a';
        --arrA[val];
    }

    for(int i = 0; i < 26; ++i) {
        if (arrA[i] != 0) return false;
    }

    return true;

}

int main() {
    int t; 
    cin >> t;
    string a, b;
    while (t--) {
        cin >> a >> b;
        if (anagram(a, b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}