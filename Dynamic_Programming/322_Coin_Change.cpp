/*
========================================
Problem: Coin Change
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given an array of coin denominations
and an amount, return the minimum
number of coins required to make
up that amount.

You may use each coin an unlimited
number of times.

Return -1 if it is impossible.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[index][amount] = Minimum number
of coins needed to make 'amount'
using coins from index to n - 1.

Choices:

1. Take current coin
   (stay at same index)

2. Skip current coin
   (move to next index)

Transition:

dp[index][amount] =
min(take, notTake)

----------------------------------------
Time Complexity: O(n * amount)
Space Complexity: O(n * amount)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<int>& coins, int amount,
              int index, vector<vector<int>>& dp) {

        if(index == coins.size()) {

            if(amount == 0)
                return 0;

            return 1e9;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int take = 1e9;

        if(coins[index] <= amount)
            take = 1 + recur(coins,
                              amount - coins[index],
                              index,
                              dp);

        int notTake = recur(coins,
                            amount,
                            index + 1,
                            dp);

        return dp[index][amount] =
               min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        int ans = recur(coins,
                        amount,
                        0,
                        dp);

        return ans >= 1e9 ? -1 : ans;
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[index][amount] = Minimum number
of coins needed to make 'amount'
using coins from index to n - 1.

Transition:

take =
1 + dp[index][amount - coin]

notTake =
dp[index + 1][amount]

dp[index][amount] =
min(take, notTake)

----------------------------------------
Time Complexity: O(n * amount)
Space Complexity: O(n * amount)

========================================
*/

class SolutionTabulation {
public:

    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, 1e9)
        );

        dp[n][0] = 0;

        for(int i = n - 1; i >= 0; i--) {

            for(int currAmount = 0;
                currAmount <= amount;
                currAmount++) {

                int take = 1e9;

                if(coins[i] <= currAmount)
                    take = 1 + dp[i][currAmount - coins[i]];

                int notTake = dp[i + 1][currAmount];

                dp[i][currAmount] =
                    min(take, notTake);
            }
        }

        return dp[0][amount] >= 1e9
               ? -1
               : dp[0][amount];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

dp[index][amount] depends on:

- dp[index][amount - coin]
- dp[index + 1][amount]

Since the take transition uses
the current row itself, we need:

curr -> dp[index]
next -> dp[index + 1]

----------------------------------------
Time Complexity: O(n * amount)
Space Complexity: O(amount)

========================================
*/

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;

        int n = coins.size();

        vector<int> next(amount + 1, 1e9);
        next[0] = 0;

        for(int i = n - 1; i >= 0; i--) {

            vector<int> curr(amount + 1, 1e9);

            curr[0] = 0;

            for(int currAmount = 1;
                currAmount <= amount;
                currAmount++) {

                int take = 1e9;

                if(coins[i] <= currAmount)
                    take = 1 + curr[currAmount - coins[i]];

                int notTake = next[currAmount];

                curr[currAmount] =
                    min(take, notTake);
            }

            next = curr;
        }

        return next[amount] >= 1e9
               ? -1
               : next[amount];
    }
};