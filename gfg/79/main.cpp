/* IMPORTANT */
#include<bits/stdc++.h>

using namespace std;

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool DFSUtil(vector<int> *adj, int u, vector<bool> &visited, int parent)
{
   visited[u]=true;                 // Mark the node as visited
   for(auto v: adj[u])              // Run for all the adjacent nodes of that vertex 
   {
       if(!visited[v])              // If vertex is not visited
       {
           if(DFSUtil(adj, v, visited, u))  // Run DFS for the adjacent vertex
            return true;                    
       }
       else if(v!=parent)                   
            return true;            
   }
   return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   vector<bool> visited(V, false);  // Created a visited vector intially all false(unvisited)
   for(int u=0;u<V;u++)             // Traversing through every node
   {
       if(!visited[u])              // If vertex is not already visited
          if(DFSUtil(adj,u,visited,-1)) // call DFS on that vertex
            return true;                // If function contains cycle return true
   }
   return false;                        // Else return false
}

int main() {
    return 0; 
}