//flood fill algorithm
//problem: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool isIndexValid(int x, int y, int m, int n) {
	return (x >=0 && x < m && y >=0 && y < n);
}

void floodFillRecursive(int xc, int yc, int c, int *a, int m, int n, int k) {
	*(a + xc*n + yc) = k;

	if(isIndexValid(xc, yc-1, m, n) && *(a + xc*n + yc-1) == c)
		floodFillRecursive(xc, yc-1, c, a, m, n, k);

	if(isIndexValid(xc, yc+1, m, n) && *(a + xc*n + yc+1) == c)
		floodFillRecursive(xc, yc+1, c, a, m, n, k);

	if(isIndexValid(xc-1, yc, m, n) && *(a + (xc-1)*n + yc) == c)
		floodFillRecursive(xc-1, yc, c, a, m, n, k);

	if(isIndexValid(xc+1, yc, m, n) && *(a + (xc+1)*n + yc) == c)
		floodFillRecursive(xc+1, yc, c, a, m, n, k);
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		int m, n, x, y, k;
		cin >> m >> n;

		int a[m][n];
		for(int i=0; i<m; ++i)
			for(int j=0; j<n; ++j)
				cin >> a[i][j];

		cin >> x >> y >> k;

		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		int c = a[x][y];

		//floodFillRecursive(x, y, c, (int *)a, m, n, k);

		while(!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			int xc = p.first, yc = p.second;
			a[xc][yc] = k;

			if(isIndexValid(xc, yc-1, m, n) && a[xc][yc-1] == c)
				q.push(make_pair(xc, yc-1));

			if(isIndexValid(xc, yc+1, m, n) && a[xc][yc+1] == c)
				q.push(make_pair(xc, yc+1));

			if(isIndexValid(xc-1, yc, m, n) && a[xc-1][yc] == c)
				q.push(make_pair(xc-1, yc));

			if(isIndexValid(xc+1, yc, m, n) && a[xc+1][yc] == c)
				q.push(make_pair(xc+1, yc));
		}

		for(int i=0; i<m; ++i)
			for(int j=0; j<n; ++j)
				cout << a[i][j] << " ";

		cout << endl;
	}

	return 0;
}