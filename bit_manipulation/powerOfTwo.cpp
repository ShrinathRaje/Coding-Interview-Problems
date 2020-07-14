//check if a number is power of two
//problem: https://practice.geeksforgeeks.org/problems/power-of-2/0/

#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        
        if(n == 0 || (n & (n-1)))
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
	return 0;
}