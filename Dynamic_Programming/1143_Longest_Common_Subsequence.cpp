/*
========================================
Problem: Longest Common Subsequence
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given two strings text1 and text2,
return the length of their longest
common subsequence.

A subsequence is a sequence that
can be derived from another sequence
by deleting some or no characters
without changing the order of the
remaining characters.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i][j] = Length of the LCS
starting from:

text1[i]
text2[j]

Choices:

If characters match:

1 + LCS(i + 1, j + 1)

Otherwise:

max(
    LCS(i + 1, j),
    LCS(i, j + 1)
)

----------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(string& text1, string& text2,
              int i, int j,
              vector<vector<int>>& dp) {

        if(i >= text1.size() || j >= text2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j]) {

            return dp[i][j] =
                1 + recur(text1,
                          text2,
                          i + 1,
                          j + 1,
                          dp);
        }

        return dp[i][j] =
            max(
                recur(text1,
                      text2,
                      i + 1,
                      j,
                      dp),

                recur(text1,
                      text2,
                      i,
                      j + 1,
                      dp)
            );
    }

    int longestCommonSubsequence(string text1,
                                 string text2) {

        vector<vector<int>> dp(
            text1.size() + 1,
            vector<int>(text2.size() + 1, -1)
        );

        return recur(text1,
                     text2,
                     0,
                     0,
                     dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][j] = Length of LCS
between:

text1[i...n-1]
text2[j...m-1]

Transition:

If characters match:

1 + dp[i+1][j+1]

Otherwise:

max(
    dp[i+1][j],
    dp[i][j+1]
)

----------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)

========================================
*/

class SolutionTabulation {
public:

    int longestCommonSubsequence(string text1,
                                 string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for(int i = n - 1; i >= 0; i--) {

            for(int j = m - 1; j >= 0; j--) {

                if(text1[i] == text2[j]) {

                    dp[i][j] =
                        1 + dp[i + 1][j + 1];
                }
                else {

                    dp[i][j] =
                        max(dp[i + 1][j],
                            dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

To compute row i,
we only need:

- Current row
- Next row

Therefore, storing the entire
2D DP table is unnecessary.

----------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(m)

========================================
*/

class Solution {
public:

    int longestCommonSubsequence(string text1,
                                 string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<int> next(m + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            vector<int> curr(m + 1, 0);

            for(int j = m - 1; j >= 0; j--) {

                if(text1[i] == text2[j]) {

                    curr[j] =
                        1 + next[j + 1];
                }
                else {

                    curr[j] =
                        max(next[j],
                            curr[j + 1]);
                }
            }

            next = curr;
        }

        return next[0];
    }
};