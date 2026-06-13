/*
========================================
Problem: Minimum Path Sum
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given an m x n grid filled with
non-negative numbers, find a path
from top-left to bottom-right
which minimizes the sum of all
numbers along its path.

Allowed Moves:

- Right
- Down

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i][j] = Minimum path sum from
           cell (i, j) to the
           destination.

Transition:

Down  = grid[i][j] + dp[i+1][j]
Right = grid[i][j] + dp[i][j+1]

Take the minimum.

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

    int recur(vector<vector<int>>& grid, int m, int n,
              int x, int y, vector<vector<int>>& dp) {

        if(x >= m || y >= n)
            return 1e9;

        if(x == m - 1 && y == n - 1)
            return grid[x][y];

        if(dp[x][y] != -1)
            return dp[x][y];

        int down = grid[x][y] + recur(grid, m, n, x + 1, y, dp);
        int right = grid[x][y] + recur(grid, m, n, x, y + 1, dp);

        return dp[x][y] = min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return recur(grid, m, n, 0, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][j] = Minimum path sum to
           reach cell (i, j)

Transition:

Up   = grid[i][j] + dp[i-1][j]
Left = grid[i][j] + dp[i][j-1]

Take the minimum.

----------------------------------------
Time Complexity: O(m * n)
Space Complexity: O(m * n)

========================================
*/

class SolutionTabulation {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0)
                    continue;

                int up = 1e9;
                int left = 1e9;

                if(i > 0)
                    up = grid[i][j] + dp[i - 1][j];

                if(j > 0)
                    left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
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

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {

            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0) {
                    curr[j] = grid[0][0];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;

                if(i > 0)
                    up = grid[i][j] + prev[j];

                if(j > 0)
                    left = grid[i][j] + curr[j - 1];

                curr[j] = min(up, left);
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};