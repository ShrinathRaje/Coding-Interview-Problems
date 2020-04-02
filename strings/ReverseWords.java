/*
* Reverse words in a string
* Date: 2nd April 2020
* Author: Shrinath Bhosale
* Problem Statement: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0/
*/

import java.util.Scanner;

public class ReverseWords {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t-- > 0) {
            String s = sc.next();
            String[] a = s.split("\\.");

            for(int i=a.length -1; i>=0; --i) {
                if(i == 0)
                    System.out.print(a[i]);
                else
                    System.out.print(a[i] + ".");
            }

            System.out.println();

        }
    }
}