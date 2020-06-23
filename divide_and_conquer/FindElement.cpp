//Find the element that appears once in sorted array
//problem: https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0/

#include <iostream>
using namespace std;

typedef long long ll;

ll find(ll a[], int n) {
	int l = 0;
	int r = n-1;

	int res;
	while(r-l >= 2) {
		if(a[l] != a[l+1]) {
			res = a[l];
			break;
		} else if(a[r] != a[r-1]) {
			res = a[r];
			break;
		} else {
			int m = l + (r-l)/2;

			if((m-l+1) % 2) {
				if(a[m] == a[m-1])
					r = m - 2;
				else if(a[m] == a[m+1])
					l = m + 2;
				else {
					res = a[m];
					break;
				}
			} else {
				if(a[m] == a[m-1])
					l = m+1;
				else
					r = m-1;
			}
		}
	}

	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    ll a[n];
	    
	    for(int i=0; i<n; ++i)
	        cin >> a[i];
   
	   // if(a[0] != a[1])
	   //     cout << a[0] << "\n";
	   // else if(a[n-1] != a[n-2])
	   //     cout << a[n-1] << "\n";
	   // else
	   //     for(int i=1; i<n-1; ++i) {
	   //         if(a[i] != a[i-1] && a[i] != a[i+1]) {
	   //             cout << a[i] << "\n";
	   //             break;
	   //         }
	   //     }
	        
	    cout << find(a, n) << "\n";
	}
	
	return 0;
}