/*
* Depth First Search traversal
* Author: Shrinath Bhosale
* Date: 8th April 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[]) {
    cout << s << " ";
    vis[s] = true;

    for (int i = 0; i < g[s].size(); ++i) {
        int v = g[s][i];
        if (!vis[v]) {
            dfs(v, g, vis);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {

        int N, E;
        cin >> N >> E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, g, vis);

        cout << endl;
    }
}