/*
* detect cycle in directed graph
* Author: Shrinath Bhosale
* Date: 18th April 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
//time complexity: O(V + E)
bool isCyclicUtil(int s, vector<int> adj[], int vis[], int rs[]) {
    vis[s] = 1;
    rs[s] = 1;
    
    for(int i=0; i<adj[s].size(); ++i) {
        int v = adj[s][i];
        if(!vis[v] && isCyclicUtil(v, adj, vis, rs)) {
            return true;
        } else if(rs[v])
            return true;
    }
    
    rs[s] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int inRecursionStack[V] = {0};
    
    for(int i=0; i<V; ++i) {
        if(!vis[i])
            if(isCyclicUtil(i, adj, vis, inRecursionStack))
                return true;
    }
    
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends