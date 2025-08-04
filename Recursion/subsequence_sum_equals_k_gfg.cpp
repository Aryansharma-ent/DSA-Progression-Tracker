/*
    File: subsequence_sum_equals_k_gfg.cpp

    Problem:
    Given an array of integers and a target sum 'k', check whether there exists any subsequence whose sum equals k.
    Return "Yes" if such a subsequence exists, otherwise return "No".

    Approach:
    - Use recursive backtracking to explore all possible subsequences.
    - At each step, either include or exclude the current element.
    - If the sum reaches k by the end of the array, return true.

    Time Complexity: O(2^n)
        - Each element has 2 choices: include or exclude.

    Space Complexity: O(n)
        - Due to recursion stack and current path storage.

    Note:
    - This is a brute-force approach. For larger inputs or optimization, dynamic programming (subset sum) can be applied.
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
   int Recur(int index, vector<int> &ans, vector<int> &nums, int sum, int k) {
        if(index == nums.size()) {
            if(sum == k) {
                return 1;
            }
            return 0;
        }

        // Include current number
        ans.push_back(nums[index]);
        int left = Recur(index + 1, ans, nums, sum + nums[index], k);
        ans.pop_back();

        // Exclude current number
       int right = Recur(index + 1, ans, nums, sum, k);
return left + right;
    }
  
  
  
    bool checkSubsequenceSum(int n, vector<int>& nums, int k) {
          vector<int> ans;
         int check = Recur(0,ans,nums,0,k);
         if(check > 0){
            return true;
         }
         return false;
        
    }
};