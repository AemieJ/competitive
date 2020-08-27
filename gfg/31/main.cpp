#include<bits/stdc++.h>

using namespace std; 

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *merge(Node *a, Node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->data < b->data) {
        a->bottom = merge(a->bottom, b);
        return a;
    } else {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}

Node *flatten(Node *root) {
    Node *a = root;
    Node *b = root->next;

    while(b != NULL) {
        Node *c = b->next;
        a = merge(a, b);
        b = c;
    }
    return a;
}