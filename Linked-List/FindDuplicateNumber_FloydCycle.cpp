/*
    LeetCode 287: Find the Duplicate Number

    ✅ Approach: Floyd’s Tortoise and Hare (Cycle Detection)
    ------------------------------------------------------
    Observation:
    - nums has size (n + 1)
    - values are in range [1..n]
    - only ONE value is duplicated (it may appear more than twice)

    We can treat the array like a linked list:
    - Each index is a node
    - The "next" pointer of index i is nums[i]
      i -> nums[i]

    Because there is a duplicate number, two indices will point to the same next node,
    creating a cycle in this linked list.

    Floyd’s Cycle Detection:
    - Phase 1: Find intersection point inside the cycle
        slow moves 1 step  -> slow = nums[slow]
        fast moves 2 steps -> fast = nums[nums[fast]]
      They will eventually meet inside the cycle.

    - Phase 2: Find the entry point of the cycle
        Reset one pointer to start (nums[0])
        Move both pointers 1 step at a time
      The point where they meet again is the duplicate number.

    ✅ Time Complexity: O(n)
    ✅ Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: find intersection inside the cycle
        do {
            slow = nums[slow];          // 1 step
            fast = nums[nums[fast]];    // 2 steps
        } while (slow != fast);

        // Phase 2: find cycle entry (duplicate)
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // duplicate number
    }
};
