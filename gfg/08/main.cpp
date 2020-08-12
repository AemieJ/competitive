#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Task: Need to Complete the function
struct Node
{
    int data;
    struct Node *next;
};

struct Node* reverseList(struct Node *head)
{
    Node* current = head; 
    Node *prev = NULL, *next = NULL; 
  
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    head = prev; 
    return head;
}