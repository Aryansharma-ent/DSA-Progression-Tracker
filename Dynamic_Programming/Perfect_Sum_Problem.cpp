/*
========================================
Problem: Perfect Sum Problem
Platform: GeeksforGeeks
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given an array of non-negative
integers and a target sum K,
count the number of subsets
whose sum is exactly K.

Note:

The array may contain zeros.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[index][target] = Number of
subsets from index 0 to index
that have sum equal to target.

Choices:

1. Skip current element
2. Take current element

Transition:

dp[index][target] =
take + notTake

Special Case:

If arr[0] == 0:

- Take zero
- Skip zero

Both contribute to sum = 0.

Hence:

dp[0][0] = 2

----------------------------------------
Time Complexity: O(n * K)
Space Complexity: O(n * K)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<int>& arr, int index,
              int target, vector<vector<int>>& dp) {

        if(index == 0) {

            if(target == 0 && arr[0] == 0)
                return 2;

            if(target == 0 || target == arr[0])
                return 1;

            return 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notTake = recur(arr, index - 1, target, dp);

        int take = 0;

        if(arr[index] <= target)
            take = recur(arr,
                         index - 1,
                         target - arr[index],
                         dp);

        return dp[index][target] = take + notTake;
    }

    int perfectSum(vector<int>& arr, int K) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(K + 1, -1)
        );

        return recur(arr, n - 1, K, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][target] = Number of subsets
using elements from 0 to i
with sum equal to target.

Transition:

notTake = dp[i-1][target]

take = dp[i-1][target-arr[i]]

dp[i][target] = take + notTake

----------------------------------------
Time Complexity: O(n * K)
Space Complexity: O(n * K)

========================================
*/

class SolutionTabulation {
public:

    int perfectSum(vector<int>& arr, int K) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(K + 1, 0)
        );

        if(arr[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;

            if(arr[0] <= K)
                dp[0][arr[0]] = 1;
        }

        for(int i = 1; i < n; i++) {

            for(int target = 0; target <= K; target++) {

                int notTake = dp[i - 1][target];

                int take = 0;

                if(arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];

                dp[i][target] = take + notTake;
            }
        }

        return dp[n - 1][K];
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
Time Complexity: O(n * K)
Space Complexity: O(K)

========================================
*/

class Solution {
public:

    int perfectSum(vector<int>& arr, int K) {

        int n = arr.size();

        vector<int> prev(K + 1, 0);

        if(arr[0] == 0)
            prev[0] = 2;
        else {
            prev[0] = 1;

            if(arr[0] <= K)
                prev[arr[0]] = 1;
        }

        for(int i = 1; i < n; i++) {

            vector<int> curr(K + 1, 0);

            for(int target = 0; target <= K; target++) {

                int notTake = prev[target];

                int take = 0;

                if(arr[i] <= target)
                    take = prev[target - arr[i]];

                curr[target] = take + notTake;
            }

            prev = curr;
        }

        return prev[K];
    }
};