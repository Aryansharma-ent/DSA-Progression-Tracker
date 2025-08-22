/*
File: count_nice_subarrays.cpp

Problem:
Given an integer array nums and an integer k, return the number of subarrays with exactly k odd numbers.

Approach:
1. Use a sliding window (two pointers) to count the number of subarrays with at most k odd numbers.
2. Define a helper function countSubarraysAtMostK(nums, k) that:
   - Expands the window by moving the right pointer.
   - Increments oddcnt when an odd number is included.
   - Shrinks the window from the left when oddcnt > k.
   - Adds (r - l + 1) to the answer for each valid r.
3. To get the number of subarrays with exactly k odd numbers:
   - Use the trick: 
       exactly_k = atMost(k) - atMost(k - 1)

Complexity:
- Time: O(n), each element is processed at most twice (once by right pointer, once by left).
- Space: O(1), only variables used (no extra data structures).

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubarraysAtMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int cnt = 0, l = 0, oddcnt = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 != 0) oddcnt++;
            
            while (oddcnt > k) {
                if (nums[l] % 2 != 0) oddcnt--;
                l++;
            }
            
            cnt += r - l + 1;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarraysAtMostK(nums, k) - countSubarraysAtMostK(nums, k - 1);
    }
};
