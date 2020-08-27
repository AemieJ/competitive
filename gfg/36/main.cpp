#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node* head) {
    if (!head) return;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != slow) {
        if (!fast || !fast->next) return;
        slow = slow->next;
        fast = fast->next->next;
    }

    int size = 1;
    fast = fast->next;
    while (fast != slow) {
        ++size;
        fast = fast->next;
    }

    slow = head;
    fast = head;
    for(int i = 1; i <= size; ++i) {
        fast = fast->next;
    }

    while (fast->next != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;

}



int main() {
    return 0;
}