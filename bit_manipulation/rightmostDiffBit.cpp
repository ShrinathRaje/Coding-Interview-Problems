//rightmost different bit
//problem: https://practice.geeksforgeeks.org/problems/rightmost-different-bit/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int m, n;
	    cin >> m >> n;
	    
	    int x = m ^ n;
	    cout << (int) (log2(x & -x) + 1) << "\n";
	}
	return 0;
}
