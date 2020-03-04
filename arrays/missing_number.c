/*
* Find the missing number
* Author: Shrinath Bhosale
* Date: 4'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0/
*/

#include<stdio.h>

int main(void) {
    int t, n;

    scanf("%i", &t);
    while(t--) {
        scanf("%i", &n);

        long sum = 0;
        for(int i=0; i<n-1; ++i) {
            int a;
            scanf("%i", &a);

            sum += a;
        }

        long s = (n * (n + 1)) / 2;

        printf("%li\n", s - sum);
    }

    return 0;
}