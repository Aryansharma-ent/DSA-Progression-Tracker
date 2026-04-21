/*
========================================
Problem: Next Greater Element III
Platform: LeetCode
Approach: Next Permutation (Greedy + STL)

Author: Aryan
Date: 2026

----------------------------------------
Approach:

1. Convert integer to string
2. Traverse from right to find the first decreasing element (breakpoint)
3. If no breakpoint exists → return -1
4. Find the next greater digit on the right side
5. Swap both elements
6. Sort the suffix (right side) to get the smallest possible number
7. Convert back to integer and check for overflow

Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring string conversion)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
         string s = to_string(n);
         int index = -1;
         for(int i = s.size() - 2;i >= 0;i--){
            if(s[i] < s[i+1]){
                index = i;
                break;
            }
         }

           if(index == -1) return -1;

         for(int i = s.size() - 1;i >= index;i--){
            if(s[index] < s[i]){
             swap(s[index],s[i]);
            break;
             }         
         }
         sort(s.begin() + index + 1,s.end());
        long long ans = stoll(s);
         if(ans <= INT_MAX && ans >= INT_MIN) return ans;

         return -1;
    }
};