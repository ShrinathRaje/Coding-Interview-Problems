//rearrange array alternately
//problem: https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    long long a[n];
	    for(int i=0; i<n; ++i)
	        cin >> a[i];
	        
	    int min_i = 0, max_i = n-1, max_el = a[n-1] + 1;
	    for(int i=0; i<n; ++i) {
	        if(i%2) {
	            a[i] += (a[min_i] % max_el) * max_el;
	            ++min_i;
	        } else {
	            a[i] += (a[max_i] % max_el) * max_el;
	            --max_i;
	        }
	    }
	    
	    for(int i=0; i<n; ++i) {
	        a[i] /= max_el;
	        cout << a[i] << " ";
	    }
	    
	    cout << "\n";
	}
	
	return 0;
}
