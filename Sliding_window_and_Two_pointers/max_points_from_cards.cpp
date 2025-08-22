/*
File: max_points_from_cards.cpp

Problem:
LeetCode 1423 – Maximum Points You Can Obtain from Cards
You are given an integer array cardPoints and an integer k.
You can pick exactly k cards from either end of the array.
Return the maximum score you can obtain.

Approach:
1. Total score of picked cards = Total sum of all cards - Sum of the unpicked subarray.
2. Since we must pick k cards from ends, we are effectively leaving (n - k) consecutive cards.
3. Find the minimum sum subarray of length (n - k) using sliding window.
4. Answer = totalSum - minSubarraySum.

Steps:
- Compute total sum of the array.
- Use sliding window of size (n - k) to find the minimum subarray sum.
- Subtract this from total sum.

Complexity:
- Time: O(n), each element is visited once while summing and once in sliding window.
- Space: O(1), only variables used.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        int windowSize = n - k;
        if (windowSize == 0) return totalSum;

        int l = 0, currSum = 0, minSum = INT_MAX;

        for (int r = 0; r < n; r++) {
            currSum += nums[r];

            if (r - l + 1 == windowSize) {
                minSum = min(minSum, currSum);
                currSum -= nums[l];
                l++;
            }
        }
        return totalSum - minSum;
    }
};
