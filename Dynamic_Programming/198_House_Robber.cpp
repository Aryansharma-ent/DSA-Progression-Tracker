/*
========================================
Problem: House Robber
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

A robber wants to rob houses
along a street.

Adjacent houses cannot be robbed
on the same night.

Find the maximum amount of money
that can be robbed.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i] = Maximum money that can be
        robbed starting from house i.

Choices:

1. Take current house:
   nums[i] + dp[i + 2]

2. Skip current house:
   dp[i + 1]

Take the maximum.

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)

(dp array + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<int>& nums, int index, vector<int>& dp) {

        if(index >= nums.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int take = nums[index] + recur(nums, index + 2, dp);

        int notTake = recur(nums, index + 1, dp);

        return dp[index] = max(take, notTake);
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return recur(nums, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i] = Maximum money that can be
        robbed considering houses
        from 0 to i.

Transition:

take    = nums[i] + dp[i - 2]
notTake = dp[i - 1]

dp[i] = max(take, notTake)

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)

========================================
*/

class SolutionTabulation {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {

            int take = nums[i] + dp[i - 2];

            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

To compute dp[i], we only need:

- dp[i - 1]
- dp[i - 2]

Therefore, storing the entire
DP array is unnecessary.

Keep only:

prev  -> dp[i - 1]
prev2 -> dp[i - 2]

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {

            int take = nums[i] + prev2;

            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};