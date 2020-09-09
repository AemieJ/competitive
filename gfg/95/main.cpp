#include<bits/stdc++.h>

using namespace std;

void solve(int &n, vector<int>& notes) {
    if (n == 0) return;
    int val = 0;
    if ( n > notes[notes.size() - 1]) val = notes[notes.size() - 1];
    for(int i = 0; i < notes.size(); ++i) {
        if ( n < notes[i]) {
            if (i != 0) val = notes[i-1];
            else val = 0;
            break;
        }
    }
    cout << val << " ";
    int remaining = n - val;
    solve(remaining, notes);
}

int main() {
    int t, n;
    vector<int> notes = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    cin >> t; 
    while (t--) {
        cin >> n;
        solve(n, notes);
        cout << endl;
    }
    return 0;
}