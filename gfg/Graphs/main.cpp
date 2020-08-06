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

void topologicalSortQueue(vector<vector<int>> g);
void topologicalSortStack(vector<vector<int>> g); //Recursive func

int main() {
    // Create the graph using adjacency matrix 
    vector<vector<int>> g; 
    g = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0}
    };
    printGraph(g);
    // bfs(g);
    // dfs(g);
    // cout << isCycleBFS(g) << endl;
    // cout << isCycleDFS(g) << endl;
    topologicalSortQueue(g);
    topologicalSortStack(g);
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

// Directed & Acyclic Graph
void topologicalSortQueue(vector<vector<int>> g) {
    int n = g.size();
    vector<int> inorder(n, 0);
    vector<int> res;
    queue<int> q; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) ++inorder[j];
        }
    }
    
    for (int k = 0; k < n; ++k) {
        if (!inorder[k]) q.push(k);
    }

    while (!q.empty()) {
        int top = q.front();
        res.push_back(top);
        q.pop();
        for (int m = 0; m < n; ++m) {
            if (g[top][m]) {
                --inorder[m];
                if (!inorder[m]) q.push(m);
            }
        }
    }
    printGraph(res);
}

void _topologicalSort(vector<vector<int>> &g, vector<int> &res, vector<int> &visited, int index) {
    visited[index] = 1;
    for (int j = 0; j < g.size(); ++j) {
        if (g[index][j] && !visited[j]) {
            _topologicalSort(g, res, visited, j);
        }
    }
    res.push_back(index);
}

void topologicalSortStack(vector<vector<int>> g) {
    int n = g.size();
    vector<int> visited(n, 0);
    vector<int> res;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            _topologicalSort(g, res, visited, i);
        }
    }
    reverse(res.begin(), res.end());
    printGraph(res);
}

/* Basic Key Points in Each Graph Algo */