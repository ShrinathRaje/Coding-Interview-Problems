/*
* majority element
* Date: 29th April
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/majority-element/0/
*/


#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    int a[1000001] = {0};
	    int f = 1;
	    for(int i=0; i<n; ++i) {
	        int e;
	        cin >> e;
	        ++a[e];

	        if(a[e] > n/2) {
	            cout << e << endl;
	            f = 0;
	            for(int j=i+1; j<n; ++j) {
	            	int x;
	            	cin >> x;
	            }	      
	            break;
	        }
	    }
	    
	    if(f)
	        cout << -1 << endl;
	}
	return 0;
}