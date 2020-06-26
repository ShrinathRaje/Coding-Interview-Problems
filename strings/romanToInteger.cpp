//convert roman number to integer
//problem: https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0/

#include<bits/stdc++.h>

using namespace std;

int value(char c) {
	if(c == 'I')
		return 1;
	if(c == 'V')
		return 5;
	if(c == 'X')
		return 10;
	if(c == 'L')
		return 50;
	if(c == 'C')
		return 100;
	if(c == 'D')
		return 500;
	if(c == 'M')
		return 1000;

	return -1;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		int i;
		int ans = 0;
		for(i=0; i<s.length()-1; ++i) {
			int v1 = value(s[i]), v2 = value(s[i+1]);
			if(v1 >= v2) {
				ans += v1;
			} else {
				ans += (v2 - v1);
				++i;
			}
		}

		if(i == s.length()-1)
			ans += value(s[i]);

		cout << ans << "\n";
	}

	return 0;
}