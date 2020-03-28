/*
* Equal Arrays
* Date: 28'th March 2020
* Author: Shrinath Bhosale
* Problem Statement: https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not/0/
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class EqualArrays {
    public static void main (String[] args) throws IOException {
        //code
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);

        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            Map<Long, Integer> m = new HashMap<>();

            String [] nums = br.readLine().split(" ");
            for(int i=0; i<n; ++i) {
                Long num = Long.parseLong(nums[i]);
                m.put(num, m.getOrDefault(num, 0) + 1);
            }

            boolean f = true;
            String [] nums2 = br.readLine().split(" ");
            for(int i=0; i<n; ++i) {
                Long num = Long.parseLong(nums2[i]);

                if(!m.containsKey(num) || m.get(num) == 0) {
                    f = false;
                    break;
                }

                int v = m.get(num);
                --v;
                m.put(num, v);
            }

            if(f)
                System.out.println(1);
            else
                System.out.println(0);
        }
    }
}
