/*
* Leaders in an array
* problem: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/
*/

#include <iostream>
#include<vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    
	    for(int i=0; i<n; ++i)
	        cin >> a[i];
	        
	    int highest = -1;
	    vector<int> v;
	    for(int i=n-1; i>=0; --i) {
	        if(a[i] >= highest) {
	            highest = a[i];
	            v.push_back(a[i]);
	        }
	    }
	    
	    for(int i=v.size() - 1; i>=0; --i)
	        cout << v[i] << " ";
	        
	    cout << endl;
	}
	return 0;
}