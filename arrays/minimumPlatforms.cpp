//minimum platforms
//problem: https://practice.geeksforgeeks.org/problems/minimum-platforms/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		int arr[n], dep[n];
		for(int i=0; i<n; ++i)
			cin >> arr[i];

		for(int i=0; i<n; ++i)
			cin >> dep[i];


		sort(arr, arr+n);
		sort(dep, dep+n);

		int i=1, j=0, p=1, r=1;
		while(i < n && j < n) {
			if(arr[i] <= dep[j]) {
				++p;
				++i;
			} else {
				--p;
				++j;
			}

			r = max(p, r);
		}

		cout << r << "\n";
	}

	return 0;
}
