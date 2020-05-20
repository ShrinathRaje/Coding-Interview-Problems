//longest substring with distinct characters
//problem: https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0/

#include <bits/stdc++.h>
using namespace std;


//time complexity: O(n)
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    string s;
	    cin >> s;
	    
	    int l = s.size(), r = 0, i = 0;
	    vector<int> v(26, -1);

	    for(int j = 0; j<l; ++j) {
	        i = max(i, v[s[j] - 'a'] + 1);
	        r = max(r, j-i + 1);
	        v[s[j] - 'a'] = j;
	    }
	    
	    cout << r << endl;
	}
	return 0;
}