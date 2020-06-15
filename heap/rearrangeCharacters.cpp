//rearrange characters
//problem: https://practice.geeksforgeeks.org/problems/rearrange-characters/0/

#include <iostream>
using namespace std;

int possible(int a[26], int l) {
    int p = l % 2;
    int d;
    if(p)
        d = l/2+1;
    else
        d = l/2;
        
    for(int i=0; i<26; ++i) {
        if(p && a[i] > d)
            return 0;
            
        if(!p && a[i] > d)
            return 0;
    }
    
    return 1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    
	    int a[26] = {0};
	    for(int i=0; i<s.length(); ++i) {
	        ++a[s[i] - 'a'];
	    }
	    
	    cout << possible(a, s.length()) << endl;
	}
	
	return 0;
}
