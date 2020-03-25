/*
* Count all paths
* Author: Shrinath Bhosale
* Date: 25'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/number-of-paths/0/
*/

#include <stdio.h>

//recursive approach
//time complexity: O(2^n)
int number_of_paths(int m, int n) {
    if(m == 1 || n == 1)
        return 1;
        
    return number_of_paths(m-1, n) + number_of_paths(m, n-1);
}

int main(void) {
	int t;
	scanf("%i", &t);
	
	while(t--) {
	    int m, n;
	    scanf("%i%i", &m, &n);
	    printf("%i\n", number_of_paths(m, n));
	}
	return 0;
}