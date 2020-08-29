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

vector<int> verticalOrder(Node *root) {
    map<int, vector<int>> m;
    queue<pair<int, Node *>> q; 

    int hd = 0;
    m[hd].push_back(root->data);
    q.push({hd, root});
    Node* temp;
    int minVal = 0, maxVal = 0;

    while(!q.empty()) {
        pair<int, Node*>front = q.front();
        hd = front.first;
        temp = front.second;
        q.pop();

        if (temp->left != NULL) {
            q.push({hd-1, temp->left});
            minVal = min(minVal, hd-1);
            m[hd-1].push_back(temp->left->data);
        }

        if (temp->right != NULL) {
            q.push({hd+1, temp->right});
            maxVal = max(maxVal, hd+1);
            m[hd+1].push_back(temp->right->data);
        }

    }

    vector<int> res;
    for(int i = minVal; i <= maxVal; ++i) {
       res.insert(res.end(), m[i].begin(), m[i].end());
    }
    return res;
}

int main() {
    return 0;
}