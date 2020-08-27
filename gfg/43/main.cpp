#include<bits/stdc++.h>

using namespace std;

void highestFrequency(const string &a, int n) {
    map<char, int> frequency;
    if (n == 0 || a == "") {
        cout << "Denied - String can't be empty" << endl;
        return;
    }
    for(auto x: a) {
        if (frequency[x]) ++frequency[x];
        else frequency[x] = 1;
    }

    char maxFreq = a[0];
    int maxCount = 0;

    for(auto freq: frequency) {
        if (freq.second > maxCount) {
            maxCount = freq.second;
            maxFreq = freq.first;
        }
    }

    cout << maxFreq << endl;
}

int main() {
    string a = "banana";
    highestFrequency(a, a.length());
    return 0;
}