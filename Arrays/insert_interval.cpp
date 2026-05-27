/*
========================================
Problem: Insert Interval
Platform: LeetCode
Approach: Interval Merging

Author: Aryan
Date: 2026

----------------------------------------
Approach:

1. Add all intervals that end
   before newInterval starts.

2. Merge all overlapping intervals
   with newInterval.

3. Add the merged interval.

4. Add remaining intervals.

----------------------------------------
Key Insight:

Intervals overlap if:

interval.start <= newInterval.end

While overlapping:
- Expand left boundary using min()
- Expand right boundary using max()

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(
        vector<vector<int>>& intervals,
        vector<int>& newInterval) {

        vector<vector<int>> ans;

        int i = 0;

        // Add all non-overlapping intervals
        // that come before newInterval
        while(i < intervals.size() &&
              intervals[i][1] < newInterval[0]) {

            ans.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals
        while(i < intervals.size() &&
              intervals[i][0] <= newInterval[1]) {

            newInterval[0] =
                min(intervals[i][0], newInterval[0]);

            newInterval[1] =
                max(intervals[i][1], newInterval[1]);

            i++;
        }

        // Add merged interval
        ans.push_back(newInterval);

        // Add remaining intervals
        while(i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};