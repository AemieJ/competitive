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

void printSpiral(Node *root) {
    if (root == NULL) return;
    map<int, vector<int>> m;
    queue<pair<int, Node*>> q;
    int hd = 0; 
    Node* temp;
    q.push({0, root}); 
    m[hd].push_back(root->data);

    while(!q.empty()) {
        pair<int, Node*> front = q.front();
        hd = front.first;
        temp = front.second;
        q.pop();

        if(temp->left != NULL) {
            m[hd+1].push_back(temp->left->data);
            q.push({hd+1, temp->left});
        }

        if(temp->right != NULL) {
            m[hd+1].push_back(temp->right->data);
            q.push({hd+1, temp->right});
        }

    }

    for(int i = 0; i <= hd; ++i) {
        if (i % 2 == 0) {
            reverse(m[i].begin(), m[i].end());
        }
        for(auto x: m[i]) {
            cout << x << " ";
        }
    }
}

int main() {
    return 0;
}