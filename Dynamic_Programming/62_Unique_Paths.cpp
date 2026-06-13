/*
========================================
Problem: Unique Paths
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

A robot is located at the
top-left corner of an m x n grid.

The robot can only move:

- Right
- Down

Find the total number of unique
paths from top-left to
bottom-right.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i][j] = Number of unique paths
           from cell (i, j)
           to destination.

Transition:

Down  = dp[i + 1][j]
Right = dp[i][j + 1]

Total Paths:

dp[i][j] = Down + Right

----------------------------------------
Time Complexity: O(m * n)
Space Complexity: O(m * n)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(int m, int n, int x, int y,
              vector<vector<int>>& dp) {

        if(x >= m || y >= n)
            return 0;

        if(x == m - 1 && y == n - 1)
            return 1;

        if(dp[x][y] != -1)
            return dp[x][y];

        int down = recur(m, n, x + 1, y, dp);
        int right = recur(m, n, x, y + 1, dp);

        return dp[x][y] = down + right;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return recur(m, n, 0, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][j] = Number of unique paths
           to reach cell (i, j)

Transition:

Up   = dp[i - 1][j]
Left = dp[i][j - 1]

Total Paths:

dp[i][j] = Up + Left

----------------------------------------
Time Complexity: O(m * n)
Space Complexity: O(m * n)

========================================
*/

class SolutionTabulation {
public:

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0)
                    continue;

                int up = 0;
                int left = 0;

                if(i > 0)
                    up = dp[i - 1][j];

                if(j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

To compute the current row,
we only need:

- Previous row
- Current row

Therefore, storing the entire
2D DP table is unnecessary.

----------------------------------------
Time Complexity: O(m * n)
Space Complexity: O(n)

========================================
*/

class Solution {
public:

    int uniquePaths(int m, int n) {

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {

            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(i > 0)
                    up = prev[j];

                if(j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};