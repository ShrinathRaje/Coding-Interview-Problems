//N meetings in one room
//problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0/

#include<bits/stdc++.h>

using namespace std;

typedef struct Meeting {
	int s;
	int f;
	int p;
} Meeting;

bool comparator(Meeting m1, Meeting m2) {
	return m1.f < m2.f;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		int s[n], f[n];

		for(int i=0; i<n; ++i)
			cin >> s[i];

		for(int i=0; i<n; ++i)
			cin >> f[i];

		Meeting m[n];
		for(int i=0; i<n; ++i) {
			m[i].s = s[i];
			m[i].f = f[i];
			m[i].p = i+1;
		}

		sort(m, m + n, comparator);

		vector<int> mp;
		mp.push_back(m[0].p);

		int ft = m[0].f;

		for(int i=1; i<n; ++i) {
			if(m[i].s >= ft) {
				mp.push_back(m[i].p);
				ft = m[i].f;
			}
		}

		for(int i=0; i<mp.size(); ++i)
			cout << mp[i] << " ";

		cout << endl;

	}
	
	return 0;
}