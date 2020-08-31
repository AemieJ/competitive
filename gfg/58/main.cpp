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

int height(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    if (node == NULL) return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);

    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main() {
    return 0;
}