#include<bits/stdc++.h>

using namespace std;

typedef pair<char, int> pd;

struct custom {
    constexpr bool operator() ( pair<char, int>& a, pair<char, int>& b ) const noexcept  {
        return a.second < b.second;
    };
};

void createHeap(priority_queue<pd, vector<pd>, custom>& pq, map<char, int>& m) {
    for(auto x: m) {
        char c = x.first;
        int freq = x.second;
        pq.push({c, freq});
    }
}

void solve(priority_queue<pd, vector<pd>, custom>& pq, string &res) {
    pair<char, int> prev = {'#', -1};
    while (!pq.empty()) {
        pair<char, int> front = pq.top();
        pq.pop();
        res += front.first; 
        if (prev.second > 0) {
            pq.push({prev.first, prev.second});
        }
        front.second--;
        prev = front;
    }
}

bool createFreqMap(map<char, int>& m, string q) {
    for(int i = 0; i < q.length(); ++i) {
        char val = q[i];
        if (m[val] != 0) {
            ++m[val];
        } else {
            m[val] = 1;
        }
    }

    for(auto x: m) {
        if (x.second > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        string res = "";
        map<char, int> m;
        priority_queue<pd, vector<pd>, custom> pq;

        cin >> s;
        bool flag = createFreqMap(m, s);
        if (!flag) cout << 1 << endl;
        createHeap(pq, m);
        solve(pq, res);
        if (res.length() != s.length()) cout << 0 << endl;
        else cout << 1 << endl;

    }
    return 0;
}