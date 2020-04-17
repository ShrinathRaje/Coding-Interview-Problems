/*
* detect cycle in undirected graph
* Author: Shrinath Bhosale
* Date: 17th April 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/
*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

//time complexity: O(V + E)
bool isCyclicUtil(int s, vector<int> adj[], int vis[], int p) {
    vis[s] = 1;
    
    for(int i=0; i<adj[s].size(); ++i) {
        int v = adj[s][i];
        if(!vis[v]) {
            if(isCyclicUtil(v, adj, vis, s))
                return true;
        } else {
            if(v != p)
                return true;
        }
    }
    
    return false;
}

bool isCyclic(vector<int> adj[], int V) {
   int vis[V] = {0};
   
   for(int i=0; i<V; ++i) {
       if(!vis[i]) {
           if(isCyclicUtil(i, adj, vis, -1)) {
               return true;
           }
       }
   }
   
   return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends