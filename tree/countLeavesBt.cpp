/*
* Count the leaves in a binary tree
* Author: Shrinath Bhosale
* Date: 18'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1/
*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

int countLeaves(struct Node *root);

/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d\n", &n);
        Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            //  cout << n1 << " " << n2 << " " << (char)lr << endl;
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];

            Node *child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }

        cout << countLeaves(root) << endl;
    }
    return 0;
}

int countLeaves(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}
