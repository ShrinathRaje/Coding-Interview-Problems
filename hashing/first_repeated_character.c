/*
* Find first repeated character
* Author: Shrinath Bhosale
* Date: 26'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0/
*/

#include <stdio.h>

int main() {
	int t;
	scanf("%i", &t);
	
	while(t--) {
	    char s[10001];
	    int a[26] = {0};
	    scanf("%s", s);
	    
	    int f = 0;
	    for(int i=0; s[i] != '\0'; ++i) {
	        int j = ++a[s[i] - 'a'];
	        if(j == 2) {
	            printf("%c\n", s[i]);
	            f = 1;
	            break;
	        }
	    }
	    
	    if(!f) {
	        printf("%i\n", -1);
	    }
	}
	return 0;
}