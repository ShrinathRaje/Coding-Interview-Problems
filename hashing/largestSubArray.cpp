//largest subarray with sum 0
//problem: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
int maxLen(int A[], int n) {
    unordered_map<int, int> m;
		int s = 0;
		int ls = 0;
		m[0] = -1;
		for(int i=0; i<n; ++i) {
			s += A[i];

			if(m.find(s) != m.end()) {
				ls = max(ls, i - m[s]);
			} else {
				m[s] = i;
			}
		}

		return ls;
}
