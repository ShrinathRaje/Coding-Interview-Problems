//check if a linked list is a palindrome
//problem: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
bool isPalindrome(Node *head) {
	if(head->next == NULL)
		return true;

	if(head->next->next == NULL)
		return head->data == head->next->data;

    Node *s = head, *f = head;

    int c = 0;
    while(f != NULL && f->next != NULL) {
    	++c;
    	s = s->next;
    	f = f->next->next;
    }

    Node *p;
    if(f)
    	p = s->next;
    else
    	p = s;

    //reverse the second half of linked list
    Node *q = NULL;
    Node *n = p;
    
    while(n) {
        Node *t = n->next;
        n->next = q;
        q = n;
        n = t;
    }

    s = head;
    for(int i=0; i<c; ++i) {
    	if(s->data != q->data)
    		return false;

    	s = s->next;
    	q = q->next;
    }

    return true;
}

