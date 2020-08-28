#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int maxDepth = -1;
void solve(Node *temp, int depth) {
    if (temp == NULL) return;
    if (depth > maxDepth) {
        cout << temp->data << " "; 
        maxDepth = depth;
    }
    solve(temp->left, depth + 1);
    solve(temp->right, depth + 1);
}

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   // Your code here
  maxDepth = -1;
  solve(root, 0);
  
}

int main() {
    return 0;
}