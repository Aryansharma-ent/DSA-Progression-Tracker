/*
========================================
Problem: Chocolate Pickup
Platform: Coding Ninjas / Striver DP
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Alice starts at (0, 0).

Bob starts at (0, n - 1).

Both move from the first row
to the last row.

Allowed moves:

- Down-Left
- Down
- Down-Right

If both land on the same cell,
collect chocolates only once.

Find the maximum chocolates
that can be collected.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[row][c1][c2] = Maximum chocolates
                  collectable starting
                  from row 'row' when:

                  Alice is at column c1
                  Bob is at column c2

Transition:

Try all possible moves for
Alice and Bob.

Total transitions:

3 × 3 = 9

----------------------------------------
Time Complexity: O(m * n * n * 9)
Space Complexity: O(m * n * n)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int solve(int row, int c1, int c2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if(c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
            return -1e9;

        if(row == m - 1) {

            if(c1 == c2)
                return grid[row][c1];

            return grid[row][c1] + grid[row][c2];
        }

        if(dp[row][c1][c2] != -1)
            return dp[row][c1][c2];

        int curr = (c1 == c2)
                   ? grid[row][c1]
                   : grid[row][c1] + grid[row][c2];

        int ans = -1e9;

        for(int d1 = -1; d1 <= 1; d1++) {

            for(int d2 = -1; d2 <= 1; d2++) {

                ans = max(ans,
                          curr + solve(row + 1,
                                       c1 + d1,
                                       c2 + d2,
                                       grid,
                                       dp));
            }
        }

        return dp[row][c1][c2] = ans;
    }

    int maxChocolates(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n,
            vector<int>(n, -1))
        );

        return solve(0, 0, n - 1, grid, dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[row][c1][c2] = Maximum chocolates
                  collectable up to
                  state (row, c1, c2)

Build the DP table from the
last row upwards.

----------------------------------------
Time Complexity: O(m * n * n * 9)
Space Complexity: O(m * n * n)

========================================
*/

class SolutionTabulation {
public:

    int maxChocolates(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n,
            vector<int>(n, 0))
        );

        for(int c1 = 0; c1 < n; c1++) {

            for(int c2 = 0; c2 < n; c2++) {

                if(c1 == c2)
                    dp[m - 1][c1][c2] = grid[m - 1][c1];
                else
                    dp[m - 1][c1][c2] =
                        grid[m - 1][c1] +
                        grid[m - 1][c2];
            }
        }

        for(int row = m - 2; row >= 0; row--) {

            for(int c1 = 0; c1 < n; c1++) {

                for(int c2 = 0; c2 < n; c2++) {

                    int curr = (c1 == c2)
                               ? grid[row][c1]
                               : grid[row][c1] + grid[row][c2];

                    int ans = -1e9;

                    for(int d1 = -1; d1 <= 1; d1++) {

                        for(int d2 = -1; d2 <= 1; d2++) {

                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;

                            if(nc1 >= 0 && nc1 < n &&
                               nc2 >= 0 && nc2 < n) {

                                ans = max(ans,
                                          curr + dp[row + 1][nc1][nc2]);
                            }
                        }
                    }

                    dp[row][c1][c2] = ans;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

To compute the current row,
we only need the next row.

Therefore, storing all rows
is unnecessary.

Keep only:

front -> dp[row + 1]
curr  -> dp[row]

----------------------------------------
Time Complexity: O(m * n * n * 9)
Space Complexity: O(n * n)

========================================
*/

class Solution {
public:

    int maxChocolates(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> front(
            n, vector<int>(n, 0)
        );

        for(int c1 = 0; c1 < n; c1++) {

            for(int c2 = 0; c2 < n; c2++) {

                if(c1 == c2)
                    front[c1][c2] = grid[m - 1][c1];
                else
                    front[c1][c2] =
                        grid[m - 1][c1] +
                        grid[m - 1][c2];
            }
        }

        for(int row = m - 2; row >= 0; row--) {

            vector<vector<int>> curr(
                n, vector<int>(n, 0)
            );

            for(int c1 = 0; c1 < n; c1++) {

                for(int c2 = 0; c2 < n; c2++) {

                    int value = (c1 == c2)
                                ? grid[row][c1]
                                : grid[row][c1] + grid[row][c2];

                    int ans = -1e9;

                    for(int d1 = -1; d1 <= 1; d1++) {

                        for(int d2 = -1; d2 <= 1; d2++) {

                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;

                            if(nc1 >= 0 && nc1 < n &&
                               nc2 >= 0 && nc2 < n) {

                                ans = max(ans,
                                          value + front[nc1][nc2]);
                            }
                        }
                    }

                    curr[c1][c2] = ans;
                }
            }

            front = curr;
        }

        return front[0][n - 1];
    }
};