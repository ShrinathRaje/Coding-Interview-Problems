//Check if a string is rotated by 2 places
//problem: https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        
        if(s2.substr(2, s2.length()+1).compare(s1.substr(0, s1.length() - 2))
        && s2.substr(0, s2.length() - 2).compare(s1.substr(2, s1.length() + 1))) {
          cout << 0 << endl;  
        } else {
            cout << 1 << endl;
        }
    }
	return 0;
}