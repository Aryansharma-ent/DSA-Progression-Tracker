/*
========================================
Problem: Triangle
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given a triangle array, return
the minimum path sum from top
to bottom.

At each step, you may move to:

- Same column
- Adjacent column

in the next row.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i][j] = Minimum path sum
           starting from
           cell (i, j)

Transition:

Down = triangle[i][j]
       + dp[i+1][j]

Diagonal = triangle[i][j]
           + dp[i+1][j+1]

Take the minimum.

----------------------------------------
Time Complexity: O(n²)
Space Complexity: O(n²)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<vector<int>>& triangle,
              int i,
              int j,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        if(i == n - 1)
            return triangle[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] +
                   recur(triangle, i + 1, j, dp);

        int diag = triangle[i][j] +
                   recur(triangle, i + 1, j + 1, dp);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }

        return recur(triangle, 0, 0, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][j] = Minimum path sum
           to reach cell (i, j)

Transition:

Up:
triangle[i][j] + dp[i-1][j]

Diagonal:
triangle[i][j] + dp[i-1][j-1]

Take the minimum.

----------------------------------------
Time Complexity: O(n²)
Space Complexity: O(n²)

========================================
*/

class SolutionTabulation {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i] = vector<int>(triangle[i].size(), 0);
        }

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++) {

            for(int j = 0; j <= i; j++) {

                int up = 1e9;
                int diag = 1e9;

                if(j < i)
                    up = triangle[i][j] + dp[i - 1][j];

                if(j > 0)
                    diag = triangle[i][j] + dp[i - 1][j - 1];

                dp[i][j] = min(up, diag);
            }
        }

        int ans = 1e9;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
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
Time Complexity: O(n²)
Space Complexity: O(n)

========================================
*/

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<int> prev(1, triangle[0][0]);

        for(int i = 1; i < n; i++) {

            vector<int> curr(i + 1, 0);

            for(int j = 0; j <= i; j++) {

                int up = 1e9;
                int diag = 1e9;

                if(j < i)
                    up = triangle[i][j] + prev[j];

                if(j > 0)
                    diag = triangle[i][j] + prev[j - 1];

                curr[j] = min(up, diag);
            }

            prev = curr;
        }

        int ans = 1e9;

        for(int j = 0; j < n; j++) {
            ans = min(ans, prev[j]);
        }

        return ans;
    }
};