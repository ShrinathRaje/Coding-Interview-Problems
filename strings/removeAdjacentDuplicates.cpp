//recursively remove all the adjacent duplicates in a string
//problem: https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0/

#include<bits/stdc++.h>

using namespace std;

string removeAdjacentDuplicates(const string &s) {
	int l = s.length();

	string a;
	int f = 0;
	for(int i=0; i<l-1; ++i) {
		if(s[i] != s[i+1]) {
			a += s[i];
		} else {
			while(i < l-1 && s[i] == s[i+1])
				++i;

			f = 1;
		}
	}

	if(s[l-1] != s[l-2])
		a += s[l-1];

	if(f)
		return removeAdjacentDuplicates(a);

	return a;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		cout << removeAdjacentDuplicates(s) << "\n";
	}

	return 0;
}
