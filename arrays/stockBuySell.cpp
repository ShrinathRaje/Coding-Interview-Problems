//stock buy and sell
//problem: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		int a[n];
		for(int i=0; i<n; ++i)
			cin >> a[i];

		vector<pair<int, int>> v;
		int begin = 0;
		int end = 0;
		for(int i=1; i<n; ++i) {
			if(a[i] < a[i-1]) {
				end = i-1;
				if(begin != end)
					v.push_back(make_pair(begin, end));
				begin = i;
			} else {
				end = i;
			}
		}

		if(end > begin)
			v.push_back(make_pair(begin, end));

		if(v.size()) {
			for(int i=0; i<v.size(); ++i) {
				pair<int, int> p = v[i];
				cout << "(" << p.first << " " << p.second << ") ";
			}

			cout << "\n";
		} else {
			cout << "No Profit\n";
		}
	}

	return 0;
}