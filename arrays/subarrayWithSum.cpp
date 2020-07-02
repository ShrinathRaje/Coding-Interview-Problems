//subarray with given sum
//problem: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, s;
		cin >> n >> s;

		ll a[n];
		for(int i=0; i<n; ++i)
			cin >> a[i];

		int f=0;
		ll sum=0;
		int found=0;
		pair<int, int> ans;
		for(int i=0; i<n; ++i) {
			sum += a[i];

			if(sum == s) {
				found = 1;
				ans = make_pair(f+1, i+1);
				break;
			} else if(sum > s) {
				while(sum > s) {
					sum -= a[f++];

					if(sum == s) {
						found = 1;
						ans = make_pair(f+1, i+1);
						break;
					}
				}
			}

			if(found)
				break;
		}

		if(found)
			cout << ans.first << " " << ans.second << "\n";
		else
			cout << -1 << "\n";
	}
	return 0;
}