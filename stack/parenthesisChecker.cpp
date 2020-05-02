/*
* parenthesis checker
* Date: 2nd May 2020
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/parenthesis-checker/0/
*/

#include <bits/stdc++.h>

using namespace std;

bool isOpen(char c) {
	if(c == '(' || c == '{' || c == '[')
		return true;
	else
		return false;
}

bool isSame(char c1, char c2) {
	if(c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']')
		return true;
	else
		return false;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		stack<char> st;
		int f = 1;
		for(int i=0; i<s.length(); ++i) {
			char c = s[i];
			if(isOpen(c))
				st.push(c);
			else {
				if(!st.empty() && isSame(st.top(), c)) {
					st.pop();
				} else {
				    f = 0;
					break;
				}
			}
		}

		if(st.empty() && f)
			cout << "balanced" << endl;
		else
			cout << "not balanced" << endl;

	}

	return 0;
}