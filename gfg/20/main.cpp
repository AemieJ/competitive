#include<bits/stdc++.h>

using namespace std;


void largestPalindrome(string &a) {
    int l = a.length();
    int maxLen = 0, sInx = 0;
    for(int i = 0; i < l; ++i) {
        for(int j = 0; j < l; ++j) {
            string part = a.substr(i, j+1);
            string rev = part;
            reverse(rev.begin(), rev.end());
            if (rev == part && part.length() > maxLen) {
                maxLen = part.length();
                sInx = i;
            }
        }
    }
    for(int i = sInx; i < (sInx + maxLen); ++i) {
        cout << a[i];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        largestPalindrome(s);
        cout << endl;
    }
    return 0;
}