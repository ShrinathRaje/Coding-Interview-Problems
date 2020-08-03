//find the number of pairs
//problem: https://practice.geeksforgeeks.org/problems/number-of-pairs/0/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int m, n;
		cin >> m >> n;

		int x[m], y[n];

		for(int i=0; i<m; ++i)
			cin >> x[i];

		int cnt[5] = {0};
		for(int i=0; i<n; ++i) {
			cin >> y[i];
			if(y[i] < 5)
				++cnt[y[i]];
		}


		sort(y, y+n);

		ll p_count = 0;
		for(int i=0; i<m; ++i) {
			if(x[i] == 1)
				continue;

			p_count += (y+n - upper_bound(y, y+n, x[i])) + cnt[1];

			if(x[i] == 2) {
				p_count -= (cnt[3] + cnt[4]);
				continue;
			}

			if(x[i] == 3) {
				p_count += cnt[2];
			}
		}

		cout << p_count << "\n";
	}

	return 0;
}
