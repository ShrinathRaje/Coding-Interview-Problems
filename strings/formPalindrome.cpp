//form a palindrome with minimum insertions
//problem: https://practice.geeksforgeeks.org/problems/form-a-palindrome/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		int l = s.length();
		int dp[l][l];

		for(int i=0; i<l; ++i)
			dp[i][i] = 1;

		for(int i=0; i<l-1; ++i)
			if(s[i] == s[i+1])
				dp[i][i+1] = 2;
			else
				dp[i][i+1] = 1;

		for(int k=3; k<=l; ++k) {
			for(int i=0; i<=l-k; ++i) {
				int j=i+k-1;

				if(s[i] == s[j])
					dp[i][j] = 2 + dp[i+1][j-1];
				else
					dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}

		cout << l - dp[0][l-1] << "\n";
	}

	return 0;
}
