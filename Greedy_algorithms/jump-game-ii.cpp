/*
Problem: Jump Game II (LeetCode 45)

Approach:
- Use a greedy BFS-like method.
- Maintain two pointers `l` and `r` that represent the current jump range.
- For every index in [l, r], calculate the farthest index reachable.
- Once the range is exhausted, increment the jump count and move to the next range [r+1, farthest].
- Repeat until the last index is covered.

Complexity:
- Time: O(n) — each index is processed at most once.
- Space: O(1) — only uses a few variables.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int l = 0;
        int r = 0;
        int jumps = 0;

        while (r < nums.size() - 1) {
            for (int index = l; index <= r; index++) {
                farthest = max(farthest, index + nums[index]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
