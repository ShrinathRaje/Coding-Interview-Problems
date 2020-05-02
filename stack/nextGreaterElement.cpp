/*
* next greater element
* Date: 2nd May 2020
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/next-larger-element/0/
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		stack<long long> s;

		for(auto &it : a) {
			cin >> it;
		}

		vector<long long> b(n);
		for(int i=a.size() - 1; i>=0; --i) {
			while(!s.empty() && s.top() <= a[i])
				s.pop();

			if(s.empty())
				b[i] = -1;
			else
				b[i] = s.top();

			s.push(a[i]);
		}

		for(int i=0; i<n; ++i) {
			cout << b[i] << " ";
		}

		cout << endl;
	}

	return 0;
}