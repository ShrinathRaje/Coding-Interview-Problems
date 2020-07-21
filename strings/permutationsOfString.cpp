//permutations of a given string
//problem: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0/

#include<bits/stdc++.h>

using namespace std;

void permute(string s, int l, int r) {
	sort(s.begin() + l, s.end());

	if(l == r) {
		cout << s << " ";
	} else {
		for(int i=l; i<=r; ++i) {
			swap(s[i], s[l]);
			permute(s, l+1, r);
			swap(s[i], s[l]);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		permute(s, 0, s.length()-1);
		cout << "\n";
	}

	return 0;
}