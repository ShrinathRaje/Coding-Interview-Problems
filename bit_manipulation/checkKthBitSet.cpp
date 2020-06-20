//check if k'th bit is set
//problem: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    
	    int a = n & (1 << k);
	    if(a)
	        cout << "Yes" << "\n";
	    else
	        cout << "No" << "\n";
	}
	return 0;
}
