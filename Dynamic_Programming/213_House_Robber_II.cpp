/*
========================================
Problem: House Robber II
Platform: LeetCode
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

A robber wants to rob houses
arranged in a circle.

Adjacent houses cannot be robbed
on the same night.

Since the first and last houses
are adjacent, they cannot both
be robbed.

Find the maximum amount of money
that can be robbed.

========================================
*/

/*
========================================
Key Insight

Unlike House Robber I, the houses
are arranged in a circle.

Therefore:

- If we rob the first house,
  we cannot rob the last house.

- If we rob the last house,
  we cannot rob the first house.

So we split the problem into:

Case 1:
Rob houses from 1 to n-1

Case 2:
Rob houses from 0 to n-2

Answer:

max(case1, case2)

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[i] = Maximum money that can be
        robbed starting from house i.

Choices:

1. Take current house:
   nums[i] + dp[i + 2]

2. Skip current house:
   dp[i + 1]

Take the maximum.

Solve the problem twice:

1. Excluding first house
2. Excluding last house

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

    int recur(vector<int>& nums,
              int n,
              int index,
              vector<int>& dp) {

        if(index >= n)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int take =
            nums[index] +
            recur(nums, n, index + 2, dp);

        int notTake =
            recur(nums, n, index + 1, dp);

        return dp[index] =
            max(take, notTake);
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < nums.size(); i++) {

            if(i != 0)
                temp1.push_back(nums[i]);

            if(i != nums.size() - 1)
                temp2.push_back(nums[i]);
        }

        int n = temp1.size();
        int m = temp2.size();

        vector<int> dp1(n + 1, -1);
        vector<int> dp2(m + 1, -1);

        int ans1 =
            recur(temp1, n, 0, dp1);

        int ans2 =
            recur(temp2, m, 0, dp2);

        return max(ans1, ans2);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[i] = Maximum money that can be
        robbed considering houses
        from 0 to i.

Transition:

take    = nums[i] + dp[i - 2]
notTake = dp[i - 1]

dp[i] = max(take, notTake)

Run House Robber I twice:

1. Excluding first house
2. Excluding last house

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)

========================================
*/

class SolutionTabulation {
public:

    int solve(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {

            int take = nums[i] + dp[i - 2];

            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < nums.size(); i++) {

            if(i != 0)
                temp1.push_back(nums[i]);

            if(i != nums.size() - 1)
                temp2.push_back(nums[i]);
        }

        return max(
            solve(temp1),
            solve(temp2)
        );
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

House Robber I only needs:

- dp[i - 1]
- dp[i - 2]

Therefore, we can store:

prev  -> dp[i - 1]
prev2 -> dp[i - 2]

Run the optimized solution twice:

1. Excluding first house
2. Excluding last house

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

class Solution {
public:

    int solve(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {

            int take = nums[i] + prev2;

            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < nums.size(); i++) {

            if(i != 0)
                temp1.push_back(nums[i]);

            if(i != nums.size() - 1)
                temp2.push_back(nums[i]);
        }

        return max(
            solve(temp1),
            solve(temp2)
        );
    }
};