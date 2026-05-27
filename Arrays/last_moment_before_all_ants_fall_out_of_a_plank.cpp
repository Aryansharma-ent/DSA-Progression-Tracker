/*
========================================
Problem: Last Moment Before All Ants Fall Out of a Plank
Platform: LeetCode
Approach: Maximum Time to Fall

Author: Aryan
Date: 2026

----------------------------------------
Approach:

1. Observe that collisions do not matter
   because ants are indistinguishable.

2. When two ants collide,
   it is equivalent to them
   passing through each other.

3. Therefore:
   - Left moving ant falls in:
       position seconds
   - Right moving ant falls in:
       n - position seconds

4. Compute the maximum fall time
   among all ants.

----------------------------------------
Key Insight:

Collision simulation is unnecessary.

The answer is simply the farthest
time any ant needs to reach an edge.

----------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        int time = 0;

        // Ants moving left
        for(int i = 0; i < left.size(); i++) {
            time = max(time, left[i]);
        }

        // Ants moving right
        for(int i = 0; i < right.size(); i++) {
            time = max(time, n - right[i]);
        }

        return time;
    }
};