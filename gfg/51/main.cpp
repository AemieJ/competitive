#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that returns the bottom view.
vector <int> bottomView(Node *root) {
   map<int, int> mapping;
   queue<pair<int, Node*>> q;
   int hd = 0;
   mapping[hd] = root->data;
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
           mapping[hd-1] = temp->left->data;
       }

       if (temp->right != NULL) {
           q.push({hd+1, temp->right});
           maxVal = max(maxVal, hd+1);
           mapping[hd+1] = temp->right->data;
       }

   }

   vector<int> res;
   for(int i = minVal; i <= maxVal; ++i) {
       res.push_back(mapping[i]);
   }
   return res;
}

int main() {
    return 0;
}