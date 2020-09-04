#include<bits/stdc++.h>

using namespace std;

// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

string topologicalSort(map<char, vector<char>>& m, vector<int>& indegree) {
    int size = m.size();
    queue<char> q;
    string s;

    for(auto x: m) {
        int key = x.first - 'a';
        if (indegree[key] == 0) q.push(x.first);
    }

    while (!q.empty()) {
        int front = q.front();
        s += front;
        q.pop();

        for(int i = 0; i < m[front].size(); ++i) {
            char val = m[front][i];
            --indegree[val - 'a']; 
            if (indegree[val - 'a'] == 0) q.push(val);
        }
    }
    return s;
}

void createGraph(map<char, vector<char>>& m, int N, string dict[], vector<int>& indegree) {
    for(int i = 1; i < N; ++i) {
        string a = dict[i-1];
        string b = dict[i]; 

        int len = min(a.length(), b.length());
        for(int j = 0; j < len; ++j) {
            if (a[j] != b[j]) {
                char in = a[j];
                char out = b[j];
                if (m.find(in) != m.end()) {
                    auto it = find(m[in].begin(), m[in].end(), out); 
                    if (it == m[in].end()) {
                        m[in].push_back(out);
                        ++indegree[out - 'a'];
                    }
                } else {
                    m[in].push_back(out);
                    ++indegree[out - 'a'];
                }
                break;
            }
        }
        
    }
}

string findOrder(string dict[], int N, int K) {
    map<char, vector<char>> m;
    vector<int> indegree(26, 0);

    createGraph(m, N, dict, indegree); 
    string s = topologicalSort(m, indegree);
    return s;
}

int main() {
    return 0;
}