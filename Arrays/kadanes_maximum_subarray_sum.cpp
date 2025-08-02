//  Kadane’s Algorithm - Maximum Subarray Sum
//  Approach:
// 1. Traverse the array while maintaining a running sum.
// 2. If the running sum becomes negative, compare it with the maximum and reset it to 0.
// 3. If the sum is positive and greater than the current maximum, update the maximum.
// 4. Special case: if array has only one element, return it directly.
//
//  Time Complexity: O(n) – One pass through the array.
//  Space Complexity: O(1) – Constant space, no extra data structures.
//  Status: Accepted on LeetCode, 0ms runtime (Beats 100%).


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (n < 2) {
                return nums[i];  // Early return for single-element array
            }

            sum += nums[i];

            if (sum < 0) {
                maxi = max(sum, maxi);
                sum = 0;
            } else if (sum > maxi && sum >= 0) {
                maxi = sum;
            }
        }

        return maxi;
    }
};
