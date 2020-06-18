//rightmost set bit
//problem: https://practice.geeksforgeeks.org/problems/find-first-set-bit/0/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    if(n)
	        cout << (int) (log2(n - (n&(n-1))) + 1) << "\n";
	    else
	        cout << 0 << "\n";
	}
	return 0;
}