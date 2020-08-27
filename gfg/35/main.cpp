#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;

Node* pairWiseSwap(Node* head) {
    Node *cur=head;
    if(!head || !head->next) return head;
    while( cur && cur->next!=NULL) {

        int x = cur->data;
        cur->data = cur->next->data;
        cur->next->data = x;
        cur = cur->next->next;
    }
    return head;
}

int main() {
    return 0;
}