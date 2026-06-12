/*
========================================
Problem: Ninja Training
Platform: Coding Ninjas / Striver DP
Approach: Dynamic Programming

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

A ninja has to perform one task
every day.

There are 3 tasks:

0 -> Running
1 -> Fighting Practice
2 -> Learning New Moves

Points for each task are given.

Constraint:

The ninja cannot perform the
same task on two consecutive days.

Find the maximum points that
can be earned.

========================================
*/

/*
========================================
Approach 1: Memoization (Top-Down DP)

State:

dp[day][last]

Maximum points obtainable from
day 0 to day 'day' when the last
performed task is 'last'.

last can be:

0, 1, 2 -> specific task
3        -> no previous task

Transition:

Try all tasks except 'last'
and take the maximum.

----------------------------------------
Time Complexity: O(n * 4 * 3)
Space Complexity: O(n * 4)

(dp table + recursion stack)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMemoization {
public:

    int recur(vector<vector<int>>& points,
              int day,
              int last,
              vector<vector<int>>& dp) {

        if(day == 0) {

            int maxi = 0;

            for(int task = 0; task < 3; task++) {

                if(task != last)
                    maxi = max(maxi,
                               points[0][task]);
            }

            return maxi;
        }

        if(dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for(int task = 0; task < 3; task++) {

            if(task != last) {

                int curr =
                    points[day][task]
                    +
                    recur(points,
                          day - 1,
                          task,
                          dp);

                maxi = max(maxi,
                           curr);
            }
        }

        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<int>> dp(
            n,
            vector<int>(4, -1)
        );

        return recur(points,
                     n - 1,
                     3,
                     dp);
    }
};

/*
========================================
Approach 2: Tabulation (Bottom-Up DP)

State:

dp[day][last]

Maximum points obtainable up to
'day' when the last task is
'last'.

Build the table from day 0.

----------------------------------------
Time Complexity: O(n * 4 * 3)
Space Complexity: O(n * 4)

========================================
*/

class SolutionTabulation {
public:

    int ninjaTraining(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<int>> dp(
            n,
            vector<int>(4, 0)
        );

        dp[0][0] = max(points[0][1],
                       points[0][2]);

        dp[0][1] = max(points[0][0],
                       points[0][2]);

        dp[0][2] = max(points[0][0],
                       points[0][1]);

        dp[0][3] = max({
            points[0][0],
            points[0][1],
            points[0][2]
        });

        for(int day = 1; day < n; day++) {

            for(int last = 0; last < 4; last++) {

                dp[day][last] = 0;

                for(int task = 0; task < 3; task++) {

                    if(task != last) {

                        int curr =
                            points[day][task]
                            +
                            dp[day - 1][task];

                        dp[day][last] =
                            max(dp[day][last],
                                curr);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};

/*
========================================
Approach 3: Space Optimized DP

Observation:

To compute the current day,
we only need the previous day.

Therefore, storing all days
is unnecessary.

Keep only:

prev -> previous day's values

----------------------------------------
Time Complexity: O(n * 4 * 3)
Space Complexity: O(4)

========================================
*/

class Solution {
public:

    int ninjaTraining(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> prev(4, 0);

        prev[0] = max(points[0][1],
                      points[0][2]);

        prev[1] = max(points[0][0],
                      points[0][2]);

        prev[2] = max(points[0][0],
                      points[0][1]);

        prev[3] = max({
            points[0][0],
            points[0][1],
            points[0][2]
        });

        for(int day = 1; day < n; day++) {

            vector<int> curr(4, 0);

            for(int last = 0; last < 4; last++) {

                for(int task = 0; task < 3; task++) {

                    if(task != last) {

                        curr[last] =
                            max(curr[last],
                                points[day][task]
                                + prev[task]);
                    }
                }
            }

            prev = curr;
        }

        return prev[3];
    }
};