/*
* number of islands
* Author: Shrinath Bhosale
* Date: 22nd April 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
int isCellValid(int r, int c, vector<int> A[], int N, int M) {
    return ((r >= 0 && r < N) && (c >=0 && c < M) && A[r][c] == 1);
}

void traverseIsland(int r, int c, vector<int> A[], int N, int M) {
    static int rw[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int cl[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    //mark as visited
    A[r][c] = 2;
    
    for(int i=0; i<8; ++i) {
        if(isCellValid(r + rw[i], c + cl[i], A, N, M))
            traverseIsland(r + rw[i], c + cl[i], A, N, M);
    }
}

int findIslands(vector<int> A[], int N, int M) {
    int count = 0;
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(A[i][j] == 1) {
                traverseIsland(i, j, A, N, M);
                ++count;
            }
        }
    }
    
    return count;
}