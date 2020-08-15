#include<iostream>
#include<vector> 
#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void traverse(Node *root, vector<int> &graph) {
    if (root == NULL) return;
    traverse(root->left, graph);
    graph.push_back(root->data);
    traverse(root->right, graph);
}

vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   
   vector<int>graph1;
   vector<int>graph2; 
   traverse(root1, graph1);
   traverse(root2, graph2);

   graph1.insert(graph1.begin(), graph2.begin(), graph2.end());
   sort(graph1.begin(), graph1.end());
   return graph1;
}