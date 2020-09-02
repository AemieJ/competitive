#include<bits/stdc++.h>

using namespace std;

/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

void bfs(vector<int>& res, vector<int> g[], vector<int>& visited, int i) {
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (!visited[front]) res.push_back(front);
        visited[front] = true;
        for(int j = 0; j < g[front].size(); ++j) {
            int node = g[front][j];
            if (!visited[node]) {
                q.push(node);
            }
        }
    }
}

vector <int> bfs(vector<int> g[], int N) {
    vector<int> res;
    vector<int> visited(N, false);
    bfs(res, g, visited, 0);
    return res;
}

int main() {
    return 0;
}