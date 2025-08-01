//  Subsets - Recursion + Backtracking Approach
//  Problem: Generate all subsets of a given array (Power Set)
//
//  Approach:
// Use recursion to explore all include/exclude decisions for each element.
// Start with an empty subset and at each index, choose to either:
// 1. Include the current element.
// 2. Skip the current element.
// Recursively build the subset and store it in the result.
//
// Time Complexity: O(2^n)
//  For every element, we have 2 choices: include or exclude.
//  So, total subsets = 2^n
//
//  Space Complexity: 
//  O(n) auxiliary space for recursion stack (max depth = n)
//  O(2^n * n) space for storing all subsets (each subset can be size n)



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recur(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        // Base case: If index has reached end of array
        if (index == nums.size()) {
            result.push_back(temp); // Store current subset
            return;
        }

        // Choice 1: Exclude the current element
        recur(index + 1, nums, temp, result);

        // Choice 2: Include the current element
        temp.push_back(nums[index]);
        recur(index + 1, nums, temp, result);

        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        recur(0, nums, temp, result);
        return result;
    }
};
