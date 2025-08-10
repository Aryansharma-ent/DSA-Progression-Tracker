/*
------------------------------------------
Problem Link   : https://leetcode.com/problems/search-in-rotated-sorted-array/
Approach       :
    - Use modified binary search to handle rotated sorted arrays.
    - At each step:
        1. If nums[mid] == target → return mid.
        2. Check which half is sorted:
            - If left half is sorted (nums[start] <= nums[mid]):
                - If target is within left half → move end to mid - 1.
                - Else → move start to mid + 1.
            - Else right half is sorted:
                - If target is within right half → move start to mid + 1.
                - Else → move end to mid - 1.
    - If not found → return -1.

Time Complexity  : O(log n) — standard binary search with constant extra steps.
Space Complexity : O(1) — no extra space used.
------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n  = nums.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
