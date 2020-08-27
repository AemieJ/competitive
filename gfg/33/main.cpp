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


int intersectPoint(Node* head1, Node* head2){
    Node *temp = head1;
    while(temp) {
        temp->data = -1 * (temp->data +1);
        temp = temp->next;
    }
    temp = head2;
    int ans = -1,p=0;
    while(temp) {
        if(temp->data < 0) {
            p=1;
            ans = -1*temp->data;
            break;
        }
        temp = temp->next;
    }
    if(p == 1)
    return (ans-1);
    return ans;
}

int naiveIntersectPoint(Node* head1, Node* head2)
{
    vector<int> order1;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != NULL) {
        order1.push_back(temp1->data); 
        temp1 = temp1->next;
    }

    vector<int> idx;
    int id = 0; 
    while (temp2 != NULL) {
        if (order1[id] == temp2->data) {
            idx.push_back(id);
            temp2 = temp2->next;
        } else if (order1[id] != temp2->data) {
            while (!order1.empty()) {
                idx.pop_back();
            }
        }
        ++id;
        if (id == order1.size() && temp2 != NULL) {
            id = 0;
            temp2 = temp2->next;
        }
    }

    return order1[idx[0]];
}

int main() {
    return 0;
}