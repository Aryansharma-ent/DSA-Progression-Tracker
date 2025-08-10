/*
------------------------------------------
Problem Link   : https://www.geeksforgeeks.org/problems/ceiling-in-a-sorted-array-1587115620/
Approach       : 
    - Sort the input array (since floor and ceil search requires sorted array).
    - Use binary search to find:
        - Floor: the largest element <= x
        - Ceil: the smallest element >= x
    - If nums[mid] > x → update ceiling and search left (end = mid - 1).
    - If nums[mid] < x → update floor and search right (start = mid + 1).
    - If nums[mid] == x → both floor and ceiling are nums[mid].

Time Complexity  : O(n log n) due to sorting + O(log n) binary search → O(n log n)
Space Complexity : O(1) extra space
------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int start = 0, end = n - 1;
        int floorVal = -1, ceilingVal = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > x) {
                ceilingVal = nums[mid];
                end = mid - 1;
            } 
            else if (nums[mid] < x) {
                floorVal = nums[mid];
                start = mid + 1;
            } 
            else {
                floorVal = nums[mid];
                ceilingVal = nums[mid];
                break;
            }
        }

        ans.push_back(floorVal);
        ans.push_back(ceilingVal);
        return ans;
    }
};
