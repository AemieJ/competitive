#include<bits/stdc++.h>

using namespace std;

bool checkParanthesis(string a) {
    stack<char> s;
    int flag = 0;
    for(auto x: a) {
        if (!s.empty()) {
            char val = s.top();
            if (val == '{' && x == '}') flag = 1;
            if (val == '[' && x == ']') flag = 1;
            if (val == '(' && x == ')') flag = 1;
        } 
        if (s.empty() || !flag) {
            s.push(x);
        }
        if (flag) {
            s.pop();
            flag = 0;
        }
    }

    if (s.empty()) return true;
    return false;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        if (checkParanthesis(s)) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
    }
    return 0;
}