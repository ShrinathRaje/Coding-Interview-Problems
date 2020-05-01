/*
* remove duplicates
* Date: 1st May 2020
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/remove-duplicates/0/
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin >> ws; //stream out any whitespace

	while(t--) {
		string s;
		getline(cin, s);
		bool h[256] = {false};
		for(int i=0; i<s.length(); ++i) {
			char c = s[i];
			if(!h[c]) {
				cout << c;
				h[c] = true;
			}
		}

		cout << endl;
	}
	return 0;
}