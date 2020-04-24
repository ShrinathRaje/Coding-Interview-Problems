/*
* knapsack problem dynamic programming tabulation approach
* Date: 25th April
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0/
*/

#include<iostream>

using namespace std;

//time complexity: O(n * W)
int knapsack(int w[], int v[], int W, int n) {
	int d[n+1][W+1];

	for(int i=0; i<=n; ++i) {
		for(int j=0; j<=W; ++j) {
			if(i == 0 || j == 0)
				d[i][j] = 0;
			else if(w[i-1] <= j)
				d[i][j] = max(v[i-1] + d[i-1][j-w[i-1]], d[i-1][j]);
			else
				d[i][j] = d[i-1][j];
		}
	}

	return d[n][W];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, W;
		cin >> n >> W;

		int v[n], w[n];

		for(int i=0; i<n; ++i)
			cin >> v[i];

		for(int i=0; i<n; ++i)
			cin >> w[i];

		cout << knapsack(w, v, W, n) << "\n";
	}

	return 0;
}