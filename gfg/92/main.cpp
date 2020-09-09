/* IMPORTANT QUES */
#include<bits/stdc++.h>

using namespace std;

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<int> visited(V, false);
    vector<int> key(V, INT_MAX);
    int wt = 0;
    key[0] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        pair<int, int>front = pq.top();
        pq.pop();
        int vertice = front.second;
       if (!visited[vertice]) {
           visited[vertice] = true; 
           wt += key[vertice];

           for(int j = 0; j < V; ++j) {
                if (!visited[j] && key[j] > graph[vertice][j]) {
                    key[j] = graph[vertice][j];
                    pq.push({key[j], j});
                }
            }
       }
    }

    return wt;
}

int main() {
    return 0;
}