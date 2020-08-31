#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &A) {
    queue<Node *> q;
    if (root != NULL) A.push_back(root->data);
    else A.push_back(-1);
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->left) {
            q.push(temp->left);
            A.push_back(temp->left->data);
        } else {
            A.push_back(-1);
        }

        if (temp->right) {
            q.push(temp->right);
            A.push_back(temp->right->data);
        } else {
            A.push_back(-1);
        }
    }    
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A) {
    Node *root;
   if (A[0] != -1) root = new Node(A[0]);
   else root = NULL;

   queue<Node *> q;
   q.push(root);
   Node *n;
   int i = 0;

   while(!q.empty()) {
       Node *temp = q.front();
       q.pop();

       if (A[i+1] != -1) {
           temp->left = new Node(A[i+1]);
           q.push(temp->left);
       } else {
           temp->left = NULL;
       }

       if (A[i+2] != -1) {
           temp->right = new Node(A[i+2]);
           q.push(temp->right);
       } else {
           temp->right = NULL;
       }
       i += 2;
   }

   return root;
}

int main() {
    return 0;
}