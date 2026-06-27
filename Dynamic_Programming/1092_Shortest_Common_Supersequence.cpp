/*
========================================
Problem: Shortest Common Supersequence
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given two strings str1 and str2,
return the shortest string that
contains both strings as
subsequences.

If multiple answers exist,
return any one of them.

========================================
*/

/*
========================================
Key Insight

The Longest Common Subsequence
(LCS) represents the characters
shared by both strings.

Characters in the LCS are added
only once.

All remaining characters must
also appear in the answer.

Length of SCS:

Length = n + m - LCS

========================================
*/

/*
========================================
Approach: LCS + Reconstruction

Step 1:

Build the LCS DP table.

State:

dp[i][j] = Length of the LCS
between:

str1[i...]
str2[j...]

Transition:

If characters match:

1 + dp[i+1][j+1]

Otherwise:

max(
dp[i+1][j],
dp[i][j+1]
)

----------------------------------------

Step 2:

Reconstruct the answer.

If characters match:

Append the character once
and move both pointers.

Otherwise:

If dp[i+1][j] >= dp[i][j+1]:

Current character of str1
is not part of the LCS.

Append str1[i].

Move i.

Else:

Append str2[j].

Move j.

Finally append all remaining
characters from either string.

----------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string shortestCommonSupersequence(string word1,
                                       string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for(int i = n - 1; i >= 0; i--) {

            for(int j = m - 1; j >= 0; j--) {

                if(word1[i] == word2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];

                else
                    dp[i][j] = max(dp[i + 1][j],
                                   dp[i][j + 1]);
            }
        }

        string ans;

        int i = 0;
        int j = 0;

        while(i < n && j < m) {

            if(word1[i] == word2[j]) {

                ans += word1[i];
                i++;
                j++;
            }

            else if(dp[i + 1][j] >= dp[i][j + 1]) {

                ans += word1[i];
                i++;
            }

            else {

                ans += word2[j];
                j++;
            }
        }

        while(i < n) {

            ans += word1[i];
            i++;
        }

        while(j < m) {

            ans += word2[j];
            j++;
        }

        return ans;
    }
};