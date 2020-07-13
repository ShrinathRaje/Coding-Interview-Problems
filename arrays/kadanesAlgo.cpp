//contiguous subarray with maximum sum
//problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0/

#include<iostream>
#include<climits>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		ll max = INT_MIN;
		ll sum = 0;
		for(int i=0; i<n; ++i) {
			int x;
			cin >> x;

			sum += x;
			if(max < sum)
				max = sum;
			if(sum < 0)
				sum = 0;
		}

		cout << max << "\n";
	}

	return 0;
}