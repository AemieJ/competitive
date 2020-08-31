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

// This function should return tree if passed  tree 
// is balanced, else false. 

bool flag;
int isBalance(Node *root)
{
    if(root==NULL) return 0;
    int a = isBalance(root->left);
    int b = isBalance(root->right);
    if(abs(a-b)>1) flag=false;
    return max(a,b)+1;
}

bool isBalanced(Node *root) {
    flag=true;
    isBalance(root);
    return flag;
}

int main() {
    return 0;
}