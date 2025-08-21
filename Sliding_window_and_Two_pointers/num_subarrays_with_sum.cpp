/*
File: num_subarrays_with_sum.cpp
Commit: Added solution for "Binary Subarrays With Sum" using sliding window + prefix trick.

Problem:
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal.

Approach:
- Use a helper function (Algo) that counts the number of subarrays with sum ≤ goal.
- The actual answer is Algo(nums, goal) - Algo(nums, goal-1).
- Algo uses a sliding window (two-pointer) approach:
    - Expand right pointer (r) and add nums[r] to sum.
    - While sum > goal, shrink left pointer (l).
    - Count valid subarrays ending at r by (r - l + 1).
- This avoids using hashmaps and runs in O(n).

Time Complexity: O(n)  
Space Complexity: O(1)

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Algo(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;  // No valid subarrays
        }
        int cnt = 0;
        int l = 0, r = 0, sum = 0;
        int n = nums.size();

        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return Algo(nums, goal) - Algo(nums, goal - 1);
    }
};
