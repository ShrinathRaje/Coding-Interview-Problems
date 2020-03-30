/*
* First element to occur k times
* Author: Shrinath Bhosale
* Date: 30'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times/0/
*/

#include <stdio.h>

int main(void) {
	int t;
	scanf("%i", &t);
	
	while(t--) {
	    int s, k;
	    scanf("%i%i", &s, &k);
	    
	    int h[1000001] = {0};
	    int a[s];
	    for(int i=0; i<s; ++i) {
	        int n;
	        scanf("%i", &n);
	        a[i] = n;
	        ++h[n];
	    }
	    
	    int f = 0;
	    for(int i=0; i<s; ++i) {
	        if(h[a[i]] == k) {
	            f = 1;
	            printf("%i\n", a[i]);
	            break;
	        }
	    }
	    
	    if(!f)
	        printf("%i\n", -1);
	}
	return 0;
}