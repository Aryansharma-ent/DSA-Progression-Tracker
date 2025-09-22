/*
Problem: Jump Game (LeetCode 55)

Approach:
- Use a greedy strategy to track the farthest index reachable at each step.
- Iterate through the array:
  - If the current index `i` is beyond the farthest reachable index (`maxReach`), 
    then we cannot proceed → return false.
  - Update `maxReach` as the maximum of its current value and `i + nums[i]`.
  - If at any point `maxReach` reaches or surpasses the last index, return true.
- If the loop ends, we can reach the last index → return true.

Complexity:
- Time: O(n) — one pass through the array.
- Space: O(1) — only uses `maxReach`.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false; // can't reach this index
            maxReach = max(maxReach, i + nums[i]); // update farthest we can go
            if (maxReach >= n - 1) return true;    // can reach the last index
        }

        return true;
    }
};
