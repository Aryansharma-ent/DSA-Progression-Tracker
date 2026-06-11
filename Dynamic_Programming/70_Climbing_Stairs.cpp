/*
========================================
Problem: Climbing Stairs
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Approach 1: Memoization (Top-Down DP)

1. Define the recurrence:

   ways(n) = ways(n - 1) + ways(n - 2)

2. Base Cases:
   - ways(1) = 1
   - ways(2) = 2

3. Use a DP array to store
   previously computed results.

4. Before solving a state,
   check if it already exists
   in the DP array.

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

    int recur(int n, vector<int>& dp) {

        if(n <= 2)
            return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] =
            recur(n - 1, dp) +
            recur(n - 2, dp);
    }

    int climbStairs(int n) {

        vector<int> dp(n + 1, -1);

        return recur(n, dp);
    }
};

/*
========================================
Approach 2: Space Optimized DP

Observation:

ways(n) depends only on:

- ways(n - 1)
- ways(n - 2)

Therefore, instead of storing
all previous states, we only
keep the last two values.

----------------------------------------
Steps:

1. Initialize:

   ways(1) = 1
   ways(2) = 2

2. Iterate from 3 to n.

3. Compute current answer:

   curr = prev + prev2

4. Shift values forward.

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

class Solution {
public:

    int climbStairs(int n) {

        if(n <= 2)
            return n;

        int prev2 = 1;
        int prev  = 2;

        for(int i = 3; i <= n; i++) {

            int curr = prev + prev2;

            prev2 = prev;
            prev  = curr;
        }

        return prev;
    }
};