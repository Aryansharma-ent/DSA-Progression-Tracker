/*
     Problem: Subset Sums
     Platform: Custom / Practice / Coding Ninjas / GFG
     Difficulty: Easy
     Problem Statement:
        - Given an array of integers, return all possible subset sums.
        - Include the sum of the empty subset (i.e., 0).
        - Order of sums doesn't matter unless asked.

     Approach:
        - Use recursion to explore two choices at each index:
            1. Include the current element in the subset sum.
            2. Exclude the current element.
        - At the base case (when index == size), store the current sum.

     Time Complexity:
        - O(2^n): Since there are 2^n subsets for n elements.

     Space Complexity:
        - O(2^n): To store the subset sums.
        - O(n): Auxiliary stack space in recursion (depth = n)

     Optimization:
        - Instead of maintaining a temporary vector and summing it every time,
          we pass the sum along in recursive calls to save time.

     Variants to Practice:
        - Print all subsets instead of sums.
        - Subset sum equals K.
        - Count subsets with sum K.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int index, int sum, vector<int> &ans, vector<int> &nums) {
        if (index == nums.size()) {
            ans.push_back(sum);
            return;
        }
        Recur(index + 1, sum + nums[index], ans, nums);

    
        Recur(index + 1, sum, ans, nums);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        Recur(0, 0, ans, nums);
        return ans;
    }
};
