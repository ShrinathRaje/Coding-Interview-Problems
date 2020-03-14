/*
* Find the minimum element in the stack in O(1) time and O(1) space
* Author: Shrinath Bhosale
* Date: 15'th March 2020
* Problem statement: https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/
*/

import java.util.*;

class GetMinimumFromStack {
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

//Space complexity: O(1)
class GfG {
    int minEle;
    Stack<Integer> s;

    public GfG() {
        s = new Stack<>();
    }

    /* returns min element from stack */
    int getMin() {
        if (s.empty()) {
            return -1;
        }

        return minEle;
    }

    /* returns popped element from stack */
    int pop() {
        // Your code here
        if (s.empty())
            return -1;

        if (s.peek() >= minEle) {
            return s.pop();
        } else {
            int x = minEle;
            minEle = 2 * minEle - s.peek();
            s.pop();
            return x;
        }
    }

    /* push element x into the stack */
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minEle = x;
        } else {
            if (x >= minEle) {
                s.push(x);
            } else {
                s.push(2 * x - minEle);
                minEle = x;
            }
        }
    }
}
