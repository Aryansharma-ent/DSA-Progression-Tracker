/*
========================================
Problem: Interval List Intersections
Platform: LeetCode
Approach: Two Pointer Technique

Author: Aryan
Date: 2026

----------------------------------------
Approach:

1. Use two pointers:
   - i for firstList
   - j for secondList

2. For current intervals:
   [start1, end1]
   [start2, end2]

   Find overlap using:

   start = max(start1, start2)
   end   = min(end1, end2)

3. If start <= end,
   then intersection exists.

4. Move the pointer whose
   interval ends first because
   that interval cannot overlap
   further.

----------------------------------------
Key Insight:

Two intervals overlap if:

max(start1, start2) <= min(end1, end2)

----------------------------------------
Time Complexity: O(n + m)
Space Complexity: O(1)
(excluding output array)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& firstList,
        vector<vector<int>>& secondList) {

        vector<vector<int>> ans;

        // Pointers for both interval lists
        int i = 0;
        int j = 0;

        // Traverse both lists
        while(i < firstList.size() &&
              j < secondList.size()) {

            // Current interval from first list
            int start1 = firstList[i][0];
            int end1   = firstList[i][1];

            // Current interval from second list
            int start2 = secondList[j][0];
            int end2   = secondList[j][1];

            // Find overlapping range
            int start = max(start1, start2);
            int end   = min(end1, end2);

            // Valid intersection exists
            if(start <= end) {
                ans.push_back({start, end});
            }

            // Move the interval that ends first
            if(end1 < end2) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};