/*
* Uncommon characters
* Author: Shrinath Bhosale
* Date: 29'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/uncommon-characters/0/
*/

#include <stdio.h>

int main() {
	int t;
	scanf("%i", &t);
	
	while(t--) {
	    char a[100001], b[100001];
	    int c[26] = {0}, d[26] = {0};
	    scanf("%s %s", a, b);
	    
	    for(int i=0; a[i] != '\0'; ++i)
	        ++c[a[i] - 'a'];
	        
	    for(int i=0; b[i] != '\0'; ++i)
	        ++d[b[i] - 'a'];
	        
	    for(int i=0; i<26; ++i) {
	        if(c[i] != 0 && d[i] == 0 || d[i] != 0 && c[i] == 0 )
	            putchar(i + 'a');
	    }
	    putchar('\n');
	}
	return 0;
}