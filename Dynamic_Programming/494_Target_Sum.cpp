/*
========================================
Problem: Target Sum
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given an integer array nums and
an integer target, assign either
'+' or '-' before each number.

Return the number of different
expressions that evaluate to
target.

========================================
*/

/*
========================================
Key Insight

Let:

S1 = Sum of elements assigned '+'
S2 = Sum of elements assigned '-'

Then:

S1 - S2 = target
S1 + S2 = totalSum

Adding both equations:

2 * S1 = totalSum + target

Therefore:

S1 = (totalSum + target) / 2

The problem reduces to:

Count the number of subsets with
sum equal to:

(target + totalSum) / 2

Invalid Cases:

1. abs(target) > totalSum
2. (totalSum + target) is odd

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[index][sum] = Number of ways
to achieve 'sum' using elements
from index onward.

Choices:

1. Add current number
2. Subtract current number

Transition:

dp[index][sum] =
plus + minus

Since sum can be negative,
shift it by totalSum.

----------------------------------------
Time Complexity: O(n * totalSum)
Space Complexity: O(n * totalSum)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<int>& nums, int target,
              int index, int total,
              vector<vector<int>>& dp) {

        if(target < -total || target > total)
            return 0;

        if(index == nums.size())
            return (target == 0);

        if(dp[index][total + target] != -1)
            return dp[index][total + target];

        int plus = recur(nums,
                          target - nums[index],
                          index + 1,
                          total,
                          dp);

        int minus = recur(nums,
                           target + nums[index],
                           index + 1,
                           total,
                           dp);

        return dp[index][total + target] =
               plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(),
                               nums.end(),
                               0);

        if(abs(target) > total)
            return 0;

        vector<vector<int>> dp(
            nums.size() + 1,
            vector<int>(2 * total + 1, -1)
        );

        return recur(nums,
                     target,
                     0,
                     total,
                     dp);
    }
};

/*
========================================
Approach 2: Tabulation (Subset Sum Transformation)

Transformation:

S1 - S2 = target
S1 + S2 = totalSum

S1 = (target + totalSum) / 2

Count subsets with sum = S1.

State:

dp[i][sum] = Number of subsets
using first i elements with
sum equal to sum.

----------------------------------------
Time Complexity: O(n * requiredSum)
Space Complexity: O(n * requiredSum)

========================================
*/

class SolutionTabulation {
public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(),
                                  nums.end(),
                                  0);

        if(abs(target) > totalSum)
            return 0;

        if((totalSum + target) % 2 != 0)
            return 0;

        int requiredSum = (totalSum + target) / 2;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(requiredSum + 1, 0)
        );

        if(nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;

            if(nums[0] <= requiredSum)
                dp[0][nums[0]] = 1;
        }

        for(int i = 1; i < n; i++) {

            for(int sum = 0; sum <= requiredSum; sum++) {

                int notTake = dp[i - 1][sum];

                int take = 0;

                if(nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][requiredSum];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

To compute the current row,
we only need the previous row.

Therefore, storing the entire
2D DP table is unnecessary.

----------------------------------------
Time Complexity: O(n * requiredSum)
Space Complexity: O(requiredSum)

========================================
*/

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(),
                                  nums.end(),
                                  0);

        if(abs(target) > totalSum)
            return 0;

        if((totalSum + target) % 2 != 0)
            return 0;

        int requiredSum = (totalSum + target) / 2;

        vector<int> prev(requiredSum + 1, 0);

        if(nums[0] == 0)
            prev[0] = 2;
        else {
            prev[0] = 1;

            if(nums[0] <= requiredSum)
                prev[nums[0]] = 1;
        }

        for(int i = 1; i < nums.size(); i++) {

            vector<int> curr(requiredSum + 1, 0);

            for(int sum = 0; sum <= requiredSum; sum++) {

                int notTake = prev[sum];

                int take = 0;

                if(nums[i] <= sum)
                    take = prev[sum - nums[i]];

                curr[sum] = take + notTake;
            }

            prev = curr;
        }

        return prev[requiredSum];
    }
};