/*
* Implement Queue using stacks
* Author: Shrinath Bhosale
* Date: 16'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1/
*/

import java.util.*;
import java.util.Stack;
import java.util.LinkedList;

public class QueueUsingStack {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            StackQueue g = new StackQueue();
            int q = sc.nextInt();
            while (q > 0) {
                int QueryTyoe = sc.nextInt();
                if (QueryTyoe == 1) {
                    int a = sc.nextInt();
                    g.insert(a);
                } else if (QueryTyoe == 2)
                    System.out.print(g.remove() + " ");
                q--;

            }
            System.out.println();
            t--;
        }
    }
}

class StackQueue {
    Stack<Integer> s1 = new Stack<Integer>();
    Stack<Integer> s2 = new Stack<Integer>();

    void insert(int B) {
        s1.push(B);
    }

    //Amortized time complexity: O(1)
    int remove() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.pop());
            }

            return (s2.empty()) ? -1 : s2.pop();
        } else {
            return s2.pop();
        }
    }
}


//Another solution is possible using 1 stack and 1 function call stack (recursion)