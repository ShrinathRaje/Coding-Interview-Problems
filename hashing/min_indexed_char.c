/*
* Minimum indexed character
* Author: Shrinath Bhosale
* Date: 1st April 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/minimum-indexed-character/0/
*/

#include<stdio.h>

int main(void) {
    int t;
    scanf("%i", &t);

    while(t--) {
        char s[100001], p[100001];
        int a[26] = {0};

        scanf("%s %s", s, p);

        for(int i=0; s[i] != '\0'; ++i) {
            int n = s[i] - 'a';
            if(a[n] == 0) {
                a[n] = i+1;
            }
        }

        int min_p = 100000;
        char min_c = '$';
        for(int i=0; p[i] != '\0'; ++i) {
            int n = p[i] - 'a';
            if(a[n] != 0 && (a[n] - 1) < min_p) {
                min_p = a[n] - 1;
                min_c = p[i];
            }
        }

        printf("%c\n", min_c);
    }
    return 0;
}