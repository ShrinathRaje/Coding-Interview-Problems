//K'th smallest element
//problem: https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int kthSmallest(int arr[], int n, int k){
    //implement merge sort or quick sort
    //use min-heap or max-heap
    sort(arr, arr+n);
    
    return arr[k-1];
}

// { Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    cout << kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends
