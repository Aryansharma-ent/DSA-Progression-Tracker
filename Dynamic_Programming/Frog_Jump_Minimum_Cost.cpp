/*
========================================
Problem: Frog Jump (Minimum Cost)
Platform: GeeksforGeeks
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Approach 1: Memoization (Top-Down DP)

State:

dp[i] = Minimum cost required to
        reach the last stone
        starting from stone i.

Transition:

Jump 1 step:
abs(height[i] - height[i+1])
+ dp[i+1]

Jump 2 steps:
abs(height[i] - height[i+2])
+ dp[i+2]

Take the minimum of both.

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

    int recur(const vector<int>& height,
              int i,
              vector<int>& dp) {

        if(i == height.size() - 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int left =
            abs(height[i] - height[i + 1]) +
            recur(height, i + 1, dp);

        int right = INT_MAX;

        if(i + 2 < height.size()) {
            right =
                abs(height[i] - height[i + 2]) +
                recur(height, i + 2, dp);
        }

        return dp[i] = min(left, right);
    }

    int minCost(vector<int>& height) {

        vector<int> dp(height.size(), -1);

        return recur(height, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

Idea:

Build the answer from smaller
subproblems.

dp[i] represents the minimum
cost required to reach stone i.

For each stone:

dp[i] =
min(
    jump from i-1,
    jump from i-2
)

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)

========================================
*/

class SolutionTabulation {
public:

    int minCost(vector<int>& height) {

        int n = height.size();

        vector<int> dp(n, 0);

        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            int left =
                abs(height[i] - height[i - 1])
                + dp[i - 1];

            int right = INT_MAX;

            if(i > 1) {
                right =
                    abs(height[i] - height[i - 2])
                    + dp[i - 2];
            }

            dp[i] = min(left, right);
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

Keep only two variables:

prev  -> dp[i - 1]
prev2 -> dp[i - 2]

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

class Solution {
public:

    int minCost(vector<int>& height) {

        int prev2 = 0;
        int prev  = 0;

        for(int i = 1; i < height.size(); i++) {

            int left =
                abs(height[i] - height[i - 1])
                + prev;

            int right = INT_MAX;

            if(i > 1) {
                right =
                    abs(height[i] - height[i - 2])
                    + prev2;
            }

            int curr = min(left, right);

            prev2 = prev;
            prev  = curr;
        }

        return prev;
    }
};