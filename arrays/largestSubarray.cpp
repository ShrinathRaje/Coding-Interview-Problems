//largest subarray of 0s and 1s
//problem: https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/


#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    unordered_map<int, int> map;
		int sum = arr[0] ? 1 : -1;
		map[sum] = 0;
		int mx = 0;
		for(int i=1; i<N; ++i) {
			sum += (arr[i] ? 1 : -1);
			if(!sum) {
				mx = i+1;
			} else {
				if(map.find(sum) != map.end()) {
					mx = max(mx, i-map[sum]);
				} else {
				    map[sum] = i;
				}
			}
		}

		return mx;
}
