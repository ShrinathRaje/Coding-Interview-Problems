//rotten oranges
//problem: https://practice.geeksforgeeks.org/problems/rotten-oranges/0/

#include <bits/stdc++.h>

//#define ll long long

using namespace std;

bool isIndexValid(int r, int c, pair<int, int> i) {
	if(i.first < r && i.first > -1 && i.second < c && i.second > -1)
		return true;
	else
		return false;
}

bool isDelimiter(pair<int, int> i) {
	if(i.first == -1 && i.second == -1)
		return true;
	else
		return false;
}

bool isFreshLeft(int r, int c, int *a) {
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j)
			if(*(a + c*i + j) == 1)
				return true;

	return false;
}

int main() {
	// ios_base::sync_with_stdio(false);
 	// cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
    	int r, c;
    	cin >> r >> c;

    	int a[r][c];
    	for(int i=0; i<r; ++i)
    		for(int j=0; j<c; ++j)
    			cin >> a[i][j];


    	queue<pair<int, int>> q;
    	for(int i=0; i<r; ++i)
    		for(int j=0; j<c; ++j)
    			if(a[i][j] == 2)
    				q.push(make_pair(i,j));

    	q.push(make_pair(-1,-1));

    	int ans = 0;
    	while(!q.empty()) {
    		pair<int, int> p = q.front();
    		q.pop();

    		if(isDelimiter(p)) {
    			if(q.empty())
    				continue;
    			else {
    				++ans;
    				q.push(p);
    			}
    		} else {
    			int i = p.first, j = p.second;
    			if(isIndexValid(r, c, make_pair(i-1, j)) && a[i-1][j] == 1) {
    				a[i-1][j] = 2;
    				q.push(make_pair(i-1, j));
    			}

    			if(isIndexValid(r, c, make_pair(i+1, j)) && a[i+1][j] == 1) {
    				a[i+1][j] = 2;
    				q.push(make_pair(i+1, j));
    			}

    			if(isIndexValid(r, c, make_pair(i, j-1)) && a[i][j-1] == 1) {
    				a[i][j-1] = 2;
    				q.push(make_pair(i, j-1));
    			}

    			if(isIndexValid(r, c, make_pair(i, j+1)) && a[i][j+1] == 1) {
    				a[i][j+1] = 2;
    				q.push(make_pair(i, j+1));
    			}
    		}
    	}


    	if(isFreshLeft(r, c, (int *)a))
    		cout << -1 << endl;
    	else
    		cout << ans << endl;

    } 

	return 0;
}