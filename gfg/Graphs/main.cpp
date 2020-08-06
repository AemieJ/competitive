#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

void printGraph(vector<vector<int>> g);
void printGraph(vector<int> g);

void bfs(vector<vector<int>> g);
bool isCycleBFS(vector<vector<int>> g);

void dfs(vector<vector<int>> g);
bool isCycleDFS(vector<vector<int>> g);

int main() {
    // Create the graph using adjacency matrix 
    vector<vector<int>> g; 
    g = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    printGraph(g);
    bfs(g);
    dfs(g);
    cout << isCycleBFS(g) << endl;
    cout << isCycleDFS(g) << endl;
    return 0;
}

void printGraph(vector<vector<int>> g) {
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        cout << i << " : "; 
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void printGraph(vector<int> g) {
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        cout << g.at(i) << " "; 
    }
    cout << endl;
}

void bfs(vector<vector<int>> g) {
    int n = g.size();
    vector<int> res;
    vector<int> visited(n, 0);
    queue<int> q; 
    q.push(0);
    visited[0] = 1;
    res.push_back(0);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int j = 0; j < n; ++j) {
            if (g[top][j] && !visited[j]) {
                q.push(j);
                visited[j] = 1;
                res.push_back(j);
            }
        }
    }
    printGraph(res);
}

bool isCycleBFS(vector<vector<int>> g) {
    int n = g.size();
    vector<int> visited(n, -1);
    queue<int> q; 
    q.push(0);
    visited[0] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        visited[top] = 1;
        for (int j = 0; j < n; ++j) {
            if (g[top][j]) {
                if (top == j) return true;
                if (!visited[j]) return true;
                if (visited[j] == -1) {
                    q.push(j);
                    visited[j] = 0;
                }
            }
        }
    }
    return false;
}

void dfs(vector<vector<int>> g) {
    int n = g.size();
    vector<int> res;
    vector<int> visited(n, 0);
    stack<int> s; 
    s.push(0);
    visited[0] = 1;
    res.push_back(0);

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        for (int j = 0; j < n; ++j) {
            if (g[top][j] && !visited[j]) {
                s.push(j);
                visited[j] = 1;
                res.push_back(j);
            }
        }
    }
    printGraph(res);
}

bool isCycleDFS(vector<vector<int>> g) {
    int n = g.size();
    vector<int> visited(n, -1);
    stack<int> s; 
    s.push(0);
    visited[0] = 0;

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        visited[top] = 1;
        for (int j = 0; j < n; ++j) {
            if (g[top][j]) {
                if (top == j) return true;
                if (!visited[j]) return true;
                if (visited[j] == -1) {
                    s.push(j);
                    visited[j] = 0;
                }
            }
        }
    }
    return false;
}
