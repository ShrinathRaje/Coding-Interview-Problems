/*
* Dijkstra's Algorithm
* Author: Shrinath Bhosale
* Date: 11th April 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/
*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );

int main() {
    int t;
    int V;
    cin>>t;
    while(t--) {
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++) {
      	    for(int j=0;j<V;j++) {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}

int getMinDist(int d[], bool vis[], int V) {
    int min = INT_MAX, min_index;
    
    for(int i=0; i<V; ++i) {
        if(!vis[i] && d[i] < min) {
            min = d[i];
            min_index = i;
        }
    }
    
    return min_index;
}

void dijkstra(vector<vector<int>> graph, int src, int V) {
    int d[V];
    bool vis[V];
    
    for(int i=0; i<V; ++i) {
        d[i] = INT_MAX;
        vis[i] = false;
    }
    
    d[src] = 0;
    
    for(int i=0; i<V-1; ++i) {
        int m = getMinDist(d, vis, V);
        
        vis[m] = true;
        
        for(int j=0; j<V; ++j) {
            if(!vis[j] && graph[m][j] && d[m] != INT_MAX && d[m] + graph[m][j] < d[j])
                d[j] = d[m] + graph[m][j];
        }
    }
    
    for(int i=0; i<V; ++i) {
        cout << d[i] << " ";
    }
}