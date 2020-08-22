#include<bits/stdc++.h>

using namespace std;

int longestDistinct(string a) {
    int l = a.length();
    vector<char> s;
    vector<int> count;
    char value = a[0];
    s.push_back(value);
    for(int i = 1; i < l; ++i) {
        char val = a[i];
        auto it = find(s.begin(), s.end(), val);
        if (it != s.end()) {
            count.push_back(s.size());
            int idx = it - s.begin();
            for(int i = 0; i <= idx; ++i) {
                s.erase(s.begin());
            }

        }
        s.push_back(val);
    }
    count.push_back(s.size()); 
    int maxVal =  *max_element(count.begin(), count.end());
    return maxVal;
}

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        cout << longestDistinct(a) << endl;
    }
    return 0;
}