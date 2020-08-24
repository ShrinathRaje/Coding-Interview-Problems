//trapping rain water
//problem: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

//time complexity: O(n), space complexity: O(n)
int trappingWater(int arr[], int n) {
	int ml[n], mr[n];

	ml[0] = arr[0];
	for(int i=1; i<n; ++i)
		ml[i] = max(ml[i-1], arr[i]);

	mr[n-1] = arr[n-1];
	for(int i=n-2; i>=0; --i)
		mr[i] = max(mr[i+1], arr[i]);

	int res = 0;
	for(int i=1; i<n-1; ++i)
		res += (min(ml[i], mr[i]) - arr[i]);

	return res;
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
