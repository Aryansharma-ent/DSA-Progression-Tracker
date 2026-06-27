/*
========================================
Problem: Delete Operation for Two Strings
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given two strings word1 and word2,
return the minimum number of
deletions required to make the
two strings equal.

========================================
*/

/*
========================================
Key Insight

The characters that do NOT need
to be deleted form the Longest
Common Subsequence (LCS).

Minimum Deletions:

(word1.length - LCS)
+
(word2.length - LCS)

Answer:

n + m - 2 * LCS

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i][j] = Length of the LCS
between:

word1[i...]
word2[j...]

Transition:

If characters match:

1 + LCS(i+1, j+1)

Otherwise:

max(
    LCS(i+1, j),
    LCS(i, j+1)
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

    int recur(string& word1, string& word2,
              int i, int j,
              vector<vector<int>>& dp) {

        if(i >= word1.size() || j >= word2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = 1 + recur(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = max(recur(word1, word2, i + 1, j, dp),
                              recur(word1, word2, i, j + 1, dp));
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int lcs = recur(word1, word2, 0, 0, dp);

        return n + m - 2 * lcs;
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i][j] = Length of the LCS
between:

word1[i...]
word2[j...]

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

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = n - 1; i >= 0; i--) {

            for(int j = m - 1; j >= 0; j--) {

                if(word1[i] == word2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];

                else
                    dp[i][j] = max(dp[i + 1][j],
                                   dp[i][j + 1]);
            }
        }

        return n + m - 2 * dp[0][0];
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

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> next(m + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            vector<int> curr(m + 1, 0);

            for(int j = m - 1; j >= 0; j--) {

                if(word1[i] == word2[j])
                    curr[j] = 1 + next[j + 1];

                else
                    curr[j] = max(next[j],
                                  curr[j + 1]);
            }

            next = curr;
        }

        int lcs = next[0];

        return n + m - 2 * lcs;
    }
};