/*
========================================
Problem: Frog Jump with K Distance
Platform: GeeksforGeeks
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

A frog is standing at stone 0
and wants to reach stone n - 1.

From stone i, it can jump to any
stone between:

i + 1 ... i + k

The cost of a jump is:

abs(height[current] - height[next])

Find the minimum total cost
required to reach the last stone.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i] = Minimum cost required
        to reach stone i.

Transition:

For every possible jump length:

1 <= jump <= k

Try reaching current stone i
from all valid previous stones.

dp[i] =
min(
    dp[i-jump]
    +
    abs(height[i] - height[i-jump])
)

----------------------------------------
Time Complexity: O(n * k)
Space Complexity: O(n)

(dp array + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(const vector<int>& heights,
              int k,
              int index,
              vector<int>& dp) {

        if(index == 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int mini = INT_MAX;

        for(int jump = 1; jump <= k; jump++) {

            if(index - jump >= 0) {

                int jumpCost =
                    recur(heights,
                          k,
                          index - jump,
                          dp)
                    +
                    abs(heights[index]
                        - heights[index - jump]);

                mini = min(mini, jumpCost);
            }
        }

        return dp[index] = mini;
    }

    int frogJump(vector<int>& heights,
                 int k) {

        int n = heights.size();

        vector<int> dp(n, -1);

        return recur(heights,
                     k,
                     n - 1,
                     dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

Idea:

Build the answer from smaller
subproblems.

dp[i] = Minimum cost required
        to reach stone i.

For each stone:

Check all previous stones that
can reach it within k jumps.

----------------------------------------
Time Complexity: O(n * k)
Space Complexity: O(n)

========================================
*/

class Solution {
public:

    int frogJump(vector<int>& heights,
                 int k) {

        int n = heights.size();

        vector<int> dp(n, 0);

        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            int mini = INT_MAX;

            for(int jump = 1;
                jump <= k;
                jump++) {

                if(i - jump >= 0) {

                    int jumpCost =
                        dp[i - jump]
                        +
                        abs(heights[i]
                            - heights[i - jump]);

                    mini = min(mini,
                               jumpCost);
                }
            }

            dp[i] = mini;
        }

        return dp[n - 1];
    }
};