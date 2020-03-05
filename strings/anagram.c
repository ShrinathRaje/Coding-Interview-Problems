/*
* Anagrams
* Author: Shrinath Bhosale
* Date: 5'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/anagram/0/
*/

#include<stdio.h>

int main(void) {
    int t;

    scanf("%i", &t);
    while(t--) {
        long h[26] = {0};
        char str1[100000], str2[100000];

        scanf("%s %s", str1, str2);

        for(int i=0; str1[i] != '\0'; ++i)
            ++h[str1[i] - 'a'];

        for(int i=0; str2[i] != '\0'; ++i)
            --h[str2[i] - 'a'];

        int f = 1;
        for(int i=0; i<26; ++i) {
            if(h[i] != 0) {
                puts("NO");
                f = 0;
                break;
            }
        }

        if(f)
            puts("YES");
    }

    return 0;
}