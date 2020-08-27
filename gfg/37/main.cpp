#include<bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

// explanation: we need m to be removed and the one before m need to be connected to the node after m. Thus, we change the pointer of m itself to the next node.
// This give the direct connection
void deleteNode(Node *m) {
   *m = *(m->next);
}

int main() {
    return 0;
}