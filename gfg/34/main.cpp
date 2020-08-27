#include<bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node *root) {
    Node *prev = root;
    Node *curr = root->next;
    while (curr != NULL) {
        if (prev->data == curr->data) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    curr = root;
    return curr;
}

int main() {
    return 0;
}