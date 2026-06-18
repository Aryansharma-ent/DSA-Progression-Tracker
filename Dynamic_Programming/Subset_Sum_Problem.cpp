/*
========================================
Problem: Subset Sum Problem
Platform: GeeksforGeeks
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given an array of positive integers
and a target sum, determine whether
there exists a subset whose sum is
equal to the target.

Return true if such a subset exists,
otherwise return false.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[index][target] = Whether it is
possible to achieve 'target'
using elements from index to n-1.

Choices:

1. Skip current element
2. Take current element

Transition:

dp[index][target] =
take OR notTake

----------------------------------------
Time Complexity: O(n * target)
Space Complexity: O(n * target)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:
    bool recur(vector<int>& arr, int target,
               int index, vector<vector<int>>& dp) {

        if(target == 0)
            return true;

        if(index == arr.size())
            return false;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool notTake = recur(arr, target, index + 1, dp);

        bool take = false;

        if(arr[index] <= target)
            take = recur(arr,
                         target - arr[index],
                         index + 1,
                         dp);

        return dp[index][target] = take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(sum + 1, -1)
        );

        return recur(arr, sum, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][target] = Whether it is
possible to form 'target'
using the first i elements.

Transition:

notTake = dp[i-1][target]

take = dp[i-1][target-arr[i]]

dp[i][target] = take OR notTake

----------------------------------------
Time Complexity: O(n * target)
Space Complexity: O(n * target)

========================================
*/

class SolutionTabulation {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<bool>> dp(
            n,
            vector<bool>(sum + 1, false)
        );

        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        if(arr[0] <= sum)
            dp[0][arr[0]] = true;

        for(int i = 1; i < n; i++) {

            for(int target = 1; target <= sum; target++) {

                bool notTake = dp[i - 1][target];

                bool take = false;

                if(arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];

                dp[i][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
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

Keep only:

prev -> dp[i - 1]
curr -> dp[i]

----------------------------------------
Time Complexity: O(n * target)
Space Complexity: O(target)

========================================
*/

class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<bool> prev(sum + 1, false);

        prev[0] = true;

        if(arr[0] <= sum)
            prev[arr[0]] = true;

        for(int i = 1; i < n; i++) {

            vector<bool> curr(sum + 1, false);

            curr[0] = true;

            for(int target = 1; target <= sum; target++) {

                bool notTake = prev[target];

                bool take = false;

                if(arr[i] <= target)
                    take = prev[target - arr[i]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        return prev[sum];
    }
};