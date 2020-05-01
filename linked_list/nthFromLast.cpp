/*
* find nth node from last node in a linked list
* Date: 1st May 2020
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/
*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

    printf("%d", getNthFromLast(head, k));
    cout << endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n) {
    // int a[1000];
    
    // int i=0;
    // for(Node *p = head; p != NULL; p = p->next) {
    //     a[i++] = p->data;
    // }
    
    // return (n > i) ? -1 : a[i - n];
    
    Node *r, *m=NULL;
    int i=0;
    for(Node *p = head; i<n; p=p->next, ++i) {
        if(p == NULL)
            return -1;
            
        r = p;
    }
    
    for(Node *p = r; p != NULL; p=p->next) {
        if(m == NULL)
            m = head;
        else
            m = m->next;
    }
    
    return m->data;
    
}