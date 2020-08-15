/*
stack solution : copied (clever) 
*/

#include<iostream> 
#include<stack>
#include<string>

using namespace std;

void minNumber(string s) {
    int l = s.length() + 1;
    stack<int> st;
    int num = 1;
    for(int i = 0; i <= l; ++i) {
        st.push(num++);
        if (s[i] == 'I' || i == l-1) {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        minNumber(s);
        cout << endl;
    }
    return 0;
}