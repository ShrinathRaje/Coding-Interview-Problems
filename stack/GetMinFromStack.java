/*
* Find the minimum element in the stack in O(1) time
* Author: Shrinath Bhosale
* Date: 15'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/
*/

import java.util.*;

public class GetMinFromStack {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int q = sc.nextInt();
            GfG g = new GfG();
            while (q > 0) {
                int qt = sc.nextInt();

                if (qt == 1) {
                    int att = sc.nextInt();
                    g.push(att);
                    // System.out.println(att);
                } else if (qt == 2) {
                    System.out.print(g.pop() + " ");
                } else if (qt == 3) {
                    System.out.print(g.getMin() + " ");
                }

                q--;
            }
            System.out.println();
            T--;
        }

    }
}

//Space complexity: O(n)
class GfG {
    int minEle;
    Stack<Integer> s;
    Stack<Integer> a;

    public GfG() {
        s = new Stack<>();
        a = new Stack<>();
    }

    /* returns min element from stack */
    int getMin() {
        // Your code here
        if (a.empty()) {
            return -1;
        }

        return a.peek();
    }

    /* returns poped element from stack */
    int pop() {
        // Your code here
        if (s.empty())
            return -1;

        a.pop();
        return s.pop();
    }

    /* push element x into the stack */
    void push(int x) {
        // Your code here
        s.push(x);

        if (a.empty()) {
            a.push(x);
        } else {
            if (x <= a.peek()) {
                a.push(x);
            } else {
                a.push(a.peek());
            }
        }
    }
}
