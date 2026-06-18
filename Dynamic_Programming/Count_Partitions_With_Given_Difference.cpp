/*
========================================
Problem: Count Partitions With Given Difference
Platform: GeeksforGeeks
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given an array and an integer diff,
count the number of ways to divide
the array into two subsets such that:

S1 - S2 = diff

where:

S1 >= S2

========================================
*/

/*
========================================
Key Insight

Let:

S1 + S2 = totalSum
S1 - S2 = diff

Adding both equations:

2 * S1 = totalSum + diff

Therefore:

S1 = (totalSum + diff) / 2

The problem reduces to:

Count the number of subsets with
sum equal to target.

target = (totalSum + diff) / 2

Invalid Cases:

1. diff > totalSum
2. totalSum + diff is odd

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[index][target] = Number of subsets
starting from index that have
sum equal to target.

Choices:

1. Skip current element
2. Take current element

Transition:

dp[index][target] =
take + notTake

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

    int recur(vector<int>& arr, int target,
              int index, vector<vector<int>>& dp) {

        if(index == arr.size())
            return (target == 0);

        if(dp[index][target] != -1)
            return dp[index][target];

        int take = 0;

        if(arr[index] <= target)
            take = recur(arr,
                         target - arr[index],
                         index + 1,
                         dp);

        int notTake = recur(arr,
                            target,
                            index + 1,
                            dp);

        return dp[index][target] = take + notTake;
    }

    int countPartitions(vector<int>& arr, int diff) {

        int totalSum = accumulate(arr.begin(),
                                  arr.end(),
                                  0);

        if(diff > totalSum)
            return 0;

        if((totalSum + diff) % 2 != 0)
            return 0;

        int target = (totalSum + diff) / 2;

        vector<vector<int>> dp(
            arr.size() + 1,
            vector<int>(target + 1, -1)
        );

        return recur(arr, target, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][target] = Number of subsets
using first i elements that have
sum equal to target.

Transition:

notTake = dp[i-1][target]

take = dp[i-1][target-arr[i]]

dp[i][target] = take + notTake

----------------------------------------
Time Complexity: O(n * target)
Space Complexity: O(n * target)

========================================
*/

class SolutionTabulation {
public:

    int countPartitions(vector<int>& arr, int diff) {

        int totalSum = accumulate(arr.begin(),
                                  arr.end(),
                                  0);

        if(diff > totalSum)
            return 0;

        if((totalSum + diff) % 2 != 0)
            return 0;

        int target = (totalSum + diff) / 2;
        int n = arr.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(target + 1, 0)
        );

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {

            for(int sum = 0; sum <= target; sum++) {

                int notTake = dp[i - 1][sum];

                int take = 0;

                if(arr[i - 1] <= sum)
                    take = dp[i - 1][sum - arr[i - 1]];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n][target];
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

    int countPartitions(vector<int>& arr, int diff) {

        int totalSum = accumulate(arr.begin(),
                                  arr.end(),
                                  0);

        if(diff > totalSum)
            return 0;

        if((totalSum + diff) % 2 != 0)
            return 0;

        int target = (totalSum + diff) / 2;

        vector<int> prev(target + 1, 0);

        prev[0] = 1;

        for(int i = 0; i < arr.size(); i++) {

            vector<int> curr(target + 1, 0);

            curr[0] = 1;

            for(int sum = 0; sum <= target; sum++) {

                int notTake = prev[sum];

                int take = 0;

                if(arr[i] <= sum)
                    take = prev[sum - arr[i]];

                curr[sum] = take + notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};