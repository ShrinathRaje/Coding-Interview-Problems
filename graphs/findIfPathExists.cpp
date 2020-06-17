//find if path exists
//problem: https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0/

#include<bits/stdc++.h>

using namespace std;

bool is_index_valid(int i, int j, int n) {
	return (i >= 0 && i<n && j>=0 && j<n);
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		int m[n][n];
		queue<pair<int, int>> q;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j) {
				cin >> m[i][j];
				if(m[i][j] == 1)
					q.push(make_pair(i, j));
			}

		int f = 0;
		while(!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			int r = p.first, c = p.second;
			if(
				is_index_valid(r, c-1, n) && m[r][c-1] == 2 ||
				is_index_valid(r, c+1, n) && m[r][c+1] == 2 ||
				is_index_valid(r-1, c, n) && m[r-1][c] == 2 ||
				is_index_valid(r+1, c, n) && m[r+1][c] == 2
				) {
				f = 1;
				break;
			}

			if(is_index_valid(r, c-1, n) && m[r][c-1] == 3) {
				m[r][c-1] = 0;
				q.push(make_pair(r, c-1));
			}

			if(is_index_valid(r, c+1, n) && m[r][c+1] == 3) {
				m[r][c+1] = 0;
				q.push(make_pair(r, c+1));
			}

			if(is_index_valid(r-1, c, n) && m[r-1][c] == 3) {
				m[r-1][c] = 0;
				q.push(make_pair(r-1, c));
			}

			if(is_index_valid(r+1, c, n) && m[r+1][c] == 3) {
				m[r+1][c] = 0;
				q.push(make_pair(r+1, c));
			}
		}

		cout << f << "\n";

	}

	return 0;
}