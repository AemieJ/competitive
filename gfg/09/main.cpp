#include<iostream>

using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotate(Node* head, int k)
{
    Node *temp = head;
    Node *end = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;
    while (k--) {
        end = head;
        head = head->next;
    }
    end->next = NULL;
    return head;
}