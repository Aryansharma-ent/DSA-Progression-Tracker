/*
========================================
Problem: Unbounded Knapsack
Platform: GeeksforGeeks
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given:

- val[i] = value of item i
- wt[i] = weight of item i
- capacity = maximum capacity

You may take an item an
unlimited number of times.

Find the maximum value that
can be obtained.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[index][cap] = Maximum value
that can be obtained using
items from index onward with
remaining capacity cap.

Choices:

1. Take current item
   (stay at same index)

2. Skip current item
   (move to next index)

Transition:

dp[index][cap] =
max(take, notTake)

----------------------------------------
Time Complexity: O(n * capacity)
Space Complexity: O(n * capacity)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<int>& val,
              vector<int>& wt,
              int cap,
              int index,
              vector<vector<int>>& dp) {

        if(index == val.size())
            return 0;

        if(dp[index][cap] != -1)
            return dp[index][cap];

        int take = 0;

        if(wt[index] <= cap)
            take = val[index]
                 + recur(val,
                         wt,
                         cap - wt[index],
                         index,
                         dp);

        int notTake =
            recur(val,
                  wt,
                  cap,
                  index + 1,
                  dp);

        return dp[index][cap] =
               max(take, notTake);
    }

    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int capacity) {

        int n = val.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(capacity + 1, -1)
        );

        return recur(val,
                     wt,
                     capacity,
                     0,
                     dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[index][cap] = Maximum value
obtainable using items from
index onward with capacity cap.

Transition:

take =
val[index] +
dp[index][cap - wt[index]]

notTake =
dp[index + 1][cap]

dp[index][cap] =
max(take, notTake)

----------------------------------------
Time Complexity: O(n * capacity)
Space Complexity: O(n * capacity)

========================================
*/

class SolutionTabulation {
public:

    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int capacity) {

        int n = val.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(capacity + 1, 0)
        );

        for(int index = n - 1;
            index >= 0;
            index--) {

            for(int cap = 0;
                cap <= capacity;
                cap++) {

                int take = 0;

                if(wt[index] <= cap)
                    take = val[index]
                         + dp[index][cap - wt[index]];

                int notTake =
                    dp[index + 1][cap];

                dp[index][cap] =
                    max(take, notTake);
            }
        }

        return dp[0][capacity];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

For Unbounded Knapsack:

take uses current row itself.

Therefore, a single 1D DP array
is sufficient.

Transition:

dp[cap] =
max(
    dp[cap],
    val[index] + dp[cap - wt[index]]
)

----------------------------------------
Time Complexity: O(n * capacity)
Space Complexity: O(capacity)

========================================
*/

class Solution {
public:

    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int capacity) {

        int n = val.size();

        vector<int> dp(capacity + 1, 0);

        for(int index = 0;
            index < n;
            index++) {

            for(int cap = wt[index];
                cap <= capacity;
                cap++) {

                dp[cap] = max(
                    dp[cap],
                    val[index]
                    + dp[cap - wt[index]]
                );
            }
        }

        return dp[capacity];
    }
};