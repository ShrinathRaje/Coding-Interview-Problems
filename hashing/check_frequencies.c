/*
* check frequencies
* Author: Shrinath Bhosale
* Date: 31st March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/check-frequencies/0/
*/

#include<stdio.h>

int main(void) {
    int t;
    scanf("%i", &t);

    while(t--) {
        char s[10001];
        int h[26] = {0};
        
        scanf("%s", s);

        for(int i=0; s[i] != '\0'; ++i) {
            ++h[s[i] - 'a'];
        }

        int min = 10001;
        int max = 0;
        for(int i=0; i<26; ++i) {
            if(h[i] > max)
                max = h[i];
            
            if(h[i] < min && h[i] != 0)
                min = h[i];
        }

        int d = max - min;
        int x = 0, y = 0;
        for(int i=0; i<26; ++i) {
                if(h[i] == max) {
                    ++x;
                }

                if(h[i] == min) {
                    ++y;
                }
            }

        if(d == 0 || x == 1 && d == 1 || y == 1 && d == 1)
            printf("%i\n", 1);
        else
            printf("%i\n", 0);
        
    }
    return 0;
}