#include<bits/stdc++.h>

using namespace std;

/* IMPORTANT QUES !!
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node {
    int data;
    struct node* next;
    
    node(int x){
       data = x;
       next = NULL;
    }
}*head;

struct node *reverse (struct node *head, int k)
{
    node *curr = head;
    node *prev = NULL;
    node *q;
    int counter = k;
    while(counter-- && curr !=NULL)
    {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    
    if(head != NULL)
    head->next = reverse(q, k);
    return prev;
}