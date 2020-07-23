//set k'th bit
//problem: https://practice.geeksforgeeks.org/problems/set-kth-bit/0/

#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        cout << (n | (1 << k)) << "\n";
    }
    return 0;
}