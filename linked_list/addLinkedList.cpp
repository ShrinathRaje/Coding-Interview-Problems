//add two numbers represented by linked list
//problem: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1/

// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
struct Node* reverseLinkedList(struct Node* head) {
    Node *p = NULL;
    Node *n = head;
    
    while(n) {
        Node *t = n->next;
        n->next = p;
        p = n;
        n = t;
    }
    
    return p;
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    Node *f = reverseLinkedList(first);
    Node *s = reverseLinkedList(second);
    
    Node *a = f, *b = s;
    int c = 0;
    Node *head = NULL;
    while(a || b) {
        int d = 0;
        if(a) {
            d += a->data;
            a = a->next;
        }
        
        if(b) {
            d += b->data;
            b = b->next;
        }
        
        d += c;
        c = d >= 10 ? 1 : 0;
        
        Node *n = new Node(d % 10);
        n->next = head;
        head = n;
    }
    
    return head;
}
