//Equilibrium index
//problem: https://practice.geeksforgeeks.org/problems/equilibrium-point/0/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n];
        
        long long sum = 0;
        for(int i=0; i<n; ++i) {
            long long x;
            cin >> x;
            
            sum += x;
            a[i] = x;
        }
        
        long long lSum = 0;
        int f = 0;
        int i;
        for(i=0; i<n; ++i) {
            if(lSum == (sum - lSum - a[i])) {
                f = 1;
                break;
            }
            
            lSum += a[i];
        }
        
        if(f)
            cout << i+1 << endl;
        else
            cout << -1 << endl;
    }
	return 0;
}