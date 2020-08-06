//find longest palindrome in a string
//problem: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0/

#include<bits/stdc++.h>

using namespace std;

void find_palindrome(int p, int n, int &max_length, int &low, int &high, string &s) {
	while(p > -1 && n < s.length() && s[p] == s[n]) {
		++n;
		--p;
	}

	int l = n-p-1;

	if(l > max_length) {
		low = p + 1;
		high = n - 1;

		max_length = l;
	}
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		if(s.length() == 1) {
			cout << s << "\n";
			continue;
		}

		int max_length = 0, low, high;
		for(int i=0; i<s.length(); ++i) {
			//find odd length palindromes
			int p = i-1, n = i+1;
			find_palindrome(p, n, max_length, low, high, s);
			

			//find even length palindromes
			if(s[i+1] == s[i] && i<s.length()-1) {
				p = i-1, n = i+2;
				find_palindrome(p, n, max_length, low, high, s);
			}
		}

		cout << s.substr(low, max_length) << "\n";

	}

	return 0;
}
