#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void inorder(Node* root, vector<Node*>& traversal) {
    if (root == NULL) return;
    inorder(root->left, traversal);
    traversal.push_back(root);
    inorder(root->right, traversal);
}

Node * bToDLL(Node *root) {
    if (root == NULL) return NULL;
    vector<Node*> traversal;
    inorder(root, traversal);

    int s = traversal.size() - 1;
    for(int i = 0; i < s; ++i) {
        Node* temp = traversal[i];
        if (i == 0) {
            temp->right = traversal[i+1];
            temp->left = NULL; 
        } else {
            temp->left = traversal[i-1];
            temp->right = traversal[i+1];
        }
    }
    if (s == 0) {
        traversal[s]->left = NULL;
    } else {
        traversal[s]->left = traversal[s-1];
    }
    traversal[s]->right = NULL;

    return traversal[0];
}

int main() {
    return 0;
}