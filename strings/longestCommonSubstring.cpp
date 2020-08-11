//longest common substring
//problem: https://practice.geeksforgeeks.org/problems/longest-common-substring/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int m, n;
		cin >> m >> n;

		string x, y;
		cin >> x >> y;

		int dp[m+1][n+1];

		int max_substr_length = 0;
		for(int i=0; i<=m; ++i) {
			for(int j=0; j<=n; ++j) {
				if(i == 0 || j == 0) {
					dp[i][j] = 0;
				} else if(y[j-1] == x[i-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
					max_substr_length = max(max_substr_length, dp[i][j]);
				} else {
					dp[i][j] = 0;
				}
			}
		}

		cout << max_substr_length << "\n";
	}

	return 0;
}
