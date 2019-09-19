#include<bits/stdc++.h>

using namespace std;

bool breathFirstSearch(vector< int >graph[] , long long int start , long long int vertices)
{
    bool visited[vertices+1] = {0};
    queue< int >listOfVertices;
    int counter = 0;
    listOfVertices.push(start);
    memset(visited,0,sizeof(visited));

    while(!listOfVertices.empty())
    {
        long long int element = listOfVertices.front();
        listOfVertices.pop();
        visited[element] = 1;
        
        for(int i= 0 ; i < graph[element].size() ; ++i)
        {
            int adjacent = graph[element][i];
            if(visited[adjacent])    
                return 0;
            else
                listOfVertices.push(adjacent);
            
        }
        ++counter;
    }
    if(counter != vertices)
        return 0;
    else 
        return 1;
}

int main()
{
    long long int vertices , edges;
    cin >> vertices >> edges;
    long long int vertice1 , vertice2;

    vector< int >graph[vertices+1];
    if(vertices-edges == 1)
    {
        for(int i=0 ; i < edges ; ++i)
        {
            cin >> vertice1 >> vertice2;
            graph[vertice1].push_back(vertice2);
        }

        if(breathFirstSearch(graph , 1 , vertices))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;

    }
    else 
        cout << "NO" << endl;
    return 0;
}