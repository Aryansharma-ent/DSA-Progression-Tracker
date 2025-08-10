/*
------------------------------------------
Problem Link   : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Approach       : 
    - Use binary search twice:
        1. First to find the first occurrence of the target.
        2. Second to find the last occurrence of the target.
    - In first occurrence search, whenever we find the target, we update 'firstans' 
      and move left (end = mid - 1) to check for earlier occurrence.
    - In last occurrence search, whenever we find the target, we update 'lastans' 
      and move right (start = mid + 1) to check for later occurrence.
    - If the target is not found, return {-1, -1}.

Time Complexity  : O(log n) for each binary search → O(log n) total
Space Complexity : O(1) extra space
------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstOccurrence(vector<int>& nums, int n, int target) {
        int start = 0, end = n - 1, firstans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                firstans = mid;
                end = mid - 1; // search left
            } 
            else if (nums[mid] < target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return firstans;
    }

    int lastOccurrence(vector<int>& nums, int n, int target) {
        int start = 0, end = n - 1, lastans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                lastans = mid;
                start = mid + 1; // search right
            } 
            else if (nums[mid] < target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return lastans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstocc = firstOccurrence(nums, n, target);
        int lastocc = lastOccurrence(nums, n, target);
        return {firstocc, lastocc};
    }
};
