#include<bits/stdc++.h>

using namespace std;

/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int minimumDist(vector<int> dist, vector<int> visited, int V) {
    int minVal = INT_MAX, minIndex = -1; 
    for(int i = 0; i < V; ++i) {
        if (!visited[i] && dist[i] <= minVal) {
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<int> visited(V, false);

    dist[src] = 0; 

    for(int i = 0; i < V - 1; ++i) {
        
        int least = minimumDist(dist, visited, V); 
        visited[least] = true;

        for(int j = 0; j < V; ++j) {
            if (!visited[j] && dist[least] != INT_MAX && g[least][j] && dist[least] + g[least][j] < dist[j]) dist[j] = dist[least] + g[least][j];
        }
    }
    return dist;
}

int main() {
    return 0;
}