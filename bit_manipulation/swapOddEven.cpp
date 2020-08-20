//swap all odd and even bits
//problem: https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		for(int i=1; i<8; i += 2) {
			int a = n & (1 << i);
			int b = n & (1 << (i-1));

			if((!a && b) || (!b && a)) {
				int k = 0;
				k = k | (1 << i);
				k = k | (1 << (i-1));

				n = n ^ k;
			}
		}

		cout << n << "\n";
	}

	return 0;
}
