/*
Problem: LeetCode 57 - Insert Interval
--------------------------------------
You are given a set of non-overlapping intervals sorted by their start times.
Insert a new interval into the intervals (merge if necessary) and return the resulting intervals.

Approach:
---------
1. Traverse the list of intervals:
   - Add all intervals that end before the new interval starts (no overlap).
2. Merge overlapping intervals:
   - While the current interval starts <= newInterval.end, merge them by updating:
     newInterval.start = min(newInterval.start, current.start)
     newInterval.end   = max(newInterval.end, current.end)
3. Add the merged newInterval to the result.
4. Append all remaining intervals (that start after newInterval ends).
5. Return the final result.

Complexity Analysis:
--------------------
- Time Complexity: O(n)  
  (We traverse all intervals once.)
- Space Complexity: O(n)  
  (For storing the result; no extra significant space used.)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Step 1: Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Step 3: Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
