#include<bits/stdc++.h>

using namespace std;

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

void dfs(vector<int>& res, vector<int> g[], vector<int>& visited, int i) {
    visited[i] = true;
    res.push_back(i);
    for(int j = 0; j < g[i].size(); ++j) {
        int node = g[i][j];
        if (!visited[node]) {
            dfs(res, g, visited, node);
        }
    }

}

vector <int> dfs(vector<int> g[], int N) {
    vector<int> res;
    vector<int> visited(N, false);
    dfs(res, g, visited, 0); 
    return res;
}

int main() {
    return 0;
}