#include<bits/stdc++.h>

using namespace std;

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> res;
    queue<int> q;
    vector<int> indegree(V, 0);

    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < adj[i].size(); ++j) {
            int node = adj[i][j];
            ++indegree[node];
        }
    }

    for(int i = 0; i < V; ++i) 
        if (indegree[i] == 0) q.push(i);
    
    while (!q.empty()) {
        int front = q.front();
        res.push_back(front);
        q.pop();

        for(int i = 0; i < adj[front].size(); ++i) {
            int node = adj[front][i];
            --indegree[node];
            if (indegree[node] == 0) q.push(node);
        }
    }

    return res;
}

int main() {
    return 0;
}