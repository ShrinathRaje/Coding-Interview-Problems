/*
* Breadth First Search Traversal
*	Author: Shrinath Bhosale
* Date: 8th Apr 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    cout << s << " ";
    
    while(!q.empty()) {
        int n = q.front(); q.pop();
        
        for(int i=0; i<adj[n].size(); ++i) {
            int v = adj[n][i];
            if(!vis[v]) {
                cout << v << " ";
                vis[v] = true;
                q.push(v);
            }
        }
    }
    
}


int main() {
    int T;
    cin>>T;
    while(T--) {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++) {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}
