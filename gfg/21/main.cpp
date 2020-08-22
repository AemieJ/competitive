#include<bits/stdc++.h>

using namespace std;

void removeDup(string a) {
    int l = a.length();
    int flag = false;
    stack<int> s;
    s.push(0);
    for(int i = 1; i < l; ++i) {
        if (!s.empty()) {
            if (a[s.top()] != a[i]) {
                if (i - s.top() != 1) {
                    s.pop();
                }
                s.push(i); 
            } else {
                flag = true;
                if (i == l - 1) s.pop();
            }
        } else {
            s.push(i);
        }
    }
    string newS = "";
    vector<char> res;
    while (!s.empty()) {
        char val = a[s.top()];
        res.push_back(val);
        s.pop();
    }

    reverse(res.begin(), res.end());
    for(auto x: res) {
        newS += x;
    }


    if (flag) removeDup(newS);
    else cout << newS;
    
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        removeDup(s);
        cout << endl;
    }
    return 0;
}