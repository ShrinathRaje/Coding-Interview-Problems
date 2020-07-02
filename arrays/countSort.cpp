//sort an array of 0s, 1s and 2s
//problem: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		int h[3] = {0};
		for(int i=0; i<n; ++i) {
			int x;
			cin >> x;
			++h[x];
		}

		for(int i=0; i<3; ++i) {
			int l = h[i];

			while(l--) {
				cout << i << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}