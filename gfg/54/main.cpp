#include<bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};

// Should set the nextRight for all nodes
void connect(Node *p) {
    if (p == NULL) return;
    map<int, vector<Node*>> m;
    queue<pair<int, Node*>> q;
    int hd = 0; 
    Node* temp;
    q.push({0, p}); 
    m[hd].push_back(p);

    while(!q.empty()) {
        pair<int, Node*> front = q.front();
        hd = front.first;
        temp = front.second;
        q.pop();

        if(temp->left != NULL) {
            m[hd+1].push_back(temp->left);
            q.push({hd+1, temp->left});
        }

        if(temp->right != NULL) {
            m[hd+1].push_back(temp->right);
            q.push({hd+1, temp->right});
        }
    }
    
    for(int i = 0; i <= hd; ++i) {
        vector<Node*> temp1 = m[i];
        int s = temp1.size(); 
        temp1[s-1]->nextRight = NULL;
        for(int j = 0; j < (s-1); ++j) {
            temp1[j]->nextRight = temp1[j+1];
        }
    }
}

int main() {
    return 0;
}