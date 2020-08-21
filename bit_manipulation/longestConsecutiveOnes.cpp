//longest consecutive 1s
//problem: https://practice.geeksforgeeks.org/problems/longest-consecutive-1s/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        // int mx = 0, c = 0;
        // for(int i=0; i<=10; ++i) {
        //     if(n & (1 << i)) {
        //         ++c;
        //     } else {
        //         mx = max(c, mx);
        //         c = 0;
        //     }
        // }
        
        int mx = 0;
        while(n) {
            n = n & (n << 1);
            ++mx;
        }
        
        cout << mx << "\n";
    }
    
	return 0;
}
