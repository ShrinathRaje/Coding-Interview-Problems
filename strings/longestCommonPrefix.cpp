//longest common prefix
//problem: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		vector<string> vs;
		int mi = n;
		int ml = 10000;
		for(int i=0; i<n; ++i) {
			string s;
			cin >> s;

			if(s.length() < ml) {
				ml = s.length();
				mi = i;
			}

			vs.push_back(s);
		}

		string ms = vs[mi];
		char s[ml+1];
		int f = 1, i;
		for(i=0; i<ml; ++i) {
			for(int j=0; j<n; ++j) {
				if(vs[j][i] != ms[i]) {
					f = 0;
					break;
				}
			}

			if(f)
				s[i] = ms[i];
			else
				break;
		}

		s[i] = '\0';

		if(s[0] != '\0')
			cout << s << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}
