/*
The structure of a BST node is as follows:
*/
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

int getCountOfNode(Node *root, int l, int h) {
    int cnt = 0;
    if (root == NULL) return 0;
    if (root->data >= l && root-> data <= h) {
        ++cnt;
    }
    return cnt + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
}