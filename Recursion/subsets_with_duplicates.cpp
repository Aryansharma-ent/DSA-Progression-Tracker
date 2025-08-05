/*
     Leetcode Problem: Subsets II (https://leetcode.com/problems/subsets-ii/)
     Difficulty: Medium

     Problem Statement:
        - Given an integer array `nums` that may contain duplicates,
          return all possible subsets (the power set) without duplicate subsets.

     Optimal Approach:
        - Sort the array to bring duplicates together.
        - Use backtracking to explore each subset.
        - Skip duplicates at the same recursive level using:
            if (i > index && nums[i] == nums[i - 1]) continue;

     Time Complexity: O(2^n)
        - Each element has two choices (include/exclude).
        - Duplicate skipping ensures unique subset generation.

     Space Complexity: O(2^n)
        - For storing all subsets.
        - O(n) auxiliary space for recursion stack and temp storage.

     Key Idea:
        - We do not use `set<vector<int>>` to eliminate duplicates.
        - Instead, we **skip picking the same number** in the same loop level.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // skip duplicates
            temp.push_back(nums[i]);
            Recur(i + 1, temp, ans, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> temp;
        Recur(0, temp, ans, nums);
        return ans;
    }
};
